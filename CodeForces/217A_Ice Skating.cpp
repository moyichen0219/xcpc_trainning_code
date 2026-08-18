// 比赛：Codeforces Round 134 (Div. 1)
// 题目：217A - Ice Skating
// 链接：https://codeforces.com/problemset/problem/217/A
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

int root(int x){
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
    int n;
    cin >> n;
    vector <int> x(n + 1);
    vector <int> y(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> x[i] >> y[i];
    }
    int cnt = n;
    for (int i = 1; i <= n; i ++){
        for (int j = i + 1; j <= n; j ++){
            if (x[i] == x[j] || y[i] == y[j]){
                if (root(i) != root(j)){
                    merge(i, j);
                    cnt --;
                }
            }
        }
    }
    cout << cnt - 1 << '\n';
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
