## 2023

### JT1 小苹果

<a href="https://www.luogu.com.cn/problem/P9748" target="_blank">Luogu P9748 [CSP-J 2023] 小苹果</a> | <a href="" target="_blank">视频解析</a>

* 题目大意

    1. 给定 $1,2,3,...,n-1,n$，总共 $n$ 个数。

    2. 从 **第 $1$ 个数** 开始，每隔 $2$ 个数取走一个，即取走 $1,4,7...$（记为 $1$ 天）。

    3. 剩下的数为 $2,3,5,6...$；重复上述操作，直到取走 $n$。

    5. 问，第几天会取完 $n$，第几天会取走 $n$ ？

* 解题思路

    1. 因为每隔 $2$ 个数取走一个，我们不妨将其 $3$ 个一组进行考虑。

        1. `1 2 3 | 4 5 6 | 7`，当 $n = 7 (n \% 3 = 1)$ 时，在第 $1$ 天取走 $n$，取走 $\lceil \frac{n}{3} \rceil = 3$ 个数；

            `2 3 5 | 6 `，继续取数，在第 $2$ 天取走 $\lceil \frac{n}{3} \rceil = 2$ 个数；

            `3 5`，继续取数，在第 $3$ 天取走 $\lceil \frac{n}{3} \rceil = 2$ 个数；

            `5`，继续取数，在第 $4$ 天取走所有的数。

        2. `1 2 3 | 4 5 6 | 7 8`，当 $n = 8 (n \% 3 = 2)$ 时，第 $1$ 天结束，取走 $\lceil \frac{n}{3} \rceil = 3$ 个数；

            `2 3 5 | 6 8`，此时 $n = 5 (n \% 3 = 2)$，第 $2$ 天结束，取走 $\lceil \frac{n}{3} \rceil = 2$ 个数；

            `3 5 8`，此时 $n = 3 (n \% 3 = 0)$，第 $3$ 天结束，取走 $\lceil \frac{n}{3} \rceil = 1$ 个数；

            `5 8`，此时 $n = 2 (n \% 3 = 2)$，第 $4$ 天结束，取走 $\lceil \frac{n}{3} \rceil = 1$ 个数；

            `8`，此时 $n = 1 (n \% 3 = 1)$，在第 $5$ 天取走 $n$，取走所有的数。
        
        3. `1 2 3 | 4 5 6 | 7 8 9`，可以用上述相同的方法分析。

    2. 可以发现，我们重复取数的过程，当第一次 $n \% 3 = 1$，就是取走 $n$ 之时，取走所有数的花费就是不断取走 $\lceil \frac{n}{3} \rceil$ 个数，看多少次操作后 $n$ 为 $0$；

<details><summary>代码</summary>

```cpp
#include <iostream>
using namespace std;

int n, ans1, ans2;

int main(){
    cin >> n;
    while(n){
        ans1 ++;
        if(n%3 == 1 && !ans2) ans2 = ans1;
        n -= (n+2)/3;
    }
    cout << ans1 << " " << ans2;
    return 0;
}
```
</details><br>


### JT2 公路

<a href="https://www.luogu.com.cn/problem/P9749" target="_blank">Luogu P9749 [CSP-J 2023] 公路</a> | <a href="" target="_blank">视频解析</a>

* 题目大意

    1. 给定 $n$ 个站点，第 $i$ 个站点到第 $i+1$ 个站点间的距离为 $v[i]$。

    2. 站点 $i$ 的油价为 $a[i]$，初始时油箱为空，油箱可以装任意多的油，$1$ 单位油可以前进 $d$。

    3. 问，从站点 $1$ 到站点 $n$ 最少需要花费多少钱加油？

* 解题思路

    1. 对于 $i$ 站点后面的 $j$ 站点，无外乎三种情况：

        1. 油价大于 $a[i]$，那么不如在 $i$ 站点加油；

        2. 油价等于 $a[i]$，那么在哪里加油都一样；

        3. 油价小于 $a[i]$，那么肯定在 $j$ 站点加油。
    
    2. 因为最开始油箱为空，必须在 $1$ 站点加油，那么我们需要找到一条油价的 **下降序列**。

    3. 此种贪心方法不会陷入局部最优，因为为了到达 `j` 站点，必须在 `i` 站点加足量的油。

<details><summary>代码</summary>

