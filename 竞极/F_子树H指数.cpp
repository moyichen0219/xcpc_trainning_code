// 比赛：竞极比赛 2093329939779661825
// 题目：F 子树 H 指数（本地语义命名）
// 链接：http://47.120.23.84/contest/2093329939779661825/2093331392757870593
// 状态：待验证
// 算法：动态开点线段树合并、树上 DFS、二分答案

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
vector <ll> a(N);
vector <ll> g[N];
vector <ll> cnt(N);

void dfs(int u, int fa){
    if (a[u] >= a[fa]){
        cnt[fa] ++;
    }
    for (auto v : g[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        if (a[v] >= a[u]){
            cnt[u] += cnt[v];
        }
    }
}

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i ++){
        cout << cnt[i] + 1 << ' ';
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
} */


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
vector <int> g[N];

void pushup(int p){
    tree[p].sum = tree[tree[p].ls].sum + tree[tree[p].rs].sum;
}

// 在值域x这个位置加入一个元素
void upd(int &p, int l, int r, int x){
    if (!p){
        p = ++tot;
    }

    if (l == r){
        tree[p].sum ++;
        return ;
    }

    int mid = (l + r) >> 1;

    if (x <= mid){
        upd(tree[p].ls, l, mid, x);
    } else {
        upd(tree[p].rs, mid + 1, r, x);
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
        upd(root[u], 1, n, min(a[u], n));
    }

    for (auto v : g[u]){
        if (v == fa){
            continue;
        }

        dfs(v, u);

        sz[u] += sz[v];
        root[u] = merge(root[u], root[v], 1, n);
    }


    // 子树中能力值 >= h 的人数是否 >= h
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


// 每个节点都建立一颗权值线段树，只插入a[u]
// dfs回溯将儿子都与父亲合并
// root[u]就是u子树的能力值频率
// 二分查找最大能满足的子树中能力值 >= h 的人数是否 >= h
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
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
