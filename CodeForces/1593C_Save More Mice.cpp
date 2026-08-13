// 比赛：Codeforces Round 748 (Div. 3)
// 题目：1593C - Save More Mice
// 链接：https://codeforces.com/problemset/problem/1593/C
// 状态：已通过
// 算法：排序、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 4e5 + 10;
int a[N];

void solve(){
    int n, k;
    cin >> k >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int cnt = 0;
    int cur = 0;
    for (int i = n; i >= 1; i --){
        if (cur >= a[i]){
            break;
        }
        cur += k - a[i];
        cnt ++;
    }
    cout << cnt << '\n';
}

int  main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t --){
        solve();
    }
    return 0;
}