```cpp
#define fst first
#define sed second
#include <iostream>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

const int N = 1e5+10;

LL v[N], a[N];
LL n, d;
LL ans;

PII p[N];
LL m;

int main(){
    cin >> n >> d;
    for(int i=2; i<=n; i++) cin >> v[i];    // v[i] = 到上一个站点的距离
    for(int i=1; i<=n; i++) cin >> a[i];    // 油价
    a[n] = -1;  // 最后一个站点肯定不需要加油，但是我们希望能到达最后一个站点

    p[++m] = {a[1], v[1]};
    LL len = 0;
    for(int i=2; i<=n; i++){
        len += v[i];
        if(a[i] < p[m].fst){    // 出现了更优惠的油价
            p[++m] = {a[i], len};
            len = 0;
        }
    }

    /*
    for(int i=1; i<=m; i++)
        cout << p[i].fst << " " << p[i].sed << "\n";
    */

    LL l = 0;   // 上次加油剩余的距离
    for(int i=1; i<m; i++){
        // 加油量 = (距离(p[i+1].sed) - l) / 消耗(d)
        // 花费 = 加油量 * p[i].fst 
        // 多余距离 = 加油量 * d + l - 距离(p[i+1].sed)
        LL addoil = (p[i+1].sed - l + d-1) / d;
        ans += addoil * p[i].fst;
        l = addoil * d + l - p[i+1].sed;
    }
    
    cout << ans;

    return 0;
}
```
</details><br>

### JT3 一元二次方程

<a href="https://www.luogu.com.cn/problem/P9750" target="_blank">Luogu P9750 [CSP-J 2023] 一元二次方程</a> | <a href="" target="_blank">视频解析</a>

* 题目大意

    1. 模拟

* 解题思路

    1. 见代码

<details><summary>代码</summary>

```cpp
#define fst first
#define sed second
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int, int> PII;

int a, b, c, d;

PII simple(int p, int q){   // 约分
    int pq = __gcd(abs(p), abs(q));
    return {p/pq, q/pq};
}

void solve(){
    cin >> a >> b >> c;
    d = b*b - 4*a*c;    // delta

    if(d < 0){          // 1. 无解
        printf("NO\n");
    }else if(d == 0){   // 2. 单解 -b / 2a
        PII res = simple(-b, 2*a);
        if(a < 0) res = {-res.fst, -res.sed};       // 负数情况
        if(res.sed == 1) printf("%d\n", res.fst);   // 2.1 分母为 1
        else printf("%d/%d\n", res.fst, res.sed);   // 2.2 分母不为 1
    }else{              // 3. 两解 -b(+-sqrt(d)) / 2a
        if(int sd = sqrt(d); sd*sd == d){           // 3.1 sqrt(d) 为整数
            PII res;
            if(a>0) res = simple(-b + sd, 2*a);     // 确定谁在前面
            else    res = simple(-b - sd, 2*a);
            if(a < 0) res = {-res.fst, -res.sed};       // 负数情况
            if(res.sed == 1) printf("%d\n", res.fst);   // 3.1.1 分母为 1
            else printf("%d/%d\n", res.fst, res.sed);   // 2.1.2 分母不为 1    
        }else{                                      // 3.2 sqrt(d) 不为整数
            // 有理数部分约分
            PII res = simple(-b, 2*a);
            if(a < 0) res = {-res.fst, -res.sed};       // 负数情况
            // 处理有理数部分 -b / 2a 
            if(res.fst != 0){
                if(res.sed == 1) printf("%d+", res.fst);
                else printf("%d/%d+", res.fst, res.sed);
            }
            // 处理无理数部分 sd / 2a
            res = {1, abs(2*a)};
            int t = 0;                  // 剩下的无理部分
            for(int r=sd; r>=1; r--)    
                if(d % (r*r) == 0) {    // 找到一个平方因子，sqrt(27) = 3 sqrt(3)
                    res.fst *= r;
                    t = d / (r*r);
                    break;
                }
            // 约分
            res = simple(res.fst, res.sed);

            if(res.fst == res.sed) printf("sqrt(%d)\n", t);
            else if(res.sed == 1)  printf("%d*sqrt(%d)\n", res.fst, t);
            else if(res.fst == 1)  printf("sqrt(%d)/%d\n", t, res.sed);
            else printf("%d*sqrt(%d)/%d\n", res.fst, t, res.sed);
        }
    }
}

int main(){
    int T, M; cin >> T >> M; while(T--)
    solve();
    return 0;
}
```
</details><br>



### JT4 

<a href="https://www.luogu.com.cn/problem/P9751" target="_blank">Luogu P9751 [CSP-J 2023] 旅游巴士</a> | <a href="" target="_blank">视频解析</a> | <a href="https://mp.weixin.qq.com/s?__biz=MzI1NTA2MDk5MA==&mid=2457235257&idx=1&sn=fc630a7217480236d78c8cf846461ab8&chksm=fca224999ffb25c9c10a67e73a5509c00857b47b272f89ca790c6f503d240ec7ae0a28270716&mpshare=1&scene=23&srcid=0915H7wD6F3QO8tiBooB99q5&sharer_shareinfo=38e5e9814b3e62dabeeee8ecc9d5b3a4&sharer_shareinfo_first=38e5e9814b3e62dabeeee8ecc9d5b3a4#rd" target="_blank">推荐阅读</a>

