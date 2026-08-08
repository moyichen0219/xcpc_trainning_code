// 比赛：2026 牛客暑期多校训练营 4（133879）
// 题目：B - Quadratic Residue - https://ac.nowcoder.com/acm/contest/133879/B
// 状态：已通过（账号评测状态已于 2026-08-08 核对）
// 分类：数论、二次剩余、完全平方数、构造
// 创建：MYC，2026/7/29
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll p;
    cin >> p;
    ll l = 1;
    ll r = 1e9 + 10;
    ll ans = 1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (mid * (mid - 1) > p) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }

    }ll x_1 = ans;
    ll q = x_1 * x_1 - p;
    ll x_2 = 0;
    if (x_1 % p == 0) {
        x_1 ++;
        x_2 = x_1 % p;
        q = x_1 * x_1 - p;
    }
    cout << x_1 << ' ' << x_2 << ' ' << q << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
