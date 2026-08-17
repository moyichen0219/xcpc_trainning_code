// 比赛：AtCoder Beginner Contest 471
// 题目：ABC471 C - Cookies and Greedy Takahashi
// 链接：https://atcoder.jp/contests/abc471/tasks/abc471_c
// 状态：已通过
// 算法：贪心、有序集合

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    set <int> s;
    for (int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        s.insert(x);
    }
    ll cur = 0;
    ll ans = 0;
    while (s.size()){
        auto it = s.lower_bound(cur);
        ll nxt;
        if (it == s.end()){
            nxt = *prev(it);
        } else if (it == s.begin()){
            nxt = *it;
        } else {
            ll l, r;
            l = *prev(it);
            r = *it;
            if (abs(cur - l) > abs(cur - r)){
                nxt = r;
            } else {
                nxt = l;
            }
        }
        ans += abs(cur - nxt);
        cur = nxt;
        s.erase(nxt);
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
