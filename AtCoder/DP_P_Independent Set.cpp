// 比赛：Educational DP Contest
// 题目：P - Independent Set
// 链接：https://atcoder.jp/contests/dp/tasks/dp_p
// 状态：待验证
// 算法：树形动态规划、独立集计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5  + 10;
const int MOD = 1e9 + 7;
vector <int> g[N];
ll dp[N][2];

void dfs(int u, int fa){
    dp[u][0] = dp[u][1] = 1;
    for (auto v : g[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        dp[u][0] = (dp[v][0] + dp[v][1]) % MOD * dp[u][0] % MOD;
        dp[u][1] = dp[v][0] * dp[u][1] % MOD;
    }
}

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1]) % MOD << '\n';
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
