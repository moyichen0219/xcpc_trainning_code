// 比赛：AtCoder Beginner Contest 168
// 题目：ABC168 D - .. (Double Dots)
// 链接：https://atcoder.jp/contests/abc168/tasks/abc168_d
// 状态：已通过
// 算法：BFS、最短路树、父节点记录

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> g[n + 1];
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <bool> vis(n + 1, false);
    vector <int> fa(n + 1, 0);
    // fa[1] = 1;
    queue <int> q;
    q.push(1);
    vis[1] = true;
    while (q.size()){
        int u = q.front();
        q.pop();
        for (auto v : g[u]){
            if (!vis[v]){
                vis[v] = true;
                fa[v] = u;
                q.push(v);
            }
        }
    }
    cout << "Yes" << '\n';
    for (int i = 2; i <= n; i ++){
        cout << fa[i] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
