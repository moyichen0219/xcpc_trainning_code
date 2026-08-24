// 比赛：2024 年 CCPC 女生专场
// 题目：G - 递增序列
// 链接：https://qoj.ac/contest/1841/problem/9745
// 状态：未通过
// 算法：暴力枚举、位运算

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    int cnt = 0;
    vector <ll> b(n + 1);
    for (int x = 0; x <= k; x ++){
        bool ok = true;
        for (int i = 1; i <= n; i ++){
            b[i] = (a[i] ^ x);
        }
        for (int i = 1; i < n; i ++){
            if (b[i] > b[i + 1]){
                ok = false;
                break;
            }
        }
        if (ok){
            cnt ++;
            // cout << x << '\n';
            // for (int i = 1; i <= n; i ++){
            //     cout << b[i] << ' ';
            // }
            // cout << '\n';
        }
    }
    cout << cnt << '\n';
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
