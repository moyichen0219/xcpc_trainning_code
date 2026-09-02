// 比赛：竞极比赛 2094600238127988737
// 题目：C - Potions (Hard Version)
// 链接：http://47.120.23.84/contest/2094600238127988737/2094602665216524292
// 状态：待验证
// 算法：贪心、优先队列、反悔

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];
int cur[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    // 由题已知，喝>=0的药水一定最优
    // 次优为喝当前最小负数的药水

    // 也就是先喝所有的药水，在生命值大于等于0的情况下
    // 如果生命值小于0了，那么就撤回之前喝的最大负数药水（a[i]最小），来让我能够喝多一点比他小的负数药水

    priority_queue<int, vector<int>, greater<int>> pq;
    ll sum = 0;
    for (int i = 1; i <= n; i ++){
        sum += a[i];
        pq.push(a[i]);
        while (sum < 0 && pq.size()){
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << pq.size() << '\n';

    /* vector <ll> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i ++){
        vector <ll> ndp(n + 1, -1);
        for (int j = 0; j <= i; j ++){
            // 跳过
            if (dp[j] != -1){
                ndp[j] = dp[j];
            }
            // 喝，保证>= 0
            if (j > 0 && dp[j - 1] != -1 && dp[j - 1] + a[i] >= 0){
                ndp[j] = max(dp[j], dp[j - 1] + a[i]);
            }
        }
        dp = ndp;
    }

    int ans = 0;
    for (int j = 0; j <= n; j++){
        if (dp[j] != -1){
            ans = j;
        }
    } */

    // cout << ans << '\n';
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
