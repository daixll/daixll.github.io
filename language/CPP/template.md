---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---


# 什么是 template

template：变参数模板。是一种编译器的特性，用于生成一系列的函数或类。

# 如何使用 template

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

## 在类中使用 templat

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