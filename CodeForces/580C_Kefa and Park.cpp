// 比赛：Codeforces Round 321 (Div. 2)
// 题目：580C - Kefa and Park
// 链接：https://codeforces.com/problemset/problem/580/C
// 状态：已通过
// 算法：树上 DFS、连续段约束、叶子计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int n, m;
int a[N];
vector <int> g[N];
int ans = 0;

void dfs(int u, int fa, int cnt){
    if (a[u]){
        cnt ++;
    } else {
        cnt = 0;
    }
    if (cnt > m){
        return ;
    }
    bool leaf = true;
    for (auto v : g[u]){
        if (v == fa){
            continue;
        }
        leaf = false;
        dfs(v, u, cnt);
    }
    if (leaf){
        ans ++;
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int i = 1; i < n; i ++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 1, 0);
    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t --){
        solve();
    }
    return 0;
}
