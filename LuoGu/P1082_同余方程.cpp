// 比赛：NOIP 2012 提高组
// 题目：P1082 同余方程
// 链接：https://www.luogu.com.cn/problem/P1082
// 状态：已通过
// 算法：扩展欧几里得、乘法逆元

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

ll inv(ll a, ll b){
    ll x, y;
    ll d = exgcd(a, b, x, y);
    if (d != 1){
        return -1;
    }
    return (x % b + b) % b;
}

void solve(){
    int a, b;
    cin >> a >> b ;
    cout << inv(a, b) << '\n';
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
