// 比赛：CSES Range Queries
// 题目：1646 - Static Range Sum Queries
// 链接：https://cses.fi/problemset/task/1646/
// 状态：待验证
// 算法：前缀和、区间查询

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll a[N], pre[N];

void solve(){
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++){
        pre[i] = pre[i - 1] + a[i];
    }

    while (q --){
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
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
