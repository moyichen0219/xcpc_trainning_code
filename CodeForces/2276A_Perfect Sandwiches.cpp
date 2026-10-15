// 比赛/平台：Educational Codeforces Round 195 (Rated for Div. 2)
// 题目：2276A - Perfect Sandwiches
// 链接：https://codeforces.com/contest/2276/problem/A
// 状态：已通过
// 算法：数学、分类讨论

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int a, b;
    cin >> a >> b;

    if (a <= b){
        cout << -1 << '\n';
        return ;
    }

    cout << min(b, a - b) << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t --){
        solve();
    }
    return 0;
}
