// 比赛：2026 牛客暑期多校训练营 10
// 题目：L - Reaper
// 链接：https://ac.nowcoder.com/acm/contest/133885/L
// 状态：已通过
// 算法：数学、分类讨论、最优化

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// int cnt = 0;

void solve(){
    // cnt ++;
    int m, r, c;
    cin >> m >> r >> c;
    if (c <= m){
        cout << fixed << setprecision(12) << 1.0 << '\n';
        return ;
    }
    ll x = ceil(1.0 * (c - m) / (m + r));
    double ans1 = (1.0 * m * (x + 1)) / (1.0 * ((x + 1) * m + x * r));
    double ans2 = (x * m * 1.0) / (c * 1.0);
    double ans = max(ans1, ans2);
    cout << fixed << setprecision(12) << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t --){
        // cout << t << ' ';
        solve();
    }
    return 0;
}
