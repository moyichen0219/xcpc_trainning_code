// 比赛/平台：CCPC2026 网络热身赛第二场（CCPCOJ）
// 题目：A - 潮汐灯带
// 链接：https://cpc.csgrandeur.cn/csgoj/problemset/problem?pid=1583
// 状态：待验证
// 算法：环形数组、滑动窗口

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll a[2 * N];

/* void solve(){
    int n, k;
    cin >> n >> k;

    for (int i= 1; i <= n; i ++){
        cin >> a[i];
        a[i + n] = a[i];
    }

    for (int i = 1; i <= 2 * n; i ++){
        pre[i] = pre[i - 1] + a[i];
    }

    int pos = -1;

    ll cur = 0;
    for (int i = k; i <= n + k; i ++){
        if (pre[i] - pre[i - k] > cur){
            pos = i - k + 1;
            cur = pre[i] - pre[i - k];
        }
    }

    cout << cur << '\n';

    if (pos > n){
        cout << pos - n << '\n';
    } else {
        cout << pos << '\n';
    }
} */

void solve(){
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        a[i + n] = a[i];
    }

    ll mx = LLONG_MIN;
    ll st = 0;

    int i = 1;
    int j = 1;
    ll cur = 0;
    while (j <= n + k - 1){
        cur += a[j];

        if (j - i + 1 == k){
            if (cur > mx){
                mx = cur;
                st = i;
            }

            cur -= a[i];
            i ++;
        }


        j ++;
    }

    cout << mx << '\n' << st << '\n';
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
