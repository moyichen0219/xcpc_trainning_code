// 比赛/平台：Educational Codeforces Round 195 (Rated for Div. 2)
// 题目：2276B - Replace and Compress
// 链接：https://codeforces.com/contest/2276/problem/B
// 状态：已通过
// 算法：字符串、局部模式、分类讨论

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;

    int n = s.size();
    string ans = "";

    int tar = 1;
    bool ok1 = false;
    bool ok2 = false;

    for (int i = 1; i < n - 1; i++){
        if (s[i - 1] != s[i] && s[i] != s[i + 1]){
            ok1 = true;
        }

        if (s[i - 1] == s[i] && s[i] == s[i + 1]){
            ok2 = true;
        }
    }

    if (ok1){
        tar ++;
    }
    if (ok2){
        tar ++;
    }

    cout << tar << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
