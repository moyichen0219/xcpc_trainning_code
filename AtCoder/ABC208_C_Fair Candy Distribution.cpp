// 比赛：AtCoder Beginner Contest 208
// 题目：ABC208 C - Fair Candy Distribution
// 链接：https://atcoder.jp/contests/abc208/tasks/abc208_c
// 状态：待验证
// 算法：排序、模拟

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, k;
    cin >> n >> k;
    vector <pair <int, int>> a(n + 1);
    int mn_pos = 0;
    int mn = 1e9 + 10;
    for (int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    ll base = k / n;
    ll rem = k % n;
    vector <ll> ans (n + 1, base);
    sort(a.begin() + 1, a.begin() + n + 1);
    for (int i = 1; i <= rem; i ++){
        ans[a[i].second] ++;
    }
    for (int i = 1; i <= n; i ++){
        cout << ans[i] << '\n';
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
