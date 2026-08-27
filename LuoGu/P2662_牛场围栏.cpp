// 比赛：WC 2002
// 题目：P2662 牛场围栏
// 链接：https://www.luogu.com.cn/problem/P2662
// 状态：已通过（账号；本地版本需修正）
// 算法：同余最短路、Dijkstra、最大不可表示数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF  = 1e18;

void solve(){
    int n, m;
    cin >> n >> m;
    ll mn = 3010;
    vector <ll> a(n);
    for (int i = 0; i < n; i ++){
        cin >> a[i];
        if (a[i] <= m){
            mn = 1;
        } else {
            mn = min(a[i] - m, mn);
        }
    }
    vector <ll> dis(mn, INF);
    priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dis[0] = 0;
    pq.push({0, 0});
    while (pq.size()){
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dis[u]){
            continue;
        }
        for (auto x : a){
            for (int i = max(x - m, mn); i <= x; i ++){
                int v = (u + i) % mn;
                if (dis[v] > d + i){
                    dis[v] = d + i;
                    pq.push({dis[v], v});
                }
            }
        }
    }
    ll ans = -1;
    for (int i = 0; i < mn; i ++){
        ans = max(ans, dis[i] - mn);
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
