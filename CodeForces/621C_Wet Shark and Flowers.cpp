// 比赛：Codeforces Round 341 (Div. 2)
// 题目：621C - Wet Shark and Flowers
// 链接：https://codeforces.com/problemset/problem/621/C
// 状态：已通过（提交 #392991914）
// 算法：概率、区间倍数计数、期望线性性

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
pair <int, int> a[N];
ll cnt[N];

void solve(){
    int n, p;
    cin >> n >> p;

    for (int i = 1; i <= n; i ++){
        cin >> a[i].first >> a[i].second;
        cnt[i] = a[i].second / p - (a[i].first - 1) / p;
    }

    for (int i = 1; i <= n; i ++){
        a[i + n].first = a[i].first;
        a[i + n].second = a[i].second;
        cnt[i + n] = cnt[i];
    }

    double ans = 0;
    for (int i = 1; i <= n; i ++){
        double p1 = 1.0 * cnt[i] / (1.0 * (a[i].second - a[i].first) + 1.0);
        double p2 = 1.0 * cnt[i + 1] / (1.0 * (a[i + 1].second - a[i + 1].first) + 1.0);

        double p = 1.0 - (1.0 - p1) * (1.0 - p2);
        ans += 2000.0 * p;
    }

    cout << fixed << setprecision(12) << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
