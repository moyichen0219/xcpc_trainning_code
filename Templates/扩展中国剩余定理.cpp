// 模板：扩展中国剩余定理（EXCRT）
// 状态：模板
// 复杂度：O(n log M)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

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
    ll nm = (i128)m1 / d * m2;

    r1 = nr % nm;
    if (r1 < 0){
        r1 += nm;
    }
    m1 = nm;
    return true;
}

ll exCRT(vector<ll> r, vector<ll> m){
    int n = r.size();
    ll ans = r[0];
    ll mod = m[0];
    for (int i = 1; i < n; i++){
        if (!merge(ans, mod, r[i], m[i])){
            return -1;
        }
    }
    return ans;
}

void solve(){

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
