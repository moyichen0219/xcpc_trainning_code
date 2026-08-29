// 比赛：洛谷题库
// 题目：P4777 【模板】扩展中国剩余定理（EXCRT）
// 链接：https://www.luogu.com.cn/problem/P4777
// 状态：已通过
// 算法：扩展中国剩余定理、扩展欧几里得

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

ll exgcd(ll a, ll b, ll &x, ll &y){
    if (b == 0){
        y = 0;
        x = 1;
        return a;
    }
    ll x1, y1;
    ll d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}

bool merge(ll &r1, ll &m1, ll r2, ll m2){
    ll x, y;
    ll d = exgcd(m1, m2, x, y);
    ll c = r2 - r1;

    if (c % d != 0){
        return false;
    }

    ll mod = m2 / d;
    ll k = (i128) x * (c / d) % mod;
    k = (k % mod + mod) % mod;

    i128 nr = (i128)r1 + (i128) m1 * k;
    ll nm = (i128) m1 / d * m2;
    r1 = nr % nm;
    if (r1 < 0){
        r1 += nm;
    }
    m1 = nm;
    return true;
}

ll exCRT(vector <ll> a, vector <ll> b){
    int n = a.size();
    ll ans = a[0];
    ll mod = b[0];
    for (int i = 1; i < n; i ++){
        if (!merge(ans, mod, a[i], b[i])){
            return -1;
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector <ll> a(n);
    vector <ll> b(n);
    for (int i = 0; i < n; i ++){
        cin >> b[i] >> a[i];
    }
    cout << exCRT(a, b) << '\n';
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
