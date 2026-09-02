// 比赛：竞极比赛 2094600238127988737
// 题目：B - Watering the Fields S
// 链接：http://47.120.23.84/contest/2094600238127988737/2094602665216524291
// 状态：待验证
// 算法：Kruskal、最小生成树、距离阈值

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e3 + 10;

struct node{
    int x, y;
    bool operator < (const node &other)const {
        if (x != other.x){
            return x < other.x;
        }
        return y < other.y;
    }
};

struct Edge{
    ll u, v, w;
    bool operator < (const Edge& i) const{
        return w == i.w ? (u == i.u ? v < i.v : u < i.u) : w < i.w;
    }
};

int pre[N];
node dot[N];
vector <Edge> edge;

int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

void merge(int x, int y){
    int rx = root(x);
    int ry = root(y);
    if (rx != ry){
        pre[rx] = ry;
    }
}

void solve(){
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i ++){
        cin >> dot[i].x >> dot[i].y;
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            if (i != j){
                ll w = abs(dot[i].x - dot[j].x) * abs(dot[i].x - dot[j].x) + abs(dot[i].y - dot[j].y) * abs(dot[i].y - dot[j].y);
                edge.push_back({i, j, w});
            }
        }
    }
    sort(begin(edge), end(edge));
    for (int i = 1; i <= n; i ++){
        pre[i] = i;
    }
    ll ans = 0;
    for(auto [u, v, w] : edge){
        if (root(u) == root(v)){
            continue;
        } else {
            if (w >= c){
                ans += w;
                merge(u, v);
            }
        }
    }
    for (int i = 1; i < n; i ++){
        if (root(i) != root(i + 1)){
            ans = -1;
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
