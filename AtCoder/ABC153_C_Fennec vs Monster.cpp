// 比赛：AtCoder Beginner Contest 153
// 题目：ABC153 C - Fennec vs Monster
// 链接：https://atcoder.jp/contests/abc153/tasks/abc153_c
// 状态：已通过
// 算法：排序、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    if (k >= n){
        cout << 0 << '\n';
        return ;
    }
    ll ans = 0;
    sort(a.begin() + 1, a.begin() + n + 1);
    for (int i = n - k; i >= 1; i --){
        ans += a[i];
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
