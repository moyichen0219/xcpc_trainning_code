// 比赛：AtCoder Beginner Contest 472
// 题目：A - A
// 链接：https://atcoder.jp/contests/abc472/tasks/abc472_a
// 状态：待验证
// 算法：字符串、模拟

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;
    for (auto c : s){
        if (c == 'A'){
            cout << c ;
        } else {
            cout << '.';
        }
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
