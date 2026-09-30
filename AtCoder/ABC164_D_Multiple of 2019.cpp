// 比赛：AtCoder Beginner Contest 164
// 题目：D - Multiple of 2019
// 链接：https://atcoder.jp/contests/abc164/tasks/abc164_d
// 状态：已通过
// 算法：后缀取模、同余、频次映射

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;

    ll ans = 0;

    map <int, int> mp;
    mp[0] = 1;

    int cur = 0;
    int p = 1;
    for (int i = s.size() - 1; i >= 0; i --){
        int x = s[i] - '0';
        cur = (cur + x * p) % 2019;
        ans += mp[cur];
        mp[cur] ++;
        p = p * 10 % 2019;
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
