// 比赛/平台：洛谷
// 题目：P4018 Roy&October之取石子
// 链接：https://www.luogu.com.cn/problem/P4018
// 状态：已通过
// 算法：博弈论、规律、模 6 分类

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;

    if (n % 6 != 0){
        cout << "October wins!" << '\n';
    } else{
        cout << "Roy wins!" << '\n';
    }
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
