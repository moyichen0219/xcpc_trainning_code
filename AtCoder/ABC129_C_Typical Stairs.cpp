// 比赛：AtCoder Beginner Contest 129
// 题目：ABC129 C - Typical Stairs
// 链接：https://atcoder.jp/contests/abc129/tasks/abc129_c
// 状态：已通过
// 算法：动态规划、计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;
    set <int> s;
    for (int i = 1; i <= m; i ++){
        int x;cin >> x;
        s.insert(x);
    }
    vector <int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; i ++){
        if (i + 1 <= n && !s.count(i + 1)){
            dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
        }
        if (i + 2 <= n && !s.count(i + 2)){
            dp[i + 2] = (dp[i + 2] + dp[i]) % MOD;
        }
    }
    cout << dp[n] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
