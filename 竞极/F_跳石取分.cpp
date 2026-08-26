// 比赛：竞极比赛 2090742212411854849
// 题目：F 跳石取分（本地语义命名）
// 链接：http://47.120.23.84/contest/2090742212411854849/2092110649929818118
// 状态：待验证
// 算法：动态规划、单调队列、滑动窗口最值

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

// 设dp[i]: 到达第i块石头时的额最大得分
// j -> i
// L <= x[i] - x[j] << R
// x[i] - R <= x[j] <= x[i] - L
// [x[i] - R, x[i] - L]
// dp[i] = max(dp[j]) + v[i]

// qedue 维护当前合法窗口的max(dp[j])
// dq.front()永远是dp最大的点

void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    vector <pair<ll, ll>> a(n + 1, {0, 0});
    for (int i = 1; i <= n; i ++){
        cin >> a[i].first >> a[i].second;
    }
    vector <ll> dp(n + 1, -INF);
    deque <ll> dq;
    // !dq.empty() && dp[dq.back] <= dp[j] -> dq.pop_back();
    // !dq.empty() && dq.front() < x[i] - R -> dq.pop_front();
    dp[0] = 0;
    int j = 0;
    for (int i = 1; i <= n; i ++){
        while (j < i && a[j].first <= a[i].first - l){
            if(dp[j] != -INF){
                while (!dq.empty() && dp[dq.back()] <= dp[j]){
                    dq.pop_back();
                }
                dq.push_back(j);
            }
            j ++;
        }
        while (!dq.empty() && a[dq.front()].first < a[i].first - r){
            dq.pop_front();
        }
        if (!dq.empty()){
            dp[i] = dp[dq.front()] + a[i].second;
        }
    }
    cout << ((dp[n] == -INF) ? -1 : dp[n]) << '\n';
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
