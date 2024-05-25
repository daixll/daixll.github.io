---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

2

线筛

```cpp
bool st[N]={1, 1};  // 0,1不是素数
int primes[N];

void make_primes(int n){// 生成 n 以内的素数
    for(int i=2; i<=n; i++){
        if(!st[i]) primes[++(*primes)]=i;   // 登记素数
        for(int j=1; j<=(*primes) && primes[j]<=n/i; j++){
            st[primes[j]*i]=1;              // 筛掉
            if(i%primes[j]==0) break;       // i 是 primes[j] 的倍数
        }   // 如果 i 是 primes[j] 的倍数, primes[j] 就是其最小质因子
    }       // 因此, 我们不必用其他质因子去筛了
}
```

六倍定理

```cpp
bool is_prime(LL x){
    if(x==2 || x==3   || x==5   ) return 1;
    if(x<2  ||(x%6!=1 && x%6!=5)) return 0; // 不与6的倍数相邻 
    for(LL i=5; i<=x/i; i+=6)  // 与6相邻, 但又有了因子 
        if(x%i==0 || x%(i+2)==0) return 0;
    return 1;
}
```

ADD

```cpp
string ADD(string A, string B, bool flg = 1) { // 默认 正序(正整数)输入 正序输出
    if (flg) reverse(A.begin(), A.end()), reverse(B.begin(), B.end());
    string res; int add = 0;    
    for (int i = 0; i < A.size() || i < B.size() || add; i++) {
        if (i < A.size()) add += A[i] - '0';// 取值
        if (i < B.size()) add += B[i] - '0';// 取的A,B相同低位
        res += add % 10 + '0';              // +
        add /= 10;                          // 进位
    }
    if (flg) reverse(res.begin(), res.end());
    return res; // flg == 0 倒叙输入输出模式 (在连续计算时减少reverse次数,以提升性能)
}
```

SUB

```cpp
string SUB(string A, string B) {  // 正序输入 正序输出
    if(! (A.size()>B.size() || (A.size()==B.size() && A>=B)) ) 
        return "-"+SUB(B, A);   // 非 A > B 的情况
    reverse(A.begin(), A.end()); reverse(B.begin(), B.end());
    string res;                 // 低位向高位减
    for (int i = 0, t = 0; i < A.size(); i++) {
        int ai = A[i] - '0';                // 换成 int
        int bi = i<B.size() ? B[i]-'0' : 0; // B位数不够
        t = ai - bi - t;                    // 减去
        res.push_back((t + 10) % 10 + '0'); // 保证是正数
        if (t < 0) t = 1;                   // 借走了一位
        else t = 0;
    }
    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}
```

MUL

```cpp
string MUL(string A, int b) { // 正序输入 正序输出
    reverse(A.begin(), A.end());
    string res;
    int x = 0;
    for (int i = 0; i < A.size() || x; i++) {
        if (i < A.size()) x += (A[i] - '0') * b;
        res.push_back(x % 10 + '0');
        x /= 10;
    }   // 去前导0
    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}
```

DIV
```cpp
string DIV(string A, int b, int& r) {    // A / b = res ... r 
    string res;    // 正序(正整数)输入 正序输出
    r = 0;
    for (int i = 0; i < A.size(); i++) {
        int ai = A[i] - '0';
        r = r * 10 + ai;            // r从高位下来,故*10
        res.push_back(r / b + '0'); // 整数位压入res
        r %= b;                     // 余数
    }
    while (res.size() > 1 && res.front() == '0') res.erase(res.begin(), res.begin() + 1);
    return res; // 去除前导 0 
}
```

qmi

```cpp
LL qmi(LL a, LL k, LL p){       // a^k == a^(k/2)^2
    if(k==0) return 1;          // 次方为 0
    LL res = qmi(a, k>>1, p);   // 计算 a^(k/2)
    if(!(k&1)) return (res%p * res%p) % p; 
    return (res%p * res%p * a) % p; // 对于不能除尽的, 还需再 *a
}
```

$x_a$ -> $x_{10}$

