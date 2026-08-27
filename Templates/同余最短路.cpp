// 模板：同余最短路
// 状态：模板
// 例题：洛谷 P2371、P2662、P3403
// 复杂度：O(M · n log M)，其中 M 为所选模数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 2e18;

int mn;             // 模数，一般取最小的增量
vector <int> a;     // 每次可以增加的数
vector <ll> dis;    // dis[r]：余数为 r 的最小可达值

// 可达值为：start + c1 * a[0] + c2 * a[1] + ...，其中 ci >= 0
// 要求 a 中的数均为正整数
void dijkstra(ll start = 0){
    mn = *min_element(a.begin(), a.end());

    dis.assign(mn, INF);
    priority_queue <pair<ll, int>, vector <pair<ll, int>>, greater<pair<ll, int>>> pq;

    dis[start % mn] = start;
    pq.push({start, start % mn});

    while (pq.size()){
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dis[u]){
            continue;
        }

        for (auto x : a){
            int v = (u + x) % mn;
            if (dis[v] > d + x){
                dis[v] = d + x;
                pq.push({dis[v], v});
            }
        }
    }
}

// 判断 x 是否可达
bool isReachable(ll x){
    if (x < 0){
        return false;
    }

    return dis[x % mn] <= x;
}

// 统计 [0, x] 中可达整数的数量
ll count_leq(ll x){
    if (x < 0){
        return 0;
    }

    ll ans = 0;
    for (int r = 0; r < mn; r ++){
        if (dis[r] <= x){
            // 从 dis[r] 开始，每隔 mn 都有一个可达值
            ans += (x - dis[r]) / mn + 1;
        }
    }

    return ans;
}

// 统计 [l, r] 中可达整数的数量
ll count_range(ll l, ll r){
    if (l > r){
        return 0;
    }

    return count_leq(r) - count_leq(l - 1);
}

// 求最大的不可达非负整数
// 前提：a 中所有数的 gcd = 1，否则不存在最大的不可达数
ll max_unreachable(){
    ll ans = -1;
    for (int r = 0; r < mn; r ++){
        // dis[r] 是余数 r 的最小可达值
        // 因此这个余数中最大的不可达值是 dis[r] - mn
        ans = max(ans, dis[r] - mn);
    }

    return ans;
}

void solve(){
    // 用法一：统计 [l, r] 中可达数的数量（P2371）
    // a = {...};
    // dijkstra();
    // cout << count_range(l, r) << '\n';

    // 用法二：求最大不可达数（P2662）
    // a = {...};
    // dijkstra();
    // cout << max_unreachable() << '\n';

    // 用法三：从 1 开始，统计不超过 h 的可达数（P3403）
    // a = {x, y, z};
    // dijkstra(1);
    // cout << count_leq(h) << '\n';
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
