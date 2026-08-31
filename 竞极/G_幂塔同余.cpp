// 比赛：竞极比赛 2093329939779661825
// 题目：G 幂塔同余（本地语义命名）
// 链接：http://47.120.23.84/contest/2093329939779661825/2093331392757870594
// 状态：待验证
// 算法：欧拉降幂、线性筛、模运算

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
const int MOD = 998244353;
int phi[N];
int spf[N]; // 最小质因子
vector <int> prime;
// state[q]：缓存 q 是否整除 D
// 1:可以， -1：不可以
vector <int> state(N);

ll x, y;

ll power(ll a, ll b, ll mod){
    ll res = 1 % mod;
    a %= mod;

    while (b){
        if (b & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

ll get_phi(ll x){
    if (x < N){
        return phi[x];
    }

    ll res = x;
    ll n = x;

    for (auto p : prime){
        if (1LL * p * p > n){
            break;
        }

        if (n % p == 0){
            while (n % p == 0){
                n /= p;
            }

            res = res / p * (p - 1);
        }
    }

    if (n > 1){
        res = res / n * (n - 1);
    }

    return res;
}

void init(){
    phi[1] = 1;

    for (int i = 2; i < N; i ++){
        if (!spf[i]){
            prime.push_back(i);
            phi[i] = i - 1;
            spf[i] = i;
        }

        for (auto p : prime){
            if (1LL * p * i >= N){
                break;
            }

            spf[i * p] = p;

            if (i % p == 0){
                phi[i * p] = phi[i] * p;
                break;
            } else {
                phi[i * p] = phi[i] * (p - 1);
            }
        }
    }
}

bool big(ll n, ll limit){
    if (n >= 5){
        return true;
    }

    ll val[] = {0, 1, 2, 9, 262144};

    return val[n] >= limit;
}

// 求 f(n) mod mod
// f(n) = n ^ f(n - 1)
// 当 f(n - 1) >= φ(mod) 时：
// n ^ (f(n - 1) % φ(mod) + φ(mod)) (mod mod)
ll F(ll n, ll mod){
    if (mod == 1){
        return 0;
    }

    if (n == 0){
        return 0;
    }

    // φ(mod)
    ll ph = get_phi(mod);

    // 求 f(n - 1) % φ(mod)
    ll e = F(n - 1, ph);

    // % φ(mod) + φ(mod)
    if (big(n - 1, ph)){
        e += ph;
    }

    return power(n, e, mod);
}



bool check_q(int q){
    if (state[q] == 0){
        if (F(x - 1, q) == F(y - 1, q)){
            state[q] = 1;
        } else{
            state[q] = -1;
        }
    }

    return state[q] == 1;
}

bool check(int d){
    int x = d;

    while (x > 1){
        int p = spf[x];

        int q = 1;

        while (x % p == 0){
            x /= p;
            q *= p;
        }

        if (!check_q(q)){
            return false;
        }
    }
    return true;
}

void solve(){
    cin >> x >> y;
    // a^b = a ^(b % phi(m) + phi(m))(mod m)
    // 首先写出同余狮子，发现(f(a - 1) - f(b - 1)) / (y - x) =  t， t mod 998244353
    // 使用拓展欧拉降幂将狮子的幂降低到范围内
    // f(a - 1) + xt = c
    // f(b - 1) + yt = c
    // c == f(a - 1) mod t
    // c == f(b - 1) mod t
    int bst = 1;

    // 第一个合法的就是最大的 d
    for (int d = 999999; d >= 1; d --){
        if (check(d)){
            bst = d;
            break;
        }
    }

    // D = f(x - 1) - f(y - 1)
    ll D = (F(x - 1, MOD) - F(y - 1, MOD) + MOD) % MOD;

    // t = D / bst
    ll ans = D * power(bst, MOD - 2, MOD) % MOD;

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
