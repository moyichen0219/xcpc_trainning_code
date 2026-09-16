// 比赛：洛谷
// 题目：P2648 - 赚钱
// 链接：https://www.luogu.com.cn/problem/P2648
// 状态：已通过
// 算法：Floyd、最大收益路径、正环检测

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 310;
const ll inf = 4e18;
ll g[N][N];

void solve(){
    ll d, p, c,f;
    cin >> d >> p >> c >> f;

    for (int i = 1; i <= c; i ++){
        for (int j = 1; j <= c; j++){
            g[i][j] = (i == j ? 0 : -inf);
        }
    }

    for (int i = 1; i <= p; i ++){
        int u, v;
        cin >> u >> v;
        g[u][v] = max(g[u][v], d);
    }

    for (int i = 1; i <= f; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = max(g[u][v], d - w);
    }

    for (int k = 1; k <= c; k ++){
        for (int i = 1; i <= c; i ++){
            for (int j = 1; j <= c; j ++){
                if (g[i][k] != -inf && g[k][j] != -inf){
                    g[i][j] = max(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= c; i ++){
        if (g[i][i] > 0){
            cout << "orz" << '\n';
            return ;
        }
    }

    ll ans = d;
    for (int i = 1; i <= c; i ++){
        for (int j = 1; j <= c; j ++){
            ans = max(ans, d + g[i][j]);
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
