---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---



# <center> 2022-2023 Season </center>

## 2023 US Open
## 2023 Feb
## 2023 Jan

<a href="" target="_blank">-</a>



## 2022 Dec



<details><summary><a href="https://www.acwing.com/problem/content/4821/" target="_blank">AcWing 4818. 奶牛大学</a> code</summary> 

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

<details><summary><a href="https://www.acwing.com/problem/content/4822/" target="_blank">AcWing 4819. 喂饱奶牛</a> code</summary>

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

<details><summary><a href="https://www.acwing.com/problem/content/4823/" target="_blank"> AcWing 4820. 逆向工程</a> 跳过</summary><br>

枚举可能的第一个分支代码，筛选出剩余的行，继续枚举第二个分支


</details>

---











# <center>2021-2022 Season</center>

## 2022 US Open 



<details><summary><a href="https://www.acwing.com/problem/content/4443/" target="_blank">AcWing 4440. 照相</a> code</summary>

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



<details><summary><a href="https://www.acwing.com/problem/content/4444/" target="_blank">AcWing 4441. 谎牛计数</a> code</summary>

> 求撒谎的奶牛的最小数量 `ans`
> 
> 我们可以直接画图
> 
> 如图所示, 我们假设 牛 在 `i` 这个位置
>
> 对于 `r` 轴, `i` 右边的牛在撒谎
> 对于 `l` 轴, `j` 左边的牛在撒谎
>
> 所有撒谎的牛的数量就是 `(r_len - i) + j`
>
> 因此, 我们可以枚举 `r` 轴上每一个位置
>
> 找到 `l` 轴上 `<r[i]` 的最后一个位置 `j` 

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

const int N=1e3+10;

int l[N], r[N]; // bessie在奶牛第i头奶牛的 左 \ 右
int ans=0x3f3f3f3f;

int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        char c[2]; int x;
        scanf("%s%d", c, &x);
        if(c[0]=='G') r[ ++ *r ] = x;
        else l[ ++ *l ] = x;
    }
    sort(l+1, l+1+*l);
    sort(r+1, r+1+*r);
    
    for(int i=1; i<=*r; i++){   // 假设, 第i头奶牛说 在我右边 是正确的
        
        int j=1;
        for(; j<=*l; j++)   // 那么, 对于 (l[j] < r[i]) 的j头奶牛说 在我左边 就是错误的
            if( l[j]>=r[i] )
                break;
        
        ans=min(ans, (*r-i)+j-1);
    }
    
    cout<<ans;
    return 0;
}
```

</details>

<details><summary><a href="https://www.acwing.com/problem/content/4445/" target="_blank">AcWing 4442. 炼金术</a> code</summary>

> 求金属 `n` 的最大数量
>
> 观察样例, 可以很容易发现
> 
>           5 
>          / \
>         3   4
>        /   
>       2
>      /
>     1
>
> 因为树形的依赖关系(例, 若图中 4 可以通过 1, 2 合成)
>  
> 我们不能用贪心的思想(例, 将 2 全部用来合成 3 或 4)
>
> 因此, 只能一步一步的尝试, `n` 号结点合成 `cnt` 个是否可以
>
> 而在询问 `n` 号结点的同时, 需要考虑其是否可以合成 `cnt` 个
>
> 因此, 我们可以很容易的想到, 用 `dfs` 来实现这个查询
>
> 而答案显然是具有单调性, 因此我们可以用二分来尝试 `cnt`
>
> 二分模板即 `满足条件中最大的一个`, 即 `在单调递增序列中找 <=x 的数中最大的一个`

```cpp
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
    
#define pb push_back

const int N=110;

int a[N], bk[N];
vector<int> h[N];   // 合成 i 所需要的金属
int n, k;

bool dfs(int u, int cntu){  // 能否获得 cntu 个材料 u
    if( a[u] >= cntu ) {    // 已经拥有
        a[u] -= cntu;
        return 1;  
    }
    if( h[u].size()==0 )    // 不足且无法合成
        return 0;  
    
    cntu-=a[u], a[u]=0;     // 还需要cntu个a[u] 
    for(auto nu: h[u])      // 尝试使用 nu 进行合成
        if( !dfs(nu, cntu-a[u]) ) 
            return 0;
    return 1;
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    cin>>k;
    for(int i=1; i<=k; i++){
        int l, m; cin>>l>>m;
        for(int j=1; j<=m; j++){
            int mi; cin>>mi;
            h[l].pb(mi);
        }
    }

    memcpy(bk, a, sizeof a);

    int l=a[n], r=1e6;
    while(l<r){
        memcpy(a, bk, sizeof a);
        int mid = l+r+1>>1;
        if(dfs(n, mid)) l = mid;
        else r = mid - 1;
    }
    cout<<l;

    return 0;
}
```

</details>



## 2022 Feb

<details><summary><a href="https://www.acwing.com/problem/content/4369/" target="_blank">AcWing 4366. 上课睡觉</a> code</summary>

> 合并实际上只有一种方案, 逆向思考
>

```cpp
// 假设合并后每堆大小 m
// 合并次数 = n - sum/mid
// 合并次数越小, mid就应该更小
#include <iostream>
using namespace std;

const int N=1e6+10;

int a[N];
int n, mmax, sum;

bool ck(int m){
    int cnt=0;
    for(int i=1; i<=n; i++){
        cnt += a[i];
        if(cnt == m) cnt=0;
        else if(cnt > m) return 0;
    }
    return 1;
}

