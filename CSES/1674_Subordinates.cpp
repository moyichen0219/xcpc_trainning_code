// 比赛/平台：CSES Problem Set
// 题目：1674 Subordinates
// 链接：https://cses.fi/problemset/task/1674/
// 状态：待验证
// 算法：树形动态规划、DFS、子树大小

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
vector <int> g[N];
int sz[N];

void dfs(int u, int fa){
    sz[u] = g[u].size();

    for (auto v : g[u]){
        if (v == fa){
            continue;
        }

        dfs(v, u);
        sz[u] += sz[v];
    }
}

void solve(){
    int n;
    cin >> n;

    for (int i = 2; i <= n; i ++){
        int u;
        cin >> u;

        g[u].push_back(i);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i ++){
        cout << sz[i] << ' ';
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
