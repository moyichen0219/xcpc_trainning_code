// 比赛：洛谷题库
// 题目：P3376 【模板】网络最大流
// 链接：https://www.luogu.com.cn/problem/P3376
// 状态：已通过
// 算法：Dinic、最大流、分层图、当前弧优化

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge{
    int to;
    ll cap;
};

const int N = 200 + 10;
const int M = 5e3 + 10;
const ll INF = 1e18;
vector <int> g[N];
vector <Edge> edge;

int dep[N];
int cur[N];
int S, T;

void add_edge(int u, int v, ll cap){
    g[u].push_back(edge.size());
    edge.push_back({v, cap});

    g[v].push_back(edge.size());
    edge.push_back({u, 0});
}

bool bfs(){
    memset(dep, -1, sizeof dep);

    queue <int> q;
    q.push(S);
    dep[S] = 0;

    while (q.size()){
        int u = q.front();
        q.pop();
        for (int i : g[u]){
            int v = edge[i].to;
            if (edge[i].cap == 0){
                continue;
            }
            if (dep[v] != -1){
                continue;
            }
            dep[v] = dep[u] + 1;
            q.push(v);
        }
    }
    return dep[T] != -1;
}

ll dfs(int u, ll flow){
    if (u == T){
        return flow;
    }
    for (int &j = cur[u]; j < g[u].size(); j ++){
        int i = g[u][j];
        int v = edge[i].to;
        if (edge[i].cap == 0){
            continue;
        }
        if (dep[v] != dep[u] + 1){
            continue;
        }
        ll f = dfs(v, min(flow, edge[i].cap));
        if (f > 0){
            edge[i].cap -= f;
            edge[i ^ 1].cap += f;
            return f;
        }
    }
    return 0;
}

ll dinic(){
    ll maxflow = 0;
    while (bfs()){
        memset(cur, 0, sizeof cur);
        while (true){
            ll f = dfs(S, INF);
            if (f == 0){
                break;
            }
            maxflow += f;
        }
    }
    return maxflow;
}

void solve(){
    int n, m;
    cin >> n >> m >> S >> T;
    for (int i = 1; i <= m; i ++){
        int u, v;
        ll cap;
        cin >> u >> v >> cap;
        add_edge(u, v, cap);
    }
    cout << dinic() << '\n';
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
