---
html:
    toc: true           # 打开侧边目录
    toc_depth: 6        # 打开的目录层级
    toc_float: true     # 侧边悬停
    collapsed: true     # 只显示高级别标题(2)
    smooth_scroll: true # 页面滚动,标题变化
    number_sections: false  # 显示标题编号
    theme: united
--- 


# 2022

---

# 2021

---

# 2020

---

# 2019

---

# 2018

---

# 2017

---

# 2016

---

# 2015

---

# 2014

---

# 2013

<details><summary><a href="https://www.acwing.com/problem/content/455/" target="_blank">Acwing 453. 计数问题</a> code</summary>

```cpp
#include <iostream>
using namespace std;

const int N=1e6+10;

int n, X, ans;

int calc(int i){   // 计算i中有几个X
    int res=0;
    while(i){
        if(i%10==X) res++;
        i/=10;
    }
    return res;
}

int main(){
    cin>>n>>X;
    for(int i=1; i<=n; i++)
        ans+=calc(i);
    cout<<ans;
    return 0;
}
```
</details>


<details><summary><a href="https://www.acwing.com/problem/content/456/" target="_blank">Acwing 454. 表达式求值</a> code</summary>

```cpp
#include <iostream>
using namespace std;

typedef long long LL;

const int N=1;

LL ans, tmp, num;
char ch;

int main(){
    cin>>tmp;
    while(cin>>ch>>num)
        if(ch=='+')
            ans+=tmp,
            tmp=num;
        else
            tmp=(tmp*num)%10000;
    cout<<(ans+tmp)%10000;
    return 0;
}
```
</details>