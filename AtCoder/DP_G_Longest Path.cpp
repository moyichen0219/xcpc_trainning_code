// 比赛：Educational DP Contest
// 题目：G - Longest Path
// 链接：https://atcoder.jp/contests/dp/tasks/dp_g
// 状态：已通过
// 算法：DAG 动态规划、记忆化 DFS

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
vector <int> g[N];
int dp[N];
bool vis[N];

int dfs(int u){
    if (vis[u]){
        return dp[u];
    }
    vis[u] = true;
    for (auto v : g[u]){
            dp[u] = max(dp[u], dfs(v) + 1);

    }
    return dp[u];
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        // g[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        ans = max(ans, dfs(i));
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
