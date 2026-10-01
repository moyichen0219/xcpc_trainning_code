// 比赛：The 2026 ICPC Guizhou Provincial Contest
// 题目：E - Charging Adapters
// 链接：https://qoj.ac/contest/4121/problem/20288
// 状态：待验证
// 算法：分层图建模、相邻连接、Dijkstra

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const ll INF = 4e18;
int x[N];

void solve(){
    int n, k, s, t;
    cin >> n >> k >> s >> t;

    for (int i = 1; i <= n; i ++){
        cin >> x[i];
    }

    vector <map <int, int>> g(n + 1);

    vector <int> pos[k + 1];

    for (int i = 1; i <= n; i ++){
        int m;
        cin >> m;

        for (int j = 1; j <= m; j ++){
            int c, w;
            cin >> c >> w;

            g[i][c] = w;
            pos[c].push_back(i);
        }
    }

    int tot = n;
    vector <map <int, int>> id(n + 1);

    for (int i = 1; i <= n; i ++){
        for (auto [c, w] : g[i]){
            id[i][c] = ++tot;
        }
    }

    vector <pair <int, ll>> e[tot + 1];

    for (int i = 1; i <= n; i ++){
        for (auto [c, w] : g[i]){
            int u = id[i][c];

            e[u].push_back({i, 0});
            e[i].push_back({u, w});
        }
    }

    for (int i = 1; i <= k; i ++){
        for (int j = 1; j <pos[i].size(); j ++){
            int a = pos[i][j - 1];
            int b = pos[i][j];

            int u = id[a][i];
            int v = id[b][i];

            ll w = abs(x[a] - x[b]);

            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
    }

    priority_queue <pair <ll, ll>, vector<pair <ll, ll>>, greater<pair <ll, ll>>> pq;

    vector <ll> d(tot + 1, INF);

    d[s] = 0;
    pq.push({d[s], s});

    while (!pq.empty()){
        auto [dd, u] = pq.top();
        pq.pop();

        if (dd != d[u]){
            continue;
        }

        for (auto [v, w] : e[u]){
            if (dd + w < d[v]){
                d[v] = dd + w;
                pq.push({d[v], v});
            }
        }
    }

    if (d[t] != INF){
        cout << d[t] << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t --){
        solve();
    }
    return 0;
}
