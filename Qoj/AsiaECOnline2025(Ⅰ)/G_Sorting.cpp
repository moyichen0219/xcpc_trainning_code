// 比赛：The 2025 ICPC Asia East Continent Online Contest (I)
// 题目：G - Sorting
// 链接：https://qoj.ac/contest/2513/problem/14307
// 状态：待验证
// 算法：必要相邻比较、构造判定

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> a(m + 1);
    vector <int> b(m + 1);
    vector <bool> vis(n, false);
    for (int i = 1; i <= m; i ++){
        cin >> a[i] >> b[i];
        if (a[i] + 1 == b[i]){
            vis[a[i]] = true;
        }
    }

    bool ok = true;
    for (int i = 1; i < n; i ++){
        if (!vis[i]){
            ok = false;
        }
    }

    if (ok){
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
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
