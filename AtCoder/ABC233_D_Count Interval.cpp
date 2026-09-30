// 比赛：AtCoder Beginner Contest 233
// 题目：D - Count Interval
// 链接：https://atcoder.jp/contests/abc233/tasks/abc233_d
// 状态：待验证
// 算法：前缀和、频次映射、子数组计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];
ll pre[N];

void solve(){
    ll n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++){
        pre[i] = pre[i - 1] + a[i];
    }

    map <ll, int> mp;
    ll cnt = 0;

    mp[0] = 1;

    for (int i = 1; i <= n; i ++){
        if (mp.find(pre[i] - k) != mp.end() && mp[pre[i] - k] > 0){
            cnt += mp[pre[i] - k];
        }
        mp[pre[i]] ++;
    }

    cout << cnt << '\n';
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
