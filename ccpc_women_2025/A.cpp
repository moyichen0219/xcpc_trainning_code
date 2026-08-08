// 比赛：2025 年 CCPC 女生专场
// 题目：A - 环状线 - https://qoj.ac/contest/2564
// 状态：待验证（已有完整实现和本地样例，但未记录是否通过评测）
// 分类：环形距离、分类讨论
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, s, t;
    cin >> n >> s >> t;
    if (s > t){
        // cout << "op 1 : " << '\n';
        if (n - s + t < s - t){
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    } else {
        // cout << "op 2 : " << '\n';
        if (t - s < n - t + s){
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
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
