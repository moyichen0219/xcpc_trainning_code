// 平台：洛谷
// 题目：P5318 【深基18.例3】查找文献
// 链接：https://www.luogu.com.cn/problem/P5318
// 状态：已通过
// 算法：图遍历、DFS、BFS、邻接表排序

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
const int N = 1e5 + 10;
vector <int> g[N];
vector <int> vis(N + 1);

void dfs(int st){
    cout << st << ' ';
    vis[st] = 1;
    for (auto v : g[st]){
        if (!vis[v]){
            dfs(v);
        }
    }
}

void bfs(int st){
    vector <int> vis(n + 1, 0);
    queue <int> q;
    q.push(st);
    vis[st] = 1;
    while (q.size()){
        int u = q.front();
        cout << u << ' ';
        q.pop();
        for (auto v : g[u]){
            if (!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

void solve(){

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i ++){
        sort(g[i].begin(), g[i].end());
    }
    dfs(1);
    cout << '\n';
    bfs(1);
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
