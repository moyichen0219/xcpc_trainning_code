// 比赛：AtCoder Beginner Contest 471
// 题目：ABC471 E - Sum of Square of Sum
// 链接：https://atcoder.jp/contests/abc471/tasks/abc471_e
// 状态：已通过
// 算法：组合数学、快速幂

#include<bits/stdc++.h>
using namespace std;
using ll = long long;


const int N = 2e5 + 10;
const int MOD = 998244353;
ll fac[N];

void init(){
    fac[0] = fac[1] = 1;
    for (int i = 2; i < N; i ++){
        fac[i] = fac[i - 1] * i % MOD;
    }
}

ll power (ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll x){
    return power(x, MOD - 2);
}

ll C(ll n, ll m){
    if (n < m || m < 0 || n < 0){
        return 0;
    }
    return fac[n] * inv(fac[n - m]) % MOD * inv(fac[m]) % MOD;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector <ll> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        sum += a[i];
    }
    // (a + B + C)^ 2 = a ^2 + b ^2 + c ^2 + 2ab + 2ac + 2bc
    ll cnt = C(n - 1, k - 1);
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        ans = (ans + 1LL * cnt * a[i] % MOD * a[i] % MOD) % MOD;
    }
    cnt = C(n - 2, k - 2);
    for (int i = 1; i <= n; i ++){
        ans = (ans + (cnt * ((sum - a[i]) % MOD * a[i] % MOD) % MOD)) % MOD;
    }
    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    init();
    while (t --){
        solve();
    }
    return 0;
}
