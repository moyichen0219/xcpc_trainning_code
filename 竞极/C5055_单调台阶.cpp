// 比赛：竞极题库
// 题目：C5055 单调台阶
// 链接：http://47.120.23.84/problems/2091929268077502465
// 状态：待验证
// 算法：贪心、前缀最大值

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 2; i <= n; i ++){
        if (a[i] < a[i - 1]){
            ans += a[i - 1] - a[i];
            a[i] = a[i - 1];
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
