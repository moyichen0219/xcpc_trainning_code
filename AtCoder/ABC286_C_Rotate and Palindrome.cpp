// 比赛：AtCoder Beginner Contest 286
// 题目：ABC286 C - Rotate and Palindrome
// 链接：https://atcoder.jp/contests/abc286/tasks/abc286_c
// 状态：已通过
// 算法：枚举、字符串、回文

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    ll ans = LLONG_MAX;
    for (int base = 0; base <= n; base ++){
        int cnt = 0;
        for (int i = 0; i < n / 2; i ++){
            if (s[(n - 1 - i + base) % n] != s[(i + base) % n]){
                cnt ++;
            }
        }
        ans = min(ans, 1ll * a * base + 1ll * b * cnt);
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
