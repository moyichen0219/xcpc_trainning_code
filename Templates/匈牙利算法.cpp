// 模板：二分图最大匹配（匈牙利算法）
// 状态：模板
// 复杂度：O(VE)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 510;

vector <int> g[N];

int match[N];
bool vis[N];

bool dfs(int u){
    for (auto v : g[u]){
        if (vis[v]){
            continue;
        }

        vis[v] = true;

        // 这个点原先没有匹配到人 或者 这个点原先匹配到的人可以找到其他人和他匹配
        if (match[v] == 0 || dfs(match[v])){
            match[v] = u;
            return true;
        }
    }
    return false;
}

void solve(){
    int n, m, e;
    cin >> n >> m >> e;
    for (int i = 1; i <= e; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    int ans = 0;

    for (int u = 1 ; u <= n; u ++){
        memset(vis, 0, sizeof(vis));
        if (dfs(u)){
            ans ++;

        }
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
