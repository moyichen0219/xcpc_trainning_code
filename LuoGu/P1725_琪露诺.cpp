// 比赛：洛谷
// 题目：P1725 琪露诺
// 链接：https://www.luogu.com.cn/problem/P1725
// 状态：已通过
// 算法：动态规划、单调队列、滑动窗口最值

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const int INF = 1e9;
int a[N];
int dp[N];

void solve (){
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i ++){
        cin >> a[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = -INF;
    }
    deque <int> dq;
    for (int i = 0; i <= n; i ++){
        int j = i - l;

        if (j >= 0 && dp[j] != -INF){
            while (dq.size() && dp[dq.back()] <= dp[j]){
                dq.pop_back();
            }
            dq.push_back(j);
        }
        while (dq.size() && dq.front() < i - r){
            dq.pop_front();
        }
        if (dq.size()){
            dp[i] = dp[dq.front()] + a[i];
        }
    }
    int ans = -INF;
    for (int i = max(0, n - r + 1); i <= n; i ++){
        ans = max(ans, dp[i]);
    }
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
