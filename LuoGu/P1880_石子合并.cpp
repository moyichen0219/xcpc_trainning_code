// 比赛：NOI 1995
// 题目：P1880 石子合并
// 链接：https://www.luogu.com.cn/problem/P1880
// 状态：已通过
// 算法：环形区间动态规划、前缀和

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 110;
int a[N];
int pre[N];
int dpx[N][N];
int dpn[N][N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; i ++){
        pre[i] = pre[i - 1] + a[i];
    }
    for (int len = 2; len <= n; len ++){
        for (int i = 1, j = i + len - 1; j <= 2 * n; i ++, j ++){
            dpn[i][j] = 1e9;
            dpx[i][j] = 0;
            for (int k = i; k < j; k ++){
                dpn[i][j] = min(dpn[i][j], dpn[i][k] + dpn[k + 1][j] + pre[j] - pre[i - 1]);
                dpx[i][j] = max(dpx[i][j], dpx[i][k] + dpx[k + 1][j] + pre[j] - pre[i - 1]);
            }
        }
    }

    int mn = 1e9;
    int mx = 0;
    for (int i = 1; i <= n; i ++){
        mn = min(mn, dpn[i][i + n - 1]);
        mx = max(mx, dpx[i][i + n - 1]);
    }

    cout << mn << '\n' << mx << '\n';
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
