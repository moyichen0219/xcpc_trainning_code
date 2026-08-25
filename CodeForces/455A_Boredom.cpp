// 比赛：Codeforces Round 260 (Div. 1)
// 题目：455A - Boredom
// 链接：https://codeforces.com/problemset/problem/455/A
// 状态：已通过
// 算法：动态规划、值域计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    int mx = 0;
    vector <int> a(n + 1);
    map <int, int> mp;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        mx = max(a[i], mx);
        mp[a[i]] ++;
    }
    vector <ll> dp(mx + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= mx; i ++){
        if (!mp[i]){
            dp[i] = dp[i - 1];
            continue;
        }
        if (i <= 2){
            dp[i] = max(dp[i - 1], 1ll * mp[i] * i);
        } else {
            dp[i] = max(dp[i - 1], dp[i - 2] + 1LL * mp[i] * i);
        }
    }
    cout << dp[mx] << '\n';
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
