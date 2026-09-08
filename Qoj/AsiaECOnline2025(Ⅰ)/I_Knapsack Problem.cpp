// 比赛：The 2025 ICPC Asia East Continent Online Contest (I)
// 题目：I - Knapsack Problem
// 链接：https://qoj.ac/contest/2513/problem/14309
// 状态：待验证
// 算法：最短路、字典序状态（松弛顺序待在线结果核对）

/*

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
const ll inf = 4e18;
int pre[N];

int n, m, v, t;

struct edge{
    int v;
    ll w;
    bool operator < (const edge& u) const {
        return w > u.w;
    }
};
vector <edge> g[N];

struct node{
    ll used;
    ll cur;
    int v;
    bool operator < (const node &other) const {
        if (used != other.used){
            return used > other.used;
        }
        if (cur != other.cur){
            return cur > other.cur;
        }
        return v > other.v;
    }
};

void init(){
    for (int i = 1; i < N; i ++){
        pre[i] = i;
    }
}

int root(int x){
    return pre[x] == x ? x : pre[x] = root(pre[x]);
}

void merge(int x, int y){
    int rx = root(x);
    int ry = root(y);

    if (rx == ry){
        return ;
    }

    pre[rx] = ry;
}

// 背包个数，已用背包
pair<ll, ll> dis[N];

void dijstra(int st){
    for (int i = 1; i <= n; i ++){
        dis[i].first = dis[i].second = inf;
    }

    priority_queue <node> pq;
    pq.push({1, 0, st});

    dis[st] = {1, 0};

    while (pq.size()){
        auto [used, cur, x] = pq.top();
        pq.pop();

        if (dis[x] != make_pair(used, cur)){
            continue;
        }

        for (auto [y, w] : g[x]){
            pair <ll, ll> nx;
            if (cur + w > v){
                nx.first = used + 1;
                nx.second = w;
            } else {
                nx.first = used;
                nx.second = cur + w;
            }

            if (nx < dis[y]){
                dis[y] = nx;
                pq.push(node{dis[y].first, dis[y].second, y});
            }

        }
    }
}

void solve(){
    cin >> n >> m >> v >> t;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        merge(u, v);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijstra(t);

    for (int i = 1; i <= n; i ++){
        if (dis[i].first == inf){
            cout << -1 << ' ';
        } else {
            cout << dis[i].first << ' ';
        }
    }
    cout << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    init();
    while (t --){
        solve();
    }
    return 0;
} */

// https://qoj.ac/contest/2513/problem/14309/statement/zh_cn

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
const ll inf = 4e18;
int pre[N];

int n, m, v, t;

struct edge{
    int v;
    ll w;
    bool operator < (const edge& u) const {
        return w > u.w;
    }
};
vector <edge> g[N];

struct node{
    ll cur;
    ll used;
    bool operator < (const node &other) const {
        if (used != other.used){
            return used < other.used;
        }
        return cur < other.cur;
    }
};
vector <node> bag(N, {inf, inf});

void init(){
    for (int i = 1; i < N; i ++){
        pre[i] = i;
    }
}

int root(int x){
    return pre[x] == x ? x : pre[x] = root(pre[x]);
}

void merge(int x, int y){
    int rx = root(x);
    int ry = root(y);

    if (rx == ry){
        return ;
    }

    pre[rx] = ry;
}

ll d[N];

void dijstra(int st){
    fill (d, d + n + 1, inf);
    bitset<N> vis;
    d[st] = 0;
    priority_queue <edge> pq;
    bag[st] = {0, 1};
    pq.push({st, d[st]});
    while (pq.size()){
        int x = pq.top().v;
        pq.pop();

        for (auto [y, w] : g[x]){
            node nx;
            d[y] = d[x] + w;
            if (bag[x].cur + w > v){
                nx.cur = w;
                nx.used = bag[x].used + 1;
            } else {
                nx.cur = bag[x].cur + w;
                nx.used = bag[x].used;
            }
            if (nx < bag[y]){
                bag[y] = nx;
                pq.push({y, d[y]});
            }
        }
    }
}

void solve(){
    cin >> n >> m >> v >> t;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        merge(u, v);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijstra(t);

    for (int i = 1; i <= n; i ++){
        if (root(i) != root(t)){
            cout << -1 << ' ';
        } else {
            cout << bag[i].used << ' ';
        }
    }
    cout << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    init();
    while (t --){
        solve();
    }
    return 0;
}
