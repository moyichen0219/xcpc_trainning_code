// 比赛/平台：洛谷
// 题目：P9873 [EC Final 2021] Beautiful String
// 链接：https://www.luogu.com.cn/problem/P9873
// 状态：未通过
// 算法：字符串模式匹配、最近合法起点、子串计数

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;

    ll ans = 0;
    int n = s.size();

    int lst = -1;

    for (int i = 0; i < n; i ++){
        if (i >= 5){
            int r = i - 5;
            if (s[r] == s[r + 1] &&
                s[r] == s[r + 4] &&
                s[r + 2] == s[r + 5]){
                    lst = r;
            }
        }
        ans += lst + 1;
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
