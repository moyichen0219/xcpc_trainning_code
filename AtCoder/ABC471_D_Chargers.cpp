// 比赛：AtCoder Beginner Contest 471
// 题目：ABC471 D - Chargers
// 链接：https://atcoder.jp/contests/abc471/tasks/abc471_d
// 状态：已通过
// 算法：优先队列、时间偏移

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll q, v;
    cin >> q >> v;
    priority_queue<ll> pq;
    while (q --){
        int op;
        cin >> op;
        if (op == 1){
            int t;
            ll w;
            cin >> t >> w;
            pq.push(w - t);
        } else if (op == 2){
            int t;
            cin >> t;
            if (pq.empty()){
                cout << -1 << '\n';
            } else {
                ll x = pq.top();
                pq.pop();
                ll ans = t + x;
                cout << min(ans, v) << '\n';
            }
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
