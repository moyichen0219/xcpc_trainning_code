// 比赛：竞极比赛 2094600238127988737
// 题目：G - 阈值连通块最大值下标异或（本地语义命名）
// 链接：http://47.120.23.84/contest/2094600238127988737/2094602665216524294
// 状态：待验证
// 算法：离线查询、并查集、按边权降序合并

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int pre[N];

struct node{
    int u, v;
    ll w;
};

struct qu{
    int x, k, id;
};

int a[N];
node edge[N];
qu query[N];
int sz[N];
ll ans[N];
ll mx[N];
ll xor_[N];

void init(){
    for (int i = 1; i < N; i ++){
        pre[i] = i;
        sz[i] = 1;
    }
}

int root(int x){
    return pre[x] == x ? x : pre[x] = root(pre[x]);
}

void merge(int x, int y){
    int rtx = root(x);
    int rty = root(y);

    if (rtx == rty){
        return ;
    }

    if (sz[rtx] > sz[rty]){
        swap(rtx, rty);
    }

    pre[rtx] = rty;
    sz[rty] += sz[rtx];

    // 把rtx合并进rty， rty是根
    if (mx[rtx] > mx[rty]){
        mx[rty] = mx[rtx];
        xor_[rty] = xor_[rtx];
    } else if (mx[rtx] == mx[rty]){
        xor_[rty] ^= xor_[rtx];
    }
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        mx[i] = a[i];
        xor_[i] = i;
    }
    for (int i = 1; i <= m; i ++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    for (int i = 1; i <= q; i ++){
        cin >> query[i].x >> query[i].k;
        query[i].id = i;
    }

    sort(edge + 1, edge + m + 1, [](const node& a, node& b){
        return a.w > b.w;
    });
    sort(query + 1, query + q + 1, [](const qu& a, qu& b){
        return a.k > b.k;
    });

    int j = 1;
    for (int i = 1; i <= q; i ++){
        auto [x, k, id] = query[i];
        while (j <= m && edge[j].w >= k){
            merge(edge[j].u, edge[j].v);
            j ++;
        }
        int rt = root(x);
        ans[id] = xor_[rt];
    }

    for (int i = 1; i <= q; i ++){
        cout << ans[i] << '\n';
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    init();
    while (t --){
        solve();
    }
    return 0;
}
