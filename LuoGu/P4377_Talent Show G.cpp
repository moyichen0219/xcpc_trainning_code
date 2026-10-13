// 比赛/平台：洛谷
// 题目：P4377 [USACO18OPEN] Talent Show G
// 链接：https://www.luogu.com.cn/problem/P4377
// 状态：已通过
// 算法：01 分数规划、二分答案、01 背包

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 300;
const double inf = 1e18;
const double eps = 1e-9;
int w[N];
int t[N];

int n, W;

bool check(double mid){
    vector <double> c(n + 1);

    for (int i = 1; i <= n; i ++){
        c[i] = t[i] - mid * w[i];
    }

    vector <double> dp(W + 1, -inf);
    dp[0] = 0;

    for (int i = 1; i <= n; i ++){
        for (int j = W; j >= 0; j --){
            if (dp[j] == -inf){
                continue;
            }

            dp[min(W, w[i] + j)] = max(dp[min(W, w[i] + j)], dp[j] + c[i]);
        }
    }

    return dp[W] >= 0;
}

void solve(){
    cin >> n >> W;

    for (int i = 1;i <= n; i ++){
        cin >> w[i] >> t[i];
    }

    double l = 0;
    double r = 1e9;

    for (int i = 1; i <= 100; i ++){
        double mid = (l + r) / 2.0;

        if (check(mid)){
            l = mid;
        } else {
            r = mid;
        }
    }

    if (l - (int)l <= eps){
        cout << fixed << setprecision(0) << floor((l + eps) * 1000) << endl;
    } else {
        cout << fixed << setprecision(0) << floor(l * 1000) << endl;
    }
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
