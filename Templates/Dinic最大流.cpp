// 模板：Dinic 最大流
// 状态：模板
// 复杂度：一般图上 O(V^2E)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 10;
const ll INF = 1e18;

struct Edge {
    int to;  // 指向的点
    ll cap;  // 当前剩余容量
};

vector<Edge> edge;
vector<int> g[N];

int dep[N];  // 分层图
int cur[N];  // 当前弧优化
int S, T;    // 源点、汇点

// 加一条有向边 u -> v，容量为 cap
void add_edge(int u, int v, ll cap) {
    // 正向边
    g[u].push_back(edge.size());
    edge.push_back({v, cap});

    // 反向边
    g[v].push_back(edge.size());
    edge.push_back({u, 0});
}

// BFS：建立分层图
bool bfs() {
    memset(dep, -1, sizeof dep);

    queue<int> q;
    dep[S] = 0;
    q.push(S);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // i 是边编号
        for (int i : g[u]) {
            int v = edge[i].to;

            // 没有剩余容量，不能走
            if (edge[i].cap <= 0) {
                continue;
            }

            // 已经分过层
            if (dep[v] != -1) {
                continue;
            }

            dep[v] = dep[u] + 1;
            q.push(v);
        }
    }

    // 如果 T 能到达，说明还存在增广路
    return dep[T] != -1;
}

// DFS：在当前分层图上推流
// flow 表示当前最多还能往下推多少流
ll dfs(int u, ll flow) {
    // 到达汇点
    if (u == T) {
        return flow;
    }

    // 当前弧优化：
    // j 从 cur[u] 开始，而不是每次从 0 开始
    for (int &j = cur[u]; j < static_cast<int>(g[u].size()); j++) {
        int i = g[u][j];
        int v = edge[i].to;

        // 没有剩余容量
        if (edge[i].cap <= 0) {
            continue;
        }

        // 只能走到下一层
        if (dep[v] != dep[u] + 1) {
            continue;
        }

        // 当前最多有 flow，这条边最多允许 edge[i].cap
        ll f = dfs(v, min(flow, edge[i].cap));

        // 成功推流
        if (f > 0) {
            // 正向剩余容量减少
            edge[i].cap -= f;

            // 反向容量增加，允许反悔
            edge[i ^ 1].cap += f;

            return f;
        }
    }

    return 0;
}

// Dinic 求最大流
ll dinic() {
    ll maxflow = 0;

    // 只要还能建立出 S -> T 的分层图
    while (bfs()) {
        // 新一轮分层图，当前弧重新初始化
        memset(cur, 0, sizeof cur);

        // 在当前分层图中不断推流
        while (true) {
            ll f = dfs(S, INF);

            // 当前分层图已经推不动
            if (f == 0) {
                break;
            }

            maxflow += f;
        }
    }

    return maxflow;
}

void solve() {
    int n, m;
    cin >> n >> m >> S >> T;

    // 如果多测，需要清空
    edge.clear();

    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        ll cap;
        cin >> u >> v >> cap;

        add_edge(u, v, cap);
    }

    cout << dinic() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Tcase = 1;
    // cin >> Tcase;

    while (Tcase--) {
        solve();
    }

    return 0;
}
