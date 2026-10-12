// 比赛/平台：CSES Problem Set
// 题目：1755 - Palindrome Reorder
// 链接：https://cses.fi/problemset/task/1755/
// 状态：待验证
// 算法：字符计数、回文构造

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;

    vector <int> cnt(26, 0);
    for (int i =0; i < s.length(); i ++){
        cnt[s[i] - 'A'] ++;
    }

    string ans = "";
    int c = 0;
    for (int i = 0; i < 26; i ++){
        if (cnt[i] % 2 != 0){
            c ++;
        }
        for (int j = 0; j < (cnt[i] / 2); j ++){
            ans += ('A' + i);
        }
    }
    string temp = ans;

    if (c > 1){
        cout << "NO SOLUTION" << '\n';
        return;
    } else if (c == 1){
        for (int i = 0; i < 26; i ++){
            if (cnt[i] % 2 != 0){
                ans += ('A' + i);
            }
        }
        cout << ans;
    } else {
        cout << ans;
    }

    cout << string(temp.rbegin(), temp.rend()) << '\n';
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
