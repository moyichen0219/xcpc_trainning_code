// 比赛：CSES Sorting and Searching
// 题目：1661 - Subarray Sums II
// 链接：https://cses.fi/problemset/task/1661/
// 状态：待验证
// 算法：前缀和、频次映射

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];
ll pre[N];

void solve(){
    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    map <ll, ll> mp;
    mp[0] = 1;
    for (int i = 1; i <= n; i ++){
        pre[i] = pre[i - 1] + a[i];
    }

    // 要注意i， j之间的先后关系
    ll cnt = 0;
    for (int i = 1; i <= n; i ++){
        if (mp.find(pre[i] - x) != mp.end()){
            cnt += mp[pre[i] - x];
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
