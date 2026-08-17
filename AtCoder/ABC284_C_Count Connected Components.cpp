// 比赛：AtCoder Beginner Contest 284
// 题目：ABC284 C - Count Connected Components
// 链接：https://atcoder.jp/contests/abc284/tasks/abc284_c
// 状态：已通过
// 算法：并查集、连通块

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 110;
int pre[N];

void init(){
    for (int i = 1; i < N; i ++){
        pre[i] = i;
    }
}

int root (int x){
    return pre[x] == x ? x : pre[x] = root(pre[x]);
}

void merge(int x, int y){
    int rtx = root(x);
    int rty = root(y);
    if (rtx != rty){
        pre[rtx] = rty;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    set <int> s;
    for (int i = 1; i <= n; i ++){
        s.insert(root(i));
    }
    cout << s.size() << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    init();
    while (t --){
        solve();
    }
    return 0;
}
