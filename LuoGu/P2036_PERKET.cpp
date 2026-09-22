// 比赛：COCI 2008/2009 Contest 2
// 题目：P2036 - PERKET
// 链接：https://www.luogu.com.cn/problem/P2036
// 状态：已通过
// 算法：子集枚举、暴力搜索

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    ll s;
    ll b;
};

const int N = 11;
node a[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].s >> a[i].b;
    }

    ll ans = 1e9 + 10;
    for (int i = 1; i <= (1 << n) - 1; i ++){
        ll cur_s = 1;
        ll cur_b = 0;
        for (int j = 0; j < n; j ++){
            if ((i >> j) & 1){
                cur_s *= 1LL * a[j + 1].s;
                cur_b += a[j + 1].b;
            }
        }
        ll res = abs(cur_b - cur_s);
        ans = min(ans, res);
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
