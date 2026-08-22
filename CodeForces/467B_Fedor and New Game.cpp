// 比赛：Codeforces Round 267 (Div. 2)
// 题目：467B - Fedor and New Game
// 链接：https://codeforces.com/problemset/problem/467/B
// 状态：已通过
// 算法：位运算、枚举

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(m + 2);
    for (int i = 1; i <= m + 1; i ++){
        cin >> a[i];
    }
    set <int> f;
    int res = 0;
    for (int i = 0; i < n; i ++){
        if ((a[m + 1] >> i & 1) == 1){
            f.insert(i);
            res ++;
        }
    }
    vector <int> cnt(m + 2);
    for (int i = 1; i <= m; i ++){
        for (int j = 0; j <= n; j ++){
            // if ((a[i] >> j & 1) == 1){
                cnt[i] += ((a[i] >> j & 1) ^ (a[m + 1] >> j & 1));
            // }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i ++){
        if (cnt[i] <= k){
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
