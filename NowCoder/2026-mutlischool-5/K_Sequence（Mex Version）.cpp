// 比赛：2026 牛客暑期多校训练营 5（133880）
// 题目：K - Sequence（Mex Version）- https://ac.nowcoder.com/acm/contest/133880/K
// 状态：已通过（账号评测状态已于 2026-08-08 核对）
// 分类：模拟、最小未出现值、二周期
// 创建：MYC，2026/7/31
#include<bits/stdc++.h>
using namespace std;

int mex(int x, int y, int z) {
    bool ok1 = false;
    bool ok2 = false;
    bool ok3 = false;
    if (x == 0 || y == 0 || z == 0) {
        ok1 = true;
    }
    if (x == 1 || y == 1 || z == 1) {
        ok2 = true;
    }
    if (x == 2 || y == 2 || z == 2) {
        ok3 = true;
    }
    if (ok1) {
        if (ok2) {
            if (ok3) {
                return 3;
            } else {
                return 2;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}


void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector <int> b(n);
    for (int i = 0; i < n; i ++) {
        b[i] = mex(a[i], a[(i + 1) % n], a[(i + n - 1) % n]);
    }
    vector <int> c(n);
    for (int i = 0; i < n; i ++) {
        c[i] = mex(b[i], b[(i + 1) % n], b[(i + n - 1) % n]);
    }
    vector <int> d(n);
    for (int i = 0; i < n; i ++) {
        d[i] = mex(c[i], c[(i + 1) % n], c[(i + n - 1) % n]);
    }
    vector <int> e(n);
    for (int i = 0; i < n; i ++) {
        e[i] = mex(d[i], d[(i + 1) % n], d[(i + n - 1) % n]);
    }
    if (k == 0) {
        for (auto i : a) {
            cout << i << ' ';
        }
    } else if (k == 1) {
        for (auto i : b) {
            cout << i << ' ';
        }
    } else if (k == 2) {
        for (auto i : c) {
            cout << i << ' ';
        }
    } else if (k % 2 == 1) {
        for (auto i : d) {
            cout << i << ' ';
        }
    } else if (k % 2 == 0) {
        for (auto i : e) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
