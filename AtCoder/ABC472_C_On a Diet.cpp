// 比赛：AtCoder Beginner Contest 472
// 题目：C - On a Diet
// 链接：https://atcoder.jp/contests/abc472/tasks/abc472_c
// 状态：待验证
// 算法：滑动窗口、模拟

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector <ll> a(n + 1);
    vector <ll> b(n + 1, 0);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    ll cur = 0;
    for (int i = 1; i <= n; i ++){
        if (i > m){
            cur -= b[i - m];
        }
        if (cur + a[i] <= k){
            cout << "Yes" << '\n';
            b[i] = a[i];
            cur += a[i];
        } else {
            cout << "No" << '\n';
            b[i] = 0;
        }
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
