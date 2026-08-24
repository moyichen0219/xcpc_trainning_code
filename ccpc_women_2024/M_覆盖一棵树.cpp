// 比赛：2024 年 CCPC 女生专场
// 题目：M - 覆盖一棵树
// 链接：https://qoj.ac/contest/1841/problem/9751
// 状态：已通过
// 算法：树形 DP、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int fa[N];

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector <int> dp(n + 1, 0);
    fa[1] = 1;
    for (int i = 2; i <= n; i ++){
        cin >> fa[i];
        g[fa[i]].push_back(i);
    }
    int ans = 0;
    for (int i = n; i >= 1; i --){
        if (!g[i].size()){
            dp[i] = 0;
            continue;
        }
        int mx = INT_MIN;
        int mn = INT_MAX;
        for (auto v : g[i]){
            mx = max(mx, dp[v] + 1);
            mn = min(mn, dp[v] + 1);
        }
        if (i == 1){
            ans = max(ans, mx);
        } else {
            dp[i] = mn;
            ans = max(ans, mx);
        }
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
