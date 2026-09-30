// 比赛：The 2026 ICPC Guizhou Provincial Contest
// 题目：C - Aquarium Feeding
// 链接：https://qoj.ac/contest/4121/problem/20286
// 状态：待验证
// 算法：周期往返、必要充分条件、线性扫描

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N], t[N];

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++){
        cin >> t[i];
    }

    for (int i = 1; i <= n; i ++){
        ll cur = 2ll * max(a[i] - a[1], a[n] - a[i]);

        if (cur > t[i]){
            cout << "No" << '\n';
            return ;
        }
    }

    cout << "Yes" << '\n';
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
