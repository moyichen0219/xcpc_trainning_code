// 比赛：NOIP 1999 提高组
// 题目：P1020 导弹拦截
// 链接：https://www.luogu.com.cn/problem/P1020
// 状态：已通过
// 算法：最长不上升子序列、最长上升子序列、二分优化

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 10;
int a[N];
int stk[N];

void solve(){
    int n = 0;
    while (cin >> a[++ n]);
    n --;
    int top = 0;
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        int pos = upper_bound(stk + 1, stk + 1 + top, a[i], greater<int>()) - stk;
        if (pos > top){
            top ++;
        }
        stk[pos] = a[i];
    }
    cout << top << '\n';
    top = 0;
    for (int i = 1; i <= n; i ++){
        int pos = lower_bound(stk + 1, stk + 1 + top, a[i]) - stk;
        if (pos > top){
            top ++;
        }
        stk[pos] = a[i];
    }
    cout << top << '\n';
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
