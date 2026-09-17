// 比赛：USACO 2009 October
// 题目：P1339 - Heat Wave G
// 链接：https://www.luogu.com.cn/problem/P1339
// 状态：已通过
// 算法：Dijkstra、无向图最短路

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2510;
const ll inf = 4e18;
vector <pair <int, int>> g[N];
ll d[N];

void solve(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i ++){
        d[i] = inf;
    }

    priority_queue <pair <int, int>, vector <pair <int, int>>, greater<pair <int, int>>> pq;

    pq.push({0, s});
    d[s] = 0;

    while (!pq.empty()){
        auto [w, x] = pq.top();
        pq.pop();

        if (w > d[x]){
            continue;
        }

        for (auto [y, c] : g[x]){
            if (w + c < d[y]){
                d[y] = w + c;
                pq.push({d[y], y});
            }
        }
    }

    cout << d[t] << '\n';
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
