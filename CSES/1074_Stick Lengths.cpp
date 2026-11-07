// 比赛/平台：CSES Problem Set
// 题目：1074 Stick Lengths
// 链接：https://cses.fi/problemset/task/1074/
// 状态：待验证
// 算法：中位数、排序、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int p[N];

void solve (){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> p[i];
    }

    sort(p + 1, p + n + 1);

    int tar = 0;
    if (n % 2 == 1){
        tar = p[n / 2 + 1];
    } else {
        tar = (p[n / 2] + p[n / 2 + 1]) / 2;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        ans += abs(p[i] - tar);
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
