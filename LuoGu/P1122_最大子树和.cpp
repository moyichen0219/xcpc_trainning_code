// 比赛/平台：洛谷
// 题目：P1122 最大子树和
// 链接：https://www.luogu.com.cn/problem/P1122
// 状态：已通过
// 算法：树形动态规划、最大连通子树

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e4;
ll a[N];
ll dp[N];
vector <int> g[N];

void dfs(int u, int fa){
    dp[u] = a[u];
    for (auto v : g[u]){
        if (v == fa){
            continue;
        }

        dfs(v, u);

        dp[u] += max(0ll, dp[v]);
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

    cout << *max_element(dp + 1, dp + n + 1) << '\n';
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
