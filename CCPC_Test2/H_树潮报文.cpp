// 比赛/平台：CCPC2026 网络热身赛第二场（CCPCOJ）
// 题目：H - 树潮报文
// 链接：https://cpc.csgrandeur.cn/csgoj/problemset/problem?pid=1590
// 状态：待验证
// 算法：树上 DFS、路径恢复、路径最小值计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e4 + 10;

vector<int> g[N];
vector<int> path;

bool dfs(int u, int fa, int t){
    path.push_back(u);

    if (u == t){
    return true;
}

    for (auto v : g[u]){
        if (v == fa){
            continue;
        }

        if (dfs(v, u, t)){
            return true;
        }
    }

    path.pop_back();
    return false;
}

void solve(){
    int op;
    cin >> op;

    if (op == 1){
        int n;
        cin >> n;

        vector <int> a(n + 1);
        vector <int> p(n + 1);

        for (int i = 2; i <= n; i ++){
            cin >> p[i];
        }

        for (int i = 1; i <= n; i ++){
            cin >> a[i];
        }

        cout << n << endl;
        for (int i = 2; i <= n; i ++){
            cout << p[i] << ' ';
        }
        cout << endl;
        for (int i = 1; i <= n; i ++){
            cout << a[i] << ' ';
        }
        cout << endl;
    } else if (op == 2){
        int n;
        cin >> n;

        vector <int> a(n + 1);
        vector <int> p(n + 1);

        for (int i = 2; i <= n; i ++){
            cin >> p[i];
        }

        for (int i = 1; i <= n; i ++){
            cin >> a[i];
        }

        for (int i = 2; i <= n; i ++){
            g[i].push_back(p[i]);
            g[p[i]].push_back(i);
        }

        int q;
        cin >> q;

        for (int i = 1; i <= q; i ++){
            int u, v;
            cin >> u >> v;

            path.clear();

            dfs(u, 0, v);

            int mn = INT_MAX;
            int cnt = 0;
            for (auto i : path){
                if (a[i] < mn){
                    mn = a[i];
                    cnt = 1;
                } else if (a[i] == mn){
                    cnt ++;
                }
            }

            cout << mn << ' ' << cnt << endl;
        }
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
