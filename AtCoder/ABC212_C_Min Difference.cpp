// 比赛：AtCoder Beginner Contest 212
// 题目：ABC212 C - Min Difference
// 链接：https://atcoder.jp/contests/abc212/tasks/abc212_c
// 状态：待验证
// 算法：排序、双指针

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 1);
    vector <int> b(m + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i ++){
        cin >> b[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    sort(b.begin() + 1, b.begin() + m + 1);
    int i = 1;
    int j = 1;
    int mn = abs(a[i] - b[j]);
    while (i <= n && j <= m){
        mn = min(mn, abs(a[i] - b[j])) ;
        if (a[i] > b[j]){
            j ++;
        } else if (a[i] < b[j]){
            i ++;
        } else {
            mn = 0;
            break;
        }
    }
    cout << mn << '\n';
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
