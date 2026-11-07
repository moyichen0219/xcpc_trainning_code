// 比赛/平台：2026 CCPC 女生专场
// 题目：E - 可带负权的背包问题
// 链接：https://qoj.ac/contest/4613/problem/23635/statement/zh_cn
// 状态：待验证
// 算法：贪心构造、超递增序列、符号背包

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 55;
ll a[N];
ll pre[N];

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    int q;
    cin >> q;

    while (q --){
        ll v;
        cin >> v;

        if (v > pre[n]){
            cout << "NO" << '\n';
            continue;
        }

        vector <int> ans(n + 1, 0);

        for (int i = n; i >= 1; i --){
            if (v > pre[i - 1]){
                v -= a[i];
                ans[i] = 1;
            } else if (v < -1 * pre[i - 1]) {
                v += a[i];
                ans[i] = -1;
            }
        }

        if (v != 0){
            cout << "NO" << '\n';
            continue;
        }

        cout << "YES" << '\n';
        for (int i = 1; i <= n; i ++){
            cout << ans[i] << ' ';
        }
        cout << "\n";
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
