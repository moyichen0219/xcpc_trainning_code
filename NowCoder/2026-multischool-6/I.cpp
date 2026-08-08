// 比赛：2026 牛客暑期多校训练营 6（133881）
// 题目：I - Integer Function - https://ac.nowcoder.com/acm/contest/133881/I
// 状态：未完成（账号未通过；位计数公式与复杂度仍需修正）
// 分类：位运算、计数
#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

ll n, d;
const int MOD = 998244353;

/* ll f(ll n){
    return __builtin_popcountll(n);
} */

// (x >> i) & 1
// ((x + d) >> j) & 1 

ll f (ll a, ll b){
    ll res = 0;
    for (int i = 0; i <= min(n, (1ll << max(a, b))); i ++){
        if (((i >> a) & 1 == 1) && (((i + d) >> b) & 1 == 1)){
            res = (res + (n - i) >> max(n, (1ll << max(a, b)) + 1)) % MOD;
        }
    }
    return res;
}

void solve(){
    cin >> n >> d;
    ll ans = 0;
    /* for (int i = 0; i <= n; i ++){
        ans += f(i) * f(i + d) % MOD;
        ans %= MOD;
        cout << f(i) << ' ' << f (i + d) << '\n';
    }
    cout << '\n'; */

    for (int i = 0; i <= 61; i ++){
        for (int j = 0; j <= 61; j ++){
            ll cnt = f(i, j);
            ans = (ans + cnt) % MOD;
        }
    }
    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t  --){
        solve();
    }
    return 0;
}
