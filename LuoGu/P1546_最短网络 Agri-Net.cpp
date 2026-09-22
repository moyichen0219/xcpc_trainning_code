// 比赛：USACO Training Section 3.1
// 题目：P1546 - 最短网络 Agri-Net
// 链接：https://www.luogu.com.cn/problem/P1546
// 状态：已通过
// 算法：Kruskal、最小生成树、并查集

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge{
    int u;
    int v;
    int w;
    bool operator < (const Edge& other) const {
        if (w != other.w){
            return w < other.w;
        }
        if (u != other.u){
            return u < other.u;
        }
        return v < other.v;
    }
};

const int N = 110;
const int inf = 1e9;
int a[N][N];
int fa[N];
vector <Edge> g;

int root(int x){
    return (fa[x] == x) ? x : fa[x] = root(fa[x]);
}

void merge(int x, int y){
    int rx = root(x);
    int ry = root(y);

    if (rx != ry){
        fa[rx] = ry;
    }
}

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        fa[i] = i;
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = i + 1; j <= n; j ++){
            g.push_back({i, j, a[i][j]});
        }
    }

    sort(g.begin(), g.end());

    int ans = 0;
    for (auto [u, v, w] : g){
        if (root(u) == root(v)){
            continue;
        } else {
            merge(u, v);
            ans += w;
        }
    }

    for (int i = 1; i < n; i ++){
        if (root(i) != root(i + 1)){
            ans = -1;
            break;
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
