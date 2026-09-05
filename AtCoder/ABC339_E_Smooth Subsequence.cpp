// 比赛：AtCoder Beginner Contest 339
// 题目：E - Smooth Subsequence
// 链接：https://atcoder.jp/contests/abc339/tasks/abc339_e
// 状态：已通过
// 算法：动态规划、线段树、区间最大值

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 10;
int a[N];
ll dp[N];
int tree[N << 2];

void upd(int p, int l, int r, int x, int val){
    if (l == r){
        tree[p] = max(tree[p], val);
        return ;
    }

    int mid = (l + r) >> 1;

    if (x <= mid){
        upd(p << 1, l, mid, x, val);
    } else {
        upd(p << 1 | 1, mid + 1, r, x, val);
    }

    tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
}

ll query(int p, int l, int r, int  L, int R){
    if (L <= l && r <= R){
        return tree[p];
    }

    ll res = 0;

    int mid = (l + r) >> 1;

    if (L <= mid){
        res = max (res, query(p << 1, l, mid, L, R));
    }

    if (R > mid){
        res = max(res, query(p << 1 | 1, mid + 1, r, L, R));
    }

    return res;
}


void solve(){
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    ll ans = 0;

    for (int i = 1; i <= n; i ++){
        int l = max(1, a[i] - d);
        int r = min(500000, a[i] + d);

        dp[i] = query(1, 1, 500000, l, r) + 1;

        ans = max(ans, dp[i]);

        upd(1, 1, 500000, a[i], dp[i]);
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
}
