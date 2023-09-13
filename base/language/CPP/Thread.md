---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# thread

## thread：线程

* `join` 方式：等待线程结束，再继续执行。
* `detach` 方式：分离线程，线程结束后自动回收资源。

```cpp  
#include <iostream>
#include <thread>
using namespace std;

void func(int i){
    cout << "hello "<< i <<" Thread" << endl;
}

int main(){
    thread (func, 1).detach();  // 创建匿名线程并分离
                                // 主线程结束，此线程也会结束
    thread t(func, 2);  // 创建线程 t
    t.join();           // 等待线程 t 结束
    return 0;
}
```
主函数创建了一个线程，然后分离，主函数结束，线程也结束。
主函数创建了一个线程，然后等待，主函数结束，线程也结束。

## this_thread：线程本身

---

# mutex

## mutex：互斥量

* `lock`：上锁。
* `unlock`：解锁。

```cpp
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int value;  // 分别对此变量进行加 [1,1e6] 和减 [1,1e6] 操作
int m_value;// 互斥锁保护的变量，同样进行加减操作
mutex mtx;  // 互斥锁

void add(){
    for(int i = 1; i <= 1e6; i++) value++;
}

void sub(){
    for(int i = 1; i <= 1e6; i++) value--;
}

void m_add(){
    for(int i = 1; i <= 1e6; i++){
        mtx.lock();   // 上锁
        m_value++;
        mtx.unlock(); // 解锁
    }
}

void m_sub(){
    for(int i = 1; i <= 1e6; i++){
        mtx.lock();   // 上锁
        m_value--;
        mtx.unlock(); // 解锁
    }
}

int main(){
    thread t1 (add);
    thread t2 (sub);
    t1.join();
    t2.join();
    cout<<value<<endl;

    thread t3 (m_add);
    thread t4 (m_sub);
    t3.join();
    t4.join();
    cout<<m_value<<endl;
    return 0;
}
```

主函数首先创建了两个线程，分别对 value 进行加减操作，然后输出 value 的值。
在加减操作中，没有对 value 进行保护，所以最后输出的 value 的值不一定是 0。

主函数接着创建了两个线程，分别对 m_value 进行加减操作，然后输出 m_value 的值。
在加减操作中，对 m_value 进行了保护，所以最后输出的 m_value 的值一定是 0。

## lock_guard：锁保护

简单理解，作用域内自动上锁解锁。

```cpp
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;  // 锁
int value = 0;

void add(int i){
    for(int i=1; i<=1e6; i++){
        lock_guard<mutex> lock(mtx);  // 加锁
        value++;
    }
}

void sub(int i){
    for(int i=1; i<=1e6; i++){
        lock_guard<mutex> lock(mtx);  // 加锁
        value--;
    }
}

int main(){
    thread t1(add, 1);
    thread t2(sub, 2);
    t1.join();
    t2.join();
    cout << value << endl;
    return 0;
}
```

主函数创建了两个线程，分别对 value 进行加减操作，然后输出 value 的值。
在加减操作中，使用 lock_guard<mutex> lock(mtx) 对 value 进行保护，所以最后输出的 value 的值一定是 0。

## unique_lock：独占锁

---

# atomic

## atomic：原子操作

## atomic_flag：原子标志

---

# condition_variable

## condition_variable：条件变量

## condition_variable_any：通用条件变量

---

# future

## future：异步操作

## shared_future：共享异步操作

## promise：异步操作

## packaged_task：异步操作