// 比赛：GXPC-S 2024
// 题目：B4168 - 分糖果
// 链接：https://www.luogu.com.cn/problem/B4168
// 状态：待验证
// 算法：动态规划、博弈

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
ll dp[N][2];

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for (int i = n; i >= 1; i --){
        dp[i][0] = max(dp[i + 1][1] + a[i], dp[i + 1][0]);
        dp[i][1] = min(dp[i + 1][1] + a[i], dp[i + 1][0]);
    }

    cout << dp[1][0] << '\n';
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
