// 比赛/平台：2026 CCPC 女生专场
// 题目：A - 又是环状线
// 链接：https://qoj.ac/contest/4613/problem/23631/statement/zh_cn
// 状态：待验证
// 算法：环形距离、相遇时间、分类讨论

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, s, t;
    cin >> n >> s >> t;

    int d = 0;
    if (s > t){
        d = s - t;
    } else {
        d = (n - t) + s;
    }

    int ans = t;
    if (d % 2 == 1){
        ans += (d + 1) / 2;
    } else {
        ans += d / 2;
    }

    ans %= n;

    if (ans == 0){
        cout << n << '\n';
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
