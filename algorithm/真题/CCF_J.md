---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 2022



J-1

<details><summary><a href="" target="_blank"></a> 16</summary>

```cpp
#include <iostream>

using namespace std;

int main(){
    unsigned short x, y;
    cin >> x >> y;
    x = (x | x << 2)& 0x33;
    x = (x | x << 1)& 0x55;
    y = (y | y << 2)& 0x33;
    y = (y | y << 1)& 0x55;
    unsigned short z = x | y << 1;
    cout << z << endl;
    return 0;
}
```

> 删去第 7 行与第 13 行的 unsigned，程序行为不变。

无符号数与有符号数，范围不同，但此题 `假设输入的 x,y 均是不超过 15 的自然数`。

> 将第 7 行与第 13 行的 short 均改为 char，程序行为不变。

显然，当输入 `10 11` 的时候，x = (char)1， y = (char)0，与程序原意不符。

> 程序总是输出一个整数“0”。

假设输入 `2 2`
x=2，y=2：`x<<2 = 8`，`8 | 2 = 10`，`x = 10 & 0x33 = 2`
x=2，y=2：`x<<1 = 4`，`4 | 2 = 6`，`x = 6 & 0x55 = 4`
x=4，y=2：`y<<2 = 8`，`8 | 2 = 10`，`y = 10 & 0x33 = 2`
x=4，y=2：`y<<1 = 4`，`4 | 2 = 6`，`y = 6 & 0x55 = 4`
x=4，y=4：`x | y << 1 = 4 | 4 << 1 = 4 | 8 = 12`
输出为 `12`，与题意不符

</details>

<details><summary><a href="" target="_blank"></a> 17</summary>

```cpp

```
</details>


<br>

J-2

<details><summary><a href="https://www.acwing.com/problem/content/description/4731/" target="_blank">AcWing 4728. 乘方</a> code</summary>

```cpp
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

int main(){
    int a, b, c;
    cin>>a>>b;
    c=pow(a, b);
    
    LL A=a, B=b, C=pow(A, B);
    
    if(c<=1000000000 && C<=1000000000 && C==c)
        cout<<c;
    else
        cout<<-1;
    
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/description/4732/" target="_blank">AcWing 4729. 解密</a> code</summary>

```cpp
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

// 枚举 O(sqrt(n)k) 6/10
void solve1(){
    int k; cin>>k;
    while(k--){
        LL n, e, d, m, p, q;
        scanf("%lld%lld%lld", &n, &d, &e);
        
        bool flg=0;
        m=n-e*d+2;
        for(p=1; p<=sqrt(n); p++){
            q=n/p;
            if(m==p+q && p*q==n){
                printf("%lld %lld\n", p, q);
                flg=1;
                break;
            }
        }
        if(!flg) puts("NO");
        
    }
}

// 二分 O(klog(m/2))
void solve2(){
    int k; cin>>k;
    while(k--){
        LL n, e, d, m, p, q;
        scanf("%lld%lld%lld", &n, &d, &e);
        
        m=n-e*d+2;
        int l=1, r=m/2;
        while(l<=r){
            p=(l+r)>>1;
            q=m-p;
            if(n==p*q) break;
            
            if(n<p*q) r=p-1;
            else l=p+1;
        }
        if(n==p*q) printf("%lld %lld\n", p, q);
        else puts("NO");
        
    }
}

// 数学 O(k)
void solve3(){
    int k; cin>>k;
    while(k--){
        LL n, e, d, m, p, q;
        scanf("%lld%lld%lld", &n, &d, &e);
        
        // e*d=(p-1)(q-1)+1
        // n/p+p=n-e*d+2=m
        // n/p+p=m 
        // -> n+p^2=mp
        // -> p^2-mp+n=0 -> [a=1, b=-m, c=n]
        m=n-e*d+2;
        
        if(pow(m,2)-4*n < 0)
            puts("NO");
        else{
            LL delta = pow(m,2)-4*n;
            p = (m-sqrt(delta)+1)/2; // 向上取整
            q = n/p;
            if(p+q==m && p*q==n) printf("%lld %lld\n", p, q);
            else puts("NO");
        }
        
    }
}

