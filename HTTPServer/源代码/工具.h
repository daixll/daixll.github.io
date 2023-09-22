#pragma once   

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"

void 错误(bool 标志, std::string 错误信息);

bool 警告(bool 标志, std::string 警告信息);

long long 读取文件(const std::string 文件名, std::string &内容);