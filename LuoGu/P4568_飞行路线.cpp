// 平台：洛谷
// 题目：P4568 [JLOI2011] 飞行路线
// 链接：https://www.luogu.com.cn/problem/P4568
// 状态：已通过
// 算法：分层图、Dijkstra、免费边状态

// 维护一个状态 <当前费用，当前点，已免费航线数>
#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

const int N = 1e4 + 10;
const int K = 15;
const ll INF = 4e18;

ll d[N][K];

struct state{
    ll w;
    int u;
    int cnt;

    bool operator < (const state& a) const {
        return w > a.w;
    }
};

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i ++){
        for (int j = 0; j <= k; j ++){
            d[i][j] = INF;
        }
    }

    int s, t;
    cin >> s >> t;

    vector <pair <int, int>> g[n];

    for (int i = 1; i <= m; i ++){
        int a, b, w;
        cin >> a >> b >> w;

        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    d[s][0] = 0;

    priority_queue <state> pq;
    pq.push({d[s][0], s, 0});

    while (!pq.empty()){
        auto [dd, u, cnt] = pq.top();
        pq.pop();

        if (dd != d[u][cnt]){
            continue;
        }

        for (auto [v, w] : g[u]){
            if (dd + w < d[v][cnt]){
                d[v][cnt] = dd + w;
                pq.push({d[v][cnt], v, cnt});
            }

            if (cnt + 1 <= k && dd < d[v][cnt + 1]){
                d[v][cnt + 1] = dd;
                pq.push({d[v][cnt + 1], v, cnt + 1});
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i <= k; i ++){
        ans = min(ans, d[t][i]);
    }

    cout << ans << '\n';
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
