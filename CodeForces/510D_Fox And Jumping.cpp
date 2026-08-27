// 比赛：Codeforces Round 290 (Div. 2)
// 题目：510D Fox And Jumping
// 链接：https://codeforces.com/problemset/problem/510/D
// 状态：已通过
// 算法：动态规划、最大公约数、状态压缩

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

void solve(){
    int n;
    cin >> n;
    vector <ll> l(n + 1);
    vector <ll> c(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> l[i];
    }
    for (int i = 1; i <= n; i ++){
        cin >> c[i];
    }
    map <ll, ll> dp;
    for (int i = 1; i <= n; i ++){
        for (auto [x, w] : dp){
            ll res = gcd(x, l[i]);
            if (dp.find(res) == dp.end()){
                dp[res] = w + c[i];
            } else {
                dp[res] = min(dp[res], w + c[i]);
            }
        }
        if (dp.find(l[i]) == dp.end()){
            dp[l[i]] = c[i];
        } else {
            dp[l[i]] = min(dp[l[i]], c[i]);
        }
    }
    cout << (dp.find(1) == dp.end() ? -1 : dp[1]) << '\n';
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
