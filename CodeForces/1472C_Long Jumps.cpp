// 比赛：Codeforces Round 693 (Div. 3)
// 题目：1472C Long Jumps
// 链接：https://codeforces.com/problemset/problem/1472/C
// 状态：已通过
// 算法：动态规划、递推

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    vector <ll> dp(n + 1);
    for (int i = 1; i <= n; i ++){
        dp[i] = a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        if (i + a[i] <= n){
            dp[i + a[i]] = max(dp[i + a[i]], dp[i] + a[i + a[i]]);
        }
        ans = max(dp[i], ans);
    }
    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t --){
        solve();
    }
    return 0;
}
