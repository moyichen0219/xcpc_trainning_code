// 比赛：2026 牛客暑期多校训练营 9
// 题目：I - Slay the Spire
// 链接：https://ac.nowcoder.com/acm/contest/133884/I
// 状态：已通过
// 算法：二分答案、等差数列、枚举

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll x, a, b;

bool check(ll cnt, ll mid){
    if (mid < cnt){
        return false;
    }
    ll ans = 0;
    if (cnt > 0){
        ans = cnt * a + (cnt * (cnt - 1) * (a - 1) / 2);
    }
    ans += (mid - cnt) * b;

    // 余毒 cnt* (a - 1)， 剩余场次 mid - cnt
    // 取最小， 每个剩余场次 -余毒， 余毒--；
    ll q = min(mid - cnt, cnt * (a - 1));
    ll rem = cnt * (a - 1);
    ans += q * (2 * rem - q + 1) / 2;
    return ans >= x;
}

void solve(){
    cin >> x >> a >> b;
    if (b >= x){
        cout << 1 << '\n';
        return ;
    }
    if (a == 1){
        cout << (x + b - 1) / b << '\n';
        return ;
    }
    ll ans = INT_MAX;
    for (int i = 0; ; i ++){
        if (check(i, i)){
            ans = min(ans, (ll)i);
            cout << ans << '\n';
            return ;
        }
        int l = 0;
        int r = 1e9 + 10;
        while (l < r){
            int mid = (l + r) / 2;
            if (check(i, mid)){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans = min(ans, (ll)r);
    }
    cout << ans << '\n';
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
