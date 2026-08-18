// 比赛：Educational DP Contest
// 题目：DP C - Vacation
// 链接：https://atcoder.jp/contests/dp/tasks/dp_c
// 状态：已通过
// 算法：动态规划、状态转移

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    ll a, b, c;
};

const int N = 1e5 + 10;
node h[N];
ll dp[4][N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        dp[1][i] = dp[2][i] = dp[3][i] = -1;
    }
    for (int i = 1; i <= 3; i ++){
        dp[i][0] = dp[i][1] = 0;
    }
    for (int i = 1; i <= n; i ++){
        cin >> h[i].a >> h[i].b >> h[i].c;
    }
    for (int i = 1; i <= n; i ++){
        dp[1][i] = max({dp[2][i - 1] + h[i].a, dp[3][i - 1] + h[i].a, dp[1][i]});
        dp[2][i] = max({dp[1][i - 1] + h[i].b, dp[3][i - 1] + h[i].b, dp[2][i]});
        dp[3][i] = max({dp[1][i - 1] + h[i].c, dp[2][i - 1] + h[i].c, dp[3][i]});
    }
    cout << max({dp[1][n], dp[2][n], dp[3][n]}) << '\n';
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
