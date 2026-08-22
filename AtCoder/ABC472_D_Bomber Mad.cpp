// 比赛：AtCoder Beginner Contest 472
// 题目：D - Bomber Mad
// 链接：https://atcoder.jp/contests/abc472/tasks/abc472_d
// 状态：待验证
// 算法：多源 BFS、网格最短路

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve(){
    int h, w, k;
    cin >> h >> w >> k;
    vector <string> s(h);
    for (int i = 0; i < h; i ++){
        cin >> s[i];
    }
    vector <bool> row(h, false);
    vector <bool> col(w, false);
    for (int i = 0; i < h; i ++){
        bool vis = false;
        for (int j = 0; j < w; j ++){
            if (s[i][j] == '#'){
                vis = true;
                break;
            }
        }
        if (!vis){
            row[i] = true;
        }
    }
    for (int j = 0; j < w; j ++){
        bool vis = false;
        for (int i = 0; i < h; i ++){
            if (s[i][j] == '#'){
                vis = true;
                break;
            }
        }
        if (!vis){
            col[j] = true;
        }
    }
    vector <vector <int>> dis(h, vector <int>(w, -1));
    queue <pair<int, int>> q;
    for (int i = 0; i < h; i ++){
        for (int j = 0; j < w; j ++){
            if (s[i][j] == '.' && row[i] && col[j]){
                dis[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (q.size()){
        auto [x, y] = q.front();
        q.pop();
        if (dis[x][y] == k){
            continue;
        }
        for (int i = 0; i < 4; i ++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && s[nx][ny] == '.' && dis[nx][ny] == -1){
                dis[nx][ny] = dis[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < h; i ++){
        for (int j = 0; j < w; j ++){
            if (dis[i][j] != -1){
                cnt ++;
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
