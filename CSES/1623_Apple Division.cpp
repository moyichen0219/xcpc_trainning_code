// 比赛/平台：CSES Problem Set
// 题目：1623 Apple Division
// 链接：https://cses.fi/problemset/task/1623/
// 状态：待验证
// 算法：子集枚举、位运算、平衡划分

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

    ll ans = LLONG_MAX;

    for (int i = 0; i < (1 << n); i ++){
        ll cur = 0;

        for (int j = 0; j < n; j ++){
            if (i & (1 << j)){
                cur += a[j];
            }
        }

        ans = min(ans, abs(sum - cur - cur));
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
