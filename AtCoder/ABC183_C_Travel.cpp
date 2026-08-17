// 比赛：AtCoder Beginner Contest 183
// 题目：ABC183 C - Travel
// 链接：https://atcoder.jp/contests/abc183/tasks/abc183_c
// 状态：待验证
// 算法：全排列、暴力枚举

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, k;
    cin >> n >> k;
    vector <vector<int>> t(n + 1, vector <int>(n + 1));
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            cin >> t[i][j];
        }
    }
    vector <int> p;
    for (int i = 2; i <= n; i ++){
        p.push_back(i);
    }
    sort(p.begin(), p.end());
    int ans = 0;
    do {
        ll sum = 0;
        sum += t[1][p[0]];
        for (int i = 0; i + 1 < p.size(); i ++){
            sum += t[p[i]][p[i + 1]];
        }
        sum += t[p.back()][1];
        if (sum == k){
            ans ++;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t -- ){
        solve();
    }
    return 0;
}
