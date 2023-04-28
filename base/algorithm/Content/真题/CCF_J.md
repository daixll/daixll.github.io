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

<details><summary><a href="https://www.acwing.com/problem/content/description/459/" target="_blank">Acwing 457. 珠心算测验</a> code</summary>

```cpp
#include <iostream>
using namespace std;

const int N=110;

int n, res;
int a[N];   // 是否有这个数
bool st[20010]; // 是否能算出来

int main(){
    cin>>n;
    for(int i=1; i<=n; i++) scanf("%d", a+i);
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            st[ a[i]+a[j] ] = 1;
    for(int i=1; i<=n; i++)
        if(st[a[i]]) res++;
    cout<<res;
    
    return 0;
}
```
</details>


<details><summary><a href="https://www.acwing.com/problem/content/460/" target="_blank">Acwing 458. 比例简化</a> code</summary>

```cpp
#include <iostream>
using namespace std;

int A, B, L;
int A1, B1;
int A2=999, B2=1;

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

int main(){
    cin>>A>>B>>L;
    for(A1=1; A1<=L; A1++)  // 枚举
    for(B1=1; B1<=L; B1++)
        if(A1*B >= A*B1)    // 满足A1/B1 >= A/B
        if(gcd(A1, B1)==1)  // 两数互质
        if(A1*B2 < A2*B1)   // 更小
            A2=A1, B2=B1;
    cout<<A2<<" "<<B2;
    return 0;
}
```
</details>


<details><summary><a href="https://www.acwing.com/problem/content/description/461/" target="_blank">AcWing 459. 螺旋矩阵</a> code</summary>

```cpp
#include <iostream>
using namespace std;

typedef long long LL;

int n, x, y, ans=1;

int main(){
    cin>>n>>x>>y;
    
    for(int i=1, j=n; i<=j; i++, j--, ans+=n*4-4, n-=2)
        if(i==x){      // 上
            cout<<ans+(y-i);
            break;
        }
        else if(j==x){ // 下
            cout<<ans+(j-y)+n*2-2;
            break;
        }
        else if(i==y){ // 左
            cout<<ans+(j-x)+n*3-3;
            break;
        }
        else if(j==y){ // 右
            cout<<ans+(x-i)+n-1;
            break;
        } 
    
    return 0;
}
```
</details>

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


<details><summary><a href="https://www.acwing.com/problem/content/description/457/" target="_blank">AcWing 455. 小朋友的数字</a> code</summary>

```cpp
#include <iostream>
using namespace std;

typedef long long LL;
const int N=1e6+10;

LL n, p;
LL a[N], b[N], t[N];
__int128 c[N];  // T为特征值

int main(){
    cin>>n>>p;
    for(int i=1; i<=n; i++){
        scanf("%lld", a+i); // 原始数字
        b[i] = a[i];        // 最大子序和
    }
    
    *b = -0x3f3f3f3f;
    for(int i=1; i<=n; i++){
        b[i] = max(b[i-1]+a[i], a[i]);
        *b = max(*b, b[i]);
        t[i] = *b; // 1-i 的最大子序和
    }
    c[1]=t[1];
    
    __int128 mmax = a[1]+t[1];    // 维护这个最大
    for(int i=2; i<=n; i++){
        c[i] = mmax;
        mmax = max(mmax, __int128(c[i]+t[i]));
    }
    
    *c = c[1];
    for(int i=2; i<=n; i++)
        *c = max(*c, c[i]);
    
    //for(int i=1; i<=n; i++) printf("%12d", a[i]); cout<<"\n";
    //for(int i=1; i<=n; i++) printf("%12d", t[i]); cout<<"\n";
    //for(int i=1; i<=n; i++) printf("%12d", c[i]); cout<<"\n";
    
    (*c)%=p;
    
    printf("%d", *c);
    
    return 0;
}
```
</details>