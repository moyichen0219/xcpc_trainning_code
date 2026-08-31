// 比赛：竞极比赛 2093329939779661825
// 题目：C 三段不相交子数组（本地语义命名）
// 链接：http://47.120.23.84/contest/2093329939779661825/2093331392749481986
// 状态：待验证
// 算法：动态规划、前缀和、全排列

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 4e18;

void solve(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector <ll> w(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> w[i];
    }
    vector <ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i ++){
        pre[i] = pre[i - 1] + w[i];
    }
    ll ans = -INF;
    int x[] = {a, b, c};
    sort(x, x + 3);
    do {
        int A = x[0];
        int B = x[1];
        int C = x[2];

        vector <ll> dp1(n + 1, -INF);
        vector <ll> dp2(n + 1, -INF);
        vector <ll> dp3(n + 1, -INF);

        for (int i = 1; i <= n; i ++){
            dp1[i] = dp1[i - 1];
            if (i >= A){
                ll sum = pre[i] - pre[i - A];
                dp1[i] = max(dp1[i], sum);
            }
        }

        for (int i = 1; i <= n; i ++){
            dp2[i] = dp2[i - 1];
            if (i >= B && dp1[i - B] != -INF){
                ll sum = pre[i] - pre[i - B];
                dp2[i] = max(dp2[i], dp1[i - B] + sum);
            }
        }

        for (int i = 1; i <= n; i ++){
            dp3[i] = dp3[i - 1];
            if (i >= C && dp2[i - C] != -INF){
                ll sum = pre[i] - pre[i - C];
                dp3[i] = max(dp3[i], dp2[i - C] + sum);
            }
        }

        ans = max(ans, dp3[n]);
    }while (next_permutation(x, x + 3));

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
