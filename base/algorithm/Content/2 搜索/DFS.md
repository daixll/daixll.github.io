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

# DFS

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



## 序列上的DFS



# BFS

## 矩阵上的BFS

<details><summary><a href="http://ybt.ssoier.cn:8088/problem_show.php?pid=1215" target="_blank">ybt 1215：迷宫</a> code</summary>

```cpp
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e2+10;
int dxy[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};

int n;          // 地图大小
char g[N][N];   // 地图
bool st[N][N];  // 走过没有
int sx, sy, ex, ey;

string solve(){
    memset(g, ' ', sizeof g);
    memset(st, 0, sizeof g);
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>g[i][j];
    cin>>sx>>sy>>ex>>ey;
    sx++, sy++, ex++, ey++;
    if(g[sx][sy]=='#' || g[ex][ey]=='#') return "NO";
    
    queue<PII> q;
    q.push({sx, sy}), st[sx][sy]=1;
    
    while(q.size()){
        auto t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        if(x == ex && y == ey) return "YES";
        
        for(int i=0; i<4; i++){
            int nx = x + dxy[i][0];
            int ny = y + dxy[i][1];
            
            if(nx>=1 && ny>=1 && nx<=n && ny<=n)
            if(g[nx][ny] == '.')
            if(st[nx][ny] == 0)
                q.push({nx, ny}), st[nx][ny]=1;
        }
    }
    return "NO";
}

int main(){
    int T; cin>>T;
    while(T--) cout<<solve()<<"\n";
    return 0;
}
```
</details>