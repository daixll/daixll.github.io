## 参考

* [C/C++ 语言参考](https://en.cppreference.com/w/)

* [欢迎回到 C++ 现代 C++](https://learn.microsoft.com/zh-cn/cpp/cpp/welcome-back-to-cpp-modern-cpp?view=msvc-170)

* [ILE C/C++ 语言参考](https://www.ibm.com/docs/zh/i/7.5?topic=c-ile-cc-language-reference)

* [C++ 语言面向对象](https://docs.net9.org/languages/c-oop/)

* [C++ 运算符号重载](https://www.runoob.com/cplusplus/cpp-overloading.html)

<br>

---

## 异常处理

```cpp
#include <iostream>
#include <fstream>
#include <cstring>

void openfile(std::string filename){
    std::ifstream file(filename);
    if(!file.is_open()) throw std::runtime_error("无法打开文件 " + filename);
    return ;
}

int32_t main(){
    try{
        openfile("txt.txt");
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
        std::cerr << "errno: " << errno << " " << strerror(errno) << "\n";
    }
    return 0;
}
```

* `try` 尝试

* `throw` 抛出

* `catch` 捕获

<br>

---

## 声明与定义

* **声明** 暂不实现，不分配内存

```cpp
extern int x;
// 声明一个变量
// 告诉编译器，这个变量在其他地方定义，但你可以在当前文件中使用它
void func();
// 声明一个函数
// 确保编译器可以正确地处理函数调用，即使函数的实现可能在其他文件中
class A;
// 前向声明一个类
// 允许在类的实现中使用另一个类而不需要包含其完整定义
```

* **定义** 声明 + 实现，分配内存（类需要具体讨论）

```cpp
int x;          // 定义一个变量
void func(){}   // 定义一个函数
class A{};      // 定义一个类
```


<br>

---

## 智能指针

为了解决内存泄漏、野（wild）指针、悬空（dangling）指针的问题，引入了智能指针

**内存泄漏**

* 含义：申请的内存没有被释放，导致无法再次使用该内存

```cpp
#include <iostream>

int main(){
    while(true)                 // 死循环
        auto* ptr = new int();  // 申请堆空间
    return 0;
}
```

* 原因：忘了 `delete`

* 后果：`Killed`，内存占用过多，程序崩溃


**野指针**

* 含义：指针根本没有正确初始化，指向的是随机内存位置，可能从未被分配过

```cpp
#include <iostream>

int main(){
    int* ptr;
    *ptr = 666;
    return 0;
}
```

* 原因：忘了 `new` 就直接用

* 后果：`Segmentation fault (core dumped)`

**悬空指针**

* 含义：曾经指向有效内存，但由于所指向的内存已被释放或对象生命周期已结束，现在变得无效

* 原因：`delete` 后还在用

```cpp
#include <iostream>

int main(){
    int* ptr1 = new int;
    delete ptr1;
    *ptr1 = 666;        // 此时实际上是越界访问了
    std::cout << "ptr1: " << *ptr1 << "\n";

    int* ptr2 = new int;
    *ptr2 = 888;        // 这个值会覆盖 *ptr1
    std::cout << "ptr1: " << *ptr1 << "\n";
    return 0;
}
```

* 后果：越界访问

<br>

### 创建

```cpp
#include <memory>

std::unique_ptr<int> uniquePtr = std::make_unique<int>();
std::shared_ptr<int> sharedPtr = std::make_shared<int>();
std::weak_ptr<int> weakPtr(sharedPtr);
```

**独占指针 `unique_ptr`**

当 `unique_ptr` 被销毁时，它所指向的对象也被销毁

```cpp
void func(){
    std::unique_ptr<int> ptr = std::make_unique<int>(666);
}   // 当函数结束时, ptr 被销毁, ptr 指向的内存也被销毁
```

**共享指针 `shared_ptr`**

多个 `shared_ptr` 可以指向同一个对象，当最后一个 `shared_ptr` 被销毁时（引用记数为 0 的时候），它所指向的对象也被销毁

```cpp
#include <iostream>
#include <memory>

// 通过引用传递智能指针
// p1 和 p2 指向同一个对象, 引用计数为 2
void f2(std::shared_ptr<int> &p1){
    std::shared_ptr<int> p2 = std::make_shared<int>(666);
    p1 = p2;
    // 此时p2和p1指向同一个对象, 引用计数为 2
    std::cout << p1.use_count() << std::endl;
}

// 创建一个空的智能指针，通过引用传递给f2函数
void f1(){
    std::shared_ptr<int> p1;
    f2(p1);
    // 当 f2 函数执行完毕后, f2 函数内部的 p2 指针被销毁, 引用计数为 1
    std::cout << p1.use_count() << std::endl;
    std::cout << *p1 << std::endl;
}

int main(){
    f1();
    return 0;
}
```



```cpp
ptr.reset();        // 销毁 ptr 指向的内存
ptr.reset(nullptr); // 销毁 ptr 指向的内存（等价）
```

**指针 `weak_ptr`**

为了避免 `shared_ptr` 的循环引用问题，引入了 `weak_ptr`

todo

<br>

---


## 内存管理


<br>

---

## 文件操作

<br>

---

## 面向对象

### 构造：初始化列表

```cpp
class A{
public:
    A(int a, int b): x(a), y(b){};
    // 在构造函数主体运行之前初始化类成员
private:
    int x, y;
};
```

### 构造：拷贝构造

### 构造：移动构造

### 构造：委托构造

### 构造：委派构造

### 重载运算符

```cpp
#include <iostream>

class A{
public:
    A(int x, int y): _x(x), _y(y){};

    // 重载 输出运算符 <<
    friend std::ostream &operator<<(std::ostream& output, A a){
        output << a._x << " " << a._y;
        return output;            
    }
    
    // 重载 输入运算符 >>
    friend std::istream &operator>>(std::istream& input, A a){
        input >> a._x >> a._y;
        return input;            
    }
    
    // 重载 一元运算符 -
    A operator- (){
        return A(-_x, -_y);
    }

    // 重载 二元运算符 +
    A operator+ (A a){
        return A(_x + a._x, _y + a._y);
    }

    // 重载 关系运算符 <
    bool operator< (A a){
        if(_x < a._x) return true;
        if(_x > a._x) return false;
        if(_y < a._y) return true;
        return false;
    }

private:
    int _x, _y;
};

int main(){
    A a(-1, 2);
    std::cout << a << "\n";
    std::cout << -a << "\n";
    std::cout << a+a << "\n";
    std::cout << (a+a<a) << "\n";
    
    return 0;
}
```

<br>

### 继承

**基类**

```cpp
class A{
public:
    void pubShow(){
        std::cout << "A_pub\n";
    }
private:
    void priShow(){
        std::cout << "A_pri\n";
    }
protected:
    void proShow(){
        std::cout << "A_pro\n";
    }
};
```

<br>

**派生**

<center>

| 继承方式 | public | protected | private |
|:-:|:-:|:-:|:-:|
| public 继承（内）    | 🟢 | 🟢 |   |
| public 继承（外）    | 🟢 |   |   |
| protected 继承（内） | 🟢 | 🟢 |   |
| protected 继承（外） |  |   |   |
| private 继承（内）   | 🟢 | 🟢 |   |
| private 继承（外）   |  |   |   |


</center>

<br>

### 多态

```cpp
#include <iostream>

class A{
public:
    virtual void pubShow(){
        std::cout << "A_pub\n";
    }
private:
    void priShow(){
        std::cout << "A_pri\n";
    }
protected:
    void proShow(){
        std::cout << "A_pro\n";
    }
};

class B: public A{
public:
    void pubShow(){
        std::cout << "B_pub\n";
    }
};

class C: public A{
public:
    void pubShow(){
        std::cout << "C_pub\n";
    }
};

int main(){
    A* a = new B();
    a->pubShow();

    delete a;
    a = new C();
    a->pubShow();

    return 0;
}
```

<br>

---

## 动态链接

[为什么不能在动态库里静态链接？](https://liam.page/2017/04/03/not-to-link-libstdc-statically-and-why/)