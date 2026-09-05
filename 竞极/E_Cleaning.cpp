// 比赛：竞极比赛 2095727662160490498
// 题目：E - Cleaning（本地语义识别）
// 链接：http://47.120.23.84/contest/2095727662160490498/2095728621846605830
// 状态：未完成
// 算法：树形 DFS、子树配对（根节点选择待修正）

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll a[N];
vector <int> g[N];

bool ok = true;

ll dfs(int u, int fa){
    // 他有几个儿子
    ll cnt = 0;
    // 他儿子的总和是多少？
    ll sum = 0;

    for (auto v : g[u]){
        if (v == fa){
            continue;
        }

        cnt ++;

        sum += dfs(v, u);
    }

    // cnt = 0, 叶子节点
    if (cnt == 0){
        return a[u];
    }

    // 根节点
    if (fa == 0){
        if (sum != a[u]){
            ok = false;
        }
        return 0;
    }

    if (2 * a[u] < sum){
        ok = false;
        return 0;
    }

    return 2 * a[u] - sum;
}

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (n == 1){
        if (a[1] != 0){
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
        return ;
    } else if (n == 2){
        if (a[1] == a[2]){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        return ;
    }

    // 左-父亲-右
    // fa--, v1--, v2--
    // 我一个fa里面的石头，可以消掉两个叶子节点的一个石头
    // 那我总共fa可以消掉2fa个叶子石头
    // 只要满足2fa > sum, 那就能消掉叶子
    int rt = 1;
    for (int i = 1; i <= n; i ++){
        if (g[i].size() == 1){
            rt = i;
            break;
        }
    }
    dfs(rt, 0);

    if (ok){
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int  main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
