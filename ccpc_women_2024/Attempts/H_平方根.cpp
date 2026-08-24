// 比赛：2024 年 CCPC 女生专场
// 题目：H - 平方根（早期实现）
// 链接：https://qoj.ac/contest/1841/problem/9746
// 状态：未通过
// 算法：连续段、数学、分类讨论

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;
    vector <pair <int, int>> cnt;
    int n = s.length();
    int lst1 = -1;
    for (int i = 0; i < s.length(); i ++){
        if (lst1 == -1 && s[i] == '1'){
            lst1 = i;
            // cout << lst1 << '\n';
        }
        if (s[i] == '0' && lst1 != -1){
            // cout << lst1 << ' ' << i - 1 << '\n';
            cnt.push_back({lst1, i - 1});
            lst1 = -1;
        }
    }
    if (lst1 != -1){
        cnt.push_back({lst1, n - 1});
    }
    long double res = 0.0;
    vector <double> len;
    for (int i = 0; i < cnt.size(); i ++){
        auto [p1, p2] = cnt[i];
        int cur = 0;
        if (i == 0){
            cur = p2 + 1;
        } else if (i == cnt.size() - 1){
            cur = n - 1 - p1 + 1;
        } else {
            cur = p2 - p1 + 1;
        }
        if (cur >= 3){
            res += ((long double)cur + 1.0) / 2.0;
        } else {
            len.push_back(cur);
        }
        /* if (i == 0){
            int cur = p2 + 1;
            auto [p, pp] = cnt[i + 1];
            int hou = pp - p + 1;
            int rem = p - p2 - 1;
            if (rem >= 1){
                if (hou > cur){
                    cnt[i + 1].first -= rem - 1;
                    len.push_back(cur);
                } else {
                    len.push_back(cur + rem - 1);
                }
            } else {
                len.push_back(cur);
            }
        } else if (i == cnt.size() - 1){
            len.push_back(n - 1 - p1 + 1);
        } else {
            int cur = p2 - p1 + 1;
            auto [p, pp] = cnt[i + 1];
            int hou = pp - p + 1;
            int rem = p - p2 - 1;
            if (rem >= 2){
                if (hou > cur){
                    cnt[i + 1].first -= rem - 1;
                    len.push_back(cur);
                } else {
                    len.push_back(cur + rem - 1);
                }
            } else {
                len.push_back(cur);
            }
        }
        // cout << p1 << ' ' << p2 << '\n'; */
    }
    for (auto i : len){
        // cout << i << ' ';
        res += sqrtl(i);
    }
    // cout << '\n';
    cout << fixed << setprecision(12) << res << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t --){
        solve();
    }
    return 0;
}
