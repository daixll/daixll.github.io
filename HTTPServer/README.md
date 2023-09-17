**参考：[muduo](https://github.com/chenshuo/muduo)**

---

`系统` WSL: Ubuntu-22.04

`软件` gcc: gcc version 11.4.0 (Ubuntu 11.4.0-1ubuntu1~22.04)

这是一个HTTP服务器，目的是通过此项目学习网络编程：

* [TCP / IP 分层模型](#tcp--ip-分层模型) 及 [三握四挥](#tcp-三握四挥)
* [socket 通信模型](#socket-通信模型)
* [socket 编程](#socket-通信简单实例)

* TCP/UDP协议、HTTP协议
* TCP/UDP编程
* 网络IO接口复用：select、poll、epoll
* 阻塞、非阻塞
* 同步、异步


## TCP / IP 分层模型


| 层     | 协议 |
| :-:    | :-: |
| 应用层 | `HTTP` `FTP` `...` |
| 传输层 | `TCP` `UDP` `...` |
| 网络层 | `IPV4` `IPV6` `...` |
| 物理层 | `LAN` `WLAN` `...` |

## socket 通信模型
socket是一个接口，而不是一种协议，其抽象在应用层与传输层之间

|       |  函数  |  服务端  |                      
| :---: |  :---:  | :---: | 
| 1 | `socket()`| 创建 socket                   |  
| 2 | `bind()`  | 绑定 ip + port 至该 socket 上 |  
| 3 | `listen()`| 监听该 端口                   |
| 4 | `accept()`| 接受来自客户端的连接请求        | 
| 5 | `recv()`  | 从 socket 中读取字符          |  
| 6 | `close()` | 关闭 socket                   |  

|       |  函数  |  客户端		|   
| :---: |  :---:  | :---: 		|
| 1 | `socket()`  | 创建 socket	|
| 2 | `connect()` | 连接指定 ip + port |
| 3 | `send()` | 发送消息 |
| 4 | `close()` | 关闭 socket |


## socket 通信简单实例
    
* 启动 [服务端](样例/套接字通信样例/服务端.cpp)
    1. 编译 `g++ 服务端.cpp -o 服务端`
    2. 运行 `./服务端` 默认运行在本地 8080 端口
* 启动 [客户端](样例/套接字通信样例/客户端.cpp)
    1. 编译 `g++ 客户端.cpp -o 客户端`
    2. 运行 `./客户端`     
   
可以同时运行多个客户端，但服务端在同一时刻只允许一台客户端连接。连接之后：
1. 客户端发送消息，服务端接收消息
2. 服务端发送消息，客户端接收消息
3. 不断重复，直到客户端断开连接

## TCP 三握四挥

* 连接
    1. `客户端` 请求连接，`connect` 阻塞。
    2. `服务端` 收到请求，`accept` 阻塞，同时向 `客户端` 发送确认信息。
    3. `客户端` 确认。`connect` 返回。同时发送信息。`accept` 返回。

* 断开
    1. `客户端` 请求断开，`close` 阻塞。
    2. `服务端` 发送确认信息（我已知晓）。
    3. `服务端` 发送请求信息（请求断开），`close` 阻塞。
    4. `客户端` 收到确认信息，发送确认信息，俩 `close` 先后返回。

* 连接之后
    1. `客户端` 发送信息，`send` 阻塞。
    2. `服务端` 接收信息，`recv` 阻塞。
    3. `服务端` 发送信息，`send` 阻塞。
    4. `客户端` 接收信息，`recv` 阻塞。
    5. 重复 1-4，直到 `客户端` 或 `服务端` 断开连接。

## Epoll

eventpoll，事件轮询，Linux 内核实现IO多路复用（IO multiplexing）的一个实现。

直观来说，I/O 复用的作用就是：让程序能够在单进程、单线程的模式下，同时处理 **多个文件描述符** 的 I/O 请求。

* `int epoll_create1()` 
    * 创建一个 epoll 对象，事件轮询的实例，返回一个文件描述符，即事件树。

* `int epoll_ctl(事件树, 操作, 文件描述符, 事件)`
    * 操作：`EPOLL_CTL_ADD` `EPOLL_CTL_MOD` `EPOLL_CTL_DEL`
    * 事件：`EPOLLIN` `EPOLLOUT` `EPOLLERR` `EPOLLHUP` `EPOLLET` `EPOLLONESHOT`

* `int epoll_wait(事件树, 事件数组, 事件数组大小, 超时时间)`
    * 事件数组：`epoll_event` 结构体数组
    * 超时时间：`-1` 阻塞，`0` 立即返回，`>0` 等待指定时间
