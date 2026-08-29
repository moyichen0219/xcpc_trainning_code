// 比赛：AtCoder Beginner Contest 274
// 题目：D - Robot Arms 2
// 链接：https://atcoder.jp/contests/abc274/tasks/abc274_d
// 状态：已通过
// 算法：动态规划、二维可达性拆分

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 10000;

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    vector <bool> dpx(20010, false);
    vector <bool> dpy(20010, false);

    dpx[a[1] + M] = true;
    dpy[0 + M] = true;

    for (int i = 3; i <= n; i += 2){
        vector <bool> ndp(20010, false);
        for (int j = -M; j <= M; j ++){
            if (!dpx[j + M]){
                continue;
            }
            if (j + a[i]  <= M){
                ndp[j + a[i] + M] = true;
            }
            if (j - a[i]  >= -M){
                ndp[j - a[i] + M] = true;
            }
        }
        dpx = ndp;
    }
    for (int i = 2; i <= n; i += 2){
        vector <bool> ndp(20010, false);
        for (int j = -M; j <= M; j ++){
            if (!dpy[j + M]){
                continue;
            }
            if (j + a[i]  <= M){
                ndp[j + a[i] + M] = true;
            }
            if (j - a[i]  >= -M){
                ndp[j - a[i] + M] = true;
            }
        }
        dpy = ndp;
    }
    if (dpx[M + x] && dpy[M + y]){
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
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
