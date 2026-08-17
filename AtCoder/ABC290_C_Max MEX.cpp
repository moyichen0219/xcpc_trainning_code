// 比赛：AtCoder Beginner Contest 290
// 题目：ABC290 C - Max MEX
// 链接：https://atcoder.jp/contests/abc290/tasks/abc290_c
// 状态：已通过
// 算法：排序、MEX

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        if (a[i] == ans){
            ans ++;
            cnt ++;
        }
        if (cnt == k){
            break;
        }
    }
    cout << ans << '\n';
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
