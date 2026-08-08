// 比赛：2026 牛客暑期多校训练营 5（133880）
// 题目：F - Four - https://ac.nowcoder.com/acm/contest/133880/F
// 状态：未完成（账号未通过；仅有输入框架）
// 分类：数论、最大公因数与最小公倍数、欧拉函数、莫比乌斯反演、狄利克雷前后缀和
// 创建：MYC，2026/7/31
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int A, B, C, D, p1, p2, p3, p4;
    cin >> A >> B >> C >> D;
    cin >> p1 >> p2 >> p3 >> p4;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
