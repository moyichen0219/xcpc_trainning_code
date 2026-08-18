// 比赛：AtCoder Beginner Contest 378
// 题目：ABC378 D - Count Simple Paths
// 链接：https://atcoder.jp/contests/abc378/tasks/abc378_d
// 状态：已通过
// 算法：DFS、回溯、路径计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 15;
vector <string> g(N);
bool vis[N][N];
int h, w, k;
ll ans;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int cnt){
    if (cnt == k){
        ans ++;
        return ;
    }
    for (int i = 0; i < 4; i ++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w){
            if (!vis[nx][ny] && g[nx][ny] == '.'){
                vis[nx][ny] = true;
                dfs(nx, ny, cnt + 1);
                vis[nx][ny] = false;
            }
        }
    }
}

void solve(){
    cin >> h >> w >> k;
    for (int i = 0; i < h ; i ++){
        cin >> g[i];
    }
    for (int i = 0; i < h; i ++){
        for (int j = 0; j < w; j ++){
            if (g[i][j] == '.'){
                vis[i][j] = true;
                dfs(i, j, 0);
                vis[i][j] = false;
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
