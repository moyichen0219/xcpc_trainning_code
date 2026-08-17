// 比赛：AtCoder Beginner Contest 293
// 题目：ABC293 C - Make Takahashi Happy
// 链接：https://atcoder.jp/contests/abc293/tasks/abc293_c
// 状态：待验证
// 算法：DFS、回溯、路径枚举

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 15;
ll g[N][N];
vector <pair <int, int>> path;
set <ll> s;
int h, w;
int ans;

void dfs(int x, int y){
    if (x > h || y > w){
        return;
    }
    if (s.count(g[x][y])){
        return ;
    }
    s.insert(g[x][y]);
    if (x == h && y == w){
        ans ++;
        s.erase(g[h][w]);
        return ;
    }
    if (x < h){
        dfs(x + 1, y);
    }
    if (y < w){
        dfs(x, y + 1);
    }
    s.erase(g[x][y]);
}

void solve(){
    cin >> h >> w;
    for (int i = 1; i <= h; i ++){
        for (int j = 1; j <= w; j ++){
            cin >> g[i][j];
        }
    }
    dfs(1, 1);
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
