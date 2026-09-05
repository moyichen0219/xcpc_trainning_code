// 比赛：Codeforces Round 444
// 题目：444C - DZY Loves Colors
// 链接：https://codeforces.com/problemset/problem/444/C
// 状态：已通过
// 算法：线段树、区间推平、区间加、历史贡献

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int n, m;

struct node{
    ll sum = 0;
    int col;
    ll add = 0;
};

node tree[N << 2];

int ls(int p){
    return p << 1;
}

int rs(int p){
    return p << 1 | 1;
}

void pushup(int p){
    tree[p].sum = tree[ls(p)].sum + tree[rs(p)].sum;

    if (tree[ls(p)].col != tree[rs(p)].col){
        tree[p].col = -1;
    } else {
        tree[p].col = tree[ls(p)].col;
    }
}

void pushdown(int p, int l, int r){
    if (l == r){
        return ;
    }

    int mid = (l + r) >> 1;

    if (tree[p].add){
        tree[ls(p)].sum += 1LL * tree[p].add * (mid - l + 1);
        tree[rs(p)].sum += 1LL * tree[p].add * (r - mid);

        tree[ls(p)].add += tree[p].add;
        tree[rs(p)].add += tree[p].add;

        tree[p].add = 0;
    }

    if (tree[p].col != -1){
        tree[ls(p)].col = tree[p].col;
        tree[rs(p)].col = tree[p].col;
    }
}

void build (int p, int l, int r){
    if (l == r){
        tree[p].col = l;
        return ;
    }

    int mid = (l + r) >> 1;

    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);

    pushup(p);
}

void upd(int p, int l, int r, int L, int R, ll v){
    if (L <= l && r <= R){
        if (tree[p].col != -1){
            tree[p].sum += 1LL * abs(v - tree[p].col) * (r - l + 1);
            tree[p].add += abs(v - tree[p].col);
            tree[p].col =v;
            return ;
        }
    }

    pushdown(p, l, r);

    int mid = (l + r) >> 1;

    if (L <= mid){
        upd(ls(p), l, mid, L, R, v);
    }

    if (R > mid){
        upd(rs(p), mid + 1, r, L, R, v);
    }

    pushup(p);
}

ll query(int p, int l, int r, int L, int R){
    if (L <= l && r <= R){
        return tree[p].sum;
    }

    pushdown(p, l, r);

    ll ans = 0;

    int mid = (l + r) >> 1;

    if (L <= mid){
        ans += query(ls(p), l, mid, L, R);
    }

    if (R > mid){
        ans += query(rs(p), mid + 1, r, L, R);
    }

    return ans;
}

void solve(){
    cin >> n >> m;
    build(1, 1, n);
    for (int i = 1; i <= m; i ++){
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1){
            int x;
            cin >> x;
            // upd
            upd(1, 1, n, l, r, x);
        } else if (op == 2){
            // query()
            ll ans = query(1, 1, n, l, r);
            cout << ans << '\n';
        }
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
