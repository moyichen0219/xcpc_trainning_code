// 比赛：AtCoder Beginner Contest 472
// 题目：B - Break a Stick
// 链接：https://atcoder.jp/contests/abc472/tasks/abc472_b
// 状态：待验证
// 算法：前缀和、枚举

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <ll> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        sum += a[i];
    }
    ll ans = LLONG_MAX;
    ll x = 0;
    for (int i = 1; i <= n; i ++){
        x += a[i];
        ll y = sum - x;
        ans = min(ans, abs(x- y));
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
