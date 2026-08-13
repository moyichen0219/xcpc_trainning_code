// 比赛：2026 牛客暑期多校训练营 8
// 题目：H - It's Magic, Not a Trick!
// 链接：https://ac.nowcoder.com/acm/contest/133883/H
// 状态：待验证
// 算法：贪心、优先队列、进位模拟

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const int MOD = 998244353;
ll a[N];

void solve(){
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    int pos = n;
    int cnt = 0;
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; i ++){
        if (cnt == 0){
            if (a[i] + 1 <= x){
                pos = i;
                break;
            } else if (a[i] >= x){
                cnt += a[i] / x;
            }
        } else {
            if (a[i] >= x){
                cnt ++;
            } else {
                int dif = x - a[i];
                if (dif <= cnt + 1){
                    cnt -= dif;
                } else {
                    pos = i;
                    break;
                }
            }
        }
    }
    ll ans = 0;
    if (pos == n){
        cout << 0 << '\n';
        return ;
    }
    for (int i = pos; i <= n; i ++){
        ans = (ans + a[i]) % MOD;
    }
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
using i128 = __int128;

const int MOD = 998244353;

void solve(){
    ll n, x;
    cin >> n >> x;
    i128 cnt = 0;
    ll ans = 0;
    ll sum = 0;
    priority_queue <ll> pq;
    for (int i= 1; i <= n; i ++){
        ll k;
        cin >> k;
        sum = (sum + k) % MOD;
        pq.push(k);
    }
    if (x == 1){
        cout << sum << '\n';
        return ;
    } else if (x == 2){
        cout << 0 << '\n';
        return ;
    }
    while (pq.size()){
        ll t = pq.top();
        pq.pop();
        if (t >= x){
            ll plus = t / x;
            ll rem = t % x;
            cnt += plus;
            pq.push(rem);
        } else {
            cnt ++;
            ll diff = x - t;
            if (diff > cnt){
                ans = (ans + t) % MOD;
                cnt --;
            } else {
                cnt -= diff;
            }
        }
    }
    if (cnt + 1 >= x){
        int rem = (cnt + 1) % x;
        ans = (ans + rem) % MOD;
    }
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
}
