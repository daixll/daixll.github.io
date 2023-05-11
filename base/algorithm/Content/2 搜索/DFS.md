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

> 先讲二叉树
> 再拓展到矩阵上
> 最后抽象到一个序列上

## 矩阵上的DFS

<details><summary><a href="https://www.acwing.com/problem/content/3505/" target="_blank">AcWing 3502. 不同路径数</a> code</summary>

> `每次可以沿上下左右四个方向前进一步`意味着对于每个节点, 我们有四种选择
> 在代码中, 我们应该如何实现, 从 `{x,y}` -> `{x-1, y}` 这个点的操作呢
> 喜闻乐见的一种方式就是直接x-1, 但在比赛中, 我们常常通过一个 `dx[4], dy[4]` 数组来实现
> 可以模拟一下 `dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1}`
> `nx = x + dx[0]`
> `ny = y + dy[0]` 
> 此时, 上下左右的转移就被我们写进了循环中, 大大减少了重复代码量

```cpp
#include <iostream>
#include <set>
using namespace std;

const int N=10;

int dxy[4][2]={ {-1,0}, {1,0}, {0,-1}, {0,1} };

set<int> cnt; 
int mp[N][N];
int n, m, k, res;

void dfs(int x, int y, int w){
    if(w > k){
        cnt.insert(res);
        return ;
    }
    
    for(int i=0; i<4; i++){
        int nx = x + dxy[i][0];
        int ny = y + dxy[i][1];
        
        if(nx>=1 && ny>=1 && nx<=n && ny<=m){
            res = res*10 + mp[nx][ny];   
            dfs(nx, ny, w+1);
            res /= 10;
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d", &mp[i][j]);
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            dfs(i, j, 0);   // 位置以及当前位数
    
    cout<<cnt.size();
    
    return 0;
}
```
</details>


<details><summary><a href="https://www.acwing.com/problem/content/description/1116/" target="_blank">AcWing 1114. 棋盘问题</a> code</summary>

> 我们首先思考一下, 求方案数, 肯定是不能重复的
> 那么我们可以再回想一下, dfs的搜索方案会重复吗? 我们上一道一题的去重是为什么?
> 思考完, 考虑一下这道题如何解决(自己尝试写一个, 先把输入写了), 他的关键之处在于`要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列`
> 画一个4*4的图就好理解了, 直接平板上画
> 这时候, 就可以引入另外一个东西了`used`数组

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 10;

char a[N][N];
bool x[N], y[N];  // 该行, 列有没有使用  
int n, k, ans;

void dfs(int i, int w) {
    if (w == k) {
        ans++;
        return;
    }
    if (i > n) return;
    for (int j = 1; j <= n; j++)
        if (!x[i] && !y[j] && a[i][j] == '#') {
            x[i] = y[j] = 1;
            dfs(i + 1, w + 1);
            x[i] = y[j] = 0;
        }
    dfs(i + 1, w);

    return;
}

void solve() {
    while (cin >> n >> k) {
        if (n == -1 && k == -1) return;
        memset(x, 0, sizeof x);
        memset(y, 0, sizeof y);
        ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        dfs(1, 0);
        cout << ans << "\n";
    }
    return;
}

