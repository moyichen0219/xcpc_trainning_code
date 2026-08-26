// 比赛：竞极题库
// 题目：C5054 舒适区间
// 链接：http://47.120.23.84/problems/2091929269054775298
// 状态：待验证
// 算法：滑动窗口、多重集合、区间极值

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    // mx - mn <= k
    vector <int> a(n + 1);
    int mx = 0;
    int mn = 1e9 + 10;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(a[i], mx);
        mn = min(a[i], mn);
    }
    if (mx - mn <= k){
        cout << n << '\n';
        return ;
    }
    int ans = 0;
    int l = 1;
    multiset <int> s;
    for (int i = 1; i <= n; i ++){
        s.insert(a[i]);
        while (*s.rbegin() - * s.begin() > k){
            s.erase(s.find(a[l]));
            l ++;
        }
        // cout << l << ' ' << i << '\n';
        ans = max (ans, i - l + 1);
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
