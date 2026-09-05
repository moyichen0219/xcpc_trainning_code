// 比赛：The 2025 ICPC Asia East Continent Online Contest (I)
// 题目：C - Canvas Painting
// 链接：https://qoj.ac/contest/2513/problem/14303
// 状态：未完成
// 算法：区间去重（尚未实现区间操作的连通合并）

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int pre[N];

void init(){
    for (int i = 1; i < N; i ++){
        pre[i] = i;
    }
}

int  root(int  x){
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

void solve(){
    int m, n;
    cin >> m >> n;
    set <pair<int, int>> s;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        if (u == v){
            continue;
        }
        if (!s.count(make_pair(u, v))){
            s.insert(make_pair(u, v));
        }
    }
    int ans = n - s.size();
    cout << max(1, ans) << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t --){
        init();
        solve();
    }
    return 0;
}
