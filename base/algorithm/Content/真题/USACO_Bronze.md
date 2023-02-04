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



# 2022-2023 Season

## 2023 US Open
## 2023 Feb
## 2023 Jan
## 2022 DEC

<a href="https://www.acwing.com/problem/content/4821/" target="_blank">AcWing 4818. 奶牛大学</a>

<details><summary>ideas</summary> 

> 求赚到的钱`res`及收取的学费`fees`
> 
> 我们需要找到一个数`fees`, 使得我们可以获得尽可能多的收益`res`
> 
> 收益`res` = `fees` * 上学的奶牛数量 
> 
> 一个限制条件是, 如果`fees` > 第i头奶牛愿意支付的最大金额`c[i]`, 第i头奶牛会放弃上学
>
> 简而言之: 学费高, 奶牛少; 学费低, 奶牛多(此限制条件也使得答案不具有单调性,故不能二分)
>
> 因此, 我们可以尝试枚举`fees`, 找到最大的`res`
>
> 对于上学的奶牛的数量, 如果对于每个`fees`, 都去原数组中检查一下, 时间复杂度过大
>
> 因此, 我们可以对原数组进行一次从大到小的排序
> 
> 此时枚举的`fees`, 就是`c[i]`, 而上学的奶牛的数量就是`i`
>
> 答案要求学费尽可能小, 因此枚举时, `res`可以被 `>=res` 更新, 而不是`>res`
</details>

<details><summary>code</summary> 

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N=1e5+10;

LL c[N];    // 每头奶牛愿意支付的最高学费
int n;      // 奶牛数量
LL res;     // 赚的钱
int fees;   // 学费

int main(){
    cin>>n;
    for(int i=1; i<=n; i++) scanf("%d", c+i);
    sort(c+1, c+1+n, greater());    // 从大到小排序
    
    for(int i=1; i<=n; i++)         // 从大到小枚举
        if( res <= c[i] * i )       // 当前学费可以赚多少
            res  = c[i] * i, fees = c[i];   // 更新答案
    
    cout<<res<<" "<<fees;
    
    return 0;
}
```
</details>



---

# 2021-2022 Season

## 2022 US Open 
## 2022 Feb
## 2022 Jan
## 2021 DEc
