// 比赛/平台：2026 CCPC 女生专场
// 题目：F - 区间测速
// 链接：https://qoj.ac/contest/4613/problem/23636/statement/zh_cn
// 状态：待验证
// 算法：区间重叠、分数化简、数学

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll x, y, l, r, v;
    cin >> x >> y >> l >> r >> v;

    ll down = 1LL * v * max(0LL, min(y, r) - max(x, l));
    ll up = (r - l) * (y - x);

    ll g = __gcd(up, down);
    up /= g;
    down /= g;

    cout << up << '/' << down << '\n';
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
