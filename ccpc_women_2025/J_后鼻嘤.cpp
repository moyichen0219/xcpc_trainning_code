// 比赛：2025 年 CCPC 女生专场
// 题目：J - 后鼻嘤（QOJ 14459）- https://qoj.ac/contest/2564/problem/14459
// 状态：已通过（QOJ 账号 Moyichen，2026-08-08 核对）
// 分类：字符串、模拟
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    getline(cin, s);
    string ss = "";
    for (int i = 0; i < s.length(); i ++){
        ss += s[i];
        if (s[i] == 'n'){
            if (i == s.length() - 1){
                ss += 'g';
            } else if (s[i + 1] == ' ') {
                ss += 'g';
            }
        }
    }
    cout << ss << '\n';
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