int main(){
    //solve1();
    //solve2();
    solve3();
    return 0;
}
```
</details>

---

# 2021

<details><summary><a href="https://www.acwing.com/problem/content/4089/" target="_blank">AcWing 4086. 分糖果</a> code</summary>

```cpp
#include <iostream>
using namespace std;

typedef long long LL;

LL n, l, r;

int main(){
    cin>>n>>l>>r;
    
    if(l/n==r/n) cout<<r%n; // 如果在同一个区间
    else cout<<n-1;
    
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/4090/" target="_blank">AcWing 4087. 插入排序</a> code</summary>

```cpp
#define fst first
#define sed second
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

typedef pair<int, int> PII;

const int N=8e3+10;

PII a[N];   // 数组
int n, q;

int p[N];    // 索引

int main(){
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i].fst);
        a[i].sed = i;
    }
    
    sort(a+1, a+1+n);
    for(int i=1; i<=n; i++)
        p[ a[i].sed ] = i;
    
    for(int _=1; _<=q; _++){
        int qq, x, v; scanf("%d", &qq);
        
        if( qq==1 ){
            scanf("%d%d", &x, &v);
            
            // 定位到原数组的位置
            x = p[x];
            
            // 将a[i].fst 转换为 v, 检查其应该左移还是右移动
            if( a[x].fst > v ){   // 左移动
                a[x].fst = v;
                for(int i=x; i>=2; i--)
                    if(a[i] < a[i-1]){
                        swap(a[i], a[i-1]);
                    
                        p[ a[i].sed ] = i;
                        p[ a[i-1].sed ] = i-1;
                    }
                    else break;
            }else
            if( a[x].fst < v ){   // 右移动
                a[x].fst = v;
                for(int i=x; i<=n-1; i++)
                    if(a[i] > a[i+1]){
                        swap(a[i], a[i+1]);
                    
                        p[ a[i].sed ] = i;
                        p[ a[i+1].sed ] = i+1;
                    }
                    else break;
            }
        }else{
            scanf("%d", &x);
            printf("%d\n", p[x]);
        }
    }
    
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/description/4091/" target="_blank">AcWing 4088. 网络连接</a> code</summary>

```cpp
#include <iostream>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;

const int N=1e3+10;

map<string, int> serv;
int n;

int s2i(string s){
    stringstream ss;
    ss<<s;
    int res;
    ss>>res;
    return res;
}

string i2s(int num){
    stringstream ss;
    ss<<num;
    string res;
    ss>>res;
    return res;
}

bool ck(string s){
    int a[5];
    string cmp;
    sscanf(s.c_str(), "%d.%d.%d.%d:%d", a, a+1, a+2, a+3, a+4);
    
    for(int i=0; i<4; i++){
        if(a[i]<0 || a[i]>255) return 0;
        cmp += i2s(a[i]) + ".";
    }
    cmp[cmp.size()-1]=':'; // 替换最后一个'.'
    
    if(a[4]<0 || a[4]>65535) return 0;
    cmp += i2s(a[4]);
    return s == cmp;
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        string op, ad; cin>>op>>ad;
        
        if(op == "Server"){
            if(ck(ad))  // 符合规范
                if(serv.count(ad))
                    cout<<"FAIL\n";
                else
                    serv[ad] = i, cout<<"OK\n";
            else
                cout<<"ERR\n";
        }
        else{
            if(ck(ad))  // 符合规范
                if(serv.count(ad))
                    cout<<serv[ad]<<"\n";
                else
                    cout<<"FAIL\n";
            else
                cout<<"ERR\n";
        }
    }
    
    
    return 0;
}
```
</details>

---

# 2020

<details><summary><a href="https://www.acwing.com/problem/content/2769/" target="_blank">AcWing 2767. 优秀的拆分</a> code</summary>

```cpp
#include <iostream>
#include <queue>
using namespace std;

int n;
int a[30];

