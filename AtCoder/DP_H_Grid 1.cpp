// 比赛：Educational DP Contest
// 题目：H - Grid 1
// 链接：https://atcoder.jp/contests/dp/tasks/dp_h
// 状态：已通过
// 算法：网格动态规划、路径计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
const int MOD = 1e9 + 7;
string g[N];
ll dp[N][N];

void solve(){
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i ++){
        cin >> g[i];
    }
    dp[0][0] = 1;
    for (int i = 0; i < h; i ++){
        for (int j = 0; j < w; j ++){
            if (i == 0 && j == 0){
                continue;
            }
            if (g[i][j] == '.'){
                if (i > 0){
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                }
                if (j > 0){
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
                }
            }
        }
    }
    cout << dp[h - 1][w - 1];
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
