// 比赛：AtCoder Beginner Contest 239
// 题目：E - Subtree K-th Max
// 链接：https://atcoder.jp/contests/abc239/tasks/abc239_e
// 状态：已通过
// 算法：树上 DFS、Top-K 合并

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
vector <ll> x(N);
vector <ll> g[N];
vector <ll> mx[N];

void dfs(int u, int fa){
    mx[u].push_back(x[u]);
    for (auto v : g[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        for (auto x : mx[v]){
            mx[u].push_back(x);
        }
    }
    sort(mx[u].begin(), mx[u].end(), greater<int>());
    // 注意到 k <= 20, 那么只用保留前20个大数即可
    if (mx[u].size() >= 20){
        mx[u].resize(20);
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++){
        cin >> x[i];
    }
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    while (q --){
        int v, k;
        cin >> v >> k;
        // sort(mx[v].begin(), mx[v].end(), greater<int>());
        cout << mx[v][k - 1] << '\n';
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
