// 比赛：AtCoder Beginner Contest 176
// 题目：ABC176 C - Step
// 链接：https://atcoder.jp/contests/abc176/tasks/abc176_c
// 状态：待验证
// 算法：贪心、前缀最大值

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        if (i != 1){
            if (a[i] < a[i - 1]){
                ans += a[i - 1] - a[i];
                a[i] = a[i - 1];
            }
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
