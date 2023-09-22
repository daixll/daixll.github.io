#include "工具.h"

void 错误(bool 标志, std::string 错误信息){
    if(!标志) return ;  // 如果没有错误，直接返回
    std::cerr<<RED<<错误信息<<" "<<errno<<RESET<<"\n";
    exit(0);
}

bool 警告(bool 标志, std::string 警告信息){
    if(!标志) return 0;  // 如果没有警告，返回 0
    std::cerr<<YELLOW<<警告信息<<" "<<errno<<RESET<<"\n";
    return 1;
}

long long 读取文件(const std::string 文件名, std::string &内容){
    std::ifstream 文件(文件名);
    if(警告(!文件.is_open(), "打开文件错误")) return 0;
    std::stringstream 缓冲区;
    缓冲区 << 文件.rdbuf();
    内容 = 缓冲区.str();
    return 内容.size();
}