// 模板：线段树维护区间加与区间 GCD
// 状态：模板
// 方法：差分数组、区间和、区间最大公约数
// 复杂度：建树 O(n)，单次操作 O(log n)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;

ll a[N];
ll d[N];

struct Node{
    ll sum;   // 差分区间和
    ll g;     // 差分区间 gcd
} tree[N << 2];

int ls(int p){
    return p << 1;
}

int rs(int p){
    return p << 1 | 1;
}

void pushup(int p){
    tree[p].sum = tree[ls(p)].sum + tree[rs(p)].sum;

    tree[p].g = gcd(
        tree[ls(p)].g,
        tree[rs(p)].g
    );
}

void build(int p, int l, int r){
    if (l == r){
        tree[p].sum = d[l];
        tree[p].g = d[l];
        return;
    }

    int mid = (l + r) >> 1;

    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);

    pushup(p);
}

// 差分数组单点 +v
void update_point(int p, int l, int r, int x, ll v){
    if (l == r){
        tree[p].sum += v;
        tree[p].g += v;
        return;
    }

    int mid = (l + r) >> 1;

    if (x <= mid){
        update_point(ls(p), l, mid, x, v);
    } else {
        update_point(rs(p), mid + 1, r, x, v);
    }

    pushup(p);
}

// 查询差分数组 [L,R] 的和
ll query_sum(int p, int l, int r, int L, int R){
    if (L <= l && r <= R){
        return tree[p].sum;
    }

    int mid = (l + r) >> 1;

    ll ans = 0;

    if (L <= mid){
        ans += query_sum(ls(p), l, mid, L, R);
    }

    if (R > mid){
        ans += query_sum(rs(p), mid + 1, r, L, R);
    }

    return ans;
}

// 查询差分数组 [L,R] 的 gcd
ll query_gcd(int p, int l, int r, int L, int R){
    if (L <= l && r <= R){
        return tree[p].g;
    }

    int mid = (l + r) >> 1;

    ll ans = 0;

    if (L <= mid){
        ans = gcd(
            ans,
            query_gcd(ls(p), l, mid, L, R)
        );
    }

    if (R > mid){
        ans = gcd(
            ans,
            query_gcd(rs(p), mid + 1, r, L, R)
        );
    }

    return ans;
}

// 原数组区间 [L,R] 全部 +v
void update_range(int n, int L, int R, ll v){

    // d[L] += v
    update_point(1, 1, n, L, v);

    // d[R + 1] -= v
    if (R + 1 <= n){
        update_point(1, 1, n, R + 1, -v);
    }
}

// 查询原数组 [L,R] 的 gcd
ll query_range(int n, int L, int R){

    // a[L] = d[1] + d[2] + ... + d[L]
    ll aL = query_sum(1, 1, n, 1, L);

    // 只有一个数
    if (L == R){
        return abs(aL);
    }

    // gcd(d[L+1], ..., d[R])
    ll g = query_gcd(1, 1, n, L + 1, R);

    return abs(gcd(aL, g));
}

void solve(){
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // 建立差分数组
    d[1] = a[1];

    for (int i = 2; i <= n; i++){
        d[i] = a[i] - a[i - 1];
    }

    build(1, 1, n);

    while (q--){
        int op;
        cin >> op;

        if (op == 1){
            // [L,R] + v
            int L, R;
            ll v;

            cin >> L >> R >> v;

            update_range(n, L, R, v);
        } else {
            // 查询 gcd(a[L], ..., a[R])
            int L, R;
            cin >> L >> R;

            cout << query_range(n, L, R) << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    while (t--){
        solve();
    }

    return 0;
}
