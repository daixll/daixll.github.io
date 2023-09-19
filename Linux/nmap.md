---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

[官方中文文档](https://nmap.org/man/zh/index.html)

`nmap [ <扫描类型> ...] [ <选项> ] { <扫描目标说明> }`

# nmap 端口状态

## open（开放的）

应用程序正在监听端口，或者响应一个请求来自已连接的客户端。接收TCP连接或者UDP报文。

## closed（关闭的）

没有应用程序监听端口。但是此端口可以被探测到，因为没有应用程序监听，所以会返回一个 RST 包或者 ICMP 端口不可达消息。

## filtered（屏蔽的）

防火墙或者 ACL 屏蔽了端口，所以无法确定端口是否开放。目标端口可能有以下几种情况：
* 未响应，屏蔽器丢弃了探测包，此举会让 nmap 误认为探测包丢失，导致扫描时间变长。
* 丢弃了探测包，但是返回了 ICMP 错误消息。

## unfiltered（未屏蔽的）

防火墙或者 ACL 没有屏蔽端口，但是 nmap 无法确定端口开放或者关闭。用其它类型的扫描，如窗口扫描，SYN 扫描，或者 FIN 扫描可以帮助确定端口是否开放。

## open|filtered（开放或者屏蔽的）

开放的端口不响应探测包，屏蔽的端口也不响应探测包。所以无法确定端口是否开放。

## closed|filtered（关闭或者屏蔽的）

只可能出现在 IPID Idle 扫描中，因为此扫描类型需要发送两个探测包，如果两个探测包都没有响应，那么就无法确定端口是否开放。

---

# nmap 扫描技术


## 1 默认扫描

`nmap dxll.love`

默认扫描是 nmap 的最基本的扫描方式，它会扫描 1000 个最常用的端口，扫描方式是 SYN 扫描。

```sh
nmap -T0 dxll.love
nmap -T1 dxll.love
nmap -T2 dxll.love
nmap -T3 dxll.love
nmap -T4 dxll.love
nmap -T5 dxll.love
```

`-T0` 是最慢的扫描方式，`-T5` 是最快的扫描方式，`-T3` 是默认的扫描方式，`-T4` 是常用的扫描方式。

`nmap -6 dxll.love`

开启 IPv6 扫描。

`nmap -v dxll.love`

开启详细模式，显示扫描过程。

`nmap -A dxll.love`

全面扫描，包括 1-10000 端口扫描，服务版本探测，操作系统探测，脚本扫描等。

## 2 扫描多个 IP

```sh
nmap spacex.com dxll.love   # 扫描多个域名
nmap 192.168.31.100,101,102 # 扫描同一网段的多个 IP，可以用逗号分隔
nmap 192.168.31.*           # 扫描同一网段的多个 IP，可以用通配符
nmap 192.168.31.1/24        # 扫描同一网段的多个 IP，可以用 CIDR 表示法
```

## 3 扫描指定端口

```sh
nmap -p 80 dxll.love        # 扫描单个端口
nmap -p 80,443 dxll.love    # 扫描多个端口
nmap -p 1-100 dxll.love     # 扫描端口范围
nmap -p-                    # 扫描所有端口 等价于 nmap -p 1-65535
```

## 4 TCP扫描

### TCP SYN 扫描

`nmap -sS dxll.love`

此方式不完成 TCP 三次握手，而是发送一个 SYN 包，如果目标端口开放，那么会返回一个 SYN/ACK 包，如果端口关闭，那么会返回一个 RST 包。

### TCP Connect 扫描

`nmap -sT dxll.love`

此方式完成 TCP 三次握手，如果目标端口开放，那么会返回一个 SYN/ACK 包，如果端口关闭，那么会返回一个 RST 包。
目标主机可能会记录下连接，所以此方式不太隐蔽。

### TCP 隐秘扫描

如果收到 RST 响应，则端口关闭，否则判定端口开放或被屏蔽。

`nmap -sN dxll.love`

不设置任何标志位。

`nmap -sF dxll.love`

只设置TCP FIN标志位。

`nmap -sX dxll.love`

flags的FIN、URG、PUSH都为1的包。

### TCP ping 扫描

`nmap -sP dxll.love`

通过发送ICMP Echo请求（也称为Ping请求）到目标主机，命令将检测主机是否响应了请求并返回IP地址。如果主机响应，则表示主机是在线的。在这个扫描中，Nmap只检查是否有响应，而不扫描主机的任何端口。

## 5 UDP 扫描

`namp -sU dxll.love`

UDP 扫描需要发送 UDP 包，如果目标端口开放，那么会返回一个 ICMP 端口不可达消息，如果端口关闭，那么会返回一个 ICMP 端口不可达消息或者没有响应。


## 6 路由跟踪

`nmap --traceroute dxll.love`

查出从本地计算机到目标之间所经过的网络节点，并可以看到通过各个节点的时间。

## 7 操作系统探测

`nmap -O dxll.love`

nmap 会发送一系列的 TCP 和 UDP 包，然后分析返回的包，从而判断目标主机的操作系统。