// 比赛：CSES Graph Algorithms
// 题目：1192 - Counting Rooms
// 链接：https://cses.fi/problemset/task/1192/
// 状态：待验证
// 算法：BFS、网格连通块

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
char g[N][N];
bool vis[N][N];
int cnt = 0;
int n, m;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int x, int y){
    queue <pair <int, int>> q;

    q.push({x, y});
    while (!q.empty()){
        auto [u, v] = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++){
            int nx = u + dx[i];
            int ny = v + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m){
                if (g[nx][ny] == '.' && !vis[nx][ny]){
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

void solve(){

    cin >> n >> m;

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> g[i][j];
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (g[i][j] == '.' && !vis[i][j]){
                cnt ++;
                bfs(i, j);
            }
        }
    }

    cout << cnt << '\n';
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