int main() {
    solve();
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/description/118/" target="_blank">AcWing 116. 飞行员兄弟</a> code</summary>

```cpp
#define fst first
#define sed second

#include <iostream>
using namespace std;

typedef pair<int, int> PII;

int g[5][5]; // 需要将所有值变为 0  

PII step[100], ans[100];

bool check(){
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++)
            if(g[i][j])
                return 0;
    return 1;
}

void updata(){
    if(ans[0].fst < step[0].fst) return ;
    
    ans[0].fst=step[0].fst;
    for(int i=1; i<=step[0].fst; i++)
        ans[i].fst = step[i].fst,
        ans[i].sed = step[i].sed;
}

// 改变该点状态
void change(int x, int y){
    for(int i=1; i<=4; i++)
        g[x][i]^=1, g[i][y]^=1;
    g[x][y]^=1;
}

void dfs(int x, int y){
    
    // 到达边界
    if(x>4){
        // 如果结果合法（是解，但非最优）
        if ( check() )
        // 更新（如果是更优解，就更新）
            updata();
        // 结束
        return ;    
    }
    
    // 改变当前点状态
    change(x, y);
    // 更新答案
    step[0].fst++;
    step[ step[0].fst ] = {x, y};
    
    if(y==4)
        dfs(x+1, 1);
    else
        dfs(x, y+1);
    
    // 恢复现场
    change(x, y);
    step[0].fst--;
    
    if(y==4)
        dfs(x+1, 1);
    else
        dfs(x, y+1);
}

int main(){
    // 获取地图
    for(int i=1; i<=4; i++){
    for(int j=1; j<=4; j++){
        char c;
        scanf("%c", &c);
        if(c=='+') g[i][j]=1;
    }
    getchar();
    }
    
    ans[0].fst=99;
    
    // 枚举每个点的状态
    dfs(1,1);
    
    cout<<ans[0].fst<<endl;
    for(int i=1; i<=ans[0].fst; i++)
        cout<<ans[i].fst<<" "<<ans[i].sed<<endl;
    
    return 0;
}
```
</details>


<details><summary><a href="https://www.luogu.com.cn/problem/P1219" target="_blank">Luogu P1219 [USACO1.5]八皇后 Checker Challenge
</a> code</summary>

> 此题在上一题的基础上加入斜线

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int N=50;

int cnt=0;  // 记录解的个数
vector<int> ans;
bool x[N], y[N], r[N], l[N];
int n;

void dfs(int c){    // 第几层
    if(ans.size() == n){
        if(++cnt<=3){
            for(auto i: ans) cout<<i<<" ";
            cout<<"\n";
        }
        return ;
    }

    for(int i=1; i<=n; i++)
        if(!x[c] && !y[i] && !r[i-c+10] && !l[i+c]){
            x[c] =   y[i] =   r[i-c+10] =   l[i+c] = 1;
            ans.push_back(i);
            dfs(c+1);
            x[c] =   y[i] =   r[i-c+10] =   l[i+c] = 0;
            ans.pop_back();
        }
}

int main(){
    cin>>n;
    dfs(1);
    cout<<cnt;
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/description/1623/" target="_blank">Acwing 1621. N 皇后问题</a> code</summary>

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N=3000;

int x[N], y[N], r[N], l[N], a[N];

bool add(int i, int j){
    if(++x[i]!=1) return 0;
    if(++y[j]!=1) return 0; 
    if(++r[j-i+1000]!=1) return 0;
    if(++l[i+j]!=1) return 0;
    return 1;
}

void solve(){
    int n; cin>>n;
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    memset(r, 0, sizeof r);
    memset(l, 0, sizeof l);
    for(int i=1; i<=n; i++) scanf("%d", a+i);

    for(int i=1; i<=n; i++)
        if( !add(i, a[i]) ){
            puts("NO");
            return ;
        }
    puts("YES");
    return ;
}

int main(){
    int T; cin>>T;
    while(T--) solve();
    return 0;
}
```
</details>

<details><summary><a href="https://www.acwing.com/problem/content/4221/" target="_blank">Acwing 4218. 翻转</a> code</summary>

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N=20;

int g[N][N];
int bk[N][N];
int m, n;
string ans;
int anscnt=0x3f3f3f3f;

void cg(int x, int y){
    g[x][y] = g[x][y] ? 0: 1;
    g[x-1][y] = g[x-1][y] ? 0: 1;
    g[x+1][y] = g[x+1][y] ? 0: 1;
    g[x][y-1] = g[x][y-1] ? 0: 1;
    g[x][y+1] = g[x][y+1] ? 0: 1;
}

bool ck(){
    for(int j=1; j<=n; j++)
        if(g[m][j]) return 0;
    return 1;
}

void dfs(int u, string res, int cnt){
    if(u>n){
        memcpy(bk, g, sizeof bk);   // 备份一下
        
        for(int i=2; i<=m; i++)
            for(int j=1; j<=n; j++)
                if(g[i-1][j])
                    cg(i, j), res += "1", cnt++;
                else
                    res += "0";
        for(int j=1; j<=n; j++) res += "0";
        
        if(!ck()) {
            memcpy(g, bk, sizeof g);    // 恢复
            return ;
        }
        memcpy(g, bk, sizeof g);    // 恢复
        
        if(cnt < anscnt || ans=="" || res<ans) ans = res, anscnt = cnt; 
        return ;
    }
    
    dfs(u+1, res+"0", cnt);  // 不改变
    
    cg(1,u);  // 改变
    dfs(u+1, res+"1", cnt+1);
    cg(1,u);  // 恢复现场
}

int main(){
    cin>>m>>n;
    
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &g[i][j]);
    
    dfs(1, "", 0); 
    
    
    int k=0;
    
    if(ans=="")cout<<"IMPOSSIBLE";
    
    for(int i=1; i<=m; i++, cout<<"\n")
        for(int j=1; j<=n; j++)
            cout<<ans[k++]<<" ";
    
    return 0;
}
```
</details>


<details><summary><a href="https://www.acwing.com/problem/content/97/" target="_blank">AcWing 95. 费解的开关</a> code</summary>

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

const int N=10;

int dxy[4][2]={ {-1,0}, {1,0}, {0,-1}, {0,1} };

// 地图 地图备份
int g[N][N], backup[N][N];
int ans=0x3f3f3f3f;

bool check(){
    for(int i=0; i<5; i++)
        if(!g[4][i]) return 0;
    return 1;
}

void bf(){
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            backup[i][j]=g[i][j];
}

void rbf(){
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            g[i][j]=backup[i][j];
}

void change(int x, int y){
    for(int i=0; i<4; i++){
        int nx=x+dxy[i][0];
        int ny=y+dxy[i][1];
        if(nx<0 || ny<0) continue;
        g[nx][ny]^=1;
    }
    g[x][y]^=1;
}

// w是当前已经改变的次数
void dfs(int u, int w){
    
    if(w > ans) return ;
    
    // 到达边界
    if(u>4){
        // 保存当前地图
        bf();
        // 直接计算下面4层
        for(int i=1; i<5 && w<=6; i++)
            for(int j=0; j<5; j++)
                if(!g[i-1][j])
                    change(i, j), w++;
        
        if(w<=6 && check()) ans=min(ans, w);
        // 恢复回去
        rbf();
        return ;
    }
    
    // 改变
    change(0, u);
    dfs(u+1, w+1);
    change(0, u);
    
    // 不改变
    dfs(u+1, w);
}


int main(){
    int n;
    cin>>n;
    
    while(n--){
        ans=0x3f3f3f3f;
        
        for(int i=0; i<5; i++)
            for(int j=0; j<5; j++){
                scanf("%1d", &g[i][j]);
                backup[i][j]=g[i][j];
            }
        
        // 第一排的第几个点
        // 已经改变了几次
        dfs(0, 0);
        
        if(ans==0x3f3f3f3f)
            puts("-1");
        else
            cout<<ans<<"\n";
    }
    
    return 0;
}
```
</details>

---

## 一般DFS


