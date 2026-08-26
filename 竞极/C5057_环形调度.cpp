// 比赛：竞极题库
// 题目：C5057 环形调度
// 链接：http://47.120.23.84/problems/2092101704070782977
// 状态：待验证
// 算法：前缀和、中位数、环形均分

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    ll sum = 0;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        sum += a[i];
    }
    ll tar = sum / n;
    vector <ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i ++){
        pre[i] = pre[i - 1] + a[i] - tar;
    }
    nth_element(pre.begin() + 1, pre.begin() + n / 2 + 1, pre.end());
    ll mid = pre[n / 2 + 1];
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        ans += llabs(pre[i] - mid);
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
