// 比赛：TPOI-2A
// 题目：P17331 - Min Mex
// 链接：https://www.luogu.com.cn/problem/P17331
// 状态：已通过
// 算法：排序、贪心、MEX

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    if (k == 1){
        for (int i = 1; i <= n; i ++){
            if (a[i] == 1){
                cout << -1 << '\n';
                return ;
            }
        }
        cout << 0 << '\n';
        return;
    }

    for (int i = 1; i <= n; i ++){
        if (a[i] == k){
            a[i] --;
            sum ++;
        }
    }

    int cur = 1;
    for (int i = 1; i <= n; i ++){

        if (a[i] == cur){
            cur ++;
        } else if (a[i] > cur){
            sum += (a[i] - cur);
            cur ++;
        }

        if (cur == k){
            break;
        }
    }

    // cout << j << ' ';

    if (cur == k){
        cout << sum << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int  main (){
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
