// 比赛/平台：Educational Codeforces Round 195 (Rated for Div. 2)
// 题目：2276C - Subarrays
// 链接：https://codeforces.com/contest/2276/problem/C
// 状态：已通过
// 算法：前缀和、同余计数、滑动窗口

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll a[N];
ll pre[N];

void solve(){
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    ll cnt = 0;

    map <int, int> mp;
    queue <int> q;
    q.push(0);

    for (int i = 1; i <= n; i ++){
        if (i > k){
            int x = q.front();
            q.pop();
            mp[x] ++;
        }

        pre[i] = pre[i - 1] + a[i];
        int cur = pre[i] % k;

        cnt += mp[cur];
        q.push(cur);
    }

    cout << cnt << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
