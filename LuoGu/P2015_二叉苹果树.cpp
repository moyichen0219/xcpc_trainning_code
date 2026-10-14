// 比赛/平台：洛谷
// 题目：P2015 二叉苹果树
// 链接：https://www.luogu.com.cn/problem/P2015
// 状态：已通过
// 算法：树形动态规划、树上背包

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 110;
const int INF = INT_MAX;
int sz[N];
ll dp[N][N];
vector <pair <int, int>> g[N];

int n, q;

void dfs(int u, int fa){
    fill (dp[u], dp[u] + q + 1, -INF);
    sz[u] = 1;
    dp[u][0] = 0;

    for (auto [v, w] : g[u]){
        if (v == fa){
            continue;
        }

        dfs(v, u);

        vector <ll> tmp(q + 1, -INF);
        for (int i = 0; i <= min(sz[u], q); i ++){
            if (dp[u][i] <= -INF / 2){
                continue;
            }

            tmp[i] = max(tmp[i], dp[u][i]);

            for (int j = 0; j <= min(sz[v], q - i - 1); j ++){
                if (dp[v][j] == -INF){
                    continue;
                }

                tmp[i + j + 1] = max(tmp[i + j + 1], dp[u][i] + dp[v][j] + w);
            }
        }

        for (int i = 0; i <= q; i ++){
            dp[u][i] = tmp[i];
        }

        sz[u] += sz[v];
    }
}

void solve(){
    cin >> n >> q;

    for (int i = 1; i <= n - 1; i ++){
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dfs(1, 0);

    cout << dp[1][q] << '\n';
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
