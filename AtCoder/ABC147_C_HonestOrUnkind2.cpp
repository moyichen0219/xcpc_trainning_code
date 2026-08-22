// 比赛：AtCoder Beginner Contest 147
// 题目：C - HonestOrUnkind2
// 链接：https://atcoder.jp/contests/abc147/tasks/abc147_c
// 状态：已通过
// 算法：二进制枚举、状态验证

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <pair<int, int>> a[n + 1];
    for (int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        for (int j = 1; j <= x; j ++){
            int p, q;
            cin >> p >> q;
            a[i].push_back({p, q});
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask ++){
        bool ok = true;
        for (int i = 1; i <= n; i ++){
            if (!(mask >> (i - 1) & 1)){
                continue;
            }
            for (auto [p, q] : a[i]){
                if ((mask >> (p - 1) & 1) != q){
                    ok = false;
                    break;
                }
            }
            if (!ok){
                break;
            }
        }
        if (ok){
            ans = max(ans, __builtin_popcount(mask));
        }
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
