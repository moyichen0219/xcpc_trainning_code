// 比赛/平台：Codeforces
// 题目：1515C Phoenix and Towers
// 链接：https://codeforces.com/problemset/problem/1515/C
// 状态：已通过
// 算法：贪心、优先队列、构造

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int h[N];
int ans[N];

void solve(){
    int n, m ,x;
    cin >> n >> m >> x;

    priority_queue <pair<ll, int>, vector <pair<ll, int>>, greater<pair<ll, int>>> pq;

    for (int i = 1; i <= n; i ++){
        cin >> h[i];
    }

    for (int i = 1; i <= m; i ++){
        pq.push({0, i});
    }

    ll cur = 0;
    for (int i = 1; i <= n; i ++){
        auto [H, id] = pq.top();
        pq.pop();

        H += h[i];
        ans[i] = id;
        cur = max(H, cur);

        pq.push({H, id});

        auto [HH, idd] = pq.top();
        if (abs(cur - HH) > x){
            cout << "NO" << '\n';
            return ;
        }
    }

    cout << "YES" << '\n';
    for (int i = 1; i <= n; i ++){
        cout << ans[i] << ' ';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t --){
        solve();
        cout << '\n';
    }
    return 0;
}
