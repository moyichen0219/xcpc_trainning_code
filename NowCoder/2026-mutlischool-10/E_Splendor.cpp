// 比赛：2026 牛客暑期多校训练营 10
// 题目：E - Splendor
// 链接：https://ac.nowcoder.com/acm/contest/133885/E
// 状态：未完成
// 算法：贪心、奇偶性、构造

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

int a[5];

// 最小化操作次数 = 最大化三种类操作次数x
// x 受到 sum / 3, (sum - (数1)) / 2, sum - (数1) - (数2)的最小值限制
// a[i] = 2*m + n
void solve(){
    ll sum = 0;
    int cnt_odd = 0;
    for (int i = 0; i < 5; i ++){
        cin >> a[i];
        sum += a[i];
        if (a[i] & 1){
            cnt_odd ++;
        }
    }
    // 进行奇数次或偶数次操作
    int p = sum & 1;
    vector <int> b(5);
    for (int i = 0; i < 5; i ++){
        //
        b[i] = a[i] - ((a[i] & 1) != p);
    }
    sort(b.begin(), b.end(), greater());
    ll x = min({sum / 3, (sum - b[0]) / 2, sum - b[0] - b[1]});
    if (x < 0){
        cout << -1 << '\n';
        return ;
    }
    if (x % 2 != p){
        x ++;
    }
    ll ans = x + (sum - 3 * x) / 2;
    cout << ans << '\n';
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
} */

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[5];

void solve(){
    ll sum = 0;
    for (int i = 0; i < 5; i ++){
        cin >> a[i];
        sum += a[i];
    }
    // sum, k模2同余
    ll k = sum & 1;
    vector <ll> b(5);
    for (int i = 0; i < 5; i ++){
        b[i] = min(a[i], k) + ((a[i] & 1) != k);
    }
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
