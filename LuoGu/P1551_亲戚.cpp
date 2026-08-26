// 比赛：洛谷题库
// 题目：P1551 亲戚
// 链接：https://www.luogu.com.cn/problem/P1551
// 状态：已通过
// 算法：并查集、连通性查询

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e3 + 10;
int pre[N];

void init (){
    for (int i = 1; i < N; i ++){
        pre[i] = i;
    }
}

int root(int x){
    return pre[x] == x ? x : pre[x] = root(pre[x]);
}

void merge(int x, int y){
    int rtx = root(x);
    int rty = root(y);
    if(rtx != rty){
        pre[rtx] = rty;
    }
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    while (q --){
        int x, y;
        cin >> x >> y;
        if (root(x) == root(y)){
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
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
