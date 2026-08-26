// 比赛：洛谷题库
// 题目：P5536 【XR-3】核心城市
// 链接：https://www.luogu.com.cn/problem/P5536
// 状态：未完成
// 算法：树的直径、树形 DP（未完成）

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
vector <int> g[N];

ll dis[N];
int further;
ll ans;

void dfs(int u, int fa){
    if (dis[u] > dis[further]){
        further = u;
    }
    for (auto v : g[u]){
        if (v == fa){
            continue;
        }
        dis[v] = dis[u] + 1;
        dfs(v, u);
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int st = 1;
    dis[st] = 0;
    dfs(st, 0);

    st = further;
    dis[st] = 0;
    dfs(st, 0);

    int d = dis[further];
    if (k < d + 1){
        cout << ceil ((d - k + 1) / 2) << '\n';
    } else {
        k -= d + 1;
        // 记录par，将直径都vis掉
        // 然后用dp找支链的长度，然后贪心选取核心城市
        cout << d / 2 - k << '\n';
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
