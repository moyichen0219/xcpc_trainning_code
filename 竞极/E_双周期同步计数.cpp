// 比赛：竞极比赛 2093329939779661825
// 题目：E 双周期同步计数（本地语义命名）
// 链接：http://47.120.23.84/contest/2093329939779661825/2093331392753676291
// 状态：待验证
// 算法：线性同余方程、EXCRT、区间计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

ll nm, ans;

ll exgcd(ll a, ll b, ll &x, ll &y){
    if (b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}

bool merge(ll &r1, ll &m1, ll r2, ll m2){
    // 当前：
    // x ≡ r1 (mod m1)
    //
    // 新的：
    // x ≡ r2 (mod m2)

    ll x, y;
    ll d = exgcd(m1, m2, x, y);
    ll c = r2 - r1;

    // 无解
    if (c % d != 0){
        return false;
    }

    // 解：
    // m1 * k ≡ c (mod m2)
    ll mod = m2 / d;

    // k = x * (c / d)  (mod m2 / d)
    ll k = (i128)x * (c / d) % mod;

    k = (k % mod + mod) % mod;

    // 新余数
    i128 nr = (i128)r1 + (i128)m1 * k;

    // 新模数 = lcm(m1, m2)
    nm = (i128)m1 / d * m2;

    r1 = nr % nm;
    if (r1 < 0){
        r1 += nm;
    }
    m1 = nm;
    return true;
}

bool exCRT(vector<ll> r, vector<ll> m){
    int n = r.size();
    ans = r[0];
    ll mod = m[0];
    for (int i = 1; i < n; i++){
        if (!merge(ans, mod, r[i], m[i])){
            return false;
        }
    }
    return true;
}

ll count(ll k, ll d, ll x){
    if (x < k){
        return 0;
    }
    return (x - k) / d + 1;
}

void solve(){
    ll L, R;
    cin >> L >> R;
    ll m, p, u, q, v;
    cin >> m >> p >> u >> q >> v;
    ll a1 = u - v;
    ll b1 = m;
    ll c1 = q - p;
    if (c1 % __gcd(a1, b1) != 0){
        cout << 0 << '\n';
        return ;
    }
    ll i1, j1;
    ll d1 = exgcd(abs(a1), b1, i1, j1);

    // i (u - v) + j m = d
    // k = (q - p) / d
    // i * k * (u - v) + j * k * m = q - p

    if (a1 < 0){
        i1 *= -1;
    }

    ll mod1 = m / d1;
    i1 *= ((i128)c1 / (i128)d1) % mod1;
    i1 = (i1 % mod1 + mod1) % mod1;

    cin >> m >> p >> u >> q >> v;

    ll a2 = u - v;
    ll b2 = m;
    ll c2 = q - p;
    if (c2 % __gcd(a2, b2) != 0){
        cout << 0 << '\n';
        return ;
    }
    ll i2, j2;
    ll d2 = exgcd(abs(a2), b2, i2, j2);

    if (a2 < 0){
        i2 *= -1;
    }

    ll mod2 = m / d2;
    i2 *= ((i128)c2/ (i128)d2) % mod2;
    i2 = (i2 % mod2 + mod2) % mod2;

    vector <ll> a;
    a.push_back(i1);
    a.push_back(i2);
    vector <ll> b;
    b.push_back(mod1);
    b.push_back(mod2);

    if (!exCRT(a, b)){
        cout << 0 << '\n';
        return ;
    }

    cout << count(ans, nm, R) - count(ans, nm, L - 1) << '\n';
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
