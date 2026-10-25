// 比赛/平台：CSES Problem Set
// 题目：1071 Number Spiral
// 链接：https://cses.fi/problemset/task/1071/
// 状态：待验证
// 算法：数学、坐标规律、奇偶分类

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(int n){
    return 1LL * n * n - n + 1;
}

void solve(){
    int t;
    cin >> t;

    for (int i = 1; i <= t; i ++){
        int y, x;
        cin >> y >> x;

        ll ans = 0;

        if (x >= y){
            if (x % 2 == 1){
                ans = f(x) + (x - y);
            } else{
                ans = f(x) - (x - y);
            }
        } else {
            if (y % 2 == 1){
                ans = f(y) - (y - x);
            } else{
                ans = f(y) + (y - x);
            }
        }

        cout << ans << '\n';
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
