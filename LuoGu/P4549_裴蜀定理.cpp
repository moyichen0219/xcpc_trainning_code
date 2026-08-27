// 比赛：洛谷题库
// 题目：P4549 【模板】裴蜀定理
// 链接：https://www.luogu.com.cn/problem/P4549
// 状态：已通过
// 算法：裴蜀定理、最大公约数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    ll ans ;
    cin >> ans ;
    ans = llabs(ans);
    for (int i = 2; i <= n; i ++){
        ll x;
        cin >> x;
        ans = __gcd(ans, llabs(x));
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
