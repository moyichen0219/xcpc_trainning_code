// 比赛：Educational DP Contest
// 题目：F - LCS
// 链接：https://atcoder.jp/contests/dp/tasks/dp_f
// 状态：已通过
// 算法：字符串动态规划、最长公共子序列、方案恢复

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3010;
int dp[N][N];

void solve(){
    string s, t;
    cin >> s >> t;
    for (int i = 1; i <= s.length(); i ++){
        for (int j = 1; j <= t.length(); j ++){
            if (s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = s.length();
    int j = t.length();
    string ans = "";

    while (i > 0 && j > 0){
        if (s[i - 1] == t[j - 1]){
            ans += s[i - 1];
            i --;
            j --;
        } else if (dp[i - 1][j] > dp[i][j - 1]){
            i --;
        } else {
            j --;
        }
    }

    reverse(ans.begin(), ans.end());

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
