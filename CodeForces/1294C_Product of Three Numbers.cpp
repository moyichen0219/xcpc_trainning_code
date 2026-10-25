// 比赛/平台：Codeforces
// 题目：1294C Product of Three Numbers
// 链接：https://codeforces.com/problemset/problem/1294/C
// 状态：已通过
// 算法：数论、因数分解、构造

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;

    int a = 0;
    int b = 0;
    int c = 0;

    for (ll i = 2; i * i <= n; i ++){
        if (n % i == 0){
            a = i;
            n /= i;
            break;
        }
    }

    if (a){
        for (ll i = a + 1; i * i <= n; i ++){
            if (n % i == 0){
                b = i;
                n /= i;
                break;
            }
        }

        c = n;

        if (b && c != b){
            cout << "YES" << '\n';
            cout << a << ' ' << b << ' ' << c << '\n';
        } else {
            cout << "NO" << '\n';
        }
    } else {
        cout << "NO" << '\n';
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
