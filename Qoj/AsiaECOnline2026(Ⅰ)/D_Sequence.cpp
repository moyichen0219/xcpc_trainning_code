// 比赛：The 2026 ICPC Asia East Continent Online Contest (I)
// 题目：D - Sequence
// 链接：https://qoj.ac/contest/4071/problem/20019
// 状态：待验证
// 算法：贪心、计数、组合计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int p = 998244353;
const int N = 1e5 + 10;

void solve(){
    int n;
    cin >> n;

    // cnt[x] 表示：给定的多重集合中，p_i的出现次数
    vector <int> cnt(N, 0);
    for (int i = 1; i <= n; i ++){
        int x; cin >> x;
        cnt[x] ++;
    }

    // 当前构造中0/1分别的个数
    int c0 = 0;
    int c1 = 0;

    // 现在放一个c1,会构造出一个p_i = c0的，因此cnt[c0] --
    ll ans = 1;
    while (n --){
        if (c0 == c1){
            ans = (ans * 2) % p;
        }
        if (cnt[c0]){
            cnt[c0] --;
            c1 ++;
        } else {
            cnt[c1] --;
            c0 ++;
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
