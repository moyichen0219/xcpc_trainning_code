// 比赛：AtCoder Beginner Contest 246
// 题目：ABC246 C - Coupon
// 链接：https://atcoder.jp/contests/abc246/tasks/abc246_c
// 状态：已通过
// 算法：贪心、优先队列

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k, x;
    cin >> n >> k >> x;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    ll ans = 0;
    for (int i = n; i >= 1; i --){
        if (a[i] >= x && k){
            int base = a[i] / x;
            int rem = a[i] % x;
            if (base <= k){
                k -= base;
                a[i] = rem;
            } else {
                a[i] -= k * x;
                k = 0;
            }
        }
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    for (int i = n; i >= 1 && k > 0; i --){
        a[i] = 0;
        k --;
    }
    for (int i = 1; i <= n; i ++){
        ans += a[i];
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
} */

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k, x;
    cin >> n >> k >> x;

    priority_queue <int> pq;
    for (int i = 1; i <= n; i ++){
        int y;
        cin >> y;
        pq.push(y);
    }

    while (k && !pq.empty()){
        int p = pq.top();
        pq.pop();
        if (p >= x){
            int use = min(k, p / x);
            p -= use * x;
            k -= use;
            if (p > 0){
                pq.push(p);
            }
        } else {
            k --;
        }
    }

    ll ans = 0;
    while (!pq.empty()){
        int p = pq.top();
        pq.pop();
        ans += p;
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
