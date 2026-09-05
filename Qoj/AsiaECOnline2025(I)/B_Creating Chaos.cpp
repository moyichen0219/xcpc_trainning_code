// 比赛：The 2025 ICPC Asia East Continent Online Contest (I)
// 题目：B - Creating Chaos
// 链接：https://qoj.ac/contest/2513/problem/14302
// 状态：待验证
// 算法：构造

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = n - k + 1; i <= n; i ++){
        cout << i << ' ';
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
