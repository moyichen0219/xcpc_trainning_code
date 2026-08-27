// 比赛：洛谷题库
// 题目：P1516 青蛙的约会
// 链接：https://www.luogu.com.cn/problem/P1516
// 状态：已通过
// 算法：扩展欧几里得、线性同余方程

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll exgcd (ll a, ll b , ll &x, ll &y){
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

void solve(){
    ll x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;
    ll a = m - n;
    ll b = l;
    ll c = y - x;

    if (c % __gcd(a, b) != 0){
        cout << "Impossible" << '\n';
        return ;
    }

    ll i, j;
    ll d = exgcd(abs(a), b, i, j);

    // ai + bj = d;
    // ai + bj = k d;
    // k = c / d;

    if (a < 0){
        i *= -1;
    }

    ll mod = l / d;
    i *= c / d;
    i = (i % mod + mod) % mod;

    cout << i << '\n';
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
