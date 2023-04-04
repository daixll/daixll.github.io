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






# <center> 2022-2023 Season </center>

## 2023 US Open
## 2023 Feb
## 2023 Jan

<a href="" target="_blank">-</a>



## 2022 DEC



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

<details><summary><a href="https://www.acwing.com/problem/content/4823/" target="_blank"> AcWing 4820. 逆向工程</a> code</summary>

> 枚举可能的第一个分支代码，筛选出剩余的行，继续枚举第二个分支


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


<details><summary><a href="" target="_blank">AcWing </a> code</summary> 

>
>

```cpp

```

</details>


<details><summary><a href="" target="_blank">AcWing </a> code</summary> 

>
>

```cpp

```

</details>

## 2021 DEc


<details><summary><a href="" target="_blank">AcWing </a> code</summary> 

>
>

```cpp

```

</details>


<details><summary><a href="" target="_blank">AcWing </a> code</summary> 

>
>

```cpp

```

</details>


<details><summary><a href="" target="_blank">AcWing </a> code</summary> 

>
>

```cpp

```

</details>

---


