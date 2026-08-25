// 比赛：洛谷题库
// 题目：P1042 - [NOIP 2003 普及组] 乒乓球
// 链接：https://www.luogu.com.cn/problem/P1042
// 状态：已通过
// 算法：模拟、计分规则

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    char cc;
    string s = "";
    while (cin >> cc){
        if (cc != 'E'){
            s += cc;
        } else {
            break;
        }
    }
    int a = 0;
    int b = 0;
    for (auto c : s){
        if (c == 'W'){
            a ++;
        } else {
            b ++;
        }
        if (max(a, b) >= 11 && abs(a - b) >= 2){
            cout << a << ':' << b << '\n';
            a = 0;
            b = 0;
        }
    }
    cout << a << ':' << b << '\n';
    cout << '\n';
    a = 0;
    b = 0;
    for (auto c : s){
        if (c == 'W'){
            a ++;
        } else {
            b ++;
        }
        if (max(a, b) >= 21 && abs(a - b) >= 2){
            cout << a << ':' << b << '\n';
            a = 0;
            b = 0;
        }
    }
    cout << a << ':' << b << '\n';
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
