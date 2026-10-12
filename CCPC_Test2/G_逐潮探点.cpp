// 比赛/平台：CCPC2026 网络热身赛第二场（CCPCOJ）
// 题目：G - 逐潮探点
// 链接：https://cpc.csgrandeur.cn/csgoj/problemset/problem?pid=1589
// 状态：待验证
// 算法：交互、逐项二分答案

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> ans;

    for (int k = 1; k <= n; k++) {
        ll l = 0, r = 1e18;

        while (l < r) {
            ll mid = l + (r - l) / 2;

            cout << "? " << mid << endl;

            int cnt;
            if (!(cin >> cnt) || cnt == -1) {
                return ;
            }

            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        ans.push_back(l);
    }

    cout << "!";
    for (auto x : ans) {
        cout << " " << x;
    }
    cout << endl;

    return ;
}


int main (){
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