void solve(){
    cin>>n;
    mmax=0, sum=0;
    for(int i=1; i<=n; i++) 
        scanf("%d", a+i), mmax=max(mmax, a[i]), sum+=a[i];
    
    if(sum==0){                 // 每一堆为0
        cout<<0<<"\n";
        return ;
    }
    for(int i=1; i<=sum; i++)   // 枚举, 每一堆为1-sum
        if(sum%i==0 && ck(i)){
            cout<<n - sum / i<<"\n";
            return ;
        }
}

int main(){
    int T; cin>>T;
    while(T--) solve();
    return 0;
}
```

</details>


<details><summary><a href="https://www.acwing.com/problem/content/4370/" target="_blank">AcWing 4367. 拍照2</a> code</summary>

> 贪心+双指针, 顺着样例模拟一下就明白
>

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

const int N=1e5+10;

int a[N], b[N];
unordered_set<int> cnt;
int n, ans;

int main(){
    cin>>n;
    for(int i=1; i<=n; i++)
        scanf("%d", a+i);
    for(int i=1; i<=n; i++)
        scanf("%d", b+i);
    
    int i=1, j=1;
    
        while(i<=n && j<=n){
            if(cnt.count(a[i])){
                i++;
                continue;
            }
            if(a[i]==b[j]){
                i++, j++;
                continue;
            }
        
            if(a[i]!=b[j]){
                cnt.insert(b[j]);
                j++;    
                ans++;  // 需要从后面移动一个
            }
        }
    cout<<ans;
    
    return 0;
}
```

</details>


<details><summary><a href="https://www.acwing.com/problem/content/4371/" target="_blank">AcWing 4368. 积木</a> code</summary>

> 递归求组合型枚举
>

```cpp
#include <iostream>
#include <string>
#include <set>
using namespace std;

bool st[4]; // 每个骰子是否有用
set<char> a[4];
int n;
string t;
bool flg;

void dfs(int u, int x){ // 第几个骰子, 第几个字符
    if(u>4) return ;
    if(flg) return ;
    
    if(x>=t.size()){
        flg=1;
        return ;
    }
    
    for(int i=0; i<4; i++)
        if(!st[i])                  // 如果没有使用
            if(a[i].count(t[x])){   // 如果骰子上有
                st[i]=1;
                dfs(u+1, x+1);
                st[i]=0;    // 恢复现场
            }
        else
            dfs(u+1, x);            // 不使用
    
}

int main(){
    cin>>n;
    
    cin>>t; for(char c: t) a[0].insert(c);
    cin>>t; for(char c: t) a[1].insert(c);
    cin>>t; for(char c: t) a[2].insert(c);
    cin>>t; for(char c: t) a[3].insert(c);
    
    while(n--){
        cin>>t;
        if(t.size() > 4){
            puts("NO");
            continue;
        }
        
        flg=0;
        for(int i=0; i<4; i++) st[i]=0;
        
        dfs(0, 0);
        if(flg)
            puts("YES");
        else
            puts("NO");
    }
    
    return 0;
}
```

</details>



## 2022 Jan


<details><summary><a href="https://www.acwing.com/problem/content/description/4332/" target="_blank">AcWing 4329. Herdle</a> code</summary> 

> 统计两个方阵中, 各个颜色的数量
> 先算绿的(同一位置同一颜色), 再算黄的(两个方块中, 减去绿色的数量, 取两个方块中的最小值)
> 

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int n, ans1, ans2;
int cnt1[26];
int cnt2[26];

string a[3], b[3];

int main(){
    for(int i=0; i<3; i++) cin>>a[i];
    for(int i=0; i<3; i++) cin>>b[i];
    
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cnt1[ a[i][j]-'A' ]++,
            cnt2[ b[i][j]-'A' ]++;
    
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if( a[i][j] == b[i][j] ){
                ans1++;
                cnt1[ a[i][j]-'A' ]--,
                cnt2[ b[i][j]-'A' ]--;
            }
        
    for(int i=0; i<26; i++)
        if(cnt1[i] && cnt2[i])
            ans2 += min(cnt1[i], cnt2[i]);
    
    cout<<ans1<<"\n"<<ans2;
    
    return 0;
}
```

</details>


<details><summary><a href="https://www.acwing.com/problem/content/description/4333/" target="_blank">AcWing 4330. 非传递骰子</a> code</summary> 

>
>

```cpp
#include <iostream>
using namespace std;

int a[5], b[5], c[5];
bool flg;

bool ck(int x[], int y[]){  // x赢 > y赢 1
    int res=0;
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++)
            if(x[i] > y[j]) res++;
            else if(y[j] > x[i]) res--;
    return res>0;
}

void dfs(int u){    // 当前赋值的
    if(flg) return ;
    if(u>4){
        
        if(ck(a, b) && ck(b, c) && ck(c, a))
            flg=1;
            
        if(ck(b, a) && ck(a, c) && ck(c, b))
            flg=1;
            
        return ;
    }
    
    for(int i=1; i<=10; i++){
        c[u]=i;
        dfs(u+1);
    }
    
    return ;
}

void solve(){
    flg=0;
    for(int i=1; i<=4; i++) scanf("%d", a+i);
    for(int i=1; i<=4; i++) scanf("%d", b+i);
    
    dfs(1); // 枚举 c 的可能
    
    if(flg) puts("yes");
    else puts("no");
    
    return ;
}

