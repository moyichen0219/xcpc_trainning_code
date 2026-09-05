// 比赛：Codeforces Round 1542
// 题目：1542B - Plus and Multiply
// 链接：https://codeforces.com/problemset/problem/1542/B
// 状态：已通过
// 算法：数学、幂枚举、整除判断

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1){
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}



void solve(){
    ll a, b, n;
    cin >> n >> a >> b;

    if ((n - a) % b == 0){
        cout << "Yes" << '\n';
        return ;
    }
    if ((n - 1) % b == 0){
        cout << "Yes" << '\n';
        return ;
    }

    ll res = 1;
    while (res <= n){
        if ((n - res) % b == 0){
            cout << "Yes" << '\n';
            return ;
        }

        if (a == 1){
            break;
        }

        if (res > n / a){
            break;
        }

        res *= a;
    }

    cout << "No" << '\n';
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
