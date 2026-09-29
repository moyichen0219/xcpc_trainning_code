// 比赛：CSES Sorting and Searching
// 题目：1141 - Playlist
// 链接：https://cses.fi/problemset/task/1141/
// 状态：待验证
// 算法：滑动窗口、映射、双指针

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    map <int, int> mp;

    int ans = 0;
    int i = 1;
    int j = 1;
    while (i <= n && j <= n){
        if (mp[a[j]] > 0){
            while (mp[a[j]] > 0){
                mp[a[i]] --;
                i ++;
            }
        }
        mp[a[j]] ++;
        ans = max(ans, j - i + 1);
        j ++;
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
