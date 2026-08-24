// 比赛：2024 年 CCPC 女生专场
// 题目：C - CCPC
// 链接：https://qoj.ac/contest/1841/problem/9741
// 状态：已通过
// 算法：字符串计数、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;
    int c = 0;
    int p = 0;
    for (auto cc : s){
        if (cc == 'C'){
            c ++;
        }
        if (cc == 'P'){
            p ++;
        }
    }
    int cnt = 0;
    if (c >= 3){
        cnt = (c - 1) / 2;
    }
    cout << min(cnt, p) << '\n';
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
