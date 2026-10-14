// 比赛/平台：洛谷
// 题目：P4322 [JSOI2016] 最佳团体
// 链接：https://www.luogu.com.cn/problem/P4322
// 状态：已通过
// 算法：01 分数规划、二分答案、依赖型树上背包

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2510;
const ll INF = 1e18;
int a[N];
int w[N];
int sz[N];
int par[N];
double dp[N][N];

int k, n;

vector <int> g[N];
vector <double> c(N);

void dfs(int u, int fa){
    fill(dp[u], dp[u] + k + 1, -INF);

    if (u != 0){
        dp[u][1] = c[u];
        sz[u] = 1;
    } else {
        dp[u][0] = 0.0;
        sz[u] = 0;
    }

    for (auto v : g[u]){
        if (v == fa){
            continue;
        }

        dfs(v, u);

        vector <double> temp(k + 1, -INF);

        for (int i = 0; i <= min(sz[u], k); i ++){
            if (dp[u][i] <= -INF / 2){
                continue;
            }

            for (int j = 0; j <= min(sz[v], k - i); j ++){
                double val = (j == 0) ? 0 : dp[v][j];

                if (j > 0 && val <= -INF / 2){
                    continue;
                }

                temp[i + j] = max(temp[i + j], dp[u][i] + val);
            }
        }

        for (int i = 0; i <= k; i ++){
            dp[u][i] = temp[i];
        }

        sz[u] += sz[v];
    }
}

bool check(double mid){
    for (int i = 1; i <= n; i ++){
        c[i] = a[i] - mid * w[i];
    }

    dfs(0, -1);

    return dp[0][k] >= 0;
}

void solve(){
    cin >> k >> n;

    for (int i = 1; i <= n; i ++){
        cin >> w[i] >> a[i] >> par[i];
    }

    for (int i = 1; i <= n; i ++){
        g[par[i]].push_back(i);
    }

    double l = 0.0;
    double r = 1e4;

    for (int i = 1; i <= 100; i ++){
        double mid = (l + r) / 2.0;

        if (check(mid)){
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(3) << l << endl;
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
