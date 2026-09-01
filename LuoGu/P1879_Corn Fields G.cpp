// 比赛：USACO 2006 November
// 题目：P1879 Corn Fields G
// 链接：https://www.luogu.com.cn/problem/P1879
// 状态：未完成
// 算法：状态压缩动态规划（待实现）

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 15;
int a[N][N];
int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};
int dp[N][N];

const int p = 1e8;

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> a[i][j];
            if (a[i][j]){
                dp[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (a[i][j] == 0){
                dp[i][j] = 0;
            } else {
                // cout << "a" << ' ';
                dp[i][j] = max(dp[i][j], 1);
                for (int p = 0; p < 4; p ++){
                    int ni = i + dx[i];
                    int nj = j + dy[j];
                    if (ni >= 1 && ni <= n && nj >= 1 && nj <= m){
                        if (a[ni][nj] == 1){
                            dp[i][j] = (dp[i][j] + dp[ni][nj]) % p;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            ans = (ans + dp[i][j]) % p;
        }
    }
    cout << ans << '\n';
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
