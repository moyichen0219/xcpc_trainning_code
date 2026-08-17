// 比赛：AtCoder Beginner Contest 368
// 题目：ABC368 C - Triple Attack
// 链接：https://atcoder.jp/contests/abc368/tasks/abc368_c
// 状态：已通过
// 算法：周期模拟、数学

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        ll x;
        cin >> x;
        while (x > 0 && ans % 3 != 0){
            ans ++;
            if (ans % 3 == 0){
                x -= 3;
            } else {
                x --;
            }
        }
        if (x <= 0){
            continue;
        }
        ll base = x / 5;
        ans += base * 3;
        x -= base * 5;
        while (x > 0){
            ans ++;
            if (ans % 3 == 0){
                x -= 3;
            } else {
                x --;
            }
        }
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
