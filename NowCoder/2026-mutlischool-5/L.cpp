// 比赛：2026 牛客暑期多校训练营 5（133880）
// 题目：L - Matrix - https://ac.nowcoder.com/acm/contest/133880/L
// 状态：未完成（账号未通过；仅有部分分类讨论）
// 分类：网格、反对角线分层、流量分配、前缀和、贪心
// 创建：MYC，2026/7/31
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e3 + 10;
int a[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    int n, m;
    cin >> n >> m;
    int mx = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    if (n == 1 && m == 1) {
        cout << 0 << '\n';
    }
    if (a[1][1] != a[n][m]) {
        cout << -1 << '\n';
    }
    if (m >= 2 && n >= 2 && a[2][1] + a[2][2] - a[1][1] < mx) {
        cout << -1 << '\n';
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
