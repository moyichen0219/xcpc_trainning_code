// 比赛：Codeforces Round 293 (Div. 2)
// 题目：518D - Ilya and Escalator
// 链接：https://codeforces.com/problemset/problem/518/D
// 状态：已通过（提交 #393106428）
// 算法：概率动态规划、期望

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, t;
    double p;
    cin >> n >> p >> t;

    vector <vector <double>> dp(t + 1, vector <double>(n + 1, 0.0));

    dp[0][0] = 1.0;
    for (int i = 0; i < t; i ++){
        for (int j = 0; j <= n; j ++){
            if (j == n){
                dp[i + 1][n] += dp[i][n];
            } else {
                dp[i + 1][j] += dp[i][j] * (1 - p);
                dp[i + 1][j + 1] += dp[i][j] * p;
            }
        }
    }

    double ans = 0;
    for (int i = 0; i <= n; i ++){
        ans += i * dp[t][i];
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
