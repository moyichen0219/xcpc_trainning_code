// 比赛/平台：CCPC2026 网络热身赛第二场（CCPCOJ）
// 题目：J - 封闭车站
// 链接：https://cpc.csgrandeur.cn/csgoj/problemset/problem?pid=1592
// 状态：待验证
// 算法：全源 BFS、无权图最短路

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
vector <int> g[N];

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <vector <int>> d(n + 1, vector <int>(n + 1, -1));

    for (int i = 1; i <= n; i ++){
        queue <int> q;
        d[i][i] = 0;
        q.push(i);

        while (!q.empty()){
            int u = q.front();
            q.pop();

            for (auto v : g[u]){
                if (d[i][v] == -1){
                    d[i][v] = d[i][u] + 1;
                    q.push(v);
                }
            }
        }
    }

    while (q --){
        int s, t;
        cin >> s >> t;

        if (s == t){
            cout << 0 << '\n';
            continue;
        }

        cout << d[s][t] - 1 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
