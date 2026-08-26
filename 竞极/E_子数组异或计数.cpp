// 比赛：竞极比赛 2090742212411854849
// 题目：E 子数组异或计数（本地语义命名）
// 链接：http://47.120.23.84/contest/2090742212411854849/2092110649929818117
// 状态：待验证
// 算法：前缀异或、二进制字典树、子数组计数

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    ll pre_xor;
    int idx;
};

void solve(){
    ll n, k;
    cin >> n >> k;
    // pre[r] ^ pre[l - 1] < k
    // pre[r] ^ k < pre[l - 1]
    // pre[l - 1] > pre[r] ^ k
    vector <ll> a(n + 1);
    vector <node> pre(n + 1);
    ll mn_xor = 1e18;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        mn_xor = min(mn_xor, pre[i - 1].pre_xor ^ a[i]);
        pre[i].pre_xor = (pre[i - 1].pre_xor ^ a[i]);
    }
    sort(pre.begin() + 1, pre.end(), [](const node& x, const node& y) {
        if (x.pre_xor != y.pre_xor) {
            return x.pre_xor < y.pre_xor;
        }
        return x.idx < y.idx;
    });
    ll ans = 0;
    if (mn_xor >= k){
        cout << 0 << '\n';
        return;
    }
    // pre[l - 1] > pre[r] ^ k
    for (int i = n; i > 1; i --){
        ll x = pre[i].pre_xor ^ k;
        // it : 第一个 >= pre[r] ^ k 的地方
        // it + 1 ~ i
        // i - (it - (pre.begin() + 1) + 1)
        auto it = lower_bound(pre.begin(), pre.end(), x, [](const node& c, ll val){
            return c.pre_xor < val;
        });
        if (it == pre.begin() || it == pre.end()){
            continue;
        }
        ans += it - (pre.begin() + 1) - 1;
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
} */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const int MAXNODE = N * 30;

int tire[MAXNODE][2];
int cnt[MAXNODE];
int idx;

void insert(int x){
    int p = 0;
    for (int i = 29; i >= 0; i --){
        int bit = (x >> i) & 1;
        if (!tire[p][bit]){
            tire[p][bit] = ++idx;
        }
        p = tire[p][bit];
        cnt[p] ++;
    }
}

ll query(int x, int k){
    int p = 0;
    ll res = 0;
    for (int i = 29; i >= 0; i --){
        int xb = (x >> i) & 1;
        int kb = (k >> i) & 1;

        if (kb == 0){
            p = tire[p][xb];
            if (!p){
                break;
            }
        } else {
            if (tire[p][xb]){
                res += cnt[tire[p][xb]];
            }
            p = tire[p][xb ^ 1];
            if (!p){
                break;
            }
        }
    }
    return res;
}

void solve(){
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    int pre = 0;
    insert(0);
    for (int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        pre ^= x;
        ans += query(pre, k);
        insert(pre);
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
