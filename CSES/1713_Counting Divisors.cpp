// 比赛/平台：CSES Problem Set
// 题目：1713 - Counting Divisors
// 链接：https://cses.fi/problemset/task/1713/
// 状态：待验证
// 算法：约数筛、调和级数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
ll cnt[N];

void init(){
    for (int i = 1; i < N; i ++){
        for (int j = i; j < N; j += i){
            cnt[j] ++;
        }
    }
}

void solve(){
    ll n;
    cin >> n;
    cout << cnt[n] << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t --){
        solve();
    }
    return 0;
}