int main(){
    int T; cin>>T;
    while(T--) solve();
    return 0;
}
```

</details>


<details><summary><a href="https://www.acwing.com/problem/content/description/4334/" target="_blank">AcWing 4331. 大旱</a> 跳过</summary><br>

差分


</details>

## 2021 Dec


<details><summary><a href="https://www.acwing.com/problem/content/description/4264/" target="_blank">AcWing 4261. 孤独的照片</a> code</summary> 

> 孤独的牛: 长度>=3, 有且仅有 1 头牛与其他的牛不一样
> 显然, 只有三种情况
> ```
> 1. ___HGH____    孤独数：左边H*右边H
> 2. __HHG         孤独数：左边H-1
> 3.     GHH___    孤独数：右边H-1
> ```
> 因此，只需要统计每个点，左/右两边不一样的牛的数量
>

```cpp
#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;
const int N=5e5+10;

string s;
int n, l[N], r[N];

int main(){
    cin>>n>>s; s=" "+s;
    
    for(int i=1, cntH=0, cntG=0; i<=n; i++) // 左边
        if( s[i]=='H' ){
            l[i]=cntG;  // 左边G的数量（左边不同者的数量）
            cntH++;     // H的数量+1
            cntG=0;     // G被H截胡了，所以G归零
        }
        else            // 同上
            l[i]=cntH, cntG++, cntH=0;
    
    for(int i=n, cntH=0, cntG=0; i>=1; i--) // 右边
        if( s[i]=='H' ){
            r[i]=cntG;
            cntH++;
            cntG=0;
        }
        else
            r[i]=cntH, cntG++, cntH=0;
    
    LL ans=0;
    for(int i=1; i<=n; i++)
        ans += 1LL*l[i]*r[i] + max(0, l[i]-1)+ max(0, r[i]-1);
    
    cout<<ans;
    return 0;
}
```

</details>


<details><summary><a href="https://www.acwing.com/problem/content/description/4265/" target="_blank">AcWing 4262. 空调</a> code</summary> 

<br>

**大意**

给定两个长度为 $n$ 的数组，$p$ 与 $t$。
我们可以对 $t$ 执行一次操作，使得区间 $[i, j]$ 中的所有数 $+1$ 或者 $-1$。
最终使得数组 $t=p$，求最少的操作次数。

**思路**

1. 为了使得 $t=p$，对于第 $i$ 位而言，$t_i$ 只需要加上 $p_i-t_i$。
    $t_i+p_i-t_i=p_i$。
    因此，我们可以处理出来一个数组 $c$，其中 $c_i=p_i-t_i$。

现在的问题：将 $c$ 数组，操作成一个全 $0$ 的数组，求最少的操作次数。

2. 每次是对区间进行操作，因此，不妨对数组做一次差分，然后再考虑。
   分析一下样例，下面是已经求完差分后的数组 $c$。
   `2 0 -2 3 0` $->$ `0 0 0 3 0`：将第 $1$ 位 $-2$，第 $3$ 位 $+2$，操作 $2$ 次。
   `0 0 0 3 0` $->$ `0 0 0 0 0`：将第 $4$ 位 $-3$, 第 $6$ 位 $+3$，操作 $3$ 次。
    可以发现，差分后的数组，加减是对应的：如果我某一位加了 $6$，后面必然会减去 $6$。

因此，我们统计我们加的次数 $a$，和减的次数 $b$。
如果 $a=b$      操作次数是 $a$ 或 $b$。
如果 $a \neq b$ 操作次数是 $max(a, b)$。


```cpp
#include <iostream>
using namespace std;

const int N=2e5+10;

int n;
int p[N], t[N], c[N];

