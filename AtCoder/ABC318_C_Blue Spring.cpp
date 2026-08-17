// 比赛：AtCoder Beginner Contest 318
// 题目：ABC318 C - Blue Spring
// 链接：https://atcoder.jp/contests/abc318/tasks/abc318_c
// 状态：已通过
// 算法：贪心、排序

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, d, p;
    cin >> n >> d >> p;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    ll ans = 0;
    for (int i = n; i >= 1; i -= d){
        ll cur = 0;
        for (int j = i; j >= max(i - d + 1, 1); j --){
            cur += a[j];
        }
        ans += min(cur, 1LL * p);
    }
    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t  = 1;
    while (t --){
        solve();
    }
    return 0;
}