int main(){
    a[1]=1;
    for(n=1; a[n]<=1e7;){
        ++n;
        a[n] = a[n-1]*2;
    }
    
    queue<int> q;
    int k; cin>>k;
    
    while(n>=2){
        if(k >= a[n]) k-=a[n], q.push(a[n]);
        n--;
    }
    if(k==0)
        while(q.size()){
            cout<<q.front()<<" ";
            q.pop();
        }
    else
        cout<<-1;
    return 0;
}
```
</details>


<details><summary><a href="https://www.acwing.com/problem/content/2770/" target="_blank">AcWing 2768. 直播获奖</a> code</summary>

```cpp
#include <iostream>
using namespace std;

const int N=1e5+10;

int n, w;   

int a[610]; // 每个分数段的成绩

int calc(int cnt){  // 获奖人数
    if(!cnt) cnt=1; // 如果获奖人数为0
    for(int i=600; ; i--){
        cnt -= a[i];
        if(cnt<=0) return i;
    }
}

int main(){
    cin>>n>>w;
    for(int i=1; i<=n; i++){
        int ai; scanf("%d", &ai);
        a[ ai ] ++;
        cout<<calc(i * w / 100)<<" ";
    }
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/2772/" target="_blank">AcWing 2770. 方格取数</a> code</summary>

```cpp
#include <cstring>
#include <iostream>
using namespace std;

typedef long long LL;

const int N=1e3+10;

int g[N][N];
LL dp[N][N][2];
int n, m;

int main(){
    //freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    memset(g, -0x3f, sizeof g);
    memset(dp, -0x3f, sizeof dp);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d", &g[i][j]);

    dp[1][1][0]=dp[1][1][1]=g[1][1];
    for(int i=2; i<=n; i++) // 用手导第一列
        dp[i][1][0] = dp[i][1][1] = dp[i-1][1][0] + g[i][1];
    //for(int i=n-1; i>=1; i--)
    //    dp[i][1][1] = dp[i+1][1][1] + g[i][1];
    //for(int i=1; i<=n; i++)
    //    dp[i][1][0] = dp[i][1][1] = max(dp[i][1][0], dp[i][1][1]);

    for(int j=2; j<=m; j++){
        for(int i=1; i<=n; i++) // 从上到下，从左边来，从上面来
            dp[i][j][0] = max(dp[i][j-1][0], dp[i-1][j][0]) + g[i][j];

        for(int i=n; i>=1; i--) // 从下到上，从左边来，从下面来
            dp[i][j][1] = max(dp[i][j-1][1], dp[i+1][j][1]) + g[i][j];
        
        for(int i=1; i<=n; i++)
            dp[i][j][0] = dp[i][j][1] = max(dp[i][j][0], dp[i][j][1]);
    }

    cout<<dp[n][m][1];
    return 0;
}
```
</details>

---

# 2019

<details><summary><a href="https://www.acwing.com/problem/content/1163/" target="_blank">AcWing 1161. 数字游戏</a> code</summary>

```cpp
#include <iostream>
using namespace std;

int main(){
    char c; 
    int ans;
    while(cin>>c)
        if(c=='1')
            ans++;
    cout<<ans;
    return 0;
}
```
</details>


<details><summary><a href="https://www.acwing.com/problem/content/1164/" target="_blank">AcWing 1162. 公交换乘</a> code</summary>

```cpp
#pragma G++ optimize("Ofast", 2, 3)
#define fst first
#define sed second
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
int n, ans;

int main(){
    cin>>n;
    
    vector<PII> q;
    
    for(int i=1; i<=n; i++){
        int x, y, z; cin>>x>>y>>z;
        ans+=y;
        
        if(x==0)    // 获得券
            q.push_back({y, z});
        else{       // 找券
            
            while( q.size() && z - q[0].sed > 45 )
                q.erase(q.begin(), q.begin()+1);    // 清空过期券
            
            for(int j=0; j<q.size(); j++)
                if( q[j].fst >= y ){
                    q.erase(q.begin()+j, q.begin()+j+1);
                    ans-=y;
                    break;
                }            
        }
    }
    
    cout<<ans;
    
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/description/1165/" target="_blank">AcWing 1163. 纪念品</a> code</summary>

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N=110;

int dp[10010];  // 第 i+1 天, 可以增加的金币的最大值
int w[N][N];    // 第 i 天, 第 j 种物品的价值

int t, n, m;    // 天数, 纪念品数量, 金币数量

int main(){
    cin>>t>>n>>m;
    for(int i=1; i<=t; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &w[i][j]);
    
    for(int i=1; i<=t-1; i++){      // 枚举天数
        memset(dp, 0, sizeof dp);
        
        for(int j=1; j<=n; j++)     // 枚举商品
            for(int k=w[i][j]; k<=m; k++)   // 枚举钱(当前这个商品的价值 到 我身上的所有钱)
                dp[k] = max(dp[k], dp[k-w[i][j]] + w[i+1][j] - w[i][j] );
        // 枚举商品是为了考虑所有可能购买或出售的纪念品
        // 枚举钱是为了考虑所有可能的购买或出售纪念品的组合
        // 
        // 通过枚举商品和钱, 我们可以找到在当前这一天
        // 使用当前拥有的金币, 可以获得的最大收益
        // 然后, 我们可以使用这个最大收益来更新dp数组
        
        m += dp[m];
    }
    
    cout<<m;
    
    return 0;
}
```
</details>

---

# 2018


<details><summary><a href="https://www.acwing.com/problem/content/475/" target="_blank">AcWing 473. 标题统计</a> code</summary>

```cpp
#include <iostream>
using namespace std;

char c;
int ans;

int main(){
    while(cin>>c)
        if(c>='A' && c<='Z' || c>='a' && c<='z' || c>='0' && c<='9')
            ans++;
    cout<<ans;
    return 0;
}
```
</details>


<details><summary><a href="https://www.acwing.com/problem/content/description/476/" target="_blank">AcWing 474. 龙虎斗</a> code</summary>

```cpp
#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;

LL a[N];   // 兵营
LL dragon, tiger, n;
LL m, s1, p1, s2, p2, cha;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    cin >> m >> p1 >> s1 >> s2;
    a[p1] += s1;

    for (int i = 1; i <= n; i++)
        if (i < m)
            dragon += (m - i) * a[i];
        else if (i > m)
            tiger += (i - m) * a[i];

    p2 = m;
    cha = llabs(dragon - tiger);

	for (int i = 1; i <= n; i++){
		if (i < m && llabs(dragon - tiger + s2 * (m - i)) < cha ) 
	        p2 = i, cha = llabs(dragon - tiger + s2 * (m - i));
		if (i > m && llabs(dragon - tiger - s2 * (i - m)) < cha)
			p2 = i, cha = llabs(dragon - tiger - s2 * (i - m));
	}
    cout << p2;

    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/description/478/" target="_blank">AcWing 476. 对称二叉树</a> code</summary>

```cpp
#include <iostream>
using namespace std;

const int N=1e6+10;

int l[N], r[N], v[N], cnt[N];   // 每个节点的子树,权,子树数量
int n;

void dfs(int i){ // 计算以 i 为节点子树数量
    if(l[i]) dfs(l[i]);
    if(r[i]) dfs(r[i]);
    cnt[i] = cnt[l[i]] + cnt[r[i]] + 1;
}

bool ck(int i, int j){ // 检查 i,j 是不是对称
    if(v[i] != v[j] || cnt[i] != cnt[j]) return 0;  // 权,树不同
    if(i == 0 && j == 0) return 1;  // 两边都是空树
    if(ck(l[i], r[j]) && ck(r[i], l[j])) return 1;
    return 0;   
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++) scanf("%d", v+i);
    for(int i=1; i<=n; i++){
        int a, b; scanf("%d%d", &a, &b);
        l[i] = (a==-1)?0:a, r[i] = (b==-1)?0:b;
    }
    dfs(1);
    
    for(int i=1; i<=n; i++)
        if( ck(l[i], r[i]) )    // 检查以 i 为根的子树
            v[0] = max(v[0], cnt[i]);
    
    cout<<v[0];
    
    return 0;
}
```
</details>

---

# 2017

<details><summary><a href="https://www.acwing.com/problem/content/471/" target="_blank">AcWing 469. 成绩</a> code</summary>

```cpp
#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    cout<<a*0.2+b*0.3+c*0.5;
    return 0;
}
```
</details>


<details><summary><a href="https://www.acwing.com/problem/content/472/" target="_blank">AcWing 470. 图书管理员</a> code</summary>

```cpp
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

