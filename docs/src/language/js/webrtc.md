**参考**

* [WebRTC 使用入门](https://web.dev/articles/webrtc-basics?hl=zh-cn#signaling_session_control_network_and_media_information)
* [WebRTC samples](https://webrtc.github.io/samples/)
* [扩展 WebRTC 的 3 种关键方法：SFU、MCU 和 XDN](https://www.red5.net/blog/3-key-approaches-for-scaling-webrtc-sfu-mcu-and-xdn/)

## 1c1s

```js
const signaling = new WebSocket('wss://85348b3.r27.cpolar.top')                         // 信令服务器
let PC = null                                                                           // 连接

signaling.onopen = () => {
    console.log('信令服务器：成功连接！')
    navigator.mediaDevices.getUserMedia({ video: true, audio: true}).then(stream => {   // 1. 获取流
        document.getElementById('local_H').srcObject = stream                           // 2. 将流绑定到标签
        PC = new RTCPeerConnection()                                                    // 3. 创建连接
        PC.onicecandidate = (e) => {                                                    // 4. 发送 ice
            if (e.candidate) {                                                          // 一定，一定，一定要在 new 完 RTCPeerConnection 后马上设置 onicecandidate
                signaling.send(JSON.stringify({
                    type: 'ice',
                    ice: JSON.stringify(e.candidate)
                }))
            }
            console.log('发送 ice candidate', e.candidate)
        }
        stream.getTracks().forEach((track) => PC.addTrack(track, stream))               // 5. 将流添加到连接
        PC.createOffer().then(offer => {                                                // 6. 创建 offer sdp
            PC.setLocalDescription(offer)                                               // 7. 设置本地 sdp
            signaling.send(JSON.stringify(offer))                                       // 8. 发送 offer sdp
            console.log('发送 offer sdp', offer)
        })})
}

signaling.onmessage = async (event) => {                                                // 9. 接收 answer sdp
    const msg = JSON.parse(event.data)                                                  
    if (msg.type === 'answer') {
        console.log('收到 answer sdp', msg)
        PC.setRemoteDescription(msg)                                                    // 10. 设置远程 sdp
    }
}

signaling.onclose = () => {console.log('信令服务器：关闭连接！')}
signaling.onerror = (error) => {console.log('信令服务器：错误连接！', error)}
```

```js
const signaling = new WebSocket('wss://85348b3.r27.cpolar.top')                         // 信令服务器
let PC = null                                                                           // 连接

signaling.onmessage = async (event) => {
    const msg = JSON.parse(event.data)
    if (msg.type === 'offer') {                                                         // 1. 收到 offer sdp
        console.log('收到 offer sdp', msg)
        PC = new RTCPeerConnection()                                                    // 2. 创建连接
        PC.ontrack = (e) => {                                                           // 3. 监听连接上的流
            document.getElementById('remote_H').srcObject = e.streams[0]
        }
        PC.setRemoteDescription(msg)                                                    // 4. 设置远程 sdp
        const answer = await PC.createAnswer()                                          // 5. 创建 answer sdp
        PC.setLocalDescription(answer)                                                  // 6. 设置本地 sdp
        signaling.send(JSON.stringify(answer))                                          // 7. 发送 answer
        console.log('发送 answer sdp', answer)
    } else if (msg.type === 'ice') {
        console.log('收到 ice candidate', JSON.parse(msg.ice))
        PC.addIceCandidate(JSON.parse(msg.ice))                                         // 8. 添加 ice
    }
}

signaling.onopen = () => {console.log('信令服务器：成功连接！')}
signaling.onclose = () => {console.log('信令服务器：关闭连接！')}
signaling.onerror = (error) => {console.log('信令服务器：错误连接！', error)}
```

```go
package main

import (
    "log"
    "net/http"
    "github.com/gorilla/websocket"
)

type Message struct {
    Type string `json:"type"`
    Sdp string `json:"sdp"`
    Ice string `json:"ice"`
}

var cs = make(map[*websocket.Conn]bool)  // 1. 连接的集合

func handleConnection(w http.ResponseWriter, r *http.Request) {
    upgrader := websocket.Upgrader{
        CheckOrigin: func(r *http.Request) bool {
            return true
        },
    }
    conn, err := upgrader.Upgrade(w, r, nil)
    if err != nil {
        log.Println("升级为 websocket 失败:", err)
        return
    }
    cs[conn] = true

    defer conn.Close()          // 连接关闭时删除连接
    log.Println("连接成功:", conn.LocalAddr())

    for {
        var msg Message
        err := conn.ReadJSON(&msg)
        if err != nil {
            log.Println("读取消息失败:", err)
            return
        }

        log.Println("收到消息:", msg.Type)

        for c := range cs {
            if c != conn {
                c.WriteJSON(msg)
            }
        }
    }
}

func main() {
    http.HandleFunc("/", handleConnection)
    http.ListenAndServe(":3002", nil)
}
```

## p2p

两人皆收发

## 