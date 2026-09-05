// 比赛：竞极比赛 2095727662160490498
// 题目：C - 所有窗口长度的最大最小值（本地语义命名）
// 链接：http://47.120.23.84/contest/2095727662160490498/2095728621846605829
// 状态：待验证
// 算法：单调栈、贡献区间、后缀最大值

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];

ll tree[N << 2];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    vector <int> ans(n + 5, 0);
    stack <int> stk;
    for (int i = 1; i <= n + 1; i ++){
        int val = (i == n + 1 ? 0 : a[i]);

        while (!stk.empty() && a[stk.top()] >= val){
            int pos = stk.top();
            stk.pop();

            int l = 0;
            if (!stk.empty()){
                l = stk.top();
            }

            int len = i - l - 1;
            ans[len] = max(ans[len], a[pos]);

        }
        if (i <= n){
            stk.push(i);
        }
    }

    for (int i = n; i >= 1; i --){
        ans[i] = max(ans[i], ans[i + 1]);
    }

    for (int i = 1; i <= n; i ++){
        cout << ans[i] << ' ';
    }
}

int  main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
