---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

所谓序列式容器，其中的元素 **可序**，但未必 **有序**。

---

# list 链表

### 创建

```cpp
list<int> l1;       // 空链表
list<int> l2(10);   // 10个元素，每个元素都是0
list<int> l3(10, 6);// 10个元素，每个元素都是6
list<int> l4(l3);   // 拷贝构造函数]
list<int> l5({1, 2, 3, 4, 5}); // 初始化列表
```

### 增加

```cpp
l1.push_back(6);            // 尾部插入
l1.push_front(6);           // 头部插入
l1.insert(l1.begin(), 6);   // 插在 l1.begin() 之前，即头部插入

l1.emplace_back(6);         // 尾部插入
l1.emplace_front(6);        // 头部插入
l1.emplace(l1.end(), 6);    // 插在 l1.end() 之前，即尾部插入
```

### 删除

```cpp
l1.clear();                 // 清空链表
l1.pop_back();              // 尾部删除
l1.pop_front();             // 头部删除
l1.erase(l1.begin());       // 删除 l1.begin() 位置的元素
l1.erase(l1.begin(), l1.end()); // 删除 [l1.begin(), l1.end()) 之间的元素

l1.remove(666);             // 删除所有值为 6 的元素
l1.unique();                // 删除所有相邻重复的元素：6 6 7 7 6 6 -> 6 7 6
```

### 修改

```cpp
l1.assign(10, 6);            // 链表大小改为10，所有元素都是6
l1.assign(l2.begin(), l2.end()); // 拷贝 l2 的所有元素
l1.assign({1, 2, 3, 4, 5});  // 拷贝初始化列表

l1.resize(10);              // 链表大小改为10，多余的元素被删除，不足的元素被补 0
l1.resize(10, 6);           // 链表大小改为10，多余的元素被删除，不足的元素被补 6

l1.reverse();               // 反转链表
```

### 查找

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

### 其他

```cpp
l1.sort();                  // 排序
l1.sort(greater<int>());    // 降序排序
```


---
# vector 动态数组

### 创建

```cpp
vector<int> v1;             // 空数组
vector<int> v2(10);         // 10个元素，每个元素都是0
vector<int> v3(10, 1);      // 10个元素，每个元素都是1
vector<int> v4(v3);         // 拷贝构造函数
vector<int> v5({1, 2, 3, 4, 5}); // 初始化列表
```

### 增加

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

### 删除

```cpp
v1.clear();                 // 清空数组

v1.pop_back();              // 尾部删除
v1.erase(v1.begin());       // 删除 v1.begin() 位置的元素
v1.erase(v1.begin(), v1.end()); // 删除 [v1.begin(), v1.end()) 之间的元素
```

### 修改

```cpp
v1.assign(10, 6);            // 数组大小改为10，所有元素都是6
v1.assign(v2.begin(), v2.end()); // 拷贝 v2 的所有元素
v1.assign({1, 2, 3, 4, 5});  // 拷贝初始化列表

v1.resize(10);              // 数组大小改为10，多余的元素被删除，不足的元素被补 0
v1.resize(10, 6);           // 数组大小改为10，多余的元素被删除，不足的元素被补 6
```

### 查找

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

### 其他

```cpp
v1.capacity();              // 返回数组容量
v1.shrink_to_fit();         // 释放多余的空间
```

---
# stack 栈

### 创建

```cpp
stack<int> s1;              // 空栈
stack<int> s2(s1);          // 拷贝构造函数
stack<int> s3({1,2,3});     // 初始化列表，1为栈底，3为栈顶
```

### 增加

```cpp
s1.push(6);                 // 入栈
```

### 删除

```cpp
s1.pop();                   // 出栈
```

### 修改

只能通过入栈和出栈来修改栈。

### 查找

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
# queue 队列

### 创建

```cpp
queue<int> q1;              // 空队列
queue<int> q2(q1);          // 拷贝构造函数
queue<int> q3({1,2,3});     // 初始化列表，1为队头，3为队尾
```

### 增加

```cpp
q1.push(6);                 // 入队
```

### 删除

```cpp
q1.pop();                   // 出队
```

### 修改

只能通过入队和出队来修改队列。

### 查找

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
# deque 双端队列

```cpp
#include <queue>   // deque 包含在 queue 中
```

### 创建

```cpp
deque<int> d1;              // 空双端队列
deque<int> d2(10);          // 10个元素，每个元素都是0
deque<int> d3(10, 1);       // 10个元素，每个元素都是1
deque<int> d4(d3);          // 拷贝构造函数
deque<int> d5({1, 2, 3, 4, 5}); // 初始化列表 1为队头，5为队尾
```

### 增加

```cpp
d1.push_back(6);            // 尾部入队
d1.push_front(6);           // 头部入队
```

### 删除

```cpp
d1.pop_back();              // 尾部出队
d1.pop_front();             // 头部出队
```

### 修改

当有修改需求时，建议使用 [vector](#vector-动态数组) 代替。

### 查找

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
# priority_queue 优先队列 (堆)

```cpp
#include <queue>   // priority_queue 包含在 queue 中
```

### 创建

```cpp
priority_queue<int> p1;     // 空优先队列，默认大顶堆
priority_queue<int, vector<int>, greater<int>> a;   // 小顶堆
```

### 增加

```cpp
p1.push(6);                 // 入队
```

### 删除

```cpp
p1.pop();                   // 出队
```

### 修改

改不了一点。

### 查找

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