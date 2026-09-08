// 比赛：2024 年中国大学生程序设计竞赛女生专场
// 题目：105487H - Square Root
// 链接：https://codeforces.com/gym/105487/problem/H
// 状态：已通过
// 算法：连续段、数学、贪心拆分

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;
    vector <int> len;

    int lst = -1;
    for (int i = 0; i < s.length(); i ++){
        if (s[i] == '1' && lst == -1){
            lst = i;
        }
        if (s[i] == '0' && lst != -1){
            len.push_back(i - 1 - lst + 1);
            lst = -1;
        }
    }

    if (lst != -1){
        len.push_back(s.length() - 1 - lst + 1);
    }

    double ans = 0.0;

    for (auto l : len){
        if (l <= 2){
            ans += sqrtl(l);
        } else if (l & 1) {
            ans += (l + 1) / 2.0;
        } else {
            ans += (l - 2) / 2.0 + sqrtl(2.0);
        }
    }

    cout << fixed << setprecision(12) << ans << '\n';
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
