// 比赛：AtCoder Beginner Contest 325
// 题目：ABC325 C - Sensors
// 链接：https://atcoder.jp/contests/abc325/tasks/abc325_c
// 状态：已通过
// 算法：BFS、网格连通块

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
vector <string> g(N);
bool vis[N][N];
int h, w;
int ans = 0;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1,  0,  1,-1, 1,-1, 0, 1};

void bfs(int x, int y){
    vis[x][y] = true;
    queue <pair<int, int>> q;
    q.push({x, y});
    while (q.size()){
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 8; i ++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w){
                if (!vis[nx][ny] && g[nx][ny] == '#'){
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }
}

void solve(){
    cin >> h >> w;
    for (int i = 0; i < h; i ++){
        cin >> g[i];
    }
    for (int i = 0; i < h; i ++){
        for (int j = 0; j < w; j ++){
            if (!vis[i][j] && g[i][j] == '#'){
                bfs(i, j);
                ans ++;
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
    while (t --){
        solve();
    }
    return 0;
}
