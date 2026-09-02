// 比赛：竞极比赛 2094600238127988737
// 题目：A - Robot Arms 2
// 链接：http://47.120.23.84/contest/2094600238127988737/2094602665216524289
// 状态：待验证
// 算法：动态规划、横纵坐标分解、可达性

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
const int M = 2000;
int a[N];

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    vector <bool> dpx(40010, false);
    vector <bool> dpy(40010, false);

    dpx[a[1] + M] = true;
    dpy[0 + M] = true;

    for (int i = 3; i <= n; i += 2){
        vector <bool> ndp(40010, false);
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
        vector <bool> ndp(40010, false);
        for (int j = -M; j <= M; j ++){
            if (!dpy[j + M]){
                continue;
            }
            if (j + a[i] <= M){
                ndp[j + a[i] + M] = true;
            }
            if (j - a[i] >= -M){
                ndp[j - a[i] + M] = true;
            }
        }
        dpy = ndp;
    }

    if (dpx[x + M] && dpy[y + M]){
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
