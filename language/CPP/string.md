---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

在 c++ 中，字符串常常会有这几个头文件：

```cpp
#include <string>
#include <string.h>
#include <cstring>
```

对于 `string.h` 和 `cstring`，本质上都是 C 语言中的头文件。`cstring` 是 C++ 中对 `string.h` 的封装，所以在 C++ 中，`string.h` 和 `cstring` 是等价的。

# cstring

`cstring` 操作的是 C 风格的字符串，也就是以 `\0` 结尾的字符串。

C 风格的字符串有三种写法：

```cpp
int main(){
    char str1[6] = "hello";
    char str2[] = "hello";
    char *str3 = "hello";
}
```

* str1 
    此写法会在 str1[5] 的位置插入 `\0`。
    数据保存在栈中。

* str2
    编译器会自动将 str2 的长度设置为 6，且在 str2[5] 的位置插入 `\0`。
    数据保存在栈中。

* str3
    此写法会在常量区（常量区不可更改）创建一个字符串，然后将 str3 指向该字符串的首地址。
    数据保存在常量区，**str3 本身** 保存在栈中。

显然，str1 和 str2 是等价的。我们都知道，数组名其实是一个指针，
所以 str1 和 str2 都是指向栈中的一个字符串。而 str3 则是指向常量区的一个字符串。

```cpp
// 输出地址
for(int i = 0; i < 6; i++) 
    printf("%x %x\n", str1 + i, &str1[i]);
// 输出内容
for(int i = 0; i < 6; i++)
    printf("%c %c\n", *(str1 + i), str1[i]);
```

```
19d5f2ec 19d5f2ec
19d5f2ed 19d5f2ed
19d5f2ee 19d5f2ee
19d5f2ef 19d5f2ef
19d5f2f0 19d5f2f0
19d5f2f1 19d5f2f1
h h
e e
l l
l l
o o
NUL NUL
```

如果把 str3 指向 str1 `str3 = str1`，那么 str3 就指向了栈中的一个字符串。
紧接着，将上面的代码复制，换成 `str3`，输出结果一毛一样。

**这就是 C 风格的字符串。本质上都是指针，指向一个连续的内存空间。**

[菜鸟教程](https://www.runoob.com/cprogramming/c-standard-library-string-h.html) 详细介绍了 `cstring` 的用法，下面是一些常用的函数：



* strlen - 获取字符串长度 `size_t strlen(const char *s);`

```cpp
unsigned int len = strlen(str);
```

`strlen` 计算从 str 开始，到 `\0` 结束的长度。
所以，如果 str 中间有 `\0`，那么 `strlen` 只会返回到 `\0` 的长度。

容易混淆的是，`sizeof` 的功能是计算一个数据类型的大小，这个类型可以是数组、函数、指针、对象等，单位为字节。

* memset - 设置字符串内容 `void *memset(void *s, int c, size_t n);`

```cpp
memset(str, 'a', sizeof str);
```

`memset` 按字节对 `str` 进行初始化，`sizeof str` 为 `str` 的大小，单位为字节。
值得一提的是，`memset` 的第二个参数是 `int` 类型，但是实际上只会取 `char` 的低 8 位。 

在算法竞赛中，我们常常会使用 `memset(g, 0x3f, sizeof g)` 来初始化一个数组。
实际上，`0x3f` 的二进制为 `0011 1111`。`memset` 会将 `g` 的每个字节都设置为 `0011 1111`。
假设 `g` 的类型为 `int`，一个 `int`，4 个字节，那么 `g` 中每个元素

* 二进制为 `0011 1111 0011 1111 0011 1111 0011 1111`。
* 十进制为 `1061109567`。



```cpp
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
int strcmp(const char *s1, const char *s2);
char *strchr(const char *s, int c);
char *strstr(const char *haystack, const char *needle);
void *memcpy(void *dest, const void *src, size_t n);
```

# string

`string` 操作的是 C++ 中的字符串，也就是 `std::string`。

`string` 是一个类，所以它有构造函数、析构函数、拷贝构造函数、赋值运算符等等。



* 构造函数

```cpp
string s1;          // 默认构造函数，s1 为空字符串
string s2(s1);      // 拷贝构造函数，s2 为 s1 的拷贝
string s3("hello"); // 用字符串初始化 s3
string s4(10, 'a'); // 用 10 个 'a' 初始化 s4
```

* 赋值运算符

```cpp
string s1, s2;
s1 = s2;            // s1 为 s2 的拷贝
string s3 = "hello";
s1 = s3;            // s1 为 s3 的拷贝
```

* 比较运算符

先按字典序比较，如果相等，再比较长度。


* 插入元素

```cpp
string s = "hello";
s.insert(1, "6");   
// 将 6 插入到 s 的第二个字符的位置
// 输出 h6ello
```

* 删除元素

```cpp
string s = "hello";
s.erase(0, 2);      
// 将 s 下标为 0 的字符开始的 2 个字符删除
// 输出 llo
```

* 替换元素

```cpp
string s = "hello";
s.replace(0, 1, "6");   
// 将 s 的第一个字符替换为 'H'
// 输出 6ello
```

* 查找元素

```cpp
string s = "hello";
int idx = s.find("ll"); 
// 查找 s 中第一个 "ll" 的位置，返回目标字符串的第一个字符的下标
// 输出 2
```

* 获取子串

```cpp
string s = "hello";
s.substr(2, 2);     
// 获取 s 中下标为 2 的字符开始的 2 个字符
// 输出 ll
```

* 获取长度

```cpp
string s = "hello";
s.size();           
// 获取 s 的长度
// 输出 5
```

* 转换为 C 风格字符串

```cpp
string s = "hello";
s.c_str();          
// 将 s 转换为 C 风格字符串
```

* 转换为整数

```cpp
string s = "123";
stoi(s);            // 将 s 转换为整数
stoll(s);           // 将 s 转换为长整数
```

* 转换为双精度浮点数

```cpp
string s = "123.456";
stod(s);            // 将 s 转换为双精度浮点数
```
