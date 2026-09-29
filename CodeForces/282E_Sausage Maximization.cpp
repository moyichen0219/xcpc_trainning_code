// 比赛：Codeforces Round 173 (Div. 2)
// 题目：282E - Sausage Maximization
// 链接：https://codeforces.com/problemset/problem/282/E
// 状态：已通过
// 算法：前缀异或、后缀异或、01 字典树


// 不知道为什么就通过了，没懂
// 在加i128之前都是wa，开i128本地测试未通过，但是cf上ac了
// 后面又用之前的ll再交了一发，居然也ac了
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;

const int N = 1e5 + 10;
ll a[N];
ll pre[N];
ll suf[N];

int son[64 * N][2];
ll idx = 0;

void insert(ll x){
    int p = 0;

    for (int i = 60; i >= 0; i --){
        int bit = (x >> i) & 1ll;
        if (!son[p][bit]){
            son[p][bit] = ++ idx;
        }
        p = son[p][bit];
    }
}

/* ll query(ll x){
    int p = 0;
    i128 ans = 0;

    for (int i = 60; i >= 0; i --){
        int bit = (x >> i) & 1ll;
        if (son[p][bit ^ 1]){
            ans |= ((i128)1ll << i);
            p = son[p][bit ^ 1];
        } else {
            p = son[p][bit];
        }
    }

    return ans;
} */

ll query(ll x){
    int p = 0;
    ll ans = 0;

    for (int i = 60; i >= 0; i --){
        int bit = (x >> i) & 1LL;

        if (son[p][bit ^ 1]){
            ans |= (1LL << i);
            p = son[p][bit ^ 1];
        } else {
            p = son[p][bit];
        }
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    insert(0);
    for (int i = 1; i <= n; i ++){
        pre[i] = pre[i - 1] ^ a[i];
    }

    suf[n + 1] = 0;
    for (int i = n; i >= 1; i --){
        suf[i] = suf[i + 1] ^ a[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n + 1; i ++){
        ans = max(ans, query(suf[i]));
        insert(pre[i]);
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