const int N=1e3+10;

int n, q;
string book[N]; // 书

int s2i(string s){
    stringstream ss;
    ss<<s;
    int res;
    ss>>res;
    return res;
}

int main(){
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>book[i];
    
    for(int i=1; i<=q; i++){
        int l, res=-1;
        string s;
        cin>>l>>s;
        
        for(int j=1; j<=n; j++)
            if(l<=book[j].size())
            if(s==book[j].substr(book[j].size()-l, l))
                if(res==-1)
                    res = s2i(book[j]);
                else    
                    res = min(res, s2i(book[j]));
            
        cout<<res<<"\n";
    }
    
    return 0;
}
```
</details>


<details><summary><a href="https://www.acwing.com/problem/content/473/" target="_blank">AcWing 471. 棋盘</a> code</summary>

```cpp
#define fst first
#define sed second
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;
const int N=110;
const int dxy[4][2]={ {-1,0},{1,0},{0,-1},{0,1} };

int g[N][N];    // 地图
int n, m;

int dis[N][N];  // 最短路

int spfa(PII s, PII e){ 
    memset(dis, 0x3f, sizeof dis);
    
    queue<pair<PII, PII>> q;    // 第二个参数是uxy变的颜色, 没变就是0; 第二个是魔法与花销
    dis[s.fst][s.sed] = 0;
    q.push({s, {0, 0}});
    
    while(q.size()){
        auto u = q.front();
        q.pop();
        
        int ux = u.fst.fst;
        int uy = u.fst.sed;
        
        for(int i=0; i<4; i++){ // 去四个方向
            int nx = ux + dxy[i][0];
            int ny = uy + dxy[i][1];
            
            if(nx<1 || ny<1 || nx>n || ny>n) continue;
            
            if( g[nx][ny] == 0 && u.sed.fst == 0 && g[ux][uy] != 0 ){   // 没变过才能继续变
                if( dis[nx][ny] > u.sed.sed + 2){
                    dis[nx][ny] = u.sed.sed + 2;
                    q.push({ {nx,ny}, {g[ux][uy], dis[nx][ny]} }); // 这是个变色玩意儿
                }
            }
            else if(g[nx][ny] && (g[nx][ny] == g[ux][uy] || g[nx][ny] == u.sed.fst)){   // 相同, 可以通过变的去
                if( dis[nx][ny] > u.sed.sed){
                    dis[nx][ny] = u.sed.sed;
                    q.push({ {nx,ny}, {0, dis[nx][ny]} });
                }
            }
            else if(g[nx][ny] && ((g[ux][uy] && g[nx][ny] != g[ux][uy]) || (u.sed.fst && g[nx][ny] != u.sed.fst)))
                if( dis[nx][ny] > u.sed.sed + 1){
                    dis[nx][ny] = u.sed.sed + 1;
                    q.push({ {nx,ny}, {0, dis[nx][ny]} });
                }
            
        }    
    }

    //for(int i=1; i<=n; i++, cout<<"\n")
    //    for(int j=1; j<=n; j++)
    //        cout<<dis[i][j]<<"   ";
    
    return dis[e.fst][e.sed] < 0x3f3f3f3f/2 ? dis[e.fst][e.sed] : -1;
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        g[x][y] = z+1;
    }
    
    cout<<spfa({1,1}, {n,n});
    
    return 0;
}
```
</details>

---

# 2016

<details><summary><a href="https://www.acwing.com/problem/content/467/" target="_blank">AcWing 465. 买铅笔</a> code</summary>

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
</details>

<details><summary><a href="https://www.acwing.com/problem/content/468/" target="_blank">AcWing 466. 回文日期</a> code</summary>

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
</details>


<details><summary><a href="https://www.acwing.com/problem/content/469/" target="_blank">AcWing 467. 海港</a> code</summary>

```cpp
#pragma G++ optimize(3, "Ofast")
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

