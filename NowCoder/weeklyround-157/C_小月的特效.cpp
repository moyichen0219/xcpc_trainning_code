// 比赛：牛客周赛 Round 157
// 题目：C - 小月的特效
// 链接：https://ac.nowcoder.com/acm/contest/139206/C
// 状态：已通过
// 算法：映射、下标奇偶性

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    map <ll, pair <int, int>> mp;
    for (int i = 1; i <= n; i ++){
        ll x;
        cin >> x;
        if (!mp.count(x)){
            mp[x] = {i, i};
        } else {
            mp[x].second = i;
        }
    }
    int ans = 0;
    for (auto [x, pp] : mp){
        int p1 = pp.first;
        int p2 = pp.second;
        if (p1 < p2 && (p2 - p1 ) % 2 == 0){
            ans ++;
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
