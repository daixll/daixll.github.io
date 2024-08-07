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



## 智能指针

为了解决内存泄漏、野（wild）指针、悬空（dangling）指针的问题，引入了智能指针

```cpp
#include <memory>
// unique_ptr
// shared_ptr
// weak_ptr
```

**内存泄漏**

导致内存占用过多，程序崩溃

* 程序运行时，申请的内存没有被释放无法再次使用该内存

* 丢失了指向该内存的指针无法访问、释放该内存

**野指针**

当一个指针未被显式初始化，它的值就是未知的，可能是一个随机的内存地址，也可能是特定编译环境下的默认值（通常是 `0` 或者 `nullptr`）

**悬空指针**

指向的内存已经被释放，但是指针本身没有被释放

* 释放内存后，指针没有被置为 nullptr
```cpp
int* ptr = new int; // 申请内存
delete ptr;         // 释放内存
// ptr 已经悬空
ptr = nullptr;      // 将 ptr 置为 nullptr, ptr 成空指针
```

* 在函数中返回局部变量的指针

```cpp
int* func(){
    int a = 6;      // 局部变量
    return &a;      // 返回局部变量的指针
}
int *ptr = func();  // ptr 指向的内存已经被释放
// ptr 已经悬空
```

* 在函数中返回指向堆内存的指针，但是没有释放堆内存

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


**独占指针 `unique_ptr`**

当 `unique_ptr` 被销毁时，它所指向的对象也被销毁

```cpp
void func(){
    std::unique_ptr<int> ptr = std::make_unique<int>(666);
}
// 当函数结束时，ptr 被销毁，ptr 指向的内存也被销毁
// 也可以手动销毁
ptr.reset();        // 销毁 ptr 指向的内存
ptr.reset(nullptr); // 销毁 ptr 指向的内存（等价）
```

**共享指针 `shared_ptr`**

多个 `shared_ptr` 可以指向同一个对象，当最后一个 `shared_ptr` 被销毁时（引用记数为 0 的时候），它所指向的对象也被销毁

```cpp
#include <iostream>
#include <memory>

// 通过引用传递智能指针
// p1 和 p2 指向同一个对象，引用计数为2
void f2(std::shared_ptr<int> &p1){
    std::shared_ptr<int> p2 = std::make_shared<int>(666);
    p1=p2;
    // 此时p2和p1指向同一个对象，引用计数为2
    std::cout<<p1.use_count()<<std::endl;
}

// 创建一个空的智能指针，通过引用传递给f2函数
void f1(){
    std::shared_ptr<int> p1;
    f2(p1);
    // 当f2函数执行完毕后，f2函数内部的p2指针被销毁，引用计数为1
    std::cout<<p1.use_count()<<std::endl;
    std::cout << *p1 << std::endl;
}

int main(){
    f1();
    return 0;
}
```


**指针 `weak_ptr`**

为了避免 `shared_ptr` 的循环引用问题，引入了 `weak_ptr`

todo

<br>

---


<br>

---


## 内存管理


<br>

---

## 文件操作


## 面向对象


[C++ 语言面向对象](https://docs.net9.org/languages/c-oop/)

## 动态链接

[为什么不能在动态库里静态链接？](https://liam.page/2017/04/03/not-to-link-libstdc-statically-and-why/)