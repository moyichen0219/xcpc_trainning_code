// 比赛：NOIP 2017 提高组
// 题目：P3951 小凯的疑惑
// 链接：https://www.luogu.com.cn/problem/P3951
// 状态：已通过
// 算法：数论、裴蜀定理、Frobenius 数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll a, b;
    cin >> a >> b;
    cout << a * b - a - b;
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
