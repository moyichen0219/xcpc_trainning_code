// 比赛：AtCoder Beginner Contest 471
// 题目：ABC471 A - Nine or Nein
// 链接：https://atcoder.jp/contests/abc471/tasks/abc471_a
// 状态：已通过
// 算法：枚举、基础运算

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int a, b;
    cin >> a >> b;
    if (a + b == 9 || a - b == 9 || a * b == 9 || (a / b == 9 && a % b == 0)){
        cout << "Nine" << '\n';
    } else {
        cout << "Nein" << '\n';
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
