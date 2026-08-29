// 比赛：Codeforces Round 321 (Div. 2)
// 题目：580D Kefa and Dishes
// 链接：https://codeforces.com/problemset/problem/580/D
// 状态：已通过
// 算法：状压动态规划

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n);
    for (int i = 0; i < n ; i ++){
        cin >> a[i];
    }
    vector<vector<ll>> w(n, vector<ll>(n, 0));
    for (int i = 0; i < k; i ++){
        int x, y, c;
        cin >> x >> y >> c;
        x --;
        y --;
        w[x][y] = c;
    }
    int mx = (1 << n);
    vector<vector<ll>> dp(mx, vector<ll>(n, -1));
    for (int i = 0; i < n; i ++){
        dp[1 << i][i] = a[i];
    }
    ll ans = 0;
    for (int mask = 0; mask < mx; mask ++){
        int cnt = __builtin_popcount(mask);
        if (cnt == m){
            for (int i = 0; i < n; i ++){
                ans = max(ans, dp[mask][i]);
            }
        }
        if (cnt > m){
            continue;
        }
        for (int i = 0; i < n; i ++){
            if ((mask >> i & 1) && dp[mask][i] != -1){
                for (int j = 0; j < n; j ++){
                    if (mask >> j & 1){
                        continue;
                    }
                    dp[mask | (1 << j)][j] = max(dp[mask | (1 << j)][j], dp[mask][i] + w[i][j] + a[j]);
                }
            }
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
