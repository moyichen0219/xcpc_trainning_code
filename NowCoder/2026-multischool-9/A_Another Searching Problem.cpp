// 比赛：2026 牛客暑期多校训练营 9
// 题目：A - Another Searching Problem
// 链接：https://ac.nowcoder.com/acm/contest/133884/A
// 状态：未完成
// 算法：图构造、计数（草稿）

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 200;
vector <int> g[N];

ll a(ll n){
    queue <int> q;
    q.push(1);
    vector <int> id(n + 1, n + 1);
    ll cnt = 0;
    ll t = 0;
    while (q.size()){
        int u = q.front();
        q.pop();
        if (id[u] == n + 1){
            t ++;
            id[u] = t;
        }
        for (auto v : g[u]){
            cnt ++;
            if (id[v] > id[u]){
                q.push(v);
            }
        }
    }
    return cnt;
}

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            if (i != j){
                g[i].push_back(j);
            }
            if (i == 1 && j == 2){
                continue;
            }
        }
    }
    cout << a((ll)n) << '\n';
}

void solve_(){
    ll k;
    cin >> k;
    // 上界 (n - 1) * (2 ^ (n - 1))
    // k % 2 == 1没有答案
    // 单设一条长链，可以得到(d - 2) * 2 + 2个cnt
    if (k % 2 == 1){
        cout << -1 << '\n';
        return ;
    } else if (k == 2){
        cout << "2 1" << '\n';
        cout << "1 2" << '\n';
        return ;
    }
    if (k % 2 == 0 && k <= 398){
        // d <= 200
        int d = (k - 2) / 2 + 2;
        cout << d << ' ' << d - 1 << '\n';
        for (int i = 1; i < d; i ++){
            cout << i << ' ' << i + 1 << '\n';
        }
    } else {
        // m <= 300
        // 多一个三元环，那么比链状的k + 4
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t --){
        solve();
    }
    return 0;
}
