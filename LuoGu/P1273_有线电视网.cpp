// 比赛/平台：洛谷
// 题目：P1273 [CHCI 2002 Final Exam #2] 有线电视网
// 链接：https://www.luogu.com.cn/problem/P1273
// 状态：已通过
// 算法：树形动态规划、树上背包、收益最大化

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3010;
const ll inf = 4e18;
int a[N];
int sz[N];
ll dp[N][N];

vector <pair <int, int>> g[N];

int n, m;

void dfs(int u, int fa){
    fill(dp[u], dp[u] + N, -inf);

    dp[u][0] = 0;

    if (u > n - m){
        sz[u] = 1;
        dp[u][0] = 0;
        dp[u][1] = a[u];
    }

    for (auto [v, w] : g[u]){
        if (v == fa){
            continue;
        }

        dfs(v, u);

        for (int i = sz[u]; i >= 0; i --){
            for (int j = sz[v]; j >= 1; j --){
                dp[u][i + j] = max(dp[u][i + j], dp[u][i] + dp[v][j] - w);
            }
        }

        sz[u] += sz[v];
    }
}

void solve(){
    cin >> n >> m;

    for (int i = 1; i <= n -m; i ++){
        int k;
        cin >> k;

        for (int j = 1; j <= k; j ++){
            int v, w;
            cin >> v >> w;
            g[i].push_back({v, w});
        }
    }

    for (int i = n - m + 1; i <= n; i++){
        cin >> a[i];
    }

    dfs(1, 0);

    for (int i = m; i >= 1; i --){
        if (dp[1][i] >= 0){
            cout << i << '\n';
            return ;
        }
    }
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
