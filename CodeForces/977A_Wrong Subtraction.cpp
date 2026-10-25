// 比赛/平台：Codeforces
// 题目：977A Wrong Subtraction
// 链接：https://codeforces.com/problemset/problem/977/A
// 状态：已通过
// 算法：模拟、数位

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;

    while (k --){
        int base = n / 10;
        int rem = n % 10;

        if (rem == 0){
            n = base;
        } else {
            n --;
        }
    }

    cout << n << '\n';
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
