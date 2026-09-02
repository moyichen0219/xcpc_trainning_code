// 比赛：USACO 2011 Open
// 题目：P2627 Mowing the Lawn G
// 链接：https://www.luogu.com.cn/problem/P2627
// 状态：已通过
// 算法：动态规划、单调队列、补集转化

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int e[N];
ll dp[N];

void solve(){
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    for (int i = 1; i <= n; i ++){
        cin >> e[i];
        sum += e[i];
    }
    for (int i = 1; i <= n + 1; i ++){
        dp[i] = 4e18;
    }
    dp[0] = 0;
    deque <int> dq;
    dq.push_back(0);
    for (int i = 1; i <= n + 1; i ++){
        while (dq.size() && dq.front() < i - k - 1){
            dq.pop_front();
        }
        if (dq.size()){
            dp[i] = dp[dq.front()] + e[i];
        }
        while (dq.size() && dp[dq.back()] >= dp[i]){
            dq.pop_back();
        }
        dq.push_back(i);

    }
    cout << sum - dp[n + 1] << '\n';
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
