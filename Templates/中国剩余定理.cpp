// 模板：中国剩余定理（CRT）
// 状态：模板
// 前提：模数两两互质
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

ll inv(ll a, ll mod){
    ll x, y;
    ll d = exgcd(a, mod, x, y);
    if (d != 1){
        return -1;
    }
    return (x % mod + mod) % mod;
}

ll CRT(vector <ll> a, vector <ll> m){
    int n = a.size();
    ll M = 1;
    for (int i = 0; i < n; i ++){
        M *= m[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i ++){
        ll Mi = M / m[i];
        ll ti = inv(Mi, m[i]);
        ans = (ans + (i128)a[i] * Mi % M * ti % M) % M;
    }
    return (ans % M + M) % M;
}

void solve(){

}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t --){
        solve();
    }
    return 0;
}
