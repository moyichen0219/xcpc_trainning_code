// 比赛：The 2026 ICPC Asia East Continent Online Contest (I)
// 题目：F - 50 Years of Excellence
// 链接：https://qoj.ac/contest/4071/problem/20021
// 状态：待验证
// 算法：行和、相邻比较、计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;

    int ans = 0;

    vector <ll> a(n + 1, 0);
    for (int i = 1; i <= n; i ++){
        ll res = 0;
        for (int j = 1; j <= m; j ++){
            int x;
            cin >> x;
            res += x;
        }
        a[i] = res;
    }

    for (int i = 1; i <= n; i ++){
        if (a[i] < a[i - 1]){
            ans ++;
        }
    }
    cout << ans << '\n';
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
