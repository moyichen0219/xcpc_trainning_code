// 比赛：Educational DP Contest
// 题目：D - Knapsack 1
// 链接：https://atcoder.jp/contests/dp/tasks/dp_d
// 状态：已通过
// 算法：动态规划、01 背包

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, W;
    cin >> n >> W;
    vector <ll> dp(W + 1, 0);

    vector <int> w(n + 1);
    vector <ll> v(n + 1);

    for (int i = 1; i <= n; i ++){
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i ++){
        for (int j = W; j >= w[i]; j --){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[W] << '\n';
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
