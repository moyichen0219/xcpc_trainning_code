// 比赛：Good Bye 2014
// 题目：500A - New Year Transportation
// 链接：https://codeforces.com/problemset/problem/500/A
// 状态：已通过
// 算法：模拟、图遍历

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, t;
    cin >> n >> t;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    int cur = 1;
    while (cur < t){
        cur += a[cur];
    }
    if (cur == t){
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

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
