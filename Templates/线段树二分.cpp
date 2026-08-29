// 模板：线段树二分
// 状态：模板（待修正）
// 功能：区间最大值、区间加、查找首个或末个不小于阈值的位置
// 已知问题：find_lst 的左右子树区间参数写反
// 复杂度：建树 O(n)，单次操作 O(log n)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll a[N];
ll tree[N << 2];
ll lazy[N << 2];

int ls(int p){
    return p << 1;
}

int rs(int p){
    return p << 1 | 1;
}

void pushup(int p){
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

void build(int p, int l, int r){
    lazy[p] = 0;

    if (l == r){
        tree[p] = a[l];
        return ;
    }

    int mid = (l + r) >> 1;

    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);

    pushup(p);
}

// 查询区间最大值
ll query(int p, int l, int r, int L, int R){
    if (L <= l && r <= R){
        return tree[p];
    }

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
void upd_p(int p, int l, int r, int x, ll v){
    if (l == r){
        tree[p] = v;
        return ;
    }

    pushdown(p);

    int mid = (l + r) >> 1;
    if (x <= mid){
        upd_p(ls(p), l, mid, x, v);
    } else {
        upd_p(rs(p), mid + 1, r, x, v);
    }

    pushup(p);
}

void upd_r(int p, int l ,int r, int L, int R, ll v){
    if (L <= l && r <= R){
        tree[p] += v;
        lazy[p] += v;
        return ;
    }

    pushdown(p);

    int mid = (l + r) >> 1;
    if (L <= mid){
        upd_r(ls(p), l, mid, L, R, v);
    }
    if (R > mid){
        upd_r(rs(p), mid + 1, r, L, R, v);
    }

    pushup(p);
}

// 第一个满足条件的位置:找 [L,R] 中第一个 a[i] >= x 的位置。
int find_1(int p, int l, int r, int L, int R, ll x){
    if (r < L || l > R){
        return -1;
    }
    if (tree[p] < x){
        return -1;
    }
    if (l == r){
        return l;
    }

    pushdown(p);

    int mid = (l + r) >> 1;
    int res = find_1(ls(p), l, mid, L, R, x);

    if (res != -1){
        return res;
    }

    return find_1(rs(p), mid + 1, r, L, R, x);
}

// 最后一个满足条件的位置:找 [L,R] 中最后一个 a[i] >= x 的位置。
int find_lst(int p, int l, int r, int L, int R, ll x){
    if (r < L || l > R){
        return -1;
    }
    if (tree[p] < x){
        return -1;
    }
    if (l == r){
        return l;
    }

    pushdown(p);

    int mid = (l + r) >> 1;
    int res = find_lst(rs(p), mid + 1, r, L, R, x);

    if (res != -1){
        return res;
    }

    return find_lst(ls(p), l, mid, L, R, x);
}

int kth(int p, int l, int r, int k){
    if (l == r){
        return l;
    }

    int mid = (l + r) >> 1;

    if (tree[ls(p)] >= k){
        return kth(ls(p), l, mid, k);
    } else {
        return kth(rs(p), mid + 1, r, k - tree[ls(p)]);
    }

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
