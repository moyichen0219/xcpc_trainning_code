// 比赛：AtCoder Beginner Contest 135
// 题目：ABC135 C - City Savers
// 链接：https://atcoder.jp/contests/abc135/tasks/abc135_c
// 状态：已通过
// 算法：贪心、模拟

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int a[N], b[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n + 1; i ++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++){
        cin >> b[i];
    }
    ll cnt = 0;
    for (int i = 1; i <= n; i ++){
        if (a[i] >= b[i]){
            cnt += b[i];
            a[i] -= b[i];
        } else {
            cnt += a[i];
            b[i] -= a[i];
            a[i] = 0;
            if (a[i + 1] >= b[i]){
                cnt += b[i];
                a[i + 1] -= b[i];
            } else {
                cnt += a[i + 1];
                a[i + 1] = 0;
            }
        }
    }
    cout << cnt << '\n';
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
