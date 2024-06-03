---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子

<br>

---

# 入门

<br>

---

# 基础

<br>

---

# 搜索

<br>

---

# 动规

<br>

---

# 字符串

## **KMP**

* 作用：字符串中查找子串
* 时间复杂度：$O(n+m)$，$n$ 为字符串长度，$m$ 为子串长度
* 核心思想：通过预处理子串，生成部分匹配表（前缀函数），利用此表在匹配过程中跳过匹配的部分

```cpp
vector<int> KMP(string s, string p){    // 返回所有匹配的位置
    int n=s.size(), m=p.size();
    s = " " + s, p = " " + p;
    vector<int> res, ne(m+1);
    for(int i=2, j=0; i<=m; i++){       // 预处理得部分匹配表
        while(j && p[j+1]!=p[i]) j=ne[j];
        if(p[i] == p[j+1]) j++;
        ne[i]=j;
    }   // m - ne[m] 为最小循环子串
    for(int i=1, j=0; i<=n; i++){       // KMP 匹配
        while(j && p[j+1]!=s[i]) j=ne[j];
        if(s[i] == p[j+1]) j++;
        if(j == m){
            j = ne[j];                  // 当匹配成功时继续
            res.push_back(i-m);
        }
    }
    return res;
}
```

## **Trie**

* 作用：存储字符串集合，非常适合前缀搜索
* 时间复杂度：插入与搜索均为 $O(n)$ 
* 核心思想：逐字符存储，利用字符串的公共前缀来节省存储空间，并加快查询速度

```cpp
class Trie{
public:
    Trie(int n=1e5):
        son(n+1, vector<int>(27)),  // 仅包含小写字母
        idx(0){};
    ~Trie(){};

    void insert(string &s){
        int p = 0;                  // deep
        for(auto &c: s){
            if(!son[p][c-'a'])
                son[p][c-'a'] = ++idx;
            p = son[p][c-'a'];
        }
        cnt[p]++;
    }

    int query(string &s){           // 此字符出现次数
        int p = 0;
        for(auto &c: s){
            if(!son[p][c-'a'])
                return 0;
            p = son[p][c-'a'];
        }
        return cnt[p];
    }

private:
    vector<vector<int>> son;        // 树
    map<int, int> cnt;              // 某节点结尾的字符串数量
    int idx;                        // 当前插入节点的值
};
```

<br>

---

# 数学

## 异或性质

## **高精度**

## **进制转换**

<br>

---

# 数据结构

## 栈

## 队列

## 单调栈

## 单调队列

## **并查集**

**1. 朴素并查集**

* 作用：
* 时间复杂度：
* 核心思想：

```cpp
// 初始化
for(int i=1; i<=n; i++) p[i]=i;     // 自己是自己的祖先
// 查找
int find(int x){                    // 找 x 的祖先
    if(p[x] != x) p[x] = find(p[x]);// 如果 x 的祖先不是自己
    return p[x];                    // 会在这个过程中合并
}
// 合并
p[find(a)] = find(b);               // a -> b
```

**2. 维护数量的并查集**

* 作用：
* 时间复杂度：
* 核心思想：


## **线段树**



<br>

---

# 图论

## LCA

<br>

---

# 计算几何

<br>

---

# game

## CCF-J

## CIE

## GESP