// 比赛：2026 牛客暑期多校训练营 4（133879）
// 题目：F - 23 Subsequences - https://ac.nowcoder.com/acm/contest/133879/F
// 状态：未完成（账号未通过；仅有输入框架）
// 分类：动态规划、最长合法子序列、线段树或树状数组、区间询问、前缀最大值
// 创建：MYC，2026/7/29
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll a[N];

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    while (q --) {
        int l, r;
        cin >> l >> r;
        ll ans = 0;

        cout << ans << '\n';
    }
}
