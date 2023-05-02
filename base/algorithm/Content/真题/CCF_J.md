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
                    q.push({{nx,ny}, {g[ux][uy], dis[nx][ny]}}); // 这是个变色玩意儿
                }
            }
            else if(g[nx][ny] && (g[nx][ny] == g[ux][uy] || g[nx][ny] == u.sed.fst)){   // 相同, 可以通过变的去
                if( dis[nx][ny] > u.sed.sed){
                    dis[nx][ny] = u.sed.sed;
                    q.push({{nx,ny}, {0, dis[nx][ny]}});
                }
            }
            else if(g[nx][ny] && ((g[ux][uy] && g[nx][ny] != g[ux][uy]) || (u.sed.fst && g[nx][ny] != u.sed.fst)))
                if( dis[nx][ny] > u.sed.sed + 1){
                    dis[nx][ny] = u.sed.sed + 1;
                    q.push({{nx,ny}, {0, dis[nx][ny]}});
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