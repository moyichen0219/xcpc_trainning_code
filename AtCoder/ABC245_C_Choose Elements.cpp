// 比赛：AtCoder Beginner Contest 245
// 题目：ABC245 C - Choose Elements
// 链接：https://atcoder.jp/contests/abc245/tasks/abc245_c
// 状态：已通过
// 算法：动态规划、状态压缩

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> a(n + 1);
    vector <int> b(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    vector <int> dp(n + 1, -1);
    dp[0] = dp[1] = 0;
    // 0 -> a_i / b_i
    // 1 -> a_i
    // 2 -> b_i
    for (int i = 2; i <= n; i ++){
        if (dp[i - 1] == 0){
            bool ok1 = false;
            bool ok2 = false;
            if (abs(a[i] - a[i - 1]) <= k || abs(a[i] - b[i - 1]) <= k){
                ok1 = true;
            }
            if (abs(b[i] - a[i - 1]) <= k || abs(b[i] - b[i - 1]) <= k){
                ok2 = true;
            }
            if (ok1 && ok2){
                dp[i] = 0;
            } else if (ok1){
                dp[i] = 1;
            } else if (ok2){
                dp[i] = 2;
            } else {
                cout << "No" << '\n';
                return ;
            }
        } else if (dp[i - 1] == 1){
            bool ok1 = false;
            bool ok2 = false;
            if (abs(a[i] - a[i - 1]) <= k){
                ok1 = true;
            }
            if (abs(b[i] - a[i - 1]) <= k){
                ok2 = true;
            }
            if (ok1 && ok2){
                dp[i] = 0;
            } else if (ok1){
                dp[i] = 1;
            } else if (ok2){
                dp[i] = 2;
            } else {
                cout << "No" << '\n';
                return ;
            }
        } else if (dp[i - 1] == 2){
            bool ok1 = false;
            bool ok2 = false;
            if (abs(a[i] - b[i - 1]) <= k){
                ok1 = true;
            }
            if (abs(b[i] - b[i - 1]) <= k){
                ok2 = true;
            }
            if (ok1 && ok2){
                dp[i] = 0;
            } else if (ok1){
                dp[i] = 1;
            } else if (ok2){
                dp[i] = 2;
            } else {
                cout << "No" << '\n';
                return ;
            }
        }
    }
    cout << "Yes" << '\n';
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