int main(){
    cin>>n;
    for(int i=1; i<=n; i++) scanf("%d", p+i);
    for(int i=1; i<=n; i++) scanf("%d", t+i);
    for(int i=1; i<=n; i++) c[i] = p[i] - t[i];
    for(int i=n; i>1; i--) c[i] = c[i] - c[i-1];
    
    int a=0, b=0;
    for(int i=1; i<=n; i++)
        if(c[i]>0) a+=c[i];
        else b+=abs(c[i]);

    cout<<max(a, b);
    return 0;
}
```

</details>


<details><summary><a href="https://www.acwing.com/problem/content/4266/" target="_blank">AcWing 4263. 走路回家</a> code</summary> 

<br>

**大意**

给定一个 $n \times n$ 大小的矩阵 $g$，对于每个点 $g[i][j]$，
有两种状态，可以到达和不可到达。
我们需要从 $(1,1)$ 点走到 $(n,n)$ 点，只能向下或者向右走，且转向次数 $\leq k$。
求到达 $(n,n)$ 点的方案次数。

**思路**

1.  我们先考虑，在转向次数不受限的情况下，走到 $(n,n)$ 点的方案数量。
    定义一个 $dp[i][j]$，代表到达 $(i,j)$ 点的方案数量。因此，有：

$$ dp[i][j] = dp[i-1][j] + dp[i][j-1] $$

2.  我们在此基础上，统计一下，到达 $(i,j)$ 的转向次数。
    显然，是不行的。因为不同方案到达 $(i,j)$ 的转向次数可能不同。
    顺着此思路继续考虑，我们是否可以统计，转向 $1,2,\cdots,k$ 次，到达 $(i,j)$ 的方案数量。
    很容易想到，定义一个 $dp[i][j][k]$，即到达 $(i,j)$ 点，转向 $k$ 次的方案数量。

只剩一个问题，如何判断，当前是否转向？

3.  在本题中，转向被定义为：
    * $(i,j-1) -> (i,j)$，$(i,j) -> (i+1,j)$
    * $(i-1,j) -> (i,j)$，$(i,j) -> (i,j+1)$
    因此，我们可以增加一个状态，康康 $(i,j)$ 是从上面来的，还是从左边来的。
    定义一个 $dp[i][j][k][op]$

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N=55;

int n, kk, ans;
string s;
int g[N][N], dp[N][N][5][2];

void solve(){
    cin>>n>>kk;
    ans=0;
    memset(g, 0, sizeof g);
    memset(dp, 0, sizeof dp);

    for(int i=1; i<=n; i++){
        cin>>s;
        for(int j=1; j<=n; j++)
            if(s[j-1]=='H') g[i][j]=1;
    }

    dp[1][1][0][0]=1; // 向右
    dp[1][1][0][1]=1; // 向下

    for(int i=1; i<=n; i++)             // 枚举所有的点
        for(int j=1; j<=n; j++){
            if(i==1 && j==1) continue;  // 忽略 (1,1)
            if(g[i][j]) continue;       // 如果不能到达
            
            for(int k=0; k<=kk; k++){   // 枚举所有的转向次数
                if ((i == 1 || j == 1) && k != 0) continue; // 初始化第一行第一列
                    dp[i][j][k][0] = dp[i][j-1][k][0];      // 继续向右
                    dp[i][j][k][1] = dp[i-1][j][k][1];      // 继续向下
                    if (k > 0)  // 允许上一步到这一步变向
                        dp[i][j][k][0] += dp[i][j-1][k - 1][1],   // 本来是向下的，现在向右走
                        dp[i][j][k][1] += dp[i-1][j][k - 1][0];   // 本来是向右的，现在向下走
            }
        }

    for (int k = 0; k <= kk; k ++ ) 
        ans += dp[n][n][k][0] + dp[n][n][k][1];
        
    printf("%d\n", ans);

    return ;
}

int main(){
    int T; cin>>T;
    while(T--) solve();
    return 0;
}
```

</details>

---




# <center>2020-2021 Season</center>

## 2021 US Open

<details><summary><a href="https://www.acwing.com/problem/content/3748/" target="_blank">AcWing 3745. 牛的学术圈 I</a> code</summary>

<br>

**大意**

给定一个数组 $c$，$c_i$ 是每篇文章被引用的次数。
我们可以使其中任意 $\leq L$ 篇文章引用次数 $+1$。
学术成就定义为 $h$：存在 $h$ 篇论文，引用次数 $\geq h$。
求最大的 $h$。

**思路**

1.  在不考虑 $L$ 的情况下，如果将文章引用次数按照降序排序，
    如果 $c[i] \geq i$，那么 $i$ 就是一个合法的 $H$，观察样例 `100 3 2 1`：
    * $c[1]$：存在 $1$ 篇论文，引用次数 $\geq 1$：`100`。
    * $c[2]$：存在 $2$ 篇论文，引用次数 $\geq 2$：`100 3`。
    * $c[3]$：不存在 $3$ 篇论文，引用次数 $\geq 3$：`100 3 2`。

2.  这个数组可以分为两部分，左边部分是合法，右边部分是不合法，
    显然，我们引用合法的论文，是不会增加我们的 $h$，
    我们需要将不合法论文中，较大的进行引用。

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

const int N=2e5+10;

int a[N];
int n, l;

