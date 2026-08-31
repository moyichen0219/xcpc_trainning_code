// 比赛：竞极比赛 2093329939779661825
// 题目：D 反转一条边最短路（本地语义命名）
// 链接：http://47.120.23.84/contest/2093329939779661825/2093331392753676290
// 状态：待验证
// 算法：Dijkstra、正反图、枚举反向边

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
// 正边
vector <int> g[N];
// 反边
vector <int> g1[N];
vector <bool> vis(N, false);
vector <ll> a(N);

int n, m;
ll ans = 4e18;
vector <int> path[N];

// 点，已经使用的费用, 是否使用反边
void dfs(int u, ll w, bool ok){
    if (u == n){
        ans = min(ans, w);
        return ;
    }
    for (auto v : g[u]){
        if (v == u){
            continue;
        }
        vis[v] = true;
        dfs(v, w + a[v], false);
        vis[v] = false;
    }
    if (!ok){
        for (auto v : g1[u]){
            // 走过的不用倒回去走
            if (!vis[v]){
                vis[v] = true;
                dfs(v, w + a[v], true);
                vis[v] = false;
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g1[v].push_back(u);
    }
    dfs(1, 0, false);
    if (ans == 4e18){
        cout << -1 << '\n';
        return ;
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
} */

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
const int N = 2e5 + 10;
const ll INF = 4e18;

struct Edge{
    int v;
    ll w;
    bool operator < (const Edge & u) const {
        return w > u.w;
    }
};

struct node{
    int u, v, w;
};
vector <node> edge;

vector <Edge> g[N];
vector <Edge> rg[N];
vector <ll> d1(N);
vector <ll> d2(N);

void dijkstra(int st, vector <ll> &d, vector <Edge> g[]){
    fill (d.begin(), d.end(), INF);
    d[st] = 0;
    bitset <N> vis;
    priority_queue <Edge> pq;
    pq.push({st, d[st]});
    while (pq.size()){
        int x = pq.top().v;
        pq.pop();
        if (vis[x]){
            continue;
        }
        vis[x] = true;
        for (auto &[y, w] : g[x]){
            if (!vis[y] && d[y] > d[x] + w){
                d[y] = d[x] + w;
                pq.push({y, d[y]});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        rg[v].push_back({u, w});
        edge.push_back({u, v, w});
    }

    dijkstra(1, d1, g);
    dijkstra(n, d2, rg);

    ll ans = d1[n];
    // u: 3, v: 2
    // d1[2] + d2[3] + w
    for (auto [u, v, w] : edge){
        if (d1[v] == INF || d2[u] == INF){
            continue;
        }
        /* if (d1[v] + d2[u] + w < ans){
            cout << u << ' ' << v << '\n';
            cout << d1[v] + d2[u] + w << '\n';
        } */
        ans = min(ans, d1[v] + d2[u] + w);
    }

    if (ans == INF){
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
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
