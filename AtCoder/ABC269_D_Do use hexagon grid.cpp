// 比赛：AtCoder Beginner Contest 269
// 题目：ABC269 D - Do use hexagon grid
// 链接：https://atcoder.jp/contests/abc269/tasks/abc269_d
// 状态：已通过
// 算法：BFS、连通块、六边形网格

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0, -1, -1, 1, 1, 0};
int dy[] = {-1, 0, -1, 1, 0, 1};

void solve(){
    int n;
    cin >> n;
    set<pair<int,int>> st;
    set<pair<int,int>> vis;
    for (int i = 1; i <= n; i ++){
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
    }
    int ans = 0;
    for (auto [x, y] : st){
        if (vis.count({x, y})){
            continue;
        }
        ans ++;
        queue <pair<int, int>> q;
        q.push({x, y});
        vis.insert({x, y});
        while (q.size()){
            auto [x, y] = q.front();
             q.pop();
             for (int i = 0; i < 6; i ++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (st.count({nx, ny}) && !vis.count({nx, ny})){
                    q.push({nx, ny});
                    vis.insert({nx, ny});
                }
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
