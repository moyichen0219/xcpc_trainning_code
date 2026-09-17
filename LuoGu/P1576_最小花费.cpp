// 比赛：洛谷
// 题目：P1576 - 最小花费
// 链接：https://www.luogu.com.cn/problem/P1576
// 状态：已通过
// 算法：Dijkstra、乘法权值、反向最短路

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e4 + 10;
const double inf = 4e18;
vector<pair<int, int>> g[N];
double d[N];

void solve(){
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i ++){
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    int st, ed;
    cin >> st >> ed;

    priority_queue <pair<double, int>, vector <pair <double, int>>, greater<pair<double, int>>> pq;
    pq.push({100.0, ed});

    for (int i = 1; i <= n; i ++){
        d[i] = inf;
    }

    d[ed] = 100.0;
    while (!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if (w > d[u]){
            continue;
        }

        for (auto [v, ww] : g[u]){
            double nw = d[u] *  100.0 / (100.0 - ww);
            if (nw < d[v]){
                d[v] = nw;
                pq.push({nw, v});
            }
        }
    }

    cout << fixed << setprecision(8) << d[st] << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t --){
        solve();
    }
    return 0;
}
