// 平台：洛谷
// 题目：P3367 【模板】并查集
// 链接：https://www.luogu.com.cn/problem/P3367
// 状态：已通过
// 算法：并查集、路径压缩

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int pre[N];

void init (int n){
    for (int i = 1; i <= n; i ++){
        pre[i] = i;
    }
}

int root(int u){
    return pre[u] == u ? u : pre[u] = root(pre[u]);
}

bool isConnect(int u, int v){
    if (root(u) != root(v)){
        return false;
    } else {
        return true;
    }
}

void merge(int u, int v){
    int rtu = root(u);
    int rtv = root(v);
    if (rtu != rtv){
        pre[rtu] = rtv;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    init(n);
    while (m --){
        int op;
        cin >> op;
        int u, v;
        cin >> u >> v;
        if (op == 1){
            merge(u, v);
        } else {
            if (isConnect(u, v)){
                cout << "Y" << '\n';
            } else {
                cout << "N" << '\n';
            }
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
