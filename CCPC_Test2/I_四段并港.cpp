// 比赛/平台：CCPC2026 网络热身赛第二场（CCPCOJ）
// 题目：I - 四段并港
// 链接：https://cpc.csgrandeur.cn/csgoj/problemset/problem?pid=1591
// 状态：待验证
// 算法：并查集、连通块计数、多阶段通信
// 备注：程序通过命令行参数选择运行角色。

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int pre[N];

void init(int n){
    for (int i = 1; i <= n; i ++){
        pre[i] = i;
    }
}

int root(int x){
    return pre[x] == x ? x : pre[x] = root(pre[x]);
}

bool merge(int x, int y){
    int rtx = root(x);
    int rty = root(y);

    if (rtx != rty){
        pre[rtx] = rty;
        return true;
    }

    return false;
}

void solve(int r){
    int n, m;
    cin >> n >> m;

    init(n);
    int cnt = n;

    vector <pair <int, int>> g;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        g.push_back({u, v});
        if (merge(u, v)){
            cnt --;
        }
    }

    cout << m << endl;
    for (auto [u, v] : g){
        cout << u << ' ' << v << endl;
    }

    if (r == 0){
        for (int i = 1; i <= 3; i ++){
            int x;
            cin >> x;

            for (int j = 1; j <= x; j ++){
                int u, v;
                cin >> u >> v;

                if (merge(u, v)){
                    cnt --;
                }
            }
        }

        cout << cnt << endl;
    } else {
        int ans;
        cin >> ans;

        cout << ans << endl;
    }
}

int main (int argc, char *argv[]){
    int r = atoi(argv[1]);
    int t = 1;
    while (t --){
        solve(r);
    }
    return 0;
}
