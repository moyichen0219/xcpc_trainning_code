// 比赛：CTSC 1997
// 题目：P2014 选课
// 链接：https://www.luogu.com.cn/problem/P2014
// 状态：已通过
// 算法：依赖型树上背包、虚拟根

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 310;
vector <int> g[N];
int w[N];
int dp[N][N];
int sz[N];

void dfs(int u){
    sz[u] = 1;
    dp[u][0] = 0;
    dp[u][1] = w[u];

    for (auto v : g[u]){
        dfs(v);

        for (int j = sz[u]; j >= 1; j --){
            for (int i = 1; i <= sz[v]; i ++){
                dp[u][j + i] = max(dp[u][j + i], dp[u][j] + dp[v][i]);
            }
        }

        sz[u] += sz[v];
    }

    // return dp[u][sz[u]];
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        int v;
        cin >> v >> w[i];
        g[v].push_back(i);
    }

    dfs(0);

    cout << dp[0][m + 1] << '\n';
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
