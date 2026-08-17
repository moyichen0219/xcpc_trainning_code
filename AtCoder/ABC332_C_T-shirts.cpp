// 比赛：AtCoder Beginner Contest 332
// 题目：ABC332 C - T-shirts
// 链接：https://atcoder.jp/contests/abc332/tasks/abc332_c
// 状态：已通过
// 算法：贪心、字符串模拟

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int a = 0;
    int other = 0;
    int mx = 0;
    for (int i = 0; i < n; i ++){
        if (s[i] == '1'){
            if (other < m){
                other ++;
            } else {
                a ++;
                mx = max(a, mx);
            }
        } else if (s[i] == '2'){
            a ++;
            mx = max(a, mx);
        } else {
            a = 0;
            other = 0;
        }
    }
    cout << mx << '\n';
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
