// 模板：二项分布
// 状态：模板
// 复杂度：预处理 O(N)，单次累计概率 O(min(k, n-k+1))

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
const int MOD = 998244353;
// const int MOD = 1e9 + 7;

ll invs[N];
ll fac[N];
ll invfac[N];

ll power(ll a , ll b){
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

// a / b
ll frac(ll a, ll b){
    return a % MOD * inv(b) % MOD;
}

void init_inv(){
    invs[1] = 1;
    for (int i = 2; i < N; i ++){
        invs[i] = MOD - 1LL * (MOD / i) * invs[MOD % i] % MOD;
    }
}

void init(){
    fac[0] = 1;
    for (int i = 1; i < N; i ++){
        fac[i] = fac[i - 1] * i % MOD;
    }
    invfac[N - 1] = inv(fac[N - 1]);
    for (int i = N - 2; i >= 0; i --){
        invfac[i] = invfac[i + 1] * (i + 1) % MOD;
    }
}

ll C(int n, int m){
    if (m < 0 || m > n){
        return 0;
    }
    return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}


// 至少有k次成功，成功概率为p
ll binomial_at_least_k(int n, int k, ll p){
    if (k <= 0){
        return 1;
    }
    if (k > n){
        return 0;
    }
    p = (p % MOD + MOD) % MOD;
    ll q = (1 - p + MOD) % MOD;
    if (p == 0){
        return 0;
    }
    if (q == 0){
        return 1;
    }

    if (k <= n - k + 1){
        ll cur = power(q, n);
        ll invq = inv(q);
        ll sum = 0;

        for (int i = 0; i < k; i ++){
            sum = (sum + cur) % MOD;
            cur = cur * (n - i) % MOD * invs[i + 1] % MOD * p % MOD *invq % MOD;
        }
        return (1- sum + MOD) % MOD;
    } else {
        ll cur = power(p, n);
        ll invp = inv(p);
        ll sum = 0;

        for (int i = n; i >= k; i --){
            sum = (sum + cur) % MOD;
            if (i == k){
                break;
            }
            cur = cur * i % MOD * invs[n - i + 1] % MOD * q % MOD * invp % MOD;
        }
        return sum;
    }
}

// 恰好成功k次，成功概率为p
ll binomial (int n, int k, ll p){
    if (k < 0 || k > n){
        return 0;
    }
    p = (p % MOD + MOD) % MOD;
    ll q = (1 - p + MOD) % MOD;
    return C(n, k) * power(p, k) % MOD * power(q, n - k) % MOD;
}

void solve(){

}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init_inv();
    init();
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
