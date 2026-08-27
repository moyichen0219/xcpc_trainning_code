// 比赛：洛谷题库
// 题目：P5656 【模板】二元一次不定方程 (exgcd)
// 链接：https://www.luogu.com.cn/problem/P5656
// 状态：已通过
// 算法：扩展欧几里得、线性丢番图方程、解集计数

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
    if (c % __gcd(a, b) != 0){
        cout << -1 << '\n';
        return ;
    }

    ll x0, y0;
    ll d = exgcd(a, b, x0, y0);

    x0 *= c / d;
    y0 *= c / d;

    ll kmn = ceil((long double)(1 - x0) / (b / d));
    ll kmx = floor((long double)(y0 - 1) / (a / d));

    if (kmx >= kmn){
        ll cnt = kmx - kmn + 1;
        ll xmn = x0 + (kmn * b / d);
        ll xmx = x0 + (kmx * b / d);
        ll ymn = y0 - (kmx * a / d);
        ll ymx = y0 - (kmn * a / d);
        cout << cnt << ' ' << xmn << ' ' << ymn << ' ' << xmx << ' ' << ymx << '\n';
    } else {
        ll xm = ((x0 % (b / d) + (b / d)) % (b / d) == 0) ? (b / d) : (x0 % (b / d) + (b / d)) % (b / d);
        ll ym = ((y0 % (a / d) + (a / d)) % (a / d) == 0) ? (a / d) : (y0 % (a / d) + (a / d)) % (a / d);
        cout << xm << ' ' << ym << '\n';
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t --){
        solve();
    }
    return 0;
}
