// 比赛：算法与数学 演习问题集
// 题目：060 - Stones Game 1
// 链接：https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_az
// 状态：已通过
// 算法：博弈论、数学

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin >> n;
    if (n % 4 == 0){
        cout << "Second" << '\n';
    } else {
        cout << "First" << '\n';
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
