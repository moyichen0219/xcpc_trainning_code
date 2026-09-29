// 比赛：CSES Mathematics
// 题目：1095 - Exponentiation
// 链接：https://cses.fi/problemset/task/1095/
// 状态：待验证
// 算法：快速幂、模运算

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll power(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    while (n --){
        ll a, b;
        cin >> a >> b;
        if (a == 0 && b == 0){
            cout << 1 << '\n';
            continue;
        }
        cout << power(a, b) % MOD << '\n';
    }
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