int main(){
    cin>>n>>l;
    for(int i=1; i<=n; i++) scanf("%d", a+i);
    
    sort(a+1, a+1+n, greater());    // 从大到小排
    int i=1;
    while(a[i]>=i && i<=n-l) i++;   // 走过合法部分，同时后面必须留够 l 个
    for(int j=0; j<l; j++) a[i+j]++;// 引用选定的 l 个
    
    sort(a+1, a+1+n, greater());    
    i=1;                            
    while(a[i]>=i && i<=n) i++;     // 找到第一个不合法的地儿
    cout<<i-1;
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/3749/" target="_blank">AcWing 3746. 牛的学术圈 II</a> code</summary>

<br>

**大意**

给定 $k$ 行，每行 $n$ 个字符串。
$n$ 个字符串按照贡献从大到小，字典序从小到大给出。
规定，贡献越小，资历越大。
对于任意两个字符串，我们需要判断谁的资历更高，或者说无法判断。

**思路**

1.  对于一行字符串 $s[n]$，如果存在 $s_i > s_j (i<j)$，
    则可以断定 $s_i$ 的贡献大于 $s_j$。
    进而得出：$[1,i]$ 的贡献都大于 $[j,n]$。

2.  为了找出所有的关系，我们枚举 $j$，
    在 $[1,j)$ 范围中，找到 $s_i > s_j$：$[1,i]$ 的贡献都大于 $j$。

```cpp
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

const int N=110;

int g[N][N];
map<string, int> tr;
int k, n;

int main(){
    cin>>k>>n;
    for(int i=1; i<=n; i++){
        string t; cin>>t;
        tr[t] = i;  // t 是第 i 名成员
    }
    for(int l=1; l<=k; l++){
        string s[N];
        int flg=1;
        for(int j=1; j<=n; j++){
            cin>>s[j];
            if(s[j-1] > s[j]) flg=j;            // 当找到一个地方 s[i] > s[j]
            for(int i=1; i<flg; i++)            // [1-i]的贡献均大于 j
                g[ tr[s[i]] ][ tr[s[j]] ] = 1,
                g[ tr[s[j]] ][ tr[s[i]] ] = -1;   
        }
    }

    for(int i=1; i<=n; i++, cout<<"\n")
        for(int j=1; j<=n; j++)
            if(i==j) cout<<"B";
            else{
                if(g[i][j] == 1) cout<<"0";
                if(g[i][j] == -1) cout<<"1";
                if(g[i][j] == 0) cout<<"?";
            }

    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/3750/" target="_blank">AcWing 3747. 牛的学术圈 III</a> code</summary>

<br>

**大意**

给定一个 $N$ 行，$M$ 列的矩阵 $g$。
对于 $g[i][j]$，有三种状态：`C` `G` `.`。
对于 `G` 而言，其上下左右四个位置的 `C` ，可以在 `G` 处建立关系，
每个 `G` 只能使用一次，求建立不重复关系的最大数量。

**思路**

1. 每个 `G` 只能使用一次，那么我们从 `G` 的角度去考虑，枚举 `G`，
   同时统计 `G` 的四周有多少 `C`：
   `C` $< 2$：不会存在关系；
   `C` $= 2$：存在一对关系；
   `C` $> 2$：存在至少两对关系。

2. 此时，我们考虑一下，关系重复建立的情况：
   `C1` `G1`
   `G2` `C2`   
   显然，当出现类似上面的排列时，`C1` 和 `C2` 可以同时在 `G1`，`G2` 建立关系，
   因此，需要维护一下每一对关系。

3. 对于两个 `G`，他们最多只会重复一对儿关系。

```cpp
#define fst first
#define sed second
#include <iostream>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

const int N=1e3+10;
const int dxy[4][2]={ {-1,0},{1,0},{0,-1},{0,1} };

int n, m, ans;
string g[N];

set<pair<PII, PII>> only; // 一对唯一的奶牛

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>g[i];
        g[i] = " "+g[i];
    }
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(g[i][j] == 'G'){ // 如果有草
                
                vector<PII> cnt;
                for(int k=0; k<4; k++){
                    int nx = i + dxy[k][0];
                    int ny = j + dxy[k][1];
                    
                    if( g[nx][ny] == 'C' ) cnt.push_back({nx, ny});
                }
                
                if(cnt.size() > 2) ans++;
                if(cnt.size() == 2){
                    int x1 = cnt[0].fst, y1 = cnt[0].sed;
                    int x2 = cnt[1].fst, y2 = cnt[1].sed;
                    
                    if( only.count( { {x1,y1}, {x2,y2} } ) ||
                        only.count( { {x2,y2}, {x1,y1} } ) )
                        continue;
                    else{
                        ans++;
                        only.insert({ {x1,y1}, {x2,y2} });
                        only.insert({ {x2,y2}, {x1,y1} });
                    }
                }
            }
    
    cout<<ans;
    
    return 0;
}
```
</details>

## 2021 Feb

<1details><summary><a href="https://www.acwing.com/problem/content/description/3373/" target="_blank">AcWing 3370. 牛年</a> code</summary>

```cpp
#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

// 用来计算
unordered_map<string, int> u;
// 本来的
unordered_map<string, int> hhash={
    {"Ox", 0},
    {"Tiger", 1},
    {"Rabbit", 2},
    {"Dragon", 3},
    {"Snake", 4},
    {"Horse", 5},
    {"Goat", 6},
    {"Monkey", 7},
    {"Rooster", 8},
    {"Dog", 9},
    {"Pig", 10},
    {"Rat", 11}
};

