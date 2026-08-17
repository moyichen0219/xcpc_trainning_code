// 比赛：牛客周赛 Round 157
// 题目：D - 小月的石阶
// 链接：https://ac.nowcoder.com/acm/contest/139206/D
// 状态：已通过
// 算法：双指针、滑动窗口

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, k;
    cin >> n >> k;
    vector <int> h(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> h[i];
    }
    int l = 1;
    ll cur = 0;
    ll ans = 0;
    for (int r = 2; r <= n; r ++){
        cur += abs(h[r] - h[r - 1]);
        while (cur > k){
            cur -= abs(h[l + 1] - h[l]);
            l ++;
        }
        ans = max(ans, (ll) r - l + 1);
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
