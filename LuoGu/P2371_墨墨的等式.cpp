// 比赛：国家集训队
// 题目：P2371 墨墨的等式
// 链接：https://www.luogu.com.cn/problem/P2371
// 状态：已通过
// 算法：同余最短路、Dijkstra、区间计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 2e18;

void solve(){
    ll n, l, r;
    cin >> n >> l >> r;
    vector <int> a(n);
    int m = 5e5 + 10;
    for (int i = 0; i < n; i ++){
        cin >> a[i];
        if (a[i] != 0){
            m = min(a[i], m);
        }
    }
    if (m == 5e5 + 10){
        if (l >= 1){
            cout << 0 << '\n';
            return ;
        } else {
            cout << 1 << '\n';
            return ;
        }
    }
    vector <ll> dis(m, INF);
    priority_queue <pair<ll, int>, vector <pair<ll, int>>, greater<pair<ll, int>>> pq;
    dis[0] = 0;
    pq.push({0, 0});
    while (pq.size()){
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dis[u]){
            continue;
        }
        for (auto x : a){
            int v = (d + x) % m;
            if (dis[v] > d + x){
                dis[v] = d + x;
                pq.push({dis[v], v});
            }
        }
    }

    ll ans = 0;
    ll cntl = 0;
    ll cntr = 0;
    for (int i = 0; i < m; i ++){
        if (dis[i] < l){
            cntl += (l - 1 - dis[i]) / m + 1;
        }
        if (dis[i] <= r){
            cntr += (r - dis[i]) / m + 1;
        }
    }
    cout << cntr - cntl << '\n';
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
