// 比赛：Codeforces Round 119 (Div. 2)
// 题目：189A - Cut Ribbon
// 链接：https://codeforces.com/problemset/problem/189/A
// 状态：已通过
// 算法：动态规划、完全背包

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector <int> dp(n + 1, -1);
    /* dp[0] = 0;
    for (int i = 1; i <= n; i ++){
        if (i >= a && dp[i - a] != -1){
            dp[i] = max(dp[i], dp[i - a] + 1);
        }

        if (i >= b && dp[i - b] != -1){
            dp[i] = max(dp[i], dp[i - b] + 1);
        }

        if (i >= c && dp[i - c] != -1){
            dp[i] = max(dp[i], dp[i - c] + 1);
        }
    } */
   dp[n] = 0;
    for (int i = n; i >= 0; i --){
        if (dp[i] == -1){
            continue;
        }
        if (i >= a){
            dp[i - a] = max(dp[i - a], dp[i] + 1);
        }
        if (i >= b){
            dp[i - b] = max(dp[i - b], dp[i] + 1);
        }
        if (i >= c){
            dp[i - c] = max(dp[i - c], dp[i] + 1);
        }
    }
    cout << dp[0] << '\n';
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
