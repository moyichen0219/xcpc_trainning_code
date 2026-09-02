// 比赛：竞极比赛 2094600238127988737
// 题目：D - Our clients, please wait a moment
// 链接：https://atcoder.jp/contests/abc325/tasks/abc325_e
// 状态：待验证
// 算法：Dijkstra、分层换乘、最短路

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 10;
const ll INF = 4e18;
int x[N][N];

struct Edge{
    int v;
    ll w;
    bool operator < (const Edge & u) const {
        return w > u.w;
    }
};

vector<Edge> g[N];
vector <ll> d1(N);
vector <ll> d2(N);
ll n, a, b, c;

void dijkstra1(int st, vector <ll> &d, vector <Edge> g[]){
    fill (d.begin(), d.end(), INF);
    d[st] = 0;
    bitset <N> vis;
    priority_queue <Edge> pq;
    pq.push({st, d[st]});
    while (pq.size()){
        int x = pq.top().v;
        pq.pop();
        if (vis[x]){
            continue;
        }
        vis[x] = true;
        for (auto &[y, w] : g[x]){
            if (!vis[y] && d[y] > d[x] + a * w){
                d[y] = d[x] + a * w;
                pq.push({y, d[y]});
            }
        }
    }
}

void dijkstra2(int st, vector <ll> &d, vector <Edge> g[]){
    fill (d.begin(), d.end(), INF);
    d[st] = 0;
    bitset <N> vis;
    priority_queue <Edge> pq;
    pq.push({st, d[st]});
    while (pq.size()){
        int x = pq.top().v;
        pq.pop();
        if (vis[x]){
            continue;
        }
        vis[x] = true;
        for (auto &[y, w] : g[x]){
            if (!vis[y] && d[y] > d[x] + b * w + c){
                d[y] = d[x] + b * w + c;
                pq.push({y, d[y]});
            }
        }
    }
}

void solve(){

    cin >> n >> a >> b >> c;

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> x[i][j] ;
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = i + 1; j <= n; j ++){
            ll w = x[i][j];
            g[i].push_back({j, w});
            g[j].push_back({i, w});
        }
    }

    dijkstra1(1, d1, g);
    dijkstra2(n, d2, g);

    ll ans = INF;
    for (int i = 1; i <= n; i ++){
        ans = min(ans, d1[i] + d2[i]);
    }

    if (ans == INF){
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
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
