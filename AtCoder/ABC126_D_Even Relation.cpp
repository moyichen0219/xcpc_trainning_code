// 比赛：AtCoder Beginner Contest 126
// 题目：D - Even Relation
// 链接：https://atcoder.jp/contests/abc126/tasks/abc126_d
// 状态：已通过
// 算法：树上 DFS、二分图染色、路径奇偶性

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    int v, w;
};

const int N = 1e5 + 10;
vector <node> g[N];
int c[N];

void dfs(int u, int fa){
    for (auto [v, w] : g[u]){
        if (v == fa){
            continue;
        }

        if (w % 2 == 0){
            c[v] = c[u];
        } else {
            c[v] = (1 ^ c[u]);
        }

        dfs(v, u);
    }
}

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    c[1] = 1;
    dfs(1, 0);

    for (int i = 1; i <= n; i ++){
        cout << c[i] << '\n';
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
