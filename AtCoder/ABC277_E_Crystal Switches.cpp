// 比赛：AtCoder Beginner Contest 277
// 题目：E - Crystal Switches
// 链接：https://atcoder.jp/contests/abc277/tasks/abc277_e
// 状态：已通过（提交 #79663845）
// 算法：分层状态图、Dijkstra、零代价状态切换

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const ll INF = 4e18;

ll d[N][2];
bool ss[N];

struct state {
    ll w;
    int u;
    int cnt;

    bool operator < (const state& other) const {
        return w > other.w;
    }
};

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i ++){
        for (int j = 0; j < 2; j ++){
            d[i][j] = INF;
        }
    }

    vector <int> g0[n + 1];
    vector <int> g1[n + 1];

    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;

        if (w == 0){
            g0[u].push_back(v);
            g0[v].push_back(u);
        } else if (w == 1){
            g1[u].push_back(v);
            g1[v].push_back(u);
        }
    }

    for (int i = 1; i <= k; i ++){
        int x;
        cin >> x;
        ss[x] = true;
    }

    d[1][1] = 0;

    priority_queue <state> pq;
    pq.push({d[1][1], 1, 1});

    while(!pq.empty()){
        auto [dd, u, cnt] = pq.top();
        pq.pop();

        if (dd != d[u][cnt]){
            continue;
        }

        if (ss[u]){
            if (dd < d[u][cnt ^ 1]){
                d[u][cnt ^ 1] = dd;
                pq.push({d[u][cnt ^ 1], u, cnt ^ 1});
            }
        }

        if (cnt == 0){
            for (auto v: g0[u]){
                if (dd + 1 < d[v][0]){
                    d[v][0] = dd + 1;
                    pq.push({d[v][0], v, cnt});
                }
            }
        } else {
            for (auto v : g1[u]){
                if (dd + 1 < d[v][1]){
                    d[v][1] = dd + 1;
                    pq.push({d[v][1], v, cnt});
                }
            }
        }
    }

    ll ans = INF;
    ans = min({ans, d[n][0], d[n][1]});

    if (ans == INF){
        cout << -1 << '\n';
    } else {
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
}