```cpp
string x_10(string x, int a){
    string res="0", p="1"; // 将 a 进制下的 x 转换为 10 进制
    for(int i=x.size()-1; i>=0; i--){
        int t; // 判断当前位数字是多少
        if(x[i]>='0' && x[i]<='9') t=x[i]-'0';
        if(x[i]>='A' && x[i]<='Z') t=x[i]-'A'+10;
        if(x[i]>='a' && x[i]<='z') t=x[i]-'a'+10;
        res=ADD(res, MUL(p, t));//res+=t*p; // t*(a^0, a^1, a^2)
        p=MUL(p, a); //p*=a; // (a^0, a^1, a^2)
    }
    return res;
}
```

$x_{10}$ -> $x_a$

```cpp
string x_a(string x, int a){
    if(x=="0") return "0";
    string res; // 将 10 进制下的 x 转换为 a 进制
    while(x!="0"){
        int r;
        x=DIV(x, a, r);
        if( r>=0 && r<=9 ) r+='0';
        else r+='A'-10;
        res+=r;
    }
    reverse(res.begin(), res.end());
    return res;
}
```

二分

```cpp
while(l<r){
    int mid = l+r >> 1;
    if(a[mid] >= x) r=mid;  // 右边是合法的, r向中间靠
    else l=mid+1;
}

while(l<r){
    int mid = l+r+1 >> 1;
    if(a[mid] <= x) l=mid;  // 左边是合法的, l向中间靠
    else r=mid-1;
}

int* b = lower_bound(a, a + 10, 3);	// 返回 第一个 3 的地址
vector<int>::iterator i = upper_bound(a.begin(), a.end(), 2);	// 返回迭代器
```

dijkstra

```cpp
int n, m; // 点、边
vector<PII> edge[100010]; // edge[x]={y,z} x->y=z
int dis[N]; // 最短路
bool st[N]; // 是否已确定最短路
// O(mlogm)
int dijkstra(int s, int e){
    // fst存dis[i] sed存i
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    // 初始化
    memset(dis, 0x3f, sizeof dis);
    dis[s]=0;
    // 起点入队
    heap.push({dis[s], s});
    while(heap.size()){
        auto x=heap.top().sed; // 取最小点
        heap.pop();
        // 在出堆的时候判断、确定是否确定最短路
        if(st[x]) continue;
        st[x]=1; // 确定最短路
        // 对该点进行松弛操作
        for(auto& [y, z]: edge[x])
        if( dis[y]>dis[x]+z ){
            dis[y]=dis[x]+z;
            heap.push({dis[y], y});
        }
    }
    return dis[e];
}
```

并查集
```cpp
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x]; 
}
// 合并
p[find(a)] = find(b);

void union(int a, int b){
    if(find(a) != find(b))  // 不可重复+, 注意顺序
        cnt[find(a)] += cnt[find(b)],   
        p[find(b)] = find(a);
}
```

KMP
```cpp
vector<int> KMP(string s, string p){
    vector<int> res;
    s = " " + s;
    p = " " + p;
    int n=s.size()-1, m=p.size()-1;
    const int N_p = p.size() + 10;
    int ne[N_p]={0}; // 模式串的next串
    //求ne数组
    for(int i = 2, j = 0; i <= m; i++) {
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
    //kmp匹配
    for(int i = 1, j = 0; i <= n; i++) {
        while(j && s[i] != p[j + 1]) j = ne[j];
        if(s[i] == p[j + 1]) j++;
        if(j == m) {
            j = ne[j]; //当匹配成功时继续往下匹配
            res.push_back(i-m);	// 记录成功下标
            // 或者其他逻辑
        }
    }
    return res;
}
```

线段树

