// 比赛/平台：Educational Codeforces Round 195 (Rated for Div. 2)
// 题目：2276D - Caveman
// 链接：https://codeforces.com/contest/2276/problem/D
// 状态：已通过
// 算法：图论、度数统计、分类讨论

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5 + 10;
vector <int> g[N];

void solve(){
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        g[i].clear();
    }

    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int mx = 0;
    for (int i = 1; i <= n; i ++){
        if (g[i].size() == 0){
            cout << "Brain Melt" << '\n';
            return ;
        }
        mx = max(mx, (int)g[i].size());
    }

    if (mx == n - 1 && m == n - 1){
        cout << 2 << '\n';
    } else {
        cout << "Many" << '\n';
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
