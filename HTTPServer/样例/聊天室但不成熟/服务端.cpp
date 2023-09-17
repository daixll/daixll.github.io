#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <sys/epoll.h>
#include <fcntl.h>

#include <thread>

#include <string.h>
#include <iostream>
#include <string>

void 错误(bool 标志, std::string 错误信息){
    if(!标志) return ;  // 如果没有错误，直接返回
    std::cerr<<错误信息<<errno<<"\n";
    exit(0);
}

bool 警告(bool 标志, std::string 警告信息){
    if(!标志) return 0;  // 如果没有警告，返回 0
    std::cerr<<警告信息<<errno<<"\n";
    return 1;
}

int 套接字(std::string IP地址, int 端口){
    int 😂 = socket(AF_INET, SOCK_STREAM, 0);
    错误(😂 == -1, "socket创建错误");

    sockaddr_in 地址;
    memset(&地址, 0, sizeof 地址);
    地址.sin_family      = AF_INET;
    地址.sin_addr.s_addr = inet_addr(IP地址.c_str());
    地址.sin_port        = htons(端口);
    int 端口复用 = 1;    // 端口复用
    setsockopt(😂, SOL_SOCKET, SO_REUSEADDR, (const void *)&端口复用, sizeof(端口复用));
    错误(
        bind(😂, (sockaddr*)&地址, sizeof 地址) == -1,
        "绑定服务端地址错误"
    );
    fcntl(😂, F_SETFL, O_NONBLOCK); // 设置为非阻塞模式
    return 😂;
}

void 接收数据(int 客户端, int 事件树){
    char 缓冲区[1024];
    while(1){
        memset(缓冲区, '\0', sizeof 缓冲区);
        // 接收数据 recv不断获取数据，客户端主动断开连接
        int 长度 = recv(客户端, 缓冲区, sizeof 缓冲区, 0);
        if(长度 > 0){
            std::cout<<"【"<<客户端<<"】 "<<"数据长度："<<长度<<" 内容："<<缓冲区<<"\n";
        } else if(长度 == -1 && errno == EINTR){    // 信号中断返回，没有任何数据可用，正常，继续
            continue;
        } else if(长度 == -1 && ((errno == EAGAIN) || (errno == EWOULDBLOCK))){  
            //std::cout<<"完成一次读取\n";            // 非阻塞模式下完成一次读取，正常，继续
            //std::cout<<"-------------------------------------------------\n";
            break;
        } else if(长度 == 0){
            std::cout<<"断开连接\n";
            close(客户端);
            break;
        }
    }
    return ;
}

void 发送数据(int 客户端){
    char 缓冲区[1024];
    while(1){
        memset(缓冲区, '\0', sizeof 缓冲区);
        std::cin>>缓冲区;
        // 发送数据 send不断发送数据，客户端主动断开连接
        send(缓冲区[0]-'0', 缓冲区, strlen(缓冲区), 0);
    }
}

int main(){
    int 服务端 = 套接字("0.0.0.0", 8080);
    错误( listen(服务端, 5) == -1, "监听错误" );

    int 事件树 = epoll_create1(0);
    错误( 事件树 == -1, "epoll创建错误" );

    epoll_event 事件, 事件列表[1024];

    memset(&事件, 0, sizeof 事件);
    事件.data.fd = 服务端;  // 监听服务端
    事件.events = EPOLLIN | EPOLLET;  // 监听可读事件
    错误(
        epoll_ctl(事件树, EPOLL_CTL_ADD, 服务端, &事件) == -1,
        "服务端注册事件错误"
    );

    std::thread( 发送数据, 0).detach(); // 一个线程负责所有的发送

    while(1){
        int 事件数量 = epoll_wait(事件树, 事件列表, 1024, -1);
        错误(事件数量 == -1, "事件树等待错误");

        //std::cout<<"事件数量："<<事件数量<<"\n";
        for(int i=0; i<事件数量; i++){
            if(事件列表[i].data.fd == 服务端){
                sockaddr_in 客户端地址;
                memset(&客户端地址, ' ', sizeof 客户端地址);
                socklen_t 客户端地址大小 = sizeof 客户端地址;
                int 客户端 = accept(服务端, (sockaddr*)&客户端地址, &客户端地址大小);
                if( 警告( 客户端==-1, "接受客户端连接错误") ) continue;
                fcntl(客户端, F_SETFL, O_NONBLOCK); // 设置为非阻塞模式
                std::cout<<"【"<<客户端<<"】 "<<"新的连接 "<<"ip："<<inet_ntoa(客户端地址.sin_addr)<<"\n";
                std::cout<<"-------------------------------------------------\n";

                memset(&事件, 0, sizeof 事件);
                事件.data.fd = 客户端;  // 监听客户端
                事件.events = EPOLLIN | EPOLLOUT | EPOLLET;  // 可读可写事件
                错误(
                    epoll_ctl(事件树, EPOLL_CTL_ADD, 客户端, &事件) == -1,
                    "客户端注册事件错误"
                );
            }
            else if(事件列表[i].events & EPOLLIN){
                // 创建一个线程来读
                std::thread( 接收数据, int(事件列表[i].data.fd), 事件树).detach();
            }
            /*
            else if(事件列表[i].events & EPOLLOUT){
                // 创建一个线程来写
                std::thread( 发送数据, int(事件列表[i].data.fd), 事件树).detach();
            }
            (*/
        }
    }

    return 0;
}