// 比赛：2024 年 CCPC 女生专场
// 题目：L - 拼图
// 链接：https://qoj.ac/contest/1841/problem/9750
// 状态：已通过
// 算法：枚举、数学、面积最大化

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < 4){
        cout << 0 << '\n';
        return ;
    }
    /* if (a >= 4 && b == c && c == d && d == 0){
        cout << 4 << '\n';

    } */
    int k = min(b, c);
    int ans = 0;
    // 定义x为长， y为宽（除去A的）（因此实际长宽需要+2）
    for (int x = 0; x <= k; x ++){
        int y ;
        if (x == 0){
            y = k;
        } else {
            y = min(k - x, d / x);
        }
        ans = max(ans, (x + 2) * (y + 2));
    }
    cout << ans << '\n';
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
