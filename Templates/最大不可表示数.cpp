// 模板：最大不可表示数（Frobenius 问题）
// 状态：模板
// 前提：所有正整数面值的最大公约数为 1
// 复杂度：O(M · n log M)，其中 M 为最小面值

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 4e18;

// Frobenius 硬币问题（多种面值）
// 前提：所有硬币面值 gcd = 1
// 返回最大无法由这些硬币非负线性组合表示的整数
ll frobenius(vector <int> a){
    int m = *min_element(a.begin(), a.end());

    // dis[r]：能由这些硬币组成，并且 mod m = r 的最小整数
    vector <ll> dis(m ,INF);
    // 组成这个余数的最小数值d，当前余数u
    priority_queue <pair<ll, int>, vector <pair<ll, int>>, greater<pair<ll, int>>> pq;

    dis[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dis[u]){
            continue;
        }

        for (int x : a){
            int v = (u + x) % m;
            if (dis[v] > d + x){
                dis[v] = d + x;
                pq.push({dis[v], v});
            }
        }
    }

    // dis[r] 是余数 r 最小的可表示数
    // 因为 m 本身是硬币，所以之后每隔 m 都能表示
    // 因而该余数最大的不可表示数为 dis[r] - m
    ll ans = -1;
    for (int r = 0; r < m; r ++){
        ans = max(ans, dis[r] - m);
    }

    return ans;
}

void solve(){

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
