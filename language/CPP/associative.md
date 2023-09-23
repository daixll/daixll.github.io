---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

所谓关联式容器，就是将数据元素组织成键值对的容器。

* 元素按照一定的排序规则组织的，而不是像顺序容器那样按照元素的插入顺序组织的。
* 关联容器的元素类型是pair类型，pair类型的第一个元素是键值，第二个元素是实值。

# 树

## 二叉搜索树 BST

## 平衡二叉树 AVLT

## 平衡二叉搜索树 BBST

## 红黑树 RBT


# set

## set 集合

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

## unordered_set 无序集合

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

## multiset 可重集合

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

## unordered_multiset 无序可重集合



#### 创建

#### 增加

#### 删除

#### 修改

#### 查找

---
# map

## map 映射

#### 创建

#### 增加

#### 删除

#### 修改

#### 查找

## unordered_map 无序映射

#### 创建

#### 增加

#### 删除

#### 修改

#### 查找

## multimap 可重映射

#### 创建

#### 增加

#### 删除

#### 修改

#### 查找

## unordered_multimap 无序可重映射

#### 创建

#### 增加

#### 删除

#### 修改

#### 查找