// 比赛：Educational DP Contest
// 题目：Q - Flowers
// 链接：https://atcoder.jp/contests/dp/tasks/dp_q
// 状态：已通过
// 算法：动态规划、树状数组、前缀最大值

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];
int h[N];
ll dp[N];
ll tree[N];

struct node {
    int a;
    int h;
};

int n, m;

int lowbit (int x){
    return x & -x;
}

void upd(int x, ll val){
    for (int i = x; i <= m; i += lowbit(i)){
        tree[i] = max(tree[i], val);
    }
}

ll query(int x){
    ll res = 0;
    for (int i = x; i > 0; i -= lowbit(i)){
        res = max(res, tree[i]);
    }
    return res;
}

void solve(){
    cin >> n;

    vector <int> H;
    for (int i = 1; i <= n; i ++){
        cin >> h[i];
        H.push_back(h[i]);
    }

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    vector <node> b(n+ 1);

    for (int i = 1; i <= n; i ++){
        b[i].a = a[i];
        b[i].h = h[i];
    }

    sort(b.begin() + 1, b.end(), [](const node& x, const node& y){
        return x.h < y.h;
    });

    sort(begin(H), end(H));
    H.erase(unique(begin(H), end(H)), end(H));
    m = H.size();

    int top = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        int pos = upper_bound(H.begin(), H.end(), h[i]) - H.begin() + 1;

        ll bst = query(pos - 1);

        dp[i] = bst + a[i];

        ans = max(ans, dp[i]);

        upd(pos, dp[i]);
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
