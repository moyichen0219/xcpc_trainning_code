// 比赛：Codeforces Beta Round 7
// 题目：7C Line
// 链接：https://codeforces.com/problemset/problem/7/C
// 状态：已通过
// 算法：扩展欧几里得、线性丢番图方程

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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

void solve(){
    ll a, b, c;
    cin >> a >> b >> c;
    c *= -1;
    if (c % __gcd(a, b) != 0){
        cout << -1 << '\n';
        return ;
    }
    ll x0, y0;
    ll d = exgcd(a, b, x0, y0);
    ll k = c / d;
    cout << x0 * k << ' ' << y0 * k << '\n';
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
