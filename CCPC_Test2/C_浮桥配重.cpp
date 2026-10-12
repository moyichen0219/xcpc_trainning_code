// 比赛/平台：CCPC2026 网络热身赛第二场（CCPCOJ）
// 题目：C - 浮桥配重
// 链接：https://cpc.csgrandeur.cn/csgoj/problemset/problem?pid=1585
// 状态：待验证
// 算法：贪心、优先队列、前缀可行性

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];
int b[N];
bool vis[N];

void solve(){
    int n;
    cin >> n;

    ll suma = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        suma += a[i];
    }

    ll sumb = 0;
    for (int i = 1; i <= n; i ++){
        cin >> b[i];
        sumb += b[i];
    }

    if (suma + sumb < 0){
        cout << -1 << '\n';
        return ;
    }

    priority_queue <int> pq;

    ll cur = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        cur += a[i];
        pq.push(b[i]);

        while (cur < 0 && pq.size()){
            cur += pq.top();
            pq.pop();
            cnt ++;
        }

        if (cur < 0){
            cout << -1 << '\n';
            return ;
        }
    }

    cout << cnt << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
