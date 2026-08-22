// 比赛：Educational Codeforces Round 126 (Rated for Div. 2)
// 题目：1661B - Getting Zero
// 链接：https://codeforces.com/problemset/problem/1661/B
// 状态：已通过
// 算法：暴力枚举、模运算

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    // 多少次+1得到2的倍数，多少次右移得到x的长度
    for (int i = 1; i <= n; i ++){
        int ans = 30;

        for (int j = 0; j <= 15; j ++){
            ll temp = a[i];
            temp = (temp + j) % 32768;
            int cnt = j;
            for (int k = 0; k < 15; k ++){
                if (temp == 0){
                    break;
                }
                temp = (temp * 2) % 32768;
                cnt ++;
            }
            // cout << cnt << ' ';
            ans = min(ans, cnt);
        }
        cout << ans << ' ';
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