* 题目大意

    1. 给定

* 解题思路

    1. 假设

<details><summary>代码</summary>

```cpp

```
</details><br>

---

## 2016

### JT1 买铅笔

<a href="https://www.luogu.com.cn/problem/P1909" target="_blank">Luogu P1909 [NOIP2016 普及组] 买铅笔</a> | <a href="" target="_blank">视频解析</a>

* 题目大意

    1. 给定

* 解题思路

    1. 假设

<details><summary>代码</summary>

```cpp
#include <iostream>
using namespace std;

int n;

int main(){
    cin>>n;
    int ans = 0x3f3f3f3f;
    for(int i=1; i<=3; i++){
        int a, b; cin>>a>>b;
        ans = min(ans,  b * ((n+a-1)/a) );
    }
    cout<<ans;
    return 0;
}
```
</details><br>

### JT2 回文日期

<a href="https://www.luogu.com.cn/problem/P2010" target="_blank">Luogu P2010 [NOIP2016 普及组] 回文日期</a> | <a href="" target="_blank">视频解析</a>

* 题目大意

    1. 给定一个起始日期和一个终止日期，求这两个日期之间有多少个回文日期，即满足：
        
        1. `YYYYMMDD` 是合法的日期；
        
        2. `YYYYMMDD` 是回文。

* 解题思路

    1. 对于回文类型的题目，我们首先考虑列举出所有的回文，然后再判断是否合法，而不是列举出所有的合法日期，然后再判断是否回文。

    2. 通过 `YYYY` 直接生成 `YYYYMMDD` 的回文
    
    3. 判断 `YYYYMMDD` 是否合法

<details><summary>代码</summary>

```cpp
#include <iostream>
using namespace std;

int a, b, ans;

int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool ck(int y, int m, int d){
    if((y*1e4+m*1e2+d)<a || (y*1e4+m*1e2+d)>b) return 0;
    
    months[2]=28;
    if(y%400==0 || y%4==0 && y%100!=0) months[2]=29;
    if(m<1 || m>12) return 0;
    if(d<1 || d>months[m]) return 0;
    return 1;
}

int main(){
    cin>>a>>b;
    
    for(int i=a/10000; i<=b/10000; i++)
        if( ck(i, (i%10)*10+(i/10%10), (i/100%10)*10+(i/1000)) ) ans++;

    cout<<ans;
    
    return 0;
}
```
</details><br>


### JT3 海港

<a href="https://www.luogu.com.cn/problem/P2058" target="_blank">Luogu P2058 [NOIP2016 普及组] 海港</a> | <a href="" target="_blank">视频解析</a>

* 题目大意

    1. 给定 $n$ 条信息，每条信息 $t, k, x_1, x_2, ... , x_k$： 

        * $t$ 时间，$k$ 个人，第 $i$ 个人的国籍为 $x_i$。

    2. 问，对于每条信息，在 $(vt, t+86400]$ 时间内，有多少种国籍？

* 解题思路

    1. 将所有的信息保存下来，按照时间排序（也就是题目给的顺序）；

    2. 对于每条信息，该条船上的人的国籍肯定需要考虑；

    3. 对于每条信息，回望过去，是否有船超过了时间范围：
        
        * 没有超过，那么就不用考虑；
        
        * 超过了，那么就需要将这条船上的人干掉。

<details><summary>代码</summary>

```cpp
#define pb push_back
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int N = 1e5+10;

vector<int> a[N];   // 每条船上人的国籍
int T[N];           // 每条船到达的时间
int n;
map<int, int> ans;

int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        int m;
        cin>>T[i]>>m;
        for(int j=1; j<=m; j++){
            int x; cin>>x;
            a[i].pb(x);
        }
    }

    queue<int> q;               // 每条信息
    for(int i=1; i<=n; i++){    // 遍历每条信息
        q.push(i);              // 对于第 i 条船，肯定要考虑
        for(auto &j: a[i]) ans[j]++;    // 国籍数量

        // 如果队头的船，不在时间范围内内，干掉
        while( T[i] - T[q.front()] >= 86400){
            for(auto &k: a[q.front()]){
                ans[k]--;
                if(ans[k] == 0) ans.erase(k);
            }
            q.pop();
        }
        cout<<ans.size()<<"\n";
    }

    return 0;
}
```
</details><br>