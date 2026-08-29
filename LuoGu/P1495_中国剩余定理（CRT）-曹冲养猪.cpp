// 比赛：洛谷题库
// 题目：P1495 【模板】中国剩余定理（CRT）/ 曹冲养猪
// 链接：https://www.luogu.com.cn/problem/P1495
// 状态：已通过
// 算法：中国剩余定理、扩展欧几里得

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

ll CRT(vector <ll> a, vector <ll> b){
    int n = a.size();
    ll M = 1;
    for (int i = 0; i < n; i ++){
        M *= b[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i ++){
        ll Mi = M / b[i];
        ll ti = inv(Mi, b[i]);
        ans = (ans + (i128)Mi * a[i] % M * ti % M) % M;
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
    cout << CRT(a, b) << '\n';
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
