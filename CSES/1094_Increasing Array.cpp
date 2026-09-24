// 比赛：CSES Introductory Problems
// 题目：1094 - Increasing Array
// 链接：https://cses.fi/problemset/task/1094/
// 状态：待验证
// 算法：贪心、线性扫描

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 2; i<= n; i ++){
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
