// 比赛：Codeforces Round 871 (Div. 4)
// 题目：1829E - The Lakes
// 链接：https://codeforces.com/problemset/problem/1829/E
// 状态：已通过
// 算法：网格 DFS、连通块

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 10;
int g[N][N];
bool vis[N][N];
int n, m;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

ll dfs(int x, int y){
    vis[x][y] = 1;
    ll res = g[x][y];
    for (int i = 0; i < 4; i ++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m){
            if (!vis[nx][ny] && g[nx][ny] != 0){
                res += dfs(nx, ny);
            }
        }
    }
    return res;
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            vis[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> g[i][j];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (g[i][j] > 0 && !vis[i][j]){
                ll sum = dfs(i, j);
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t --){
        solve();
    }
    return 0;
}
