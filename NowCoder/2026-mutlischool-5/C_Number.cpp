// 比赛：2026 牛客暑期多校训练营 5（133880）
// 题目：C - Number
// 链接：https://ac.nowcoder.com/acm/contest/133880/C
// 状态：未完成
// 算法：构造、排列、进位、有向欧拉回路（结果尚未输出）
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int B;
    cin >> B;
    if (B == 1 && B % 2 == 1) {
        cout << -1 << '\n';
    }
    if (B == 4) {
        cout << "0 1 2 3\n1 3 0 2\n 2 0 3 1";
    }
    vector <int> a;
    int cur = B;
    while (cur > 0) {
        cur -= 2;
        a.push_back(cur);
    }
    a.push_back(B - 1);
    a.push_back(0);
    cur = B - 3;
    a.push_back(cur);
    while (cur > 0) {
        cur -= 2;
        a.push_back(cur);
    }

}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
