// 比赛：NOIP 2000 提高组
// 题目：P1004 - 方格取数
// 链接：https://www.luogu.com.cn/problem/P1004
// 状态：未完成
// 算法：贪心尝试（应改为双路径动态规划）

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10;
int g[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

ll dijkstra(int st){
    ll res = 0;

    queue<pair<int, int>> q;
    q.push({1, 1});

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        int mx = 0;
        int nxx = 0, nyy = 0;
        for (int i = 0; i < 4; i ++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (g[nx][ny] >= mx){
                nxx = nx;
                nyy = ny;
                mx = g[nxx][nyy];
            }
        }

        g[nxx][nyy] = 0;
        res += mx;
        q.push({nxx, nyy});
    }

    return res;
}

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            g[i][j] = 0;
        }
    }

    while (true){
        int x, y, v;
        cin >> x >> y >> v;
        if (x == 0 && y == 0 && v == 0){
            break;
        }
        g[x][y] = v;
    }

    cout << "a" << '\n';
    ll ans = 0;
    ans += dijkstra(1);
    ans += dijkstra(1);

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
