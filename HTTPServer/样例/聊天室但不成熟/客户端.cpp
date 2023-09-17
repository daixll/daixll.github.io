#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <sys/epoll.h>
#include <fcntl.h>

#include <thread>
#include <vector>

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

void 接收数据(int 客户端){
    char 缓冲区[1024];
    while(1){
        memset(缓冲区, '\0', sizeof 缓冲区);
        // 接收数据 recv不断获取数据，客户端主动断开连接
        int 长度 = recv(客户端, 缓冲区, sizeof 缓冲区, 0);
        std::cout<<"【"<<客户端<<"】 ";
        if(长度 > 0){
            std::cout<<"数据长度："<<长度<<" 内容："<<缓冲区<<"\n";
        } else if(长度 == -1 && errno == EINTR){    // 信号中断返回，没有任何数据可用，正常，继续
            continue;
        } else if(长度 == -1 && ((errno == EAGAIN) || (errno == EWOULDBLOCK))){  
            std::cout<<"完成一次读取\n";            // 非阻塞模式下完成一次读取，正常，继续
            std::cout<<"-------------------------------------------------\n";
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
        send(客户端, 缓冲区, strlen(缓冲区), 0);
    }
}

int main(){
    int 客户端 = socket(AF_INET, SOCK_STREAM, 0);
    错误(客户端 == -1, "socket创建错误");
    
    sockaddr_in 服务端地址;
    memset(&服务端地址, 0, sizeof 服务端地址);
    // 服务端地址为域名
    服务端地址.sin_family      = AF_INET;
    服务端地址.sin_addr.s_addr = inet_addr("27.14.239.49");
    服务端地址.sin_port        = htons(2024);
    错误(
        connect(客户端, (sockaddr*)&服务端地址, sizeof 服务端地址) == -1,
        "连接服务端错误"
    );
    //fcntl(客户端, F_SETFL, O_NONBLOCK); // 设置为非阻塞模式
    
    std::vector<std::thread> 任务;
    任务.push_back(std::thread(发送数据, 客户端));
    任务.push_back(std::thread(接收数据, 客户端));

    for(auto &i : 任务){
        i.join();
    }

    return 0;
}
