// 平台：洛谷
// 题目：P3304 [SDOI2013] 直径
// 链接：https://www.luogu.com.cn/problem/P3304
// 状态：未完成
// 算法：树的直径（仅完成直径长度，尚未统计所有直径的公共边）

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
vector <pair<int, int>> g[N];

ll dp[N];
ll dis[N];
int further;
ll ans;

void dfs(int u, int father){
    if (dis[u] > dis[further]){
        further = u;
    }
    for (auto [v, w] : g[u]){
        if (v == father){
            continue;
        }
        dis[v] = dis[u] + w;
        dfs(v, u);
    }
}

/* 树形dp
void dfs(int u, int father){
    dp[u] = 0;
    for (auto [v, w] : g[u]){
        if (v == father){
            continue;
        }
        dfs(u, v);
        ans = max(ans, dp[u] + dp[v] + w);
        dp[u] = max(dp[u], dp[v] + w);
    }
} */

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    // 从随意一个起点出发，达到的最远的点，必定是直径的一个端点（A）
    // 再从A出发，最远的那个节点就是直径的另一个端点（B）
    // A-B就是直径

    int st = 1;
    dis[st] = 0;
    dfs(1, 0);

    int A = further;

    dis[A] = 0;
    dfs(A, 0);
    int B = further;

    cout << dis[B] << '\n';
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
