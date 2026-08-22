// 模板：组合数与模逆元
// 状态：模板
// 复杂度：预处理 O(N)，单次查询 O(1)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const ll MOD = 998244353;

ll fac[N], invfac[N];

// 快速幂
ll power(ll a, ll b){
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

// 模逆
ll inv(ll x){
    return power(x, MOD - 2);
}

// 预处理阶乘与逆阶乘
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

// 组合数 C(n,m)
ll C(int n, int m){
    if (m < 0 || m > n){
        return 0;
    }

    return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

void solve(){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();

    solve();

    return 0;
}
