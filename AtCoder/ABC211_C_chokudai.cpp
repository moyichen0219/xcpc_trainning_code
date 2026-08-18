// 比赛：AtCoder Beginner Contest 211
// 题目：ABC211 C - chokudai
// 链接：https://atcoder.jp/contests/abc211/tasks/abc211_c
// 状态：已通过
// 算法：动态规划、子序列计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    string t = "chokudai";
    vector <int> dp(n + 1, 0);
    dp[0] = 1;
    for (auto c : s){
        for (int i = 7; i >= 0; i --){
            if (c == t[i]){
                dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
            }
        }
    }
    cout << dp[8] << '\n';
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
