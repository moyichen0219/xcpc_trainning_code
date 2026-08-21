// 比赛：Codeforces Round 277.5 (Div. 2)
// 题目：489C - Given Length and Sum of Digits...
// 链接：https://codeforces.com/problemset/problem/489/C
// 状态：已通过
// 算法：贪心、构造、数位

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int m, s;
    cin >> m >> s;
    if (s > 9 * m || (s == 0 && m > 1)){
        cout << "-1 -1" << '\n';
        return ;
    }
    if (s == 0){
        cout << "0 0" << '\n';
        return;
    }
    vector <int> mx(m + 1);
    vector <int> mn(m + 1);
    if (s / 9 >=  m - 1){
        int rem = s % 9;
        int base = s / 9;
        if (rem != 0){
            for (int i = 1; i <= m; i ++){
                mx[i] = mn[i] = 9;
            }
            mx[m] = rem;
            mn[1] = rem;
        } else {
            mn[1] = 1;
            int cur = s - 1;
            for (int i = m; i > 1; i --){
                mn[i] = min(cur, 9);
                cur -= mn[i];
            }
            mn[1] += cur;
            cur = s;
            for (int i = 1; i <= m; i ++){
                mx[i] = min(cur, 9);
                cur -= mx[i];
            }
        }
    } else {
        mn[1] = 1;
        int cur = s - 1;
        for (int i = m; i > 1; i --){
            mn[i] = min(cur, 9);
            cur -= mn[i];
        }
        cur = s;
        for (int i = 1; i <= m; i ++){
            mx[i] = min(cur, 9);
            cur -= mx[i];
        }
    }
    for (int i = 1; i <= m; i ++){
        cout << mn[i] ;
    }
    cout << ' ';
    for (int i = 1; i <= m; i ++){
        cout << mx[i] ;
    }
    cout << '\n';
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