int main(){
    
    // 以这玩意儿为基准
    u["Bessie"]=0;
    
    int _; cin>>_;
    while(_--){
        
        string str[10];
        for(int i=1; i<=8; i++) cin>>str[i];
        
        // 之前，str[1]在str[8]的左边
        if(str[4]=="previous"){
            // 后生的差值
            int x=u[ str[8] ];
            // 先生的生肖代码
            int y=hhash[ str[5] ];
    
            // 计算差
            int r=((x-y)%12+12)%12;
            if(r==0) r=12;
            
            u[ str[1] ] = x-r;
        }
        // 之后，str[1]在str[8]的右边
        else{
            // 先生的差值
            int x=u[ str[8] ]; 
            // 后生的生肖代码
            int y=hhash[ str[5] ];
            
            // 计算差
            int r=((y-x)%12+12)%12;
            if(r==0) r=12;
            
            u[ str[1] ] = x+r;
        }
        
    }
    
    cout<<abs(u["Elsie"]);
    
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/3374/" target="_blank">AcWing 3371. 舒适的奶牛</a> code</summary>

```cpp
#pragma GCC optimize(3, "inline", "Ofast")

#include <stdio.h>

//int N=1010;

int g[1010][1010];
int f[1010][1010]; // 记录这个位置的牛是否舒适

int dxy[4][2]={ {-1,0}, {1,0}, {0,-1}, {0,1} };

// 每一次加入后，只会影响上下左右四个方向的奶牛舒不舒服
// 那么再check一下

// 检查(x,y)奶牛舒服
int check(int x, int y){
    int res=0;
    
    for(int i=0; i<4; i++){
        int nx=x+dxy[i][0];
        int ny=y+dxy[i][1];
        
        if( nx<0 || ny <0 ) continue;
        
        if(g[nx][ny]==1)
            res++;
    }
    
    if(res==3) return 1;
    return 0;
}

int main(){
    int n, ans=0;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        g[a][b]=1;
        
        // 检查这头牛
        if( check(a, b) ) ans++, f[a][b]=1;
        
        // 检查周围四头牛
        for(int i=0; i<4; i++){
            int nx=a+dxy[i][0];
            int ny=b+dxy[i][1];
            
            // 有牛, 舒服, 没被舒服过
            if(g[nx][ny] && check(nx, ny) && f[nx][ny]==0){
                ans++;
                f[nx][ny]=1;
                continue;
            }
            
            // 有牛,不舒服了,曾经舒服过
            if(g[nx][ny] && check(nx, ny)==0 && f[nx][ny]==1){
                ans--;
                f[nx][ny]=0;
                continue;
            }
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
```
</details>


<details><summary><a href="https://www.acwing.com/problem/content/3375/" target="_blank">AcWing 3372. 顺时针围栏</a> code</summary>

```cpp
#include <iostream>
#include <string>
using namespace std;

const int N=2e5+10;

string solve(){
    int res=0;
    string s; cin>>s;
    for(int i=0; i<s.size()-1; i++)
        if(s[i] != s[i+1]){
            string t = string(1, s[i]) + string(1, s[i+1]);
            if(t=="NE" || t=="ES" || t=="SW" || t=="WN") res++;
            else res--;
        }

    if(res>0) return "CW";
    return "CCW";
}

int main(){
    int T; cin>>T;
    while(T--) cout<<solve()<<"\n";
    return 0;
}
```
</details>

## 2021 Jan

<details><summary><a href="https://www.acwing.com/problem/content/description/3361/" target="_blank">AcWing 3358. 放养但没有完全放养</a> code</summary>

```cpp
#include <iostream>
#include <cstring>
using namespace std;

string str, sub;

int main(){
    cin>>str>>sub;
    
    int i=0;
    int ans=0;
    
    while(i<sub.size()){
        
        
        for(int j=0; j<str.size(); j++)
            if(sub[i]==str[j]){
                i++;
            }
        
        ans++;
    }
    
    cout<<ans;
    
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/3362/" target="_blank">AcWing 3359. 更多奇怪的照片</a> code</summary>

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

// 奇数、偶数的数量
int odd, even;

int main(){
    int n;
    cin>>n;
    for(auto i=1; i<=n; i++){
        int t;
        scanf("%d", &t);
        
        if(t&1) 
            odd++;
        else
            even++;
    }
    // 我有奇数的个数
    // 有偶数的个数
    // 那么他们相同的部分，一定可以配 min(odd, even)*2 组数
    // 剩下 a = abs(odd-even) 数量的 全奇 或者 全偶
    // 若全奇
    //      （偶数个）2个奇数的和是偶数
    //      显然，我们必定可以配出 (a/3)*2 组 
    //      对于没使用的奇数，一个会影响俩，直接ans--
    //      如果 a - int(a/3) * 2 >=1 , ans -= ( a - int(a/3) * 2 )
    // 若全偶
    //      不管了，再加一个
    
    int ans=min(odd, even)*2;
    
    //cout<<odd<<" "<<even<<endl;
    
    if(odd>even){
        int a=abs(odd-even);
        
        //cout<<a<<endl;
        
        ans += (int(a/3))*2;    // 全奇配的
        
        //cout<<ans;
        
        a -= ( int(a/3)*3 );    // 剩余的
        
        if(a==2)
            ans++;
        else if(a==1)
            ans--;
    }
    else if(even>odd)
        ans++;
    
    cout<<ans;
    
    return 0;
}
```
</details>

## 2020 Dec

<details><summary><a href="https://www.acwing.com/problem/content/description/3349/" target="_blank">AcWing 3346. 你知道你的ABC吗</a> code</summary>

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n[10];
int used[10];

int main(){
    for(int i=1; i<=7; i++)
        cin>>n[i];
    sort(n+1, n+8);
    
    do{
        sort(n+1, n+4);
        
        // a+b
        if( n[1]+n[2] != n[4] ) continue;
        // b+c
        if( n[2]+n[3] != n[5] ) continue;
        // a+c
        if( n[1]+n[3] != n[6] ) continue;
        // a+b+c
        if( n[1]+n[2]+n[3] != n[7] ) continue;
        
        for(int i=1; i<=3; i++)
            cout<<n[i]<<" ";
        break;
        
    }
    while(next_permutation(n+1, n+7));
    
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/3350/" target="_blank">AcWing 3347. 菊花链</a> code</summary>

```cpp
#include <iostream>
using namespace std;

const int N=1010;

int hua[N];

int main(){
    int n=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        scanf("%d", &hua[i]);
        hua[i]+=hua[i-1];     // 做一个前缀和
    }
    
    int res=n; // 提前一朵花 
    
    for(int j=1; j<=n; j++){
        for(int i=1; i<j; i++){ // 这里取消等号 等于的时候是一朵花
            // i-j的照片
            int all=hua[j]-hua[i-1]; // 花瓣数量
            int duo=j-i+1;           // 花朵数量
            double pp=(double)all/duo;
            int p=all/duo;
            //cout<<i<<"-"<<j<<":"<<pp<<endl;
            if( pp-p>1e-6 )continue;
            

            // 检查花k是否是平均的花
            for(int k=i; k<=j; k++)
                if( p==(hua[k]-hua[k-1]) ){
                    res++;
                    break;
                }
            
        }
    }
    
    cout<<res;
    
    return 0;
}
```
</details>

---

# <center>2019-2020 Season</center>

## 2020 US Open

## 2020 Feb

<details><summary><a href="https://www.acwing.com/problem/content/1673/" target="_blank">AcWing 1671. 三角形</a> code</summary>

```cpp
#pragma GCC optimize(2, 3, "Ofast", "inline")

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

#define x first
#define y second

PII a[110];

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) scanf("%lld%lld", &a[i].x, &a[i].y);
    
    LL ans=-1;
    
    for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
    for(int k=1; k<=n; k++)
        if(a[i].x==a[j].x && a[j].y==a[k].y)
            ans=max(ans,  llabs(a[j].y-a[i].y)*llabs(a[k].x-a[j].x)  );
        
    cout<<ans;
    
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/1674/" target="_blank">AcWing 1672. 疯狂的科学家</a> code</summary>

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int N=1e3+10;

string A, B;

int main(){
    int n;
    cin>>n;
    cin>>A>>B;
    
    int res=0;
    for(int i=0; i<A.size(); i++){
        
        if(A[i]!=B[i]){
            i++;
            while(A[i]!=B[i]) i++;
            i--;
            res++;
        }
    
    }
    
    cout<<res;
    
    return 0;
}
```
</details>

## 2020 Jan

<details><summary><a href="https://www.acwing.com/problem/content/1444/" target="_blank">AcWing 1442. 单词处理器</a> code</summary>

```cpp
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    string str;
    int a=0;
    for(int i=1; i<=n; i++){
        cin>>str;
        
        if( str.size()+a > k ){
            cout<<endl;
            a=0;
        }
        
        cout<<str<<" ";
        a+=str.size();
    }
    
    
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/1445/" target="_blank">AcWing 1443. 拍照</a> code</summary>

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

const int N=1e3+10;

int a[N], b[N];

int main(){
    int n=0;
    cin>>n;
    for(int i=1; i<n; i++) scanf("%d", &b[i]);
    
    for(int k=1; k<=n; k++){          
        unordered_map<int, int> hash; 
                // 记录某个数字是否出现
        a[1]=k; // 第一个数字是k
        hash[k]++;
        
        int i=2;
        for( ; i<=n; i++){
            a[i]=b[i-1]-a[i-1];
            
            if(hash[a[i]]) break;        // 位置重复的牛
            if(a[i]<=0 || a[i]>n) break; // 不该出现的牛
            
            hash[a[i]]++;
        }
        
        if(i>n) break; // a排序完成
    }
    
    for(int i=1; i<=n; i++) cout<<a[i]<<" ";
    
    return 0;
}
```
</details>

## 2019 Dec

<details><summary><a href="https://www.acwing.com/problem/content/1461/" target="_blank">AcWing 1459. 奶牛体操</a> code</summary>

```cpp
#include <iostream>
using namespace std;

const int N=30;

int a[N][N];

int main(){
    int k, n;
    cin>>k>>n;
    // k次训练
    // n头奶牛
    for(int i=1; i<=k; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &a[i][j]);
    
    int ans=0;
    
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++){
            
            // x必须先出现
            int x=a[1][i], y=a[1][j];
            
            bool flg = 1;
            // 遍历其余次训练情况
            for(int m=2; m<=k && flg; m++)
                for(int t=1; t<=n; t++)
                    if( a[m][t] == y){
                        flg=0;
                        break;
                    }
                    else if( a[m][t] == x )
                        break;
            
            if(flg) ans++;
        }
    
    cout<<ans;
    
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/1462/" target="_blank">AcWing 1460. 我在哪？</a> code</summary>

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int n, ans;
string s;

bool ck(int res){
    set<string> H;
    for(int i=0; i+res<=n; i++)
        if(H.count(s.substr(i, res))) return 0;
        else H.insert(s.substr(i, res));
    return 1;
}

int main(){
    cin>>n>>s;
    for(ans=1; ans<n; ans++)
        if( ck(ans) ) break;
    cout<<ans;
    return 0;
}
```
</details>


---

# <center>2018-2019 Season</center>

## 2019 US Open

<details><summary><a href="https://www.acwing.com/problem/content/1472/" target="_blank">AcWing 1470. 水桶传递队列</a> code</summary>

```cpp
#define fst first
#define sed second

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

char g[15][15];  // 地图
int used[15][15];// 是否到达过
int ans[15][15]; // 到达该点的最短路径
int dxy[4][2]={ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

// 结束点
int ex, ey;
// 开始点
int sx, sy;

void BFS(int x, int y){
    
    queue<PII> q;
    q.push( {x, y} );
    used[x][y]=1;
    
    while( q.size() ){
        
        int nx = q.front().fst;
        int ny = q.front().sed;
        
        for(int i=0; i<4; i++){
            int nnx = nx+dxy[i][0];
            int nny = ny+dxy[i][1];
            
            if(nnx>=1&&nnx<=10 && nny>=1&&nny<=10)
            if(used[nnx][nny]==0)
            if(g[nnx][nny]!='R')
            {
                ans[nnx][nny]=ans[nx][ny]+1;
                used[nnx][nny]=1;
                q.push( {nnx, nny} );
                if(g[nnx][nny]=='B') return ;
            }
            
        }
        
        q.pop();
    }
    
}

int main(){
    
    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++){
            scanf("%c", &g[i][j]);
            if(g[i][j]=='L')
                sx=i, sy=j;
            if(g[i][j]=='B')
                ex=i, ey=j;
        }
        getchar();
    }
    
    BFS(sx, sy);
    
    cout<<ans[ex][ey]-1;
    
    return 0;
}
```
</details>


## 2019 Feb

<details><summary><a href="https://www.acwing.com/problem/content/1685/" target="_blank">AcWing 1683. 困牛放牧</a> code</summary>

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int a[3];

int main(){
    cin>>a[0]>>a[1]>>a[2];
    sort(a, a+3);
    
    if(a[1]-a[0]==1 && a[2]-a[1]==1){ // 6 7 8
        cout<<0<<endl<<0;
        return 0;
    }
    
    int mmin=0;
    int mmax = max(a[2]-a[1]-1, a[1]-a[0]-1);
    
    if(a[1]-a[0]==2 || a[2]-a[1]==2)
        mmin=1;
    else
        mmin=2;
    
    cout<<mmin<<endl<<mmax;
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/1686/" target="_blank">AcWing 1684. 大型植被恢复</a> code</summary>

```cpp
#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

#define x first
#define y second
typedef pair<int, int> PII;

// 每只奶牛喜欢的两块草地
PII a[160];
// 每块草地种的草
int res[110];
// 该草地不能和那些草地的草相同
vector<int> ad[110];

int main(){
    int n, m;
    cin>>n>>m;
    
    for(int i=1; i<=m; i++){
        scanf("%d%d", &a[i].x, &a[i].y);
        ad[a[i].x].pb(a[i].y);
        ad[a[i].y].pb(a[i].x); // 1号草场的不能和5，6冲突
    } 
    
    for(int i=1; i<=n; i++){
        
        // 从四块草地里选
        for(int d=1; d<=4; d++){
            
            bool flag=1;
            for(int j=0; j<ad[i].size(); j++)
                if(res[ ad[i][j] ]==d){ // 冲突
                    flag=0;
                    break;
                }
            
            if(flag){
                res[i]=d;
                break;
            }            
        }
        
    }
    
    for(int i=1; i<=n; i++)
        cout<<res[i];
    
    return 0;
}
```
</details>

## 2019 Jan

<details><summary><a href="https://www.acwing.com/problem/content/1697/" target="_blank">AcWing 1695. 果壳游戏</a> code</summary>

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

// 小模拟
int arr[110][4];
int n;

// 在第 u 个壳下面
int ke(int u){
    int k[4]={0};
    k[u]=1;
    int res=0;
    
    for(int i=1; i<=n; i++){
        
        swap(k[ arr[i][1] ], k[ arr[i][2] ]);
        if(k[ arr[i][3] ]) res++;
    }
    //cout<<res<<endl;
    return res;
}

int main(){
    
    cin>>n;
    for(int i=1; i<=n; i++) scanf("%d%d%d", &arr[i][1], &arr[i][2], &arr[i][3]);
    
    int ans=0;
    for(int i=1; i<=3; i++)
        ans = max( ans, ke(i) );
    
    cout<<ans;
    
    return 0;
}
```
</details>

## 2018 Dec

<details><summary><a href="https://www.acwing.com/problem/content/1716/" target="_blank">AcWing 1714. 混合牛奶</a> code</summary>

```cpp
#include <iostream>
using namespace std;

int C[5], M[5];

int main(){
    for(int i=1; i<=3; i++)
        scanf("%d%d", &C[i], &M[i]);
    
    for(int i=1; i<=33; i++){
        // 桶1 到 桶2
        int t=M[1]+M[2];
        if( t>C[2] ){   // 不够装
            M[2]=C[2];  // 装满
            M[1]=t-M[2];// 桶1的奶
        }
        else{
            M[1]=0;
            M[2]=t;
        }
        
        // 桶2 到 桶3
        t=M[2]+M[3];
        if( t>C[3] ){   // 不够装
            M[3]=C[3];  // 装满
            M[2]=t-M[3];// 桶2的奶
        }
        else{
            M[2]=0;
            M[3]=t;
        }
        
        // 桶3 到 桶1
        t=M[3]+M[1];
        if( t>C[1] ){   // 不够装
            M[1]=C[1];  // 装满
            M[3]=t-M[1];// 桶3的奶
        }
        else{
            M[3]=0;
            M[1]=t;
        }
        
    }
    
    // 桶1 到 桶2
    int t=M[1]+M[2];
    if( t>C[2] ){   // 不够装
        M[2]=C[2];  // 装满
        M[1]=t-M[2];// 桶1的奶
    }
    else{
        M[1]=0;
        M[2]=t;
    }
    
    cout<<M[1]<<endl<<M[2]<<endl<<M[3];
    
    return 0;
}
```
</details>


<details><summary><a href="https://www.acwing.com/problem/content/1717/" target="_blank">AcWing 1715. 桶列表</a> code</summary>

```cpp
#include <iostream>
using namespace std;

int arr[1010];

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        
        arr[a]+=c;
        arr[b]-=c;
    }
    
    int ans=0;
    
    for(int i=1; i<=1000; i++){
        arr[i]+=arr[i-1];
        ans=max(ans, arr[i]);
    }
    
    cout<<ans;
    
    return 0;
}
```
</details>

---


# <center>2017-2018 Season</center>