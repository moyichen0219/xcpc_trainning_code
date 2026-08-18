// 比赛：牛客小白月赛 119
// 题目：NC296377 / C - 睡前床边看LIVE
// 链接：https://ac.nowcoder.com/acm/problem/296377
// 状态：待验证
// 算法：分类讨论、计数、数学

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    map <int, int> mp;
    for (int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        mp[x] ++;
    }
    int mx = mp.rbegin()->first;
    int mn = mp.begin()->first;
    // cout << mx << ' ' << mn << '\n';
    if (mn == mx && mx == n - 1){
        cout << "Other" << '\n';
        return ;
    }
    if (mn == mx && mx * 2 <= n){
        cout << "Other" << '\n';
        return ;
    }
    if (mn + 1 == mx && mp[mn] == mx){
        cout << "Other" << '\n';
        return ;
    }
    cout << "Lie" << '\n';
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
