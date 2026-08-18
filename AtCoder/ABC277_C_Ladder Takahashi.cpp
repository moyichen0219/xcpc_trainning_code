// 比赛：AtCoder Beginner Contest 277
// 题目：ABC277 C - Ladder Takahashi
// 链接：https://atcoder.jp/contests/abc277/tasks/abc277_c
// 状态：待验证
// 算法：BFS、图遍历、离散顶点

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int bfs(set <int> &s, map <int, vector<int>> &g, int st, int cnt){
    queue <int> q;
    q.push(st);
    s.insert(st);
    cnt = st;
    while(q.size()){
        int x = q.front();
        q.pop();
        cnt = max(cnt, x);
        for (auto v : g[x]){
            if (!s.count(v)){
                s.insert(v);
                q.push(v);
            }
        }
    }
    return cnt;
}

void solve(){
    int n;
    cin >> n;
    set <int> s;
    map <int, vector<int>> g;
    for (int i = 1; i <= n; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (g.find(1) == g.end()){
        cout << 1 << '\n';
        return ;
    }
    s.insert(1);
    cout << bfs(s, g, g[1][0], 1) << '\n';
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