```cpp
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class ST {   // 线段树（尽管使用了泛型，但非 int 并不怎么支持，hh）
public:
    struct node {
        int l, r;   // 区间 [l,r]
        T val;      // 权值

        T mmax;     // 区间最大值
        T mmin;     // 区间最小值
        T aadd;     // 区间增量
        T ssum;     // 区间和
        /* --- */

        /* --- */
    };

    // 使用可选参数构造
    ST(vector<T> _arr = std::vector<T>()) {
        if (_arr.size() == 0) {
            arr.assign(ST_N, T());
            build(1, 1, ST_N - 10);
        }
        else {
            arr = _arr;
			arr.insert(arr.begin(), T());  // 为了方便，从 1 开始
			build(1, 1, arr.size()-1);
		}
    }

    // 将 [l,r] 区间增加 val
    void modify_add(int l, int r, T val) {
        l = max(1, l), r = min(r, (int)arr.size()-1);
		modify_add(1, l, r, val);
    }

    // 将 [l,r] 区间修改为 val 
    void modify_mmm(int l, int r, T val) {
    }

	// 查询 [l,r] 区间
    node query(int l, int r) {
        l = max(1, l), r = min(r, (int)arr.size()-1);
        return query(1, l, r);
    }


private:
    static const int ST_N = 2e5+10;

    node tr[4 * ST_N];  // 最大大小;

    vector<T> arr;

    // 向下更新
    void pushdown(node &root, node &left, node &right) {
        if (root.aadd) {                                    // 向下传递
            left.aadd += root.aadd;                         // 标记下传
            left.ssum += root.aadd * (left.r - left.l + 1); // 区间和更新
            left.mmax += root.aadd;                         // 区间最大值更新
            left.mmin += root.aadd;                         // 区间最小值更新

			right.aadd += root.aadd;
			right.ssum += root.aadd * (right.r - right.l + 1);
            right.mmax += root.aadd;
            right.mmin += root.aadd;

            /* --- */

            /* --- */

            root.aadd = 0;                                  // 清空标记   
        }
    }

    // 向上更新
    void pushup(node& root, node& left, node& right) {
        root.ssum = left.ssum + right.ssum;
        root.mmax = max(left.mmax, right.mmax);
        root.mmin = min(left.mmin, right.mmin);
        /* --- */

        /* --- */

    }

    // 将 [l,r] 区间增加 val 
    void modify_add(int u, int l, int r, T val) {
        if (l <= tr[u].l && tr[u].r <= r) {
            tr[u].aadd += val;                          // 标记增加
            tr[u].ssum += val * (tr[u].r - tr[u].l + 1);// 区间和更新
            tr[u].mmax += val;                          // 区间最大值更新
            tr[u].mmin += val;                          // 区间最小值更新
            pushdown(tr[u], tr[u << 1], tr[u << 1 | 1]);// 向下传递信息
        }
        else {
            pushdown(tr[u], tr[u << 1], tr[u << 1 | 1]);// 向下传递信息
            int mid = tr[u].l + tr[u].r >> 1;
            if (mid >= l) modify_add(u << 1, l, r, val);
            if (mid < r) modify_add(u << 1 | 1, l, r, val);
            pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
        }
    }

	// 查询 [l,r] 区间
	node query(int u, int l, int r) {
		if (l <= tr[u].l && tr[u].r <= r) return tr[u]; // 完全包含

		pushdown(tr[u], tr[u << 1], tr[u << 1 | 1]);    // 向下传递信息

		int mid = tr[u].l + tr[u].r >> 1;
		if (mid >= r)                               // ************l****r****m****
			return query(u << 1, l, r);             // tr[u].l[~~~~^~~~~^~~~~] 在这个区间，l小于tr[u].l在之前其实已经考虑过了
		else if (mid < l)
			return query(u << 1 | 1, l, r);
		else {                                      // 横跨俩区间
			auto left = query(u << 1, l, r);
			auto right = query(u << 1 | 1, l, r);
			node ans;                               // 合并答案
			pushup(ans, left, right);
			return ans;
		}
	}

    // 初始化 建树
    void build(int u, int l, int r) {
        tr[u] = { l, r };   // u 节点下辖左右区间
        
        if (l == r) {       // 叶子节点 l == r
			tr[u].val = arr[l];
            tr[u].mmax = arr[l];
            tr[u].mmin = arr[l];
            tr[u].ssum = arr[l];
            /* --- */

            /* --- */
        }
        else {              // 递归创建左右儿子
            int mid = l + r >> 1;
            build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
            pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
        }
    }
};

int n, m;

int main() {
    cin >> n >> m;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    ST<int> st(a);




    while (m--) {
        string op;
        cin >> op;
        if (op == "C") {
            int l, r, d;
            cin >> l >> r >> d;
            st.modify_add(l, r, d);
        }
        else {
            int l, r;
            cin >> l >> r;
            auto ans = st.query(l, r);
            cout << ans.ssum << endl;
        }
    }

    return 0;
}
```