---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

<style>
    .center
    {
    width: auto;
    display: table;
    margin-left: auto;
    margin-right: auto;
    }
</style>

# 引子

**[源代码](https://github.com/daixll/A_Tour_of_Socket)**

> 请务必确定，对以下知识有一定的了解

**TCP / IP 分层模型**：

| 层     | 协议 |
| :-:    | :-: |
| 应用层 | `HTTP` `FTP` `...` |
| 传输层 | `TCP` `UDP` `...` |
| 网络层 | `IPv4` `IPv6` `...` |
| 物理层 | `LAN` `WLAN` `...` |

**计算机组成原理**：

|  设备  |  功能   |
| :-:  | :-: |
| 数据总线 | 传输数据 |
| IO设备   | 输入输出 |
| 主存储器 | 存储数据 |
| CPU    | 计算数据 |

**操作系统**：

* （内核空间）管理计算机硬件资源进行管理和控制

* （用户空间）提供系统调用接口，供用户程序调用

* **进程**：为了让计算机能够同时运行多个程序，操作系统引入了进程的概念

* **线程**：线程是 CPU 调度的基本单位，进程是资源分配的基本单位

<br>

**参考**

* **书籍**
    * 《Linux 多线程服务端编程：使用 muduo C++ 网络库》
    * 《Linux 高性能服务器编程》 游双


* **博客**
    * [30天自制C++服务器](https://github.com/yuesong-feng/30dayMakeCppServer)
    * [webServer](https://blog.csdn.net/weixin_50437588/category_12156183.html)

<br>

---

# 1 阻塞 IO

当 **进程** 发起 **IO请求** 后，如果 **内核** 没有准备好数据，那么 **进程** 将一直等待，直到 **内核** 准备好数据为止

> 当程序发起发送数据的请求时，如果发送缓冲区已满，那么程序将一直等待，直到发送缓冲区有空间为止

> 当程序发起接收数据的请求时，如果接收缓冲区为空，那么程序将一直等待，直到接收缓冲区有数据为止

## TCP

**TCP 通信模型**

socket 是一个接口，而不是一种协议，其抽象在应用层与传输层之间

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


### server

1. 创建套接字 `socket()`
    ```cpp
    #include <sys/socket.h> // socket()
    ```

    ```cpp
    int server = socket(AF_INET, SOCK_STREAM, 0); // 创建套接字
    ```
    > 当 `socket()` 函数调用成功时，返回一个文件描述符，即 `socket`，当调用失败时，返回 `-1`


    * `AF_INET`：IPv4
    * `SOCK_STREAM`：TCP
    * `0`：自动选择协议，这里是 `TCP` 协议

<br>

2. 绑定 ip + port `bind()`
    ```cpp
    #include <cstring>     // memset()
    #include <arpa/inet.h> // sockaddr
    ```

    ```cpp
    // 服务端地址
    sockaddr_in server_addr;
    memset(&server_addr, '\0', sizeof server_addr);
    // 给地址赋值
    server_addr.sin_family      = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    server_addr.sin_port        = htons(10086);
    // 绑定
    bind(server, (sockaddr*)&server_addr, sizeof server_addr);
    ```
    > 当 `bind()` 函数调用成功时，返回 `0`，当调用失败时，返回 `-1`

    * `sockaddr_in`：IPv4 套接字地址结构体
    * `sin_family`：地址族，这里是 IPv4
    * `sin_addr.s_addr`：IPv4 地址
    * `sin_port`：端口号

    <br>

    > 为什么要强制转换为 `sockaddr`？ 
    > 为什么要使用 `sockaddr_in` 而不是 `sockaddr`？
    > * `sockaddr` 是一个通用的套接字地址结构体，可以用于任何类型的套接字
    > * `sockaddr_in` 是一个 IPv4 套接字地址结构体，只能用于 IPv4 套接字
    > * `sockaddr_in` 是 `sockaddr` 的子类，可以强制转换为 `sockaddr`
    > * 除了 `sockaddr_in`，还有 `sockaddr_in6`、`sockaddr_un` 等
    
<br>

3. 监听 `listen()`

    ```cpp
    // 监听
    listen(server, 0);
    ```
    > 当 `listen()` 函数调用成功时，返回 `0`，当调用失败时，返回 `-1`

    * `0`：等待队列的最大长度，目前无需关注

<br>

4. 接受连接请求 `accept()`

    ```cpp
    sockaddr_in client_addr;
    socklen_t   client_addr_len = sizeof client_addr;
    int client = accept(server, (sockaddr*)&client_addr, &client_addr_len);
    ```
    > 当 `accept()` 函数调用成功时，返回一个文件描述符，即 `socket`，当调用失败时，返回 `-1`

    * `socklen_t`：`sockaddr` 的长度类型

    > 为什么这里需要传入 `&client_addr_len` 而不是 `client_addr_len`？
    > * `accept()` 函数会修改 `client_addr_len` 的值，所以需要传入指针

<br>

5. 接收消息 `recv()`

    ```cpp
    char buf[1024];
    memset(buf, '\0', sizeof buf);
    recv(server, buf, sizeof buf, 0);
    ```

    > 通常，`recv()` 函数返回接收到的字节数，对端关闭返回 `0`，其余返回 `-1`

<br>

6. 关闭套接字 `close()`

    ```cpp
    close(server);
    ```

<br>

### client

1. 创建套接字 `socket()`
    ```cpp
    #include <sys/socket.h> // socket()
    ```

2. 连接指定 ip + port `connect()`
    ```cpp
    sockaddr_in server_addr;
    memset(&server_addr, '\0', sizeof server_addr);
    // 给地址赋值
    server_addr.sin_family      = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port        = htons(10086);
    // 连接
    connect(client, (sockaddr*)&server_addr, sizeof server_addr);
    ```

    > 当 `connect()` 函数调用成功时，返回 `0`，当调用失败时，返回 `-1`

3. 发送消息 `send()`

    ```cpp
    char buf[1024];
    memset(buf, '\0', sizeof buf);
    scanf("%s", buf);
    send(client, buf, strlen(buf), 0);
    ```

    > 通常，`send()` 函数返回发送的字节数，对端关闭返回 `0`，其余返回 `-1`

4. 关闭套接字 `close()`

    ```cpp
    close(client);
    ```

<br>

### send 和 recv

* `> 0` 发送或接收的字节数
* `= 0` 对端已经关闭连接
* `< 0` 出现了错误


<br>

###  TCP 三握四挥

* 连接
    1. `客户端` 请求连接，`connect` 阻塞
    2. `服务端` 收到请求，`accept` 阻塞，同时向 `客户端` 发送确认信息
    3. `客户端` 确认；`connect` 返回；同时发送信息；`accept` 返回

* 断开
    1. `客户端` 请求断开，`close` 阻塞
    2. `服务端` 发送确认信息（我已知晓）
    3. `服务端` 发送请求信息（请求断开），`close` 阻塞
    4. `客户端` 收到确认信息，发送确认信息，俩 `close` 先后返回

* 连接之后
    1. `客户端` 发送信息，`send` 阻塞
    2. `服务端` 接收信息，`recv` 阻塞
    3. `服务端` 发送信息，`send` 阻塞
    4. `客户端` 接收信息，`recv` 阻塞
    5. 重复 1-4，直到 `客户端` 或 `服务端` 断开连接

<br>

---

## UDP

**UDP 通信模型**

|       |  函数  |  服务端  |                      
| :---: |  :---:  | :---: | 
| 1 | `socket()`| 创建 socket                   |  
| 2 | `bind()`  | 绑定 ip + port 至该 socket 上 |  
| 3 | `recvfrom()`| 接收来自客户端的消息        |
| 4 | `close()` | 关闭 socket                   |  

|       |  函数  |  客户端		|   
| :---: |  :---:  | :---: 		|
| 1 | `socket()`  | 创建 socket	|
| 2 | `sendto()` | 发送消息 |
| 3 | `close()` | 关闭 socket |

### server

1. 创建套接字 `socket()`

    ```cpp
    int server = socket(AF_INET, SOCK_DGRAM, 0);    // 创建套接字
    ```
    * `SOCK_DGRAM`：UDP
    * `0`：自动选择协议，这里是 `UDP` 协议

2. 绑定 ip + port `bind()`

    ```cpp
    // 服务端地址
    sockaddr_in server_addr;
    memset(&server_addr, '\0', sizeof server_addr);
    // 给地址赋值
    server_addr.sin_family      = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    server_addr.sin_port        = htons(10086);
    // 绑定
    bind(server, (sockaddr*)&server_addr, sizeof server_addr);
    ```

3. 接收消息 `recvfrom()`

    ```cpp
    // 缓冲区
    char buf[1024];
    memset(buf, '\0', sizeof buf);
    // 客户端地址
    sockaddr_in client_addr;
    memset(&client_addr, '\0', sizeof client_addr);
    socklen_t   client_addr_len = sizeof client_addr;
    // 接收消息
    recvfrom(server, buf, sizeof buf, 0, (sockaddr*)&client_addr, &client_addr_len);
    ```

4. 关闭套接字 `close()`

    ```cpp
    close(server);
    ```

### client

1. 创建套接字 `socket()`

    ```cpp
    int server = socket(AF_INET, SOCK_DGRAM, 0);    // 创建套接字
    ```

2. 发送消息 `sendto()`

    ```cpp
    // 服务端地址
    sockaddr_in server_addr;
    memset(&server_addr, '\0', sizeof server_addr);
    // 给地址赋值
    server_addr.sin_family      = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port        = htons(10086);
    // 发送消息
    char buf[1024];
    memset(buf, '\0', sizeof buf);
    scanf("%s", buf);
    sendto(client, buf, strlen(buf), 0, (sockaddr*)&server_addr, sizeof server_addr);
    ```

3. 关闭套接字 `close()`

    ```cpp
    close(client);
    ```

<br>

---

## HTTP *

HTTP 协议是基于 TCP 协议的应用层协议，默认端口号是 80（HTTPS是 443），HTTP 协议的通信模型是 **请求-响应** 模型

* 请求，即客户端向服务端发送的消息
* 响应，即服务端向客户端发送的消息

HTTP 协议的请求消息和响应消息都是由 **请求 / 响应行**、**请求 / 响应头**、**请求 / 响应体** 组成

* **请求行** 由三部分组成：请求方法、请求路径、HTTP版本

    * 请求方法：
        * **GET：**
           - **用途：** 请求获取指定资源.不应该对服务器端数据产生任何影响。
           - **示例：** `GET /index.html`，获取首页信息。

        2. **POST：**
           - **用途：** 用于向指定资源提交数据，请求服务器进行处理。常用于提交表单数据或上传文件。
           - **示例：** `POST /users`，提交用户注册表单。

        3. **PUT：**
           - **用途：** 请求服务器存储一个资源。通常是更新已存在的资源或创建新资源。
           - **示例：** `PUT /products/123`，更新产品编号为123的商品信息。

        4. **DELETE：**
           - **用途：** 请求服务器删除指定的资源。
           - **示例：** `DELETE /users/456`，删除用户编号为456的用户信息。

        5. **HEAD：**
           - **用途：** 请求获取指定资源的响应头信息，而不获取响应体的内容。通常用于检查资源是      否存在或获取资源的元信息。
           - **示例：** `HEAD /documents/789`，检查文档编号为789的资源是否存在。

        6. **OPTIONS：**
           - **用途：** 请求获取目标资源所支持的通信选项。用于查询服务器支持的HTTP方法。
           - **示例：** `OPTIONS /products`，查询服务器支持的HTTP方法。

        7. **TRACE：**
           - **用途：** 用于追踪路径。发送请求时，服务器会返回该请求所经过的服务器路径。主要用      于调试和测试。
           - **示例：** `TRACE /debug`，追踪请求的路径。

        8. **CONNECT：**
           - **用途：** 用于建立与目标资源的隧道连接，通常用于加密连接，如HTTPS。
           - **示例：** `CONNECT www.example.com:443`，与目标服务器建立加密连接。

    * 请求路径：`/`、`/index.html`、`/jiao.html`、`...`
        * 我们将请求路径称为 `URI`，即统一资源标识符，而 `URL` 是 `URI` 的子集

    * HTTP版本：`HTTP/1.0`、`HTTP/1.1`、`HTTP/2.0`
<br>

* **请求头** 由请求头字段和请求头字段值组成，每个请求头字段都有特定的含义，常见的请求头字段有：
    * `Accept`：指定客户端能够接收的内容类型
    * `Accept-Encoding`：指定客户端能够接收的内容编码方式
    * `Accept-Language`：指定客户端能够接收的语言
    * `Connection`：指定客户端与服务端的连接类型
    * `Host`：指定请求的主机名和端口号
    * `User-Agent`：指定客户端的类型
    * `Referer`：指定请求的来源页面
    * `Cookie`：指定请求的 Cookie
    * `Content-Type`：指定请求体的类型
    * `Content-Length`：指定请求体的长度
    * `Authorization`：指定请求的授权信息
    * `If-Modified-Since`：指定请求的资源的最后修改时间
    * `If-None-Match`：指定请求的资源的 ETag 值

<br>

* **请求体** 具体的数据
    * 通常是在 post 请求中，将表单数据放在请求体中

<br>

* **响应行** 由三部分组成：HTTP版本、状态码、状态码描述

    * HTTP版本：`HTTP/1.0`、`HTTP/1.1`、`HTTP/2.0`
    * 状态码：`200`、`404`、`500`、`...`
    * 状态码描述：`OK`、`Not Found`、`Internal Server Error`、`...`
    * 例如：`HTTP/1.1 200 OK`

<br>

* **响应头** 由响应头字段和响应头字段值组成，每个响应头字段都有特定的含义，常见的响应头字段有：
    * `Content-Type`：指定响应体的类型
    * `Content-Length`：指定响应体的长度
    * `Content-Encoding`：指定响应体的编码方式
    * `Content-Language`：指定响应体的语言
    * `Content-Disposition`：指定响应体的处理方式
    * `Set-Cookie`：指定响应的 Cookie
    * `Location`：指定响应的重定向地址
    * `Last-Modified`：指定响应的资源的最后修改时间
    * `ETag`：指定响应的资源的 ETag 值

<br>

* **响应体** 具体的数据
    * 例如网页的 HTML 代码
    * 例如图片的二进制数据、pdf文件等


<br>

---

## Boost.Asio *


<br>

---

# 2 非阻塞 IO

当 **进程** 发起 **IO请求** 后，即使 **内核** 没有准备好数据，**进程** 也将立即返回，不会等待，同时 **内核** 会返回一个错误码，告诉 **进程** 为什么没有准备好数据

## 非阻塞输入

```cpp
std::cin.sync_with_stdio(false);        // 关闭同步
if(std::cin.rdbuf() -> in_avail() > 0)  // 如果输入缓冲区有数据
    std::getline(std::cin, s);          // 读取数据
```

## c2s

此时，我们可以构建一个简单的 c2s 通信模型：
**多个** 客户端可以与 **一个** 服务端 **收发任意条** 消息

**`server`：**

1. 创建套接字 `socket()`
2. 绑定 ip + port `bind()`
3. 监听 `listen()`
4. 设置套接字为非阻塞 `fcntl()`
    ```cpp
    #include <fcntl.h>      // fcntl()
    ```
    ```cpp
    fcntl(server, F_SETFL, O_NONBLOCK);
    ```
    * `fcntl()`：控制文件描述符属性
    `int fcntl(int fd, int cmd, ... /* arg */ );`
        * `fd`：文件描述符
        * `cmd`：操作命令，对 `fd` 进行操作
            * `F_SETFL`：设置文件描述符状态标志
            * `F_GETFL`：获取文件描述符状态标志
        * `arg`：操作命令的参数，根据 `cmd` 的不同而不同
            * `O_NONBLOCK`：非阻塞
            * `O_ASYNC`：异步
            * `O_SYNC`：同步


5. 循环接受连接请求 `accept()`
6. 循环接收 `recv()` 和发送 `send()` 消息
7. 关闭套接字 `close()`

**`client`：**

1. 创建套接字 `socket()`
2. 连接指定 ip + port `connect()`
3. 设置套接字为非阻塞 `fcntl()`
4. 循环发送 `send()` 和接收 `recv()` 消息
5. 关闭套接字 `close()`

<br>

---

## echo server

echo server，即客户端发送什么，服务端就回复什么
在 c2s 的基础上，初步尝试使用面向对象的思想实现：

* `SockAddr`：套接字地址类
* `Event`：事件类，包含事件处理函数
* `Acceptor`：接收器类

<br>

---

## http server

在 echo server 中，使用 deal 函数处理接收到的消息，如果想处理 http 请求，只需要重写 deal 函数即可：
* 获取 http 请求的请求
* 解析 http 请求的请求
* 构造 http 响应的响应
* 发送 http 响应的响应

<br>

---

## c2c

之前的 c2s 通信模型，是多个客户端与一个服务端收发任意条消息，现在我们尝试构建一个 c2c 通信模型：

* 每个客户端可以与任意个客户端建立连接
* 每个客户端可以与任意个客户端收发任意条消息


<br>

---


# 3 复用 IO

在阻塞 IO 中，如何没有连接请求，`accept()` 函数将一直阻塞，直到有连接请求为止，`recv()` 和 `send()` 函数也是如此，如果没有数据，将一直阻塞，直到有数据为止。

在非阻塞 IO 中，我们采取循环的方式，不断的调用 `accept()`、`recv()`、`send()` 函数，如果没有接收到连接请求或数据，那么函数将立即返回，不会等待，同时内核会返回一个错误码，告诉进程为什么没有准备好数据。

在 IO 复用 中，我们可以使用 `select()`、`poll()`、`epoll()` 函数，将多个文件描述符注册到内核中，当有文件描述符准备好数据时，内核将通知进程，进程再调用 `accept()`、`recv()`、`send()` 函数，这样就不需要循环调用这些函数了。

<br>

---

# 信号驱动 IO


<br>

---

# 异步 IO

前 4 种 IO 模型都是同步 IO，即用户进程发起 IO 请求后，需要等待内核完成 IO 操作后才能继续执行

<br>

---

# errno


<div class="center">

| 错误码 | 别名 | 错误描述 | note | 
| :-: | :-: | :-: | :-: |
| 4 | `EINTR` | 信号中断 | 通常是由于用户按下了 `Ctrl + C` |
| 11 | `EAGAIN` `EWOULDBLOCK`| 操作被阻塞 | 非阻塞下，没有数据可读或写 |


</div>






# Socket


* [TCP / IP 分层模型](#tcp--ip-分层模型) 及 [三握四挥](#tcp-三握四挥)
* [socket TCP 通信模型](#socket-tcp-通信模型) 及 [实例](#socket-tcp-通信简单实例)
* [socket UDP 通信模型](#socket-udp-通信模型) 及 [实例](#socket-udp-通信简单实例)
* 网络IO接口复用：select、poll、[epoll](#epoll)
* 阻塞、[非阻塞](#非阻塞-socket)、[Socket选项](#socket-选项)
* 同步、异步
* HTTP协议






## 



## socket UDP 通信简单实例

* 启动 [服务端](样例/UDP通信样例/服务端.cpp)
    1. 编译 `g++ 服务端.cpp -o 服务端`
    2. 运行 `./服务端` 默认运行在本地 8080 端口
* 启动 [客户端](样例/UDP通信样例/客户端.cpp)
    1. 编译 `g++ 客户端.cpp -o 客户端`
    2. 运行 `./客户端`     
   
可以同时运行多个客户端，服务端允许多台客户端连接；连接之后：

1. 客户端发送消息，服务端接收消息，回复单一消息
2. 服务端发送消息，客户端接收消息，回复单一消息
3. 不断重复，直到客户端断开连接

## Socket 选项

* `int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);`
    * `sockfd`：文件描述符
    * `level`：选项定义的层次
        * `SOL_SOCKET`：通用套接字选项
        * `IPPROTO_IP`：IP选项
        * `IPPROTO_TCP`：TCP选项
        * `IPPROTO_IPV6`：IPv6选项
    * `optname`：选项名称
        * `SO_REUSEADDR`：允许重用本地地址和端口
        * `SO_REUSEPORT`：允许重用本地地址和端口
        * `SO_KEEPALIVE`：开启 TCP Keep-Alive
        * `SO_LINGER`：关闭 socket 时，底层会将发送缓冲区的数据发送给对端，然后等待一段时间，如果还没收到对端的确认信息，就强制关闭 socket
        * `SO_RCVBUF`：设置接收缓冲区大小
        * `SO_SNDBUF`：设置发送缓冲区大小
        * `TCP_NODELAY`：禁用 Nagle 算法
        * `TCP_MAXSEG`：设置 TCP 最大分段大小
        * `TCP_CORK`：开启 TCP_CORK，关闭 Nagle 算法
        * `TCP_QUICKACK`：开启 TCP_QUICKACK，关闭延迟确认
    * `optval`：选项值
    * `optlen`：选项值长度

* `int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen);`
    * `sockfd`：文件描述符
    * `level`：选项定义的层次
    * `optname`：选项名称
    * `optval`：选项值
    * `optlen`：选项值长度


## 非阻塞 Socket

* `int fcntl(int fd, int cmd, ... /* arg */ );`
    * `fd`：文件描述符
    * `cmd`：
        * `F_GETFL`：获取文件描述符状态标志
        * `F_SETFL`：设置文件描述符状态标志
    * `arg`：文件描述符状态标志
        * `O_NONBLOCK`：非阻塞
        * `O_ASYNC`：异步
        * `O_SYNC`：同步


阻塞：调用函数时，如果数据没有准备好，那么函数将一直等待，直到数据准备好为止

非阻塞：调用函数时，如果数据没有准备好，那么函数将立即返回，不会等待数据准备好


* `accept`
    * 阻塞：没有新连接时，一直等待
    * 非阻塞：没有新连接时，立即返回 `EWOULDBLOCK(11)` 或 `EAGAIN`

* `recv`
    * 阻塞：没有数据时，一直等待
    * 非阻塞：没有数据时，立即返回 `EWOULDBLOCK(11)` 或 `EAGAIN`

* `read`
    * 阻塞：没有数据时，一直等待
    * 非阻塞：没有数据时，立即返回 `EWOULDBLOCK(11)` 或 `EAGAIN`


## Epoll

eventpoll，事件轮询，Linux 内核实现IO多路复用（IO multiplexing）的一个实现

直观来说，I/O 复用的作用就是：让程序能够在单进程、单线程的模式下，同时处理 **多个文件描述符** 的 I/O 请求

* `int epoll_create1()` 
    * 创建一个 epoll 文件描述符，事件轮询的实例，返回一个文件描述符，即事件树
    * 底层创建一个 红黑树 和 就绪链表（双向链表）
    * 红黑树 存储所监控的文件描述符的节点数据，就绪链表 存储就绪的文件描述符的节点数据

* `int epoll_ctl(事件树, 操作, 文件描述符, 事件)`
    * 操作：
        * `EPOLL_CTL_ADD`：注册新的事件到事件树
        * `EPOLL_CTL_MOD`：修改已经注册的事件
        * `EPOLL_CTL_DEL`：删除已经注册的事件
    * 事件：
        * `EPOLLIN`：对应的文件描述符可以读 `read`（包括对端SOCKET正常关闭）
        * `EPOLLPRI`：对应的文件描述符有紧急的数据可读（这里应该表示有带外数据到来）
        * `EPOLLOUT`：对应的文件描述符可以写 `recv`
        * `EPOLLERR`：对应的文件描述符发生错误
        * `EPOLLHUP`：对应的文件描述符被挂断
        * `EPOLLET`：将 EPOLL 设为边缘触发(Edge Triggered)模式
        * `EPOLLONESHOT`：只监听一次事件，当监听完这次事件之后，删除

* `int epoll_wait(事件树, 事件数组, 事件数组大小, 超时时间)`
    * 事件数组：`epoll_event` 结构体数组
    * 超时时间：`-1` 阻塞，`0` 立即返回，`>0` 等待指定时间


## Epoll 通信实例

* 启动 [服务端](样例/事件轮询样例/服务端.cpp)
    1. 编译 `g++ 服务端.cpp -o 服务端`
    2. 运行 `./服务端` 默认运行在本地 8080 端口
* 启动 [客户端](样例/事件轮询样例/客户端.cpp)
    1. 编译 `g++ 客户端.cpp -o 客户端`
    2. 运行 `./客户端`     
   
可以同时运行多个客户端，服务端允许多台客户端连接连接之后：
1. 客户端发送消息，服务端接收消息，回复单一消息

## 面向对象



## Channel

`Channel` 是 `Epoll` 的事件处理类，`Epoll` 通过 `Channel` 处理事件


<br>

---

# Boost.Asio

[Boost.Asio](https://www.boost.org/doc/libs/1_83_0/doc/html/boost_asio.html)

