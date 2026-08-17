// 比赛：AtCoder Beginner Contest 471
// 题目：ABC471 B - Survey Tabulation
// 链接：https://atcoder.jp/contests/abc471/tasks/abc471_b
// 状态：已通过
// 算法：字符串、映射、计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    int mx = 0;
    map <string, int> ss;
    for (int i = 1; i <= n; i ++){
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j ++){
            if (s[j] >= 'A' && s[j] <= 'Z'){
                s[j] += 'a' - 'A';
            }
        }
        ss[s] ++;
    }
    for (auto [s, cnt] : ss){
        mx = max(cnt, mx);
    }
    cout << mx << '\n';
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
