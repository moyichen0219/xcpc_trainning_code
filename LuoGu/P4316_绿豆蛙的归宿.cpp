// 平台：洛谷
// 题目：P4316 绿豆蛙的归宿
// 链接：https://www.luogu.com.cn/problem/P4316
// 状态：已通过
// 算法：DAG、拓扑排序、期望动态规划

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;

    vector <pair <int, int>> g[n + 1];

    vector <int> ind(n + 1, 0);

    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});

        ind[v] ++;
    }

    vector <int> topo;

    priority_queue <int, vector <int>, greater<int>> pq;

    for (int i = 1; i <= n; i ++){
        if (!ind[i]){
            pq.push(i);
        }
    }

    while (!pq.empty()){
        int x = pq.top();
        pq.pop();

        topo.push_back(x);

        for (auto [v, w] : g[x]){
            ind[v] --;

            if (!ind[v]){
                pq.push(v);
            }
        }
    }

    vector <double> ans(n + 1);

    for (int i = topo.size() - 1; i >= 0; i --){
        int u = topo[i];

        if (u == n){
            ans[u] = 0;
            continue;
        }

        double k = g[u].size();
        for (auto [v, w] : g[u]){
            ans[u] += 1.0 * (w + ans[v]) / k;
        }
    }

    cout << fixed << setprecision(2) << ans[1] << '\n';
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
