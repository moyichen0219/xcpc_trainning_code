// 比赛：Educational DP Contest
// 题目：I - Coins
// 链接：https://atcoder.jp/contests/dp/tasks/dp_i
// 状态：已通过
// 算法：概率动态规划、正面次数计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3010;
double p[N];
double dp[N][N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> p[i];
    }

    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i ++){
        for (int j = 0; j <= i; j ++){
            dp[i][j] += dp[i - 1][j] * (1 - p[i]);
            if (j >= 1){
                dp[i][j] += dp[i - 1][j - 1] * p[i];
            }
        }
    }
    double ans = 0.0;
    for (int i = n; i >= (n + 1) / 2; i --){
        ans += dp[n][i];
    }
    cout << fixed << setprecision(12) << ans << '\n';
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
