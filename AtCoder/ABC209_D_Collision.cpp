// 比赛/平台：AtCoder Beginner Contest 209
// 题目：D - Collision
// 链接：https://atcoder.jp/contests/abc209/tasks/abc209_d
// 状态：已通过
// 算法：树上距离、LCA、奇偶性

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
const ll inf = 4e18;
const int LOG = 20;
vector <int> g[N];

int n;
ll d[N];

int dep[N];
ll f[N][LOG + 1];

void dij(int st){
    fill(d, d + n + 1, inf);

    d[st] = 0;

    bitset<N>vis;

    priority_queue <pair <ll, int>, vector <pair <ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0, st});
    while (pq.size()){
        auto [di, u] = pq.top();
        pq.pop();

        if (vis[u]){
            continue;
        }

        vis[u] = true;

        for (auto v : g[u]){
            if (!vis[v] && d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                pq.push({d[v], v});
            }
        }
    }
}

void dfs(int u, int fa){
    dep[u] = dep[fa] + 1;

    f[u][0] = fa;
    for (int i = 1; i <= LOG; i ++){
        f[u][i] = f[f[u][i - 1]][i - 1];
    }

    for (auto v : g[u]){
        if (v == fa){
            continue;
        }

        dfs(v, u);
    }
}

int lca (int u, int v){
    if (dep[u] < dep[v]){
        swap(u, v);
    }

    int diff = dep[u] - dep[v];

    for (int j = 0; j <= LOG; j ++){
        if (diff >> j & 1){
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

void solve(){
    int q;
    cin >> n >> q;

    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    dij(1);

    for (int i = 1; i <= q; i ++){
        int u, v;
        cin >> u >> v;

        ll diff = d[u] + d[v] - 2 * d[lca(u, v)];

        if (diff % 2 == 1){
            cout << "Road" << '\n';
        } else {
            cout << "Town" << '\n';
        }
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t= 1;
    while (t --){
        solve();
    }
    return 0;
}
