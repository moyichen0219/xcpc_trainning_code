// 平台：洛谷
// 题目：P3379 【模板】最近公共祖先（LCA）
// 链接：https://www.luogu.com.cn/problem/P3379
// 状态：待验证
// 算法：倍增、LCA、树上查询

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 10;
const int LOG = 20;
vector <int> g[N];
int dep[N];
int f[N][LOG + 1];

void dfs(int u, int father){
    dep[u] = dep[father] + 1;
    f[u][0] = father;
    for (int j = 1; j <= LOG; j ++){
        f[u][j] = f[f[u][j - 1]][j - 1];
    }
    for (auto v : g[u]){
        if (v == father){
            continue;
        }
        dfs(v, u);
    }
}

int lca(int u, int v){
    if (dep[u] < dep[v]){
        swap(u, v);
    }
    for (int j = LOG; j >= 0; j --){
        if (dep[f[u][j]] >= dep[v]){
            u = f[u][j];
        }
    }
    if (u == v){
        return u;
    }
    for (int j = LOG; j >= 0; j --){
        if (f[u][j] != f[v][j]){
            u = f[u][j];
            v = f[v][j];
        }
    }
    return f[u][0];
}

/*  优化调整深度
int lca(int u, int v){
    if (dep[u] < dep[v]){
        swap(u, v);
    }
    int d = dep[u] - dep[v];
    for (int j = 0; j <= LOG; j ++){
        if (d >> j & 1){
            u = f[u][j];
        }
    }
    if (u == v){
        return u;
    }
    for (int j = LOG; j >= 0; j --){
        if (f[u][j] != f[v][j]){
            u = f[u][j];
            v = f[v][j];
        }
    }
    return f[u][0];
} */

void solve(){
    int n, m ,s;
    cin >> n >> m >> s;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(s, 0);
    while (m --){
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
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
