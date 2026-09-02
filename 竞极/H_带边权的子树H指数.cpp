// 比赛：竞极比赛 2093329939779661825
// 题目：H 带边权的子树 H 指数（本地语义命名）
// 链接：http://47.120.23.84/contest/2093329939779661825/2093331392762064898
// 状态：待验证
// 算法：动态开点线段树合并、截断、批量计数、树上 DFS、二分答案

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const int M = N * 40;

struct Node{
    int ls;
    int rs;
    int sum;
}tree[M];

int n, m;
int tot;
int a[N];
int root[N];
int sz[N];
int ans[N];
vector <pair<int, int>> g[N];

void pushup(int p){
    tree[p].sum = tree[tree[p].ls].sum + tree[tree[p].rs].sum;
}

void upd(int &p, int l, int r, int x, int val){
    if (!p){
        p = ++tot;
    }

    if (l == r){
        tree[p].sum += val;
        return ;
    }

    int mid = (l + r) >> 1;

    if (x <= mid){
        upd(tree[p].ls, l, mid, x, val);
    } else {
        upd(tree[p].rs, mid + 1, r, x, val);
    }

    pushup(p);
}

int merge(int x, int y, int l, int r){
    if (!x || !y){
        return x | y;
    }

    if (l == r){
        tree[x].sum += tree[y].sum;
        return x;
    }

    int mid = (l + r) >> 1;

    tree[x].ls = merge(tree[x].ls, tree[y].ls, l, mid);
    tree[x].rs = merge(tree[x].rs, tree[y].rs, mid + 1, r);

    pushup(x);
    return x;
}

int cut (int &p, int l, int r, int w){
    if (!p){
        return 0;
    }

    // 最大的都小于等于w，没有要截断的
    if (r <= w){
        return 0;
    }

    if (l > w){
        int cnt = tree[p].sum;
        p = 0;
        return cnt;
    }

    int mid = (l + r) >> 1;

    int cnt = 0;

    cnt += cut(tree[p].ls, l, mid, w);
    cnt += cut(tree[p].rs, mid + 1, r, w);

    pushup(p);

    return cnt;
}

int query(int p, int l, int r, int ql, int qr){
    if (!p){
        return 0;
    }

    if (ql <= l && r <= qr){
        return tree[p].sum;
    }

    int mid = (l + r) >> 1;

    int res = 0;

    if (ql <= mid){
        res += query(tree[p].ls, l, mid, ql, qr);
    }

    if (qr > mid){
        res += query(tree[p].rs, mid + 1, r, ql, qr);
    }

    return res;
}

void dfs(int u, int fa){
    sz[u] = 1;

    if (a[u] > 0){
        upd(root[u], 1, n, min(a[u], n), 1);
    }

    for (auto [v, w] : g[u]){
        if (v == fa){
            continue;
        }

        dfs(v, u);

        sz[u] += sz[v];

        int cnt = cut(root[v], 1, n, w);

        if (cnt){
            upd(root[v], 1, n, w, cnt);
        }

        root[u] = merge(root[u], root[v], 1, n);
    }


    int l = 0;
    int r = sz[u];

    while (l != r){
        int mid = (l + r + 1) >> 1;

        int cnt = query(root[u], 1, n, mid, n);
        if(cnt >= mid){
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    ans[u] = l;
}


// 初始对每个节点都建立一个权值线段树
// dfs u的每一个儿子
// 把所有root[v] > w的变成w
// 将子树合并进u里面
// 二分求H
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int i = 1; i < n; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i ++){
        cout << ans[i] << ' ';
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
