// 比赛：竞极比赛 2094600238127988737
// 题目：F - The Contest
// 链接：http://47.120.23.84/contest/2094600238127988737/2094602665216524293
// 状态：待验证
// 算法：最长不下降子序列、最少修改

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];
int stk[N];

void solve(){
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    int n = k1 + k2 + k3;
    for (int i = 1; i <= k1; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + k1 + 1);
    for (int i = k1 + 1; i <= k1 + k2; i ++){
        cin >> a[i];
    }
    sort(a + 1 + k1, a + 1 + k1 + k2);
    for (int i = k1 + k2 + 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a + 1 + k1 + k2, a + 1 + n);

    int top = 0;
    for (int i = 1; i <= n; i ++){
        int pos = lower_bound(stk + 1, stk + top + 1, a[i]) - stk;
        if (pos > top){
            top ++;
        }
        stk[pos] = a[i];
    }

    cout << n - top << '\n';
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
