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

<a href="" target="_blank">还未收录</a>



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


<a href="https://www.acwing.com/problem/content/4822/" target="_blank">AcWing 4819. 喂饱奶牛</a>

<details><summary>ideas</summary>

> 求种植的方案 `res`
>
> 对于第 i 头奶牛, 其可以移动的区间为 `[i-k, i+k]`, 其中`i-k>=1`, `i+k<=n`
>
> 对于第 i 颗草, 其可以满足的奶牛区间为 `[i-k, i+k]`, 其中`i-k>=1`, `i+k<=n`
>
> 我们先考虑第一种牛:
>
> 为了使得种植的草最少, 当在 `i` 找到牛, 便在 `i+k` 种草, 其影响区间`[i+k -k, i+k +k]`
>
> 如此往复, 下一次从 `i+k+k +1` 位置找牛
>
> 此题边界判断比较简单, `min(i+k, n)` 即种草位置
>
> 接下来考虑第二种牛:
>
> 总体思想和考虑第一头牛的时候一致, 唯一的变数是, 种第二种草的位置可能已经被第一种草给占据了
>
> 显然, 此时我们只能将种草位置左移动, 因为向右移动, 第i头牛没得草吃
>
> `while(res[j] == '草一') --j;` 如果被种草了, 就不断前移
>
> 但实际上, 只需要移动到 j-1, `if(res[j] == '草一') --j;`
>
> 对于学有余力的小朋友,可以尝试用反证法证明其正确性:
> notice: 第 i 位和 i-1 位置都被 G 占用( 当且仅当 k==0 )

</details>

<details><summary>code</summary> 

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N=1e5+10;

char res[N];    // 种植方案(答案)
char g[N];      // 奶牛种类
int n, k, cnt;  // 奶牛数量 移动 种植数量

void solve(){
    cnt=0;
    memset(res, '.', sizeof res);
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>g[i];
    
    for(int i=1; i<=n; i++)
    if( g[i] == 'G' ){
        int j=min(n, i+k);  // 种植 G 的位置
        res[j] = 'G'; cnt++;// 种植
        i=j+k;              // 可以影响到的右边界
    }
    
    for(int i=1; i<=n; i++)
    if( g[i] == 'H' ){
        int j=min(n, i+k);  // 种植 H 的位置
        if( res[j] == 'G' ) --j; // 思考:为什么--j的位置一定不会冲突?
        res[j] = 'H'; cnt++;
        i=j+k;
    }
    
    cout<<cnt<<"\n";
    for(int i=1; i<=n; i++)
        cout<<res[i];
    cout<<"\n";
}

int main(){
    int T; cin>>T; 
    while(T--) solve();
    return 0;
}
```
</details>


<a href="https://www.acwing.com/problem/content/4823/" target="_blank">AcWing 4820. 逆向工程</a>

<details><summary>ideas</summary>

> 枚举可能的第一个分支代码，筛选出剩余的行，继续枚举第二个分支

</details>

<details><summary>code</summary>

</details>

---

# 2021-2022 Season

## 2022 US Open 

<a href="https://www.acwing.com/problem/content/4443/" target="_blank">AcWing 4440. 照相</a>

<details><summary>ideas</summary>

> 求最小的翻转的次数 `ans`
>
> 观察题目, 题目保证字符串是偶数, 且每次翻转也是偶数, 因此我们将字符串看为
>
> `GG`, `HH`, `GH`, `HG` 组成的, 显然, `GG`和`HH`无论怎么翻转都不会让`ans`增加
> 
> 而只有翻转`GH`, 才会使得答案更好, 不如模拟一下:
> 
> `GHGH HGHG GHGH` 原串
> `HGHG HGHG GHGH` 翻转 4
> `GHGH GHGH GHGH` 翻转 8
> `HGHG HGHG HGHG` 翻转 12
>
> 因为每次翻转是`1-n`的, 我们发现, `HG` 也需要翻转
>
> 因此答案其实就是连续的 `GH` 和 `HG` 的段数
>
> 值得注意, 如果以 `HG` 结尾, 我们将会多统计一次


</details>

<details><summary>code</summary>

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int n, ans;
string s;

int main(){
    cin>>n>>s;
    s=" "+s;

    bool gh = 0, hg = 0;
    for(int i=1; i<=n; i+=2)
        if(s[i]=='G' && s[i+1]=='H' && !gh)
            ans++, gh=1, hg=0;
        else 
        if(s[i]=='H' && s[i+1]=='G' && !hg)
            ans++, gh=0, hg=1;
    
    cout<< ans - hg;
    return 0;
}
```

</details>

<a href="https://www.acwing.com/problem/content/4444/" target="_blank">AcWing 4441. 谎牛计数</a>

<details><summary>ideas</summary>

> t

</details>

<details><summary>code</summary>

</details>

<a href="https://www.acwing.com/problem/content/4445/" target="_blank">AcWing 4442. 炼金术</a>

<details><summary>ideas</summary>

> t

</details>

<details><summary>code</summary>

</details>

## 2022 Feb
## 2022 Jan
## 2021 DEc
