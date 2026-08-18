// 比赛：Educational DP Contest
// 题目：DP A - Frog 1
// 链接：https://atcoder.jp/contests/dp/tasks/dp_a
// 状态：已通过
// 算法：动态规划、线性 DP

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1);
    vector <ll> dp(n + 1, 1e9);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    dp[1] = 0;
    for (int i = 1; i <= n; i ++){
        if (i + 1 <= n){
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(a[i] - a[i + 1]));
        }
        if (i + 2 <= n){
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i] - a[i + 2]));
        }
    }
    cout << dp[n] << '\n';
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
