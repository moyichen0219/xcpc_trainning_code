// 比赛：AtCoder Beginner Contest 468
// 题目：ABC468 A - Maximal Value
// 链接：https://atcoder.jp/contests/abc468/tasks/abc468_a
// 状态：已通过
// 算法：枚举、局部最大值
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n - 2; i ++) {
        if (a[i + 1] > a[i] && a[i + 1] > a[i + 2]) {
            cnt ++;
        }
    }
    cout << cnt << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t --) {
        solve();
    }
    return 0;
}
