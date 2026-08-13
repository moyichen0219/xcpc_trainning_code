// 比赛：第十一届中国大学生程序设计竞赛女生专场
// 题目：C - 短视频
// 链接：https://qoj.ac/contest/2564/problem/14452
// 状态：已通过
// 算法：模拟、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, T;
    cin >> n >> T;
    vector <int> t(n + 1);
    vector <int> k(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> t[i] >> k[i];
    }
    ll res = 0;
    for (int i = 1; i <= n; i ++){
        res += min((ll)t[i], max(1LL, T + k[i] + 1 - res));
    }
    cout << res << '\n';
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
