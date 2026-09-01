// 比赛：洛谷题库
// 题目：P1352 没有上司的舞会
// 链接：https://www.luogu.com.cn/problem/P1352
// 状态：已通过
// 算法：树形动态规划、最大权独立集

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 6e3 + 10;
int a[N];
int dp[N][2];
vector <int> g[N];

void dfs(int u, int fa){
    dp[u][1] = a[u];
    dp[u][0] = 0;

    for (auto v : g[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        ans = max({ans, dp[i][0], dp[i][1]});
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
