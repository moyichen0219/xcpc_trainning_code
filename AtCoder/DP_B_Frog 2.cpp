// 比赛：Educational DP Contest
// 题目：DP B - Frog 2
// 链接：https://atcoder.jp/contests/dp/tasks/dp_b
// 状态：已通过
// 算法：动态规划、线性 DP

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> h(n + 1);
    vector <int> dp(n + 1, 1e9);
    for (int i = 1; i <= n; i ++){
        cin >> h[i];
    }
    dp[1] = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= k; j ++){
            if (i + j <= n){
                dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
            }
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
