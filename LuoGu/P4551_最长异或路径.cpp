// 比赛：洛谷
// 题目：P4551 - 最长异或路径
// 链接：https://www.luogu.com.cn/problem/P4551
// 状态：已通过
// 算法：树上前缀异或、DFS、01 字典树

/* // https://www.luogu.com.cn/problem/P4551

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int son[32 * N][2];
int idx = 0;

vector <pair<int, int>> g[N];
int d[N];

int ans = 0;

void insert(int x){
    int p = 0;

    for (int i = 30; i >= 0; i --){
        int bit = (x >> i) & 1;

        if (!son[p][bit]){
            son[p][bit] = ++ idx;
        }

        p = son[p][bit];
    }
}

int query(int x){
    int p = 0;
    int res = 0;

    for (int i = 30; i >= 0; i --){
        int bit = (x >> i) & 1;

        if (son[p][bit ^ 1]){
            p = son[p][bit ^ 1];
            res |= (1 << i);
        } else {
            p = son[p][bit];
        }
    }

    return res;
}

void dfs(int u, int fa){
    for (auto [v, w] : g[u]){
        if (v == fa){
            continue;
        }

        d[v] = (d[u] ^ w);
        dfs(v, u);
    }
}

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n - 1; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    d[1] = 0;
    dfs(1, 0);

    insert(d[1]);
    for (int i = 2; i <= n; i ++){
        ans = max(ans, query(d[i]));
        insert(d[i]);
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


// https://www.luogu.com.cn/problem/P4551

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int son[32 * N][2];
int idx = 0;

vector <pair<int, int>> g[N];
int d[N];

int ans = 0;

void insert(int x){
    int p = 0;

    for (int i = 30; i >= 0; i --){
        int bit = (x >> i) & 1;

        if (!son[p][bit]){
            son[p][bit] = ++ idx;
        }

        p = son[p][bit];
    }
}

int query(int x){
    int p = 0;
    int res = 0;

    for (int i = 30; i >= 0; i --){
        int bit = (x >> i) & 1;

        if (son[p][bit ^ 1]){
            p = son[p][bit ^ 1];
            res |= (1 << i);
        } else {
            p = son[p][bit];
        }
    }

    return res;
}

void dfs(int u, int fa){
    for (auto [v, w] : g[u]){
        if (v == fa){
            continue;
        }

        d[v] = (d[u] ^ w);
        ans = max(ans, query(d[v]));

        insert(d[v]);
        dfs(v, u);
    }
}

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n - 1; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    insert(0);

    dfs(1, 0);

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
