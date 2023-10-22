---
toc:
    depth_to: 3
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 推荐阅读

[现代 C++ 教程](https://changkun.de/modern-cpp/)

[微软 VS中的C++](https://learn.microsoft.com/zh-cn/cpp/cpp/welcome-back-to-cpp-modern-cpp?view=msvc-170)


# class


---

# Memory Areas

## Stack

## Heap

## Data Segment

## Code Segment


---

# namespace

**namespace：命名空间**

有了命名空间，我们就可以将不同的函数、类、变量等放在不同的命名空间中，从而避免命名冲突。

## 命名空间的使用

**在函数中使用**

`jiao` 命名空间中有一个 `print` 函数，`JIAO` 命名空间中也有一个 `print` 函数。
前者输出 666，后者输出 777。

```cpp
#include <iostream>

namespace jiao {
void print(){
    std::cout<<"666";
}
}

namespace JIAO {
void print(){
    std::cout<<"777";
}
}

int main(){
    jiao::print();  // 输出 666
    JIAO::print();  // 输出 777
    return 0;
}
```

<br>

**在类中使用**

`jiao` 命名空间中有一个 `A` 类，`JIAO` 命名空间中也有一个 `A` 类。
前者实例化后输出 666，后者实例化后输出 777。

```cpp
#include <iostream>

namespace jiao {
class A{
public:
    void print(){
        std::cout<<"666";
    }
};
}

namespace JIAO {
class A{
public:
    void print(){
        std::cout<<"777";
    }
};
}

int main(){
    jiao::A a1;
    JIAO::A a2;
    a1.print(); // 输出 666
    a2.print(); // 输出 777
    return 0;
}
```

<br>

## 命名空间的嵌套

命名空间允许嵌套。

```cpp
#include <iostream>

namespace JIAO{
void p(){
    std::cout<<"555";
}

namespace jiao1{
    void p(){
        std::cout<<"666";
    }
}

namespace jiao2{
    void p(){
        std::cout<<"777";
    }
}
}

int main(){
    JIAO::p();
    JIAO::jiao1::p();
    JIAO::jiao2::p();
    return 0;
}
```

<br>

## 命名空间和类的区别

对于类而言：`A` 类中可以有 `p` 函数，`B` 类中可以有 `p` 函数；
对于命名空间而言，`A` 命名空间中可以有 `p` 函数，`B` 命名空间中也可以有 `p` 函数。
这俩值得比较一下：

| 维度 | 命名空间 | 类 |
|:-:|:-:|:-:|
| 实例化 | 不需要实例化，直接访问命名空间中的成员 | 需要实例化对象，通过对象访问类的成员 |
| 封装性 | 不具备封装性，命名空间中的成员默认是公有的 | 具有封装性，类的成员可以是公有的、私有的、或受保护的 | 
| 内存管理 | 不需要内存管理，命名空间中的成员都是静态的 | 需要内存管理，类的成员可以是静态的、也可以是动态的 |
| 适用场景 | 用于组织代码、避免命名冲突 | 用于封装数据和行为、实现面向对象编程 |

> Q：为什么命名空间中的成员都是静态的？

> A：因为命名空间中的成员都是全局的，全局的成员都是静态的。
> 因此，即使类定义在命名空间中，但实际的内存分配和释放是与类的实例化相关的，而不是与命名空间本身相关。

<br>

## 关于 cstdio 和 stdio.h
 
`cstdio` 是 C++ 标准库的头文件，其中定义了 C 语言标准库的函数，这些函数被放置在 std 命名空间中。因此，在 C++ 中使用 `cstdio` 时，需要加上 `std::` 前缀，例如 `std::printf`、`std::fopen`等。

`stdio.h` 是 C 语言标准库的头文件，其中定义了 C 语言标准库的函数，这些函数被放置在全局命名空间中。因此，在 C 语言中使用 `stdio.h` 时，不需要加上 `std::` 前缀，例如 `printf`、`fopen`等。

**但是**，为了保持语言的向后兼容性，这些标准库函数也可以直接在全局作用域（即不加 `std::` 前缀）中使用，而不会产生编译错误。这是一个历史遗留的特性，但不是推荐的做法，更推荐使用 `std::printf` 等带有 `std::` 前缀的形式，以确保代码的清晰性和可读性，避免潜在的命名冲突问题。

<br>

在这段代码中，我们定义了一个命名空间 `jiao`，其中有一个 `printf` 函数，输出 `666`。
在 `main` 函数中，我们调用了 `jiao` 命名空间中的 `printf` 函数，输出 `666`，
调用标准库中的 `std::printf` 函数，输出 `777`。

```cpp
#include <iostream>
#include <cstdio>

namespace jiao{
    void printf(){
        std::cout<<"666";
    };
}

int main(){
    jiao::printf();     // 666
    std::printf("777"); // 777
    return 0;
}
```

<br>

在这段代码中，我们没有引入 `std` 命名空间，所以 `std::printf` 会报错。

```cpp
//#include <iostream>   // iostream 会引入 std::printf
#include <stdio.h>      // 非cstdio，没有引入 std 的概念

namespace jiao{
    void printf(){
        //std::cout<<"666";
    };
}

int main(){
    jiao::printf();
    printf("777");
    std::printf("888"); // 命名空间 "std" 中没有 "printf"
    return 0;
}
```

---

# string 

字符串常常会有这几个头文件：

```cpp
#include <string>
#include <string.h>
#include <cstring>
```

对于 `string.h` 和 `cstring`，本质上都是 C 语言中的头文件。
`cstring` 相较于 `string.h`，多了一个命名空间。
因此，我们只讨论 `string` 和 `cstring`。

## string

`string` 操作的是 C++ 中的字符串，也就是 `std::string`。

**值得一提** 的是，我们往往不需要引入 `string` 头文件，因为 `string` 头文件已经被 `iostream` 引入了。

`string` 是一个类，所以它有构造函数、析构函数、拷贝构造函数、赋值运算符等等。

<br>

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

```cpp
string a = "aa";
string b = "ab";
a < b;  // true 
```

```cpp
string a = "bb";
string b = "bba";
a < b;  // true 
```

* 插入元素

```cpp
string s = "hello";
s.insert(1, "6");   
// 将 6 插入到 s 下标为 1 的位置
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
s.replace(0, 2, "6");   
// 将 s 下标为 0 的字符开始的 2 个字符替换为 6
// 输出 6llo
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

<br>

## cstring

`cstring` 操作的是 C 风格的字符串，也就是以 `\0` 结尾的字符数组。

C 风格的字符串有三种写法：

```cpp
int main(){
    char str1[6] = "hello";
    char str2[] = "hello";
    char *str3 = "hello";
}
```

* `str1` 
    此写法会在 `str1[5]` 的位置插入 `\0`。
    数据保存在栈中。

* `str2`
    编译器会自动将 `str2` 的长度设置为 6，且在 `str2[5]` 的位置插入 `\0`。
    数据保存在栈中。

* `str3`
    此写法会在常量区（常量区不可更改）创建一个字符串，然后将 `str3` 指向该字符串的首地址。
    数据保存在常量区，**`str3` 本身** 保存在栈中。

显然，`str1` 和 `str2` 是等价的。我们都知道，数组名其实是一个指针，
所以 `str1` 和 `str2` 都是指向栈中的一个字符串。而 `str3` 则是指向常量区的一个字符串。

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

如果把 `str3` 指向 `str1`，即 `str3 = str1`，那么 `str3` 就指向了栈中的一个字符串。
紧接着，将上面的代码复制，换成 `str3`，输出结果一毛一样。

**这就是 C 风格的字符串。本质上都是指针，指向一个连续的内存空间。**

[菜鸟教程](https://www.runoob.com/cprogramming/c-standard-library-string-h.html) 详细介绍了 `cstring` 的用法，下面是一些常用的函数：

<br>

* `strlen` 获取字符串长度 `size_t strlen(const char *s);`

```cpp
unsigned int len = strlen(str);
```

`strlen` 计算从 `str` 开始，到 `\0` 结束的长度。
所以，如果 `str` 中间有 `\0`，那么 `strlen` 只会返回到 `\0` 的长度。

容易混淆的是，`sizeof` 的功能是计算一个数据类型的大小，这个类型可以是数组、函数、指针、对象等，单位为字节。

* `memset` 设置字符串内容 `void *memset(void *s, int c, size_t n);`

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


---

# regex

[正则表达式](/Linux/Regex/index.html) 的本质，就是某种 **字符组合**。 

## 定义正则表达式

## 判断串

## 查找匹配子串

## 取出匹配子串

## 替换匹配子串

**创建正则表达式**

```cpp
std::regex r("^([0-9]{1,3}\\.){3}[0-9]{1,3}$");
```

此正则表达式用于匹配 IPv4 地址。

**判断字符串是否匹配正则表达式**

```cpp
std::regex_match("127.0.0.1", r);   // true
```

**查找字符串中匹配正则表达式的子串**

```cpp
#include <iostream>
#include <regex>

int main() {
    std::regex r("\\b([0-9]{1,3}\\.){3}[0-9]{1,3}\\b");
    // 匹配IPv4地址的正则表达式
    // \b 是单词边界，确保匹配的是完整的IPv4地址
    std::smatch m;  // 存放匹配结果
    std::string s = "127.0.0.1 192.168.31.1";

    while (std::regex_search(s, m, r)) {
        std::cout << "Found match: " << m[0] << std::endl;
        s = m.suffix(); // 获取当前匹配子串之后的子串
    }

    return 0;
}
```

# template

template：变参数模板。

## 在函数中使用 template

可以让函数接受任意类型的参数，而不是固定的类型。


```cpp
template<typename T>
inline void Tswap(T *a, T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}
```

## 在类中使用 template

可以让类接受任意类型的参数，而不是固定的类型。

```cpp
template<typename T>
class queue {
public:
    void push(T x){
        q[tail++] = x;
    };
    void pop(){
        head++;
    };
    T front(){
        return q[head];
    };
    int size(){
        return this->tail-this->head;
    }
private:
    T q[100];
    int head = 0;
    int tail = 0;
};
```

## variant

### variant

### union

联合体是一种特殊的数据类型，允许在相同的内存位置存储不同的数据类型。

```cpp
union MyUnion{
    int a;
    double b;
    char c;
};
```


# function

function：用来包装任何可以被调用的对象，包括函数指针、函数对象、Lambda 表达式、成员函数指针等，从而提供了一种统一的方式来处理各种可调用对象。

```cpp
#include <functional>
std::function<return_type(parameter_types)> function_name;
```

* return_type：返回值类型。
* parameter_types：参数类型。
* function_name：函数名。

**使用成员函数指针**

```cpp
#include <iostream>
#include <functional>

class MyClass {
public:
    int multiply(int a, int b) {
        return a * b;
    }
};

int main() {
    MyClass obj;
    std::function<int(MyClass&, int, int)> func = &MyClass::multiply;
    std::cout << func(obj, 3, 4) << std::endl;  // 输出 12
    
    return 0;
}
```

**使用函数指针**

```cpp
#include <iostream>
#include <functional>

int add(int a, int b) {
    return a + b;
}

int main() {
    std::function<int(int, int)> func = add;
    std::cout << func(3, 4) << std::endl;  // 输出 7
    
    return 0;
}
```


# lambda

lambda：匿名函数 / 闭包。

允许在需要函数对象（比如传递给算法、STL 容器等）的地方，以一种更为简洁的方式定义匿名函数。

```cpp
[capture](parameters) -> return_type { body_of_lambda }
```

* capture：捕获列表，捕获外部变量。
* parameters：参数列表。
* return_type：返回值类型。
* body_of_lambda：函数体。

```cpp
#include <iostream>

int main() {
    int x=1;
    int y=2;
     
    // 使用Lambda表达式直接定义并调用
    // Lambda捕获x, y变量，并传递参数x+y, y*y
    int result = 
        [x, y](int a, int b) -> int {
            return x + y + a + b;
        }(x+y, y*y); 
    
    std::cout << "Result: " << result << std::endl; // 输出 10
    
    return 0;
}
```

```cpp
#include <iostream>
#include <functional>

int main() {
    int x=1;
    int y=2;
    
    std::function<int(int, int)> f = [x, y](int a, int b) -> int{
        return x + y + a + b;
    };

    std::cout << f(x*x, y+y) << std::endl;

    return 0;
}
```

# 智能指针

为了解决内存泄漏、野（wild）指针、悬空（dangling）指针的问题，引入了智能指针。

**内存泄漏**

导致内存占用过多，程序崩溃。
* 程序运行时，申请的内存没有被释放。无法再次使用该内存。
* 丢失了指向该内存的指针。无法访问、释放该内存。

**野指针**

当一个指针未被显式初始化，它的值就是未知的，可能是一个随机的内存地址，也可能是特定编译环境下的默认值（通常是0或者nullptr）

**悬空指针**

指向的内存已经被释放，但是指针本身没有被释放。

* 释放内存后，指针没有被置为 nullptr。
```cpp
int *ptr = new int; // 申请内存
delete ptr;         // 释放内存
// ptr 已经悬空
ptr = nullptr;      // 将 ptr 置为 nullptr, ptr 成空指针
```

* 在函数中返回局部变量的指针。

```cpp
int *func(){
    int a = 6;      // 局部变量
    return &a;      // 返回局部变量的指针
}
int *ptr = func();  // ptr 指向的内存已经被释放
// ptr 已经悬空
```

* 在函数中返回指向堆内存的指针，但是没有释放堆内存。

```cpp
int *func(){
    int *ptr = new int; // 申请内存
    return ptr;         // 返回指向堆内存的指针
}
int *ptr = func();      // ptr 指向的内存没有被释放
delete ptr;             // 释放内存
// ptr 已经悬空
ptr = nullptr;          // 将 ptr 置为 nullptr, ptr 成空指针
```

## unique_ptr

## shared_ptr

## weak_ptr



# 移动语义和右值引用

# 范围 for 循环

# 异常处理

# 类型推导



---

# STL

## 序列式容器

所谓序列式容器，其中的元素 **可序**，但未必 **有序**。

### list

链表

#### 创建

```cpp
list<int> l1;       // 空链表
list<int> l2(10);   // 10个元素，每个元素都是0
list<int> l3(10, 6);// 10个元素，每个元素都是6
list<int> l4(l3);   // 拷贝构造函数]
list<int> l5({1, 2, 3, 4, 5}); // 初始化列表
```

#### 增加

```cpp
l1.push_back(6);            // 尾部插入
l1.push_front(6);           // 头部插入
l1.insert(l1.begin(), 6);   // 插在 l1.begin() 之前，即头部插入

l1.emplace_back(6);         // 尾部插入
l1.emplace_front(6);        // 头部插入
l1.emplace(l1.end(), 6);    // 插在 l1.end() 之前，即尾部插入
```

#### 删除

```cpp
l1.clear();                 // 清空链表
l1.pop_back();              // 尾部删除
l1.pop_front();             // 头部删除
l1.erase(l1.begin());       // 删除 l1.begin() 位置的元素
l1.erase(l1.begin(), l1.end()); // 删除 [l1.begin(), l1.end()) 之间的元素

l1.remove(666);             // 删除所有值为 6 的元素
l1.unique();                // 删除所有相邻重复的元素：6 6 7 7 6 6 -> 6 7 6
```

#### 修改

```cpp
l1.assign(10, 6);            // 链表大小改为10，所有元素都是6
l1.assign(l2.begin(), l2.end()); // 拷贝 l2 的所有元素
l1.assign({1, 2, 3, 4, 5});  // 拷贝初始化列表

l1.resize(10);              // 链表大小改为10，多余的元素被删除，不足的元素被补 0
l1.resize(10, 6);           // 链表大小改为10，多余的元素被删除，不足的元素被补 6

l1.reverse();               // 反转链表
```

#### 查找

```cpp
// 使用迭代器
list<int>::iterator it = l.begin();
while(it != l.end()){
    cout<<*it<<" ";
    it++;
}
// 使用 for 循环
for(auto i: l) cout<<i<<" ";

l1.empty();                 // 判断链表是否为空
l1.size();                  // 返回链表大小
l1.max_size();              // 返回链表最大容量

l1.front();                 // 返回头部元素
l1.back();                  // 返回尾部元素
```

#### 其他

```cpp
l1.sort();                  // 排序
l1.sort(greater<int>());    // 降序排序
```


---
### vector

动态数组

#### 创建

```cpp
vector<int> v1;             // 空数组
vector<int> v2(10);         // 10个元素，每个元素都是0
vector<int> v3(10, 1);      // 10个元素，每个元素都是1
vector<int> v4(v3);         // 拷贝构造函数
vector<int> v5({1, 2, 3, 4, 5}); // 初始化列表
```

#### 增加

```cpp
v1.push_back(6);            // 尾部插入
v1.emplace_back(6);         // 尾部插入

v1.insert(v1.begin(), 6);                   // 插在 v1.begin() 之前，即头部插入
v1.insert(v1.begin(), 10, 6);               // 插在 v1.begin() 之前，即头部插入10个6
v1.insert(v1.begin(), v2.begin(), v2.end());// 插入 v2 的所有元素
v1.insert(v1.begin(), {1, 2, 3, 4, 5});     // 插入初始化列表

v1.emplace(v1.end(), 6);                    // 插在 v1.end() 之前，即尾部插入
v1.emplace(v1.end(), 10, 6);                // 插在 v1.end() 之前，即尾部插入10个6
v1.emplace(v1.end(), v2.begin(), v2.end()); // 插入 v2 的所有元素
v1.emplace(v1.end(), {1, 2, 3, 4, 5});      // 插入初始化列表

v1.reserve(10);             // 预留 10 个元素的空间
```

#### 删除

```cpp
v1.clear();                 // 清空数组

v1.pop_back();              // 尾部删除
v1.erase(v1.begin());       // 删除 v1.begin() 位置的元素
v1.erase(v1.begin(), v1.end()); // 删除 [v1.begin(), v1.end()) 之间的元素
```

#### 修改

```cpp
v1.assign(10, 6);            // 数组大小改为10，所有元素都是6
v1.assign(v2.begin(), v2.end()); // 拷贝 v2 的所有元素
v1.assign({1, 2, 3, 4, 5});  // 拷贝初始化列表

v1.resize(10);              // 数组大小改为10，多余的元素被删除，不足的元素被补 0
v1.resize(10, 6);           // 数组大小改为10，多余的元素被删除，不足的元素被补 6
```

#### 查找

```cpp
// 通过迭代器遍历
auto it = v.begin();
while(it != v.end()){
    cout<<*it<<" ";
    it++;
}
// 通过 for 循环遍历
for(auto i: v) cout<<i<<" ";

v1.empty();                 // 判断数组是否为空
v1.size();                  // 返回数组大小
v1.max_size();              // 返回数组最大容量

v1.front();                 // 返回头部元素
v1.back();                  // 返回尾部元素

v1[0];                      // 返回下标为 0 的元素
v1.at(0);                   // 返回下标为 0 的元素 (越界会抛出异常)

v1.data();                  // 返回第一个元素的指针
```

#### 其他

```cpp
v1.capacity();              // 返回数组容量
v1.shrink_to_fit();         // 释放多余的空间
```

---
### stack

栈

#### 创建

```cpp
stack<int> s1;              // 空栈
stack<int> s2(s1);          // 拷贝构造函数
stack<int> s3({1,2,3});     // 初始化列表，1为栈底，3为栈顶
```

#### 增加

```cpp
s1.push(6);                 // 入栈
```

#### 删除

```cpp
s1.pop();                   // 出栈
```

#### 修改

只能通过入栈和出栈来修改栈。

#### 查找

```cpp
// 遍历栈 会清空栈
while(!s1.empty()){
    cout<<s1.top()<<" ";
    s1.pop();
}

s1.empty();                 // 判断栈是否为空
s1.size();                  // 返回栈大小
s1.top();                   // 返回栈顶元素
```

---
### queue

队列

#### 创建

```cpp
queue<int> q1;              // 空队列
queue<int> q2(q1);          // 拷贝构造函数
queue<int> q3({1,2,3});     // 初始化列表，1为队头，3为队尾
```

#### 增加

```cpp
q1.push(6);                 // 入队
```

#### 删除

```cpp
q1.pop();                   // 出队
```

#### 修改

只能通过入队和出队来修改队列。

#### 查找

```cpp
// 遍历队列 会清空队列
while(!q1.empty()){
    cout<<q1.front()<<" ";
    q1.pop();
}

q1.empty();                 // 判断队列是否为空
q1.size();                  // 返回队列大小
q1.front();                 // 返回队头元素
q1.back();                  // 返回队尾元素
```

---
### deque

双端队列

```cpp
#include <queue>   // deque 包含在 queue 中
```

#### 创建

```cpp
deque<int> d1;              // 空双端队列
deque<int> d2(10);          // 10个元素，每个元素都是0
deque<int> d3(10, 1);       // 10个元素，每个元素都是1
deque<int> d4(d3);          // 拷贝构造函数
deque<int> d5({1, 2, 3, 4, 5}); // 初始化列表 1为队头，5为队尾
```

#### 增加

```cpp
d1.push_back(6);            // 尾部入队
d1.push_front(6);           // 头部入队
```

#### 删除

```cpp
d1.pop_back();              // 尾部出队
d1.pop_front();             // 头部出队
```

#### 修改

当有修改需求时，建议使用 [vector](#vector-动态数组) 代替。

#### 查找

```cpp
// 从队头开始 遍历双端队列 会清空双端队列
while(!d1.empty()){
    cout<<d1.front()<<" ";
    d1.pop_front();
}

// 从队尾开始 遍历双端队列 会清空双端队列
while(!d1.empty()){
    cout<<d1.back()<<" ";
    d1.pop_back();
}

d1.empty();                 // 判断双端队列是否为空
d1.size();                  // 返回双端队列大小
d1.front();                 // 返回队头元素
d1.back();                  // 返回队尾元素
```

---
### priority_queue

优先队列 (堆)

```cpp
#include <queue>   // priority_queue 包含在 queue 中
```

#### 创建

```cpp
priority_queue<int> p1;     // 空优先队列，默认大顶堆
priority_queue<int, vector<int>, greater<int>> a;   // 小顶堆
```

#### 增加

```cpp
p1.push(6);                 // 入队
```

#### 删除

```cpp
p1.pop();                   // 出队
```

#### 修改

改不了一点。

#### 查找

```cpp
// 遍历优先队列 会清空优先队列
// 如果是大顶堆，遍历出来的是降序序列
while(!p1.empty()){ 
    cout<<p1.top()<<" ";
    p1.pop();
}

p1.empty();                 // 判断优先队列是否为空
p1.size();                  // 返回优先队列大小
p1.top();                   // 返回队头元素
```

## 关联式容器

所谓关联式容器，就是将数据元素组织成键值对的容器。

* 元素按照一定的排序规则组织的，而不是像顺序容器那样按照元素的插入顺序组织的。
* 关联容器的元素类型是pair类型，pair类型的第一个元素是键值，第二个元素是实值。

### 树

#### 二叉搜索树 BST

#### 平衡二叉树 AVLT

#### 平衡二叉搜索树 BBST

#### 红黑树 RBT

### set

集合

set 的元素是唯一的，不能重复。

set 的底层实现是红黑树，所以 set 的元素是有序的。

```cpp
#include <set>
```

#### 创建

```cpp
set<int> s1;                // 元素类型是 int
set<pair<string, int>> s2;  // 元素类型是 pair 类型
```

#### 增加

```cpp
s.insert(6);                // 插入元素 6
s2.insert({"hello", 6});    // 插入元素 {"hello", 6}
```

#### 删除

```cpp
s.clear();                      // 清空所有元素
s.erase(6);                     // 删除元素 6
s2.erase({"hello", 6});         // 删除元素 {"hello", 6}
s.erase(s.begin());             // 删除第一个元素
s.erase(s.begin(), s.end());    // 删除所有元素
```

#### 修改

改不了。

#### 查找

```cpp
s.find(6);                      // 查找元素 6 返回迭代器
s.count(6);                     // 查找元素 6 的个数
s.lower_bound(6);               // 查找第一个大于等于 6 的元素 返回迭代器
s.upper_bound(6);               // 查找第一个大于 6 的元素 返回迭代器

auto it = s.equal_range(6);     // 查找第一个大于等于 6 和 第一个大于 6 的元素 返回迭代器
cout<<(*it.first)<<" "<<(*it.second);

// 遍历
for(auto it = s.begin(); it != s.end(); it++) cout<<(*it)<<" ";
for(auto i: s) cout<<i<<" ";
```

### unordered_set

无序集合

unordered_set 的元素是唯一的，不能重复。

unordered_set 的底层实现是哈希表，所以 unordered_set 的元素是无序的。

```cpp
#include <unordered_set>
```

#### 创建

```cpp
unordered_set<int> s1;                // 元素类型是 int
unordered_set<pair<string, int>> s2;  // 元素类型是 pair 类型
```

#### 增加

```cpp
s.insert(6);                // 插入元素 6
s2.insert({"hello", 6});    // 插入元素 {"hello", 6}
```

#### 删除

```cpp
s.clear();                      // 清空所有元素
s.erase(6);                     // 删除元素 6
s2.erase({"hello", 6});         // 删除元素 {"hello", 6}
s.erase(s.begin());             // 删除第一个元素
s.erase(s.begin(), s.end());    // 删除所有元素
```

#### 修改

改不了。

#### 查找

```cpp
s.find(6);                      // 查找元素 6 返回迭代器
s.count(6);                     // 查找元素 6 的个数
```

### multiset

可重集合

multiset 的元素是可以重复的。

multiset 的底层实现是红黑树，所以 multiset 的元素是有序的。

```cpp
#include <set>
```

#### 创建

```cpp
multiset<int> s1;                // 元素类型是 int
multiset<pair<string, int>> s2;  // 元素类型是 pair 类型
```

#### 增加

```cpp
s.insert(6);                // 插入元素 6
s2.insert({"hello", 6});    // 插入元素 {"hello", 6}
```

#### 删除

```cpp
s.clear();                      // 清空所有元素
s.erase(6);                     // 删除元素 6
s2.erase({"hello", 6});         // 删除元素 {"hello", 6}
s.erase(s.begin());             // 删除第一个元素
s.erase(s.begin(), s.end());    // 删除所有元素
```

#### 修改

改不了。

#### 查找

```cpp
s.find(6);                      // 查找元素 6 返回迭代器
s.count(6);                     // 查找元素 6 的个数
s.lower_bound(6);               // 查找第一个大于等于 6 的元素 返回迭代器
s.upper_bound(6);               // 查找第一个大于 6 的元素 返回迭代器

s.equal_range(6);               // 查找第一个大于等于 6 和 第一个大于 6 的元素 返回迭代器
// 如果没有大于等于 6 的元素，那么第一个迭代器指向第一个大于 6 的元素，返回的两个迭代器相等
```

### unordered_multiset

无序可重集合



#### 创建

#### 增加

#### 删除

#### 修改

#### 查找

---
### map

映射

#### 创建

#### 增加

#### 删除

#### 修改

#### 查找

### unordered_map

无序映射

#### 创建

#### 增加

#### 删除

#### 修改

#### 查找

### multimap

可重映射

#### 创建

#### 增加

#### 删除

#### 修改

#### 查找

### unordered_multimap

无序可重映射

#### 创建

#### 增加

#### 删除

#### 修改

#### 查找

## 迭代器 iterator

## 容器适配器 adapter

## 算法 algorithm

## 函数对象 functor
