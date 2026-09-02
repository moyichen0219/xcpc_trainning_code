// 比赛：NOIP 2017 普及组
// 题目：P3957 跳房子
// 链接：https://www.luogu.com.cn/problem/P3957
// 状态：已通过
// 算法：二分答案、动态规划、单调队列

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 10;
int a[N];
int x[N];
int s[N];
int dp[N];

int n, d, k;

bool check(int mid){
    for (int i = 1; i <= n; i ++){
        dp[i] = -1e9;
    }
    dp[0] = 0;
    int l = max(1, d - mid);
    int r = d + mid;
    deque <int> dq;
    int cur = 0;
    for (int i = 1; i <= n; i ++){
        while (cur < i && x[i] - x[cur] >= l){
            if (dp[cur] != -1e9){
                while (dq.size() && dp[dq.back()] < dp[cur]){
                    dq.pop_back();
                }
                dq.push_back(cur);
            }
            cur ++;
        }

        while (dq.size() && x[i] - x[dq.front()] > r){
            dq.pop_front();
        }

        if (dq.size()){
            dp[i] = dp[dq.front()] + s[i];
        }

        if (dp[i] >= k){
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> d >> k;
    for (int i = 1; i <= n; i ++){
        cin >> x[i] >> s[i];
    }
    int l = 0;
    int r = 1e9 + 10;
    int ans = -1;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        } else{
            l = mid + 1;
        }
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
