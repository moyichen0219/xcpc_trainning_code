// 比赛：2024 年 CCPC 女生专场
// 题目：H - 平方根
// 链接：https://qoj.ac/contest/1841/problem/9746
// 状态：已通过
// 算法：连续段、数学、分类讨论

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;
    vector <pair<int, int>> len;
    int lst1 = -1;
    int n = s.length();
    for (int i = 0; i < s.length(); i ++){
        if (lst1 == -1 && s[i] == '1'){
            lst1 = i;
        }
        if (lst1 != -1 && s[i] == '0'){
            len.push_back({lst1, i - 1});
            lst1 = -1;
        }
    }
    if (lst1 != -1){
        len.push_back({lst1, n - 1});
    }
    long double res = 0.0;
    vector <int> ans ;
    for (int i = 0; i < len.size(); i ++){
        auto [p1, p2] = len[i];
        int cur = p2 - p1 + 1;
        if (cur & 1){
            res += ((long double)cur + 1.0) / 2.0;
        } else {
            res += ((long double)cur) / 2.0 + sqrtl(2.0L) - 1.0;
        }
    }
    for (auto i : ans){
        res += sqrtl(i);
    }
    cout << fixed << setprecision(12) << res << '\n';
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
