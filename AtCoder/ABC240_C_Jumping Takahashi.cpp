// 比赛：AtCoder Beginner Contest 240
// 题目：ABC240 C - Jumping Takahashi
// 链接：https://atcoder.jp/contests/abc240/tasks/abc240_c
// 状态：已通过
// 算法：动态规划、可达性

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 110;
const int M = 10010;
int dp[N][M];

struct node{
    int a, b;
};

node c[N];

void solve(){
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i ++){
        cin >> c[i].a >> c[i].b;
    }
    dp[n][x] = 1;
    for (int i = n; i >= 1; i --){
        for (int j = 0; j <= x; j ++){
            if (!dp[i][j]){
                continue;
            }
            if (j - c[i].a >= 0){
                dp[i - 1][j - c[i].a] = 1;
            }
            if (j - c[i].b >= 0){
                dp[i - 1][j - c[i].b] = 1;
            }
        }
    }
    if (dp[0][0]){
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
