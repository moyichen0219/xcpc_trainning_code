// 模板：线段树查找第 k 个 1
// 状态：模板
// 功能：单点赋值、区间计数、全局或区间第 k 个 1
// 复杂度：单次操作 O(log n)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll a[N];
// 维护区间中 1 的数量
ll tree[N << 2];

int ls (int p){
    return p << 1;
}

int rs(int p){
    return p << 1 | 1;
}

void pushup(int p){
    tree[p] = tree[ls(p)] + tree[rs(p)];
}

void build (int p, int l, int r){
    if (l == r){
        tree[p] = a[l];
        return ;
    }

    int mid = (l + r) >> 1;

    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);

    pushup(p);
}

// 单点赋值 a[x] = v，v 一般是 0/1
void upd(int p, int l, int r, int x, ll v){
    if (l == r){
        tree[p] = v;
        return ;
    }

    int mid = (l + r) >> 1;

    if (x <= mid){
        upd(ls(p), l, mid, x, v);
    } else {
        upd(rs(p), mid + 1, r, x, v);
    }

    pushup(p);
}

// 查询 [L, R] 中 1 的数量
ll query(int p, int l, int r, int L, int R){
    if (L <= l && r <= R){
        return tree[p];
    }

    int mid = (l + r) >> 1;
    ll ans = 0;

    if (L <= mid){
        ans += query(ls(p), l, mid, L, R);
    }
    if (R > mid){
        ans += query(rs(p), mid + 1, r, L, R);
    }

    return ans;
}

// 找整个数组中第 k 个 1 的位置
int kth(int p, int l, int r, ll k){
    if (k <= 0 || tree[p] < k){
        return -1;
    }
    if (l == r){
        return l;
    }

    int mid = (l + r) >> 1;
    ll l_cnt = tree[ls(p)];

    if (l_cnt >= k){
        return kth(ls(p), l, mid, k);
    } else {
        return kth(rs(p), mid + 1, r, k - l_cnt);
    }
}


// 找区间 [L, R] 中第 k 个 1 的位置
// 整个数组中第 (前缀 [1,L-1] 的 1 的数量 + k) 个 1
// 就是全局第 cnt[L - 1] + k 个 1 的位置
int kth_r(int n, int L, int R, ll k){
    if (k <= 0){
        return -1;
    }
    ll pre = 0;

    if (L > 1){
        pre = query(1, 1, n, 1, L - 1);
    }

    ll cnt = query(1, 1, n, L, R);

    if (cnt < k){
        return -1;
    }

    return kth(1, 1, n, pre + k);
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
