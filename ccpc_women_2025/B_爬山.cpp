// 比赛：2025 年 CCPC 女生专场
// 题目：B - 爬山
// 链接：https://qoj.ac/contest/2564/problem/14451
// 状态：已通过
// 算法：状态扩展、Dijkstra
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge{
    ll v, t;
    bool operator < (const edge& other)const {
        if (t != other.t){
            return t < other.t;
        }
        return v < other.v;
    };
};

struct node{
    ll u, t, h;
    bool operator < (const node& other)const {
        return t > other.t;
    }
};

const int N = 1e4 + 10;
int h[N];
vector<edge> g[N];

void solve(){
    int n, m, H;
    cin >> n >> m >> H;
    for (int i = 1; i <= n; i ++){
        cin >> h[i];
    }
    for (int i = 1; i <= m; i ++){
        ll u, v, t;
        cin >> u >> v >> t;
        g[u].push_back({v, t});
        g[v].push_back({u, t});
    }
    vector <vector <ll>> dp(n + 1, vector <ll> (H + 1, LLONG_MAX));
    priority_queue <node> pq;
    pq.push({1, 0, 0});
    dp[1][0] = 0;
    while (pq.size()){
        auto [u, tt, hh] = pq.top();
        pq.pop();
        if (tt != dp[u][hh]){
            continue;
        }
        for (auto [v, t] : g[u]){
            ll nh;
            if (h[u] > h[v]){
                nh = 0;
            } else {
                nh = hh + h[v] - h[u];
                if (nh > H){
                    continue;
                }
            }
            ll nt = tt + t;
            if (nt < dp[v][nh]){
                dp[v][nh] = nt;
                pq.push({v, nt, nh});
            }
        }
    }
    for (int i = 2; i <= n; i ++){
        ll tt = *min_element(dp[i].begin(), dp[i].end());
        if (tt == LLONG_MAX){
            cout << -1 << ' ';
        } else {
            cout << tt << ' ';
        }
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
