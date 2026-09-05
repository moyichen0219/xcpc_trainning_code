// 比赛：Codeforces Round 474
// 题目：474E - Pillars
// 链接：https://codeforces.com/problemset/problem/474/E
// 状态：已通过
// 算法：动态规划、线段树、离散化、方案恢复

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
ll h[N];
int dp[N];
int pre[N];

struct node{
    // 当前索引
    int id;
    // 最大dp
    int dp;
};

int m;
node tree[N << 2];

node better(const node& a, const node& b){
    if (a.dp != b.dp){
        return a.dp > b.dp ? a : b;
    }
    return a.id < b.id ? a : b;
}

void upd(int p, int l, int r, int x, int val, int id){
    if (l == r){
        if (tree[p].dp < val){
            tree[p].dp = val;
            tree[p].id = id;
        }
        return ;
    }

    int mid = (l + r) >> 1;

    if (x <= mid){
        upd(p << 1, l, mid, x, val, id);
    } else {
        upd(p << 1 | 1, mid + 1, r, x, val, id);
    }

    tree[p] = better(tree[p << 1], tree[p << 1 | 1]);
}

// 返回前驱和最大dp[j]
node query(int p, int l, int r, int ql, int qr){
    if (ql <= l && r <= qr){
        return tree[p];
    }

    int mid = (l + r) >> 1;

    node res = {0, 0};

    if (ql <= mid){
        res = better(res, query(p << 1, l, mid, ql, qr));
    }

    if (qr > mid){
        res = better(res, query(p << 1 | 1, mid + 1, r, ql, qr));
    }

    return res;
}

void solve(){
    ll n, d;
    cin >> n >> d;

    vector <ll> a;

    for (int i = 1; i <= n; i ++){
        cin >> h[i];
        a.push_back(h[i]);
    }

    sort(begin(a), end(a));
    a.erase(unique(begin(a), end(a)), end(a));
    m = a.size();

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        ll l = h[i] - d;
        ll r = h[i] + d;

        node bst = {0, 0};

        int L = upper_bound(a.begin(), a.end(), l) - a.begin();
        if (L >= 1){
            bst = better(bst, query(1, 1, m, 1, L));
        }

        int R = lower_bound(a.begin(), a.end(), r) - a.begin() + 1;
        if (R <= m){
            bst = better(bst, query(1, 1, m, R, m));
        }

        dp[i] = bst.dp + 1;
        pre[i] = bst.id;

        int pos = lower_bound(a.begin(), a.end(), h[i]) - a.begin() + 1;
        upd(1, 1, m, pos, dp[i], i);
    }


    int bst_ed = 0;
    for (int i = 1; i <= n; i ++){
        if (dp[i] > dp[bst_ed]){
            bst_ed = i;
        }
    }

    vector <int> path;

    while (bst_ed){
        path.push_back(bst_ed);
        bst_ed = pre[bst_ed];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';

    for (auto i : path){
        cout << i << ' ';
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
