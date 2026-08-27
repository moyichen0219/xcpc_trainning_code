// 比赛：洛谷题库
// 题目：P3403 跳楼机
// 链接：https://www.luogu.com.cn/problem/P3403
// 状态：已通过
// 算法：同余最短路、Dijkstra、可达状态计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 2e18;

void solve(){
    ll h;
    int x, y, z;
    cin >> h >> x >> y >> z;
    int mn = min({x, y, z});
    vector <ll> dis(mn, INF);
    priority_queue <pair<ll, int>, vector <pair<ll, int>>, greater<pair<ll, int>>> pq;

    dis[1 % mn] = 1;
    pq.push({1, 1 % mn});
    while (pq.size()){
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dis[u]){
            continue;
        }
        int v = 0;

        v = (u + x) % mn;
        if (dis[v] > d + x && d + x <= h){
            dis[v] = d + x;
            pq.push({dis[v], v});
        }

        v = (u + y) % mn;
        if (dis[v] > d + y && d + y <= h){
            dis[v] = d + y;
            pq.push({dis[v], v});
        }

        v = (u + z) % mn;
        if (dis[v] > d + z && d + z <= h){
            dis[v] = d + z;
            pq.push({dis[v], v});
        }
    }

    ll ans = 0;
    for (int i = 0; i < mn; i ++){
        if (dis[i] <= h){
            // 从 dis[r] 开始，每隔 mn 有一个可达楼层
            // 问 <= h 的一共有多少个
            ans += (h - dis[i]) / mn + 1;
        }
    }
    cout << ans << '\n';
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
