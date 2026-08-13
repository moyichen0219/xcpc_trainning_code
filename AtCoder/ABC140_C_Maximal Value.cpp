// 比赛：AtCoder Beginner Contest 140
// 题目：ABC140 C - Maximal Value
// 链接：https://atcoder.jp/contests/abc140/tasks/abc140_c
// 状态：已通过
// 算法：贪心、相邻约束

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> b(n + 1);
    for (int i = 1; i < n; i ++){
        cin >> b[i];
    }
    ll ans = b[1] + b[n - 1];
    for (int i = 1; i < n; i ++){
        ans += min(b[i + 1], b[i]);
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
