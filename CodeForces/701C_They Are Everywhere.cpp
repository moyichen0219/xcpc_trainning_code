// 比赛/平台：Codeforces
// 题目：701C They Are Everywhere
// 链接：https://codeforces.com/problemset/problem/701/C
// 状态：待验证
// 算法：滑动窗口、双指针、字符计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt = 0;

    map <char, int>mp;
    for (int i = 0; i < s.length(); i ++){
        mp[s[i]] ++;
    }
    int x = mp.size();
    mp.clear();

    int l = 0;
    int cur = 0;
    int ans = INT_MAX;

    for (int i = 0; i < s.length(); i ++){
        if (mp[s[i]] == 0){
            cur ++;
        }

        mp[s[i]] ++;

        while (cur == x){
            ans = min(ans, i - l + 1);

            mp[s[l]] --;

            if (mp[s[l]] == 0){
                cur --;
            }

            l ++;
        }
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
