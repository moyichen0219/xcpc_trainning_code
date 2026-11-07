// 比赛/平台：洛谷
// 题目：P2197 【模板】Nim 游戏
// 链接：https://www.luogu.com.cn/problem/P2197
// 状态：已通过
// 算法：博弈论、Nim 异或

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;

    ll tar = 0;
    for (int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        tar ^= x;
    }

    if (tar != 0){
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
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
