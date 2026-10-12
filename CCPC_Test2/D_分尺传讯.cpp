// 比赛/平台：CCPC2026 网络热身赛第二场（CCPCOJ）
// 题目：D - 分尺传讯
// 链接：https://cpc.csgrandeur.cn/csgoj/problemset/problem?pid=1586
// 状态：待验证
// 算法：排序、贪心、双阶段协议

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int op;
    cin >> op;

    if (op == 1){
        ll n, l;
        cin >> n >> l;

        vector <ll> a(n + 1);

        for (int i = 1; i <= n; i ++){
            cin >> a[i];
            a[i] /= l;
        }

        sort(a.begin() + 1, a.end(), greater<ll>());

        for (int i = 1; i <= n; i ++){
            cout << a[i] << ' ';
        }
        cout << endl;
    } else if (op == 2){
        ll n , k;
        cin >> n >> k;

        priority_queue <ll> pq;
        int cnt = 0;

        for (int i = 1; i <= n; i ++){
            ll x;
            cin >> x;
            pq.push(x);
        }

        ll cur = 0;
        while (pq.size() && cur < k){
            ll x = pq.top();
            pq.pop();

            cur += x;
            cnt ++;
        }

        if (cur < k){
            cout << -1 << endl;
        } else {
            cout << cnt << endl;
        }
    }
}

int main (){
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
