// 比赛：洛谷
// 题目：P1443 - 马的遍历
// 链接：https://www.luogu.com.cn/problem/P1443
// 状态：已通过
// 算法：BFS、网格最短路、马步遍历

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 410;

const int inf = 1e9 + 10;
int d[N][N];

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, -1, 1, -1, 1};

void solve(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            d[i][j] = inf;
        }
    }

    d[x][y] = 0;
    queue <pair<int, int>> q;
    q.push({x, y});
    while (q.size()){
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 8; i ++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m){
                if (d[nx][ny] > d[x][y] + 1){
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (d[i][j] == inf){
                cout << -1 << ' ';
                continue;
            }
            cout << d[i][j] << ' ';
        }
        cout << '\n';
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