const int N=1e5+10;
int n;
int T[N];   // 每艘船到达的时间
int K[N];   // 船上乘客的数量
vector<int> X[N];   // x[i]上每个乘客的信息

unordered_map<int, int> ans;  // 每个国籍的人的数量

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        scanf("%d%d", T+i, K+i);
        for(int j=1; j<=K[i]; j++){
            int t; scanf("%d", &t);
            X[i].push_back(t);
        }
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++){
        q.push(i);   // 第i秒的人
        
        for(int j=0; j<K[i]; j++) 
            ans[ X[i][j] ]++;
        
        while(T[q.front()]+86400 <= T[i]){
            for(int j=0; j<K[q.front()]; j++) {
                ans[ X[q.front()][j] ]--;
                if( ans[ X[q.front()][j] ] == 0 ) ans.erase(X[q.front()][j]);
            }
            q.pop();
        }
        
        printf("%d\n", ans.size());
    }
    
    
    return 0;
}
```
</details>


---

# 2015

<details><summary><a href="https://www.acwing.com/problem/content/description/463/" target="_blank">AcWing 461. 金币</a> code</summary>

```cpp
#include <iostream>
using namespace std;

int k, ans, one=1, x=1, y=1;

int main(){
    cin>>k;
    for(int i=1; i<=k; i++, x++){
        ans+=one;
        if(x==y){
            x=0;
            y++;
            one++;
        }
    }
    cout<<ans;
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/464/" target="_blank">AcWing 462. 扫雷游戏</a> code</summary>

```cpp
#include <iostream>
using namespace std;

const int N=1e2+10;

int dxy[8][2]={ {-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1} };

char g[N][N];
int res[N][N];
int n, m;

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>g[i][j];
            
    for(int i=1; i<=n; i++, cout<<"\n")
        for(int j=1; j<=m; j++){
            for(int k=0; k<8; k++)
                res[i][j] += g[ i+dxy[k][0] ][ j+dxy[k][1] ]=='*';
        
            if(g[i][j]=='*')
                cout<<'*';
            else 
                cout<<res[i][j];
        }
    
    return 0;
}
```
</details>


<details><summary><a href="https://www.acwing.com/problem/content/465/" target="_blank">AcWing 463. 求和</a> code</summary>

```cpp
/*
x+z == 2y, 说明这俩奇偶同性, 那么当x<z时, 必定存在x<y<z. 

分数与y其实是无关的, 所以我们需要找到相同颜色的一对 x,z

在样例中, 
对于颜色2(蓝), 是(1,5) = 6*7  = 42
对于颜色1(红), 是(4,6) = 10*4 = 40

显然,与分数无关
我们只需要在同一个颜色中,将奇偶性质相同的提取出来
比如,红色的奇数的, 此时会出现(类似于):(1,5), (1,9), (5, 9)这样的玩意儿
大家肯定也不想非常朴素的去一个一个计算吧

分析一下, 把1,5,9看作a,b,c,对应的数字是na,nb,nc
(a+b)*(na+nb) =[a*na]+ a*nb + b*na +[b*nb]
(a+c)*(na+nc) = a*na + a*nc + c*na +[c*nc]
(b+c)*(nb+nc) = b*nb + b*nc + c*nb + c*nc

求一下和
= a*na + b*nb + c*nc + ( a*na + a*nb + a*nc ) + ( b*na + b*nb + b*nc ) + ( c*na + c*nb + c*nc )
= a*na + b*nb + c*nc + ( a*(na+nb+nc) + b*(na+nb+nc) + c*(na+nb+nc) )
= a*na + b*nb + c*nc + (a+b+c)*(na+nb+nc)

对于a*na + b*nb + c*nc的数量,应该是是n-2的,n是格子数量,而这个是如何推出来的嘞,以后推
公式就出来了
ans = (n-2) Σ(i*ni) + Σ(i)Σ(ni)
*/
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5+10;
const int MOD = 10007;

int num[N], cor[N]; // 数字和颜色
vector<PII> a[N][2];// 同奇同色
int n, m;

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) scanf("%d", num+i);
    for(int i=1; i<=n; i++) scanf("%d", cor+i);
    
    for(int i=1; i<=n; i++)
        a[ cor[i] ][ i&1 ].push_back({i, num[i]});
    
    LL ans=0;
    for(auto c: a)
    for(int k=0; k<=1; k++)
        if(c[k].size()>=2){
            LL one=0, two=0, thr=0;
            for(auto &[i,j]: c[k]){
                one = (one + ((LL)i*j) % MOD) % MOD;
                two = (two + i) % MOD;
                thr = (thr + j) % MOD;
            }
            ans += (one * (c[k].size()-2)) + (two * thr);
            ans %= MOD;
        }
    
    cout<<ans%MOD;
    
    return 0;
}
```
</details>


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


<details><summary><a href="https://www.acwing.com/problem/content/456/" target="_blank">Acwing 454. 表达式求值</a> code</summary><br>

**大意**

给定一个只含 `[0, 2^31-1]` `+` `*` 的表达式，求出它的值。

**思路**

如果表达式中有多种运算符，显然用栈来做是最好的。但此题只有 `+` `*` 两种运算符。

1. 我们从第一个数开始考虑，首先接受一个数 `tmp`，然后循环接受一个运算符 `ch`，和数 `num`。
    * 如果 `ch` 为 `+`，那么左边的数 `tmp` 就可以加到答案上了，因为 `tmp` 不会影响后面的运算。
      将 `num` 赋值给 `tmp`，继续循环。
    * 如果 `ch` 为 `*`，那么 `tmp` 就要乘上 `num`，将 `tmp*num` 看作一个整体。
      将 `tmp*num` 赋值给 `tmp`，继续循环。 



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


<details><summary><a href="https://www.acwing.com/problem/content/description/457/" target="_blank">AcWing 455. 小朋友的数字</a> code</summary><br>

**大意**

给定一个数组 $a[n]$，通过这个数组可以得到一个数组 $b[n]$，
$b[i]$ 表示 $a[1] \sim a[i]$ 中最大的子序列和。

* 样例
    $a[n]$ = `1` `2` `3` `4` `5`
    $b[n]$ = `1` `3` `6` `10` `15`

* 更具有一般性的样例
    $a[n]$ = `1` `-2` `3` `-4` `5`
    $b[n]$ = `1` `-1` `3` `-1` `5`

* 更具有一般性的样例
    $a[n]$ = `9` `-2` `3` `-4` `2`
    $b[n]$ = `9` `7` `10` `6` `8`

通过 $b[n]$ 可以得到特征值数组，$b[i] = max(b[j])$，其中 $j ∈ [1, i]$。

通过 $a[n]$ 和 $b[n]$ 可以得到一个新的数组 $c[n]$，
$c[i] = max(c[j]+b[j])$，其中 $j ∈ [1, i)$，
特别的，$c[1] = b[1]$。

求最大的 $c[i]$。

**思路**

1. 求出 $b[n]$。就是在 $a[n]$ 中求最大子序列和。
   $i=1$ 时，$b[1] = a[1]$
    $i>1$ 时，$b[i] = max(b[i-1]+a[i], a[i])$

2. 求出 特征数组 $b[n]$，即
    $b[i] = max(b[j])$，其中 $j ∈ [1, i]$。

3. 求出 $c[n]$，即
    $c[i] = max(c[j]+b[j])$，其中 $j ∈ [1, i)$，
    特别的，$c[1] = b[1]$。

4. 求出最大的 $c[i]$。

```cpp
#include <iostream>
using namespace std;

typedef long long LL;

const int N=1e6+10;

LL n, p;
LL a[N], b[N];
__int128 c[N];

int main(){
    cin>>n>>p;
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    
    b[1]=a[1];
    for(int i=2; i<=n; i++) b[i] = max(b[i-1]+a[i], a[i]);
    for(int i=2; i<=n; i++) b[i] = max(b[i-1], b[i]);
    
    c[1]=b[1];
    __int128 mmax = c[1]+b[1];
    for(int i=2; i<=n; i++){
        c[i] = mmax;
        mmax = max(mmax, c[i] + b[i]);
    }
    
    mmax = c[1];
    for(int i=2; i<=n; i++) mmax=max(mmax, c[i]);

    printf("%lld", mmax%p);
    
    /* 
    cout<<"\n";
    for(int i=1; i<=n; i++) printf("%12lld", a[i]); cout<<"\n";
    for(int i=1; i<=n; i++) printf("%12lld", b[i]); cout<<"\n";
    for(int i=1; i<=n; i++) printf("%12lld", c[i]); cout<<"\n";
    */
    
    return 0;
}
```
</details>