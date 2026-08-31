// 模板：线段树区间最大值
// 状态：模板
// 功能：建树、区间最大值查询、单点赋值、区间加
// 复杂度：建树 O(n)，单次操作 O(log n)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll a[N];
// tree[p] : 区间最大值
ll tree[N << 2]; // ll tree[4 * N];
// 整个区间待下传的加法
ll lazy[N << 2];

int ls(int p){
    // return 2 * p;
    return p << 1;
}

int rs(int p){
    // return 2 * p + 1
    return p << 1 | 1;
}

void pushup(int p){
    // 维护区间最大值
    tree[p] = max(tree[ls(p)], tree[rs(p)]);
}

void pushdown(int p){
    if (lazy[p] == 0){
        return ;
    }
    tree[ls(p)] += lazy[p];
    tree[rs(p)] += lazy[p];

    lazy[ls(p)] += lazy[p];
    lazy[rs(p)] += lazy[p];

    lazy[p] = 0;
}

void build (int p, int l, int r){
    // 区间操作懒标记
    lazy[p] = 0;

    if (l == r){
        tree[p] = a[l];
        return ;
    }
    int mid = (l + r) >> 1;

    build(ls(p), l, mid);
    build(rs(p), mid  + 1, r);

    pushup(p);
}

// 查询区间最大值
ll query(int p, int l, int r, int L, int R){
    // 如果 [l, r] ∈ [L, R]，那么tree[p]就是答案
    if (L <= l && r <= R){
        return tree[p];
    }

    // 区间操作才需要
    pushdown(p);

    ll ans = -1e18;

    int mid = (l + r) >> 1;
    if (L <= mid){
        ans = max(ans, query(ls(p), l, mid, L, R));
    }
    if (R > mid){
        ans = max(ans, query(rs(p), mid + 1, r, L, R));
    }

    return ans;
}

// 单点修改 a[x] = v
void update_point(int p, int l, int r, int x, ll v){
    if (l == r){
        tree[p] = v;
        return ;
    }

    pushdown(p);

    int mid = (l + r) >> 1;
    if (x <= mid){
        update_point(ls(p), l, mid, x, v);
    } else {
        update_point(rs(p), mid + 1, r, x, v);
    }

    pushup(p);
}

// 区间修改[l, r] + v
void update_range(int p, int l, int r, int L, int R, ll v){
    if (L <= l && r <= R){
        tree[p] += v;
        lazy[p] += v;
        return ;
    }
    pushdown(p);
    int mid = (l + r) >> 1;
    if (L <= mid){
        update_range(ls(p), l, mid, L, R, v);
    }
    if (R > mid){
        update_range(rs(p), mid + 1, r, L, R, v);
    }
    pushup(p);
}

void solve(){

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
