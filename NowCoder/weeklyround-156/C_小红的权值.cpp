// 比赛：牛客周赛 Round 156
// 题目：C - 小红的权值
// 链接：https://ac.nowcoder.com/acm/contest/138917/C
// 状态：已通过
// 算法：贪心、排序、前缀和、二分查找

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];

ll cnt (priority_queue<ll> pq, ll ans, ll k){
    ll cnt = 0;
    while (pq.size()){
        ll x = pq.top();
        pq.pop();
        ans -= x;
        cnt ++;
        if (ans <= k){
            return cnt;
        }
    }
    return cnt;
}

void solve(){
    ll n, q, x;
    cin >> n >> q >> x;
    ll ans = 0;
    priority_queue <ll> pq;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        ll tar = abs(a[i] - x);
        ans += tar;
        pq.push(tar);
    }
    while (q --){
        ll k;
        cin >> k;
        if (k >= ans){
            cout << 0 << '\n';
            continue;
        }
        ll res = cnt(pq, ans, k);
        cout << res << '\n';
    }
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

const int N = 2e5 + 10;
int a[N];

ll cnt (priority_queue<ll> pq, ll ans, ll k){
    ll cnt = 0;
    while (pq.size()){
        ll x = pq.top();
        pq.pop();
        ans -= x;
        cnt ++;
        if (ans <= k){
            return cnt;
        }
    }
    return cnt;
}

void solve(){
    ll n, q, x;
    cin >> n >> q >> x;
    ll ans = 0;
    vector <ll> b;
    vector <ll> pre(n);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        ll tar = abs(a[i] - x);
        ans += tar;
        b.push_back(tar);
    }
    sort(begin(b), end(b), greater<ll>());
    pre[0] = b[0];
    for (int i = 1; i < n; i ++){
        pre[i] = pre[i - 1] + b[i];
    }
    while (q --){
        ll k;
        cin >> k;
        if (k >= ans){
            cout << 0 << '\n';
            continue;
        }
        auto it = lower_bound(begin(pre), end(pre), ans - k);
        cout << it - pre.begin() + 1 << '\n';
    }
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
