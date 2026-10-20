// 比赛/平台：洛谷
// 题目：P2577 [ZJOI2005] 午餐
// 链接：https://www.luogu.com.cn/problem/P2577
// 状态：已通过
// 算法：排序、动态规划、双队列调度

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    ll a, b;
    bool operator < (const node& other)const {
        if (b != other.b){
            return b > other.b;
        }
        return a > other.a;
    }
};

const int N = 210;
const int M = 4e4 + 10;
node x[N];
ll pre[N];
ll dp[N][M];

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> x[i].a >> x[i].b;
    }

    sort(x + 1, x + n + 1);

    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + x[i].a;
    }

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i ++){
        for (int j = 0; j <= pre[i]; j ++){
            if (j >= x[i].a){
                dp[i][j] = min(dp[i][j], max(dp[i - 1][j - x[i].a], j + x[i].b));
            }
            dp[i][j] = min(dp[i][j], max(dp[i - 1][j], pre[i] - j + x[i].b));
        }
    }

    cout << *min_element(dp[n], dp[n] + pre[n] + 1) << '\n';
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
