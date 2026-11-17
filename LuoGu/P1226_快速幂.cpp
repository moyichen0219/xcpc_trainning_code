// 比赛/平台：洛谷
// 题目：P1226 【模板】快速幂
// 链接：https://www.luogu.com.cn/problem/P1226
// 状态：已通过
// 算法：快速幂、模运算

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll b, ll p){
    ll res = 1;
    while (b){
        if (b & 1){
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll a, b, p;
    cin >> a >> b >> p;

    cout << a << '^' << b << " mod " << p << '=';
    cout << power(a, b, p) << '\n';
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
