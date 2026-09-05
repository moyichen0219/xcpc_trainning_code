// 比赛：NOIP 2018 提高组
// 题目：P5019 - 铺设道路
// 链接：https://www.luogu.com.cn/problem/P5019
// 状态：已通过
// 算法：贪心、差分

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1, 0);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        if (a[i] > a[i - 1]){
            ans += (a[i] - a[i - 1]);
        }
    }
    cout << ans << '\n';
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
