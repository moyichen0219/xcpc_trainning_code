// 比赛：Educational Codeforces Round 93 (Rated for Div. 2)
// 题目：1398C - Good Subarrays
// 链接：https://codeforces.com/problemset/problem/1398/C
// 状态：已通过
// 算法：前缀和、等值计数、频次映射

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int a[N];

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i ++){
        a[i + 1] = a[i] + (s[i] - '0') - 1;
    }

    ll cnt = 0;

    map <int, int> mp;
    mp[0] = 1;

    for (int i = 1; i <= n; i ++){
        if (mp.find(a[i]) != mp.end() && mp[a[i]] > 0){
            cnt += mp[a[i]];
        }
        mp[a[i]] ++;
    }

    cout << cnt << '\n';
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
