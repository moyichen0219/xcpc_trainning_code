// 比赛：AtCoder Beginner Contest 252
// 题目：ABC252 C - Slot Strategy
// 链接：https://atcoder.jp/contests/abc252/tasks/abc252_c
// 状态：已通过
// 算法：枚举、排序

#include<bits/stdc++.h>
using namespace std;
using ll= long long;

void solve(){
    int n;
    cin >> n;
    vector <int> pos[10];
    for (int i = 1; i <= n; i ++){
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j ++){
            pos[s[j] -'0'].push_back(j);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= 9; i ++){
        sort(pos[i].begin(), pos[i].end());
        int cur = 0;
        int base = 0;
        int lst = -1;
        for (auto p : pos[i]){
            if (p != lst){
                base = 0;
            } else {
                base ++;
            }
            cur = max(cur, p + 10 * base);
            lst = p;
        }
        ans = min(cur, ans);
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
