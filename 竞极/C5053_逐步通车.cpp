// 比赛：竞极题库
// 题目：C5053 逐步通车
// 链接：http://47.120.23.84/problems/2091929270199820290
// 状态：待验证
// 算法：离线查询、并查集、连通点对计数

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n , m, q;
    cin >> n >> m >> q;
    int mx = 0;
    map <ll, int> mp;
    vector <pair<int , int>> g[n + 1];
    for (int i= 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        if (u == v){
            continue;
        }
        mx = max(mx, w);
        g[u].push_back({v, w});
        mp[w] ++;
    }
    // w <= x
    while (q --){
        int x;
        cin >> x;
        ll ans = 0;

        cout << ans << '\n';
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
} */

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const ll MOD = 998244353;

ll fac[N], invfac[N];

// 快速幂
ll power(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 模逆
ll inv(ll x){
    return power(x, MOD - 2);
}

// 预处理阶乘与逆阶乘
void init(){
    fac[0] = 1;

    for (int i = 1; i < N; i ++){
        fac[i] = fac[i - 1] * i % MOD;
    }

    invfac[N - 1] = inv(fac[N - 1]);

    for (int i = N - 2; i >= 0; i --){
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }
}

// 组合数 C(n,m)
ll C(int n, int m){
    if (m < 0 || m > n){
        return 0;
    }

    return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

// 可撤销并查集
// 只能撤销上一次有效操作
struct DSU{
    vector <ll> f, siz;
    stack <pair<int, int>> his;

    DSU (int n){
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int root(int x){
        return f[x] == x ? x : root(f[x]);
    }

    ll merge(int x, int y){
        x = root(x);
        y = root(y);
        if (x == y){
            return false;
        }
        if (siz[x] < siz[y]){
            swap(x, y);
        }
        ll add = siz[x] * siz[y];
        his.push({x, y});
        siz[x] += siz[y];
        f[y] = x;
        return add;
    }

    int time(){
        return his.size();
    }

    void revert(int tm){
        while(his.size() > tm){
            auto[x, y] = his.top();
            his.pop();
            f[y] = y;
            siz[x] -= siz[y];
        }
    }
};

// 我们发现，答案为C(2, 连通块1点数和) + C(2, 连通块2点数和) + ……
// 发现在线查询实现难度有点大

struct node{
    int u, v, w;
    bool operator < (const node& other)const {
        if (w != other.w){
            return w < other.w;
        }
        if (u != other.u){
            return u < other.u;
        }
        return v < other.v;
    }
};

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    vector <node> g;
    g.reserve(m);
    int mx = 0;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        if (u == v){
            continue;
        }
        mx = max(mx, w);
        g.push_back({u, v, w});
    }

    vector <pair<int, int>> qury;
    for (int i = 1; i <= q; i ++){
        int x;
        cin >> x;
        // cout << x << ' ' << i << '\n';
        qury.push_back({x, i});
    }

    vector <ll> ans(q + 1);
    sort(qury.begin(), qury.end());
    sort(g.begin(), g.end());

    int add = 0;
    ll cur = 0;

    DSU dsu(n + 1);

    for (int i = 0; i < q; i ++){
        auto [x, idx] = qury[i];
        // cout << x << ' ';
        while (add < g.size() && g[add].w <= x){
            cur += dsu.merge(g[add].u, g[add].v);
            // cout << cur << '\n';
            add ++;
        }
        ans[idx] = cur;
    }
    for (int i = 1; i <= q; i ++){
        cout << ans[i] << '\n';
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
