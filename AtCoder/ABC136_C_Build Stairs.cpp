// 比赛：AtCoder Beginner Contest 136
// 题目：ABC136 C - Build Stairs
// 链接：https://atcoder.jp/contests/abc136/tasks/abc136_c
// 状态：待验证
// 算法：贪心、差分

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1);
    bool ok = true;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        if (a[i] < a[i - 1]){
            ok = false;
        }
    }
    vector <int> d(n + 1);
    for (int i = 1; i < n; i ++){
        d[i] = a[i + 1] - a[i];
    }
    for (int i = 1; i < n; i ++){
        if (d[i] < 0){
            if (d[i] == -1){
                a[i] ++;
                d[i] ++;
                d[i + 1] --;
            } else {
                cout << "No" << '\n';
                return ;
            }
        }
    }
    cout << "Yes" << '\n';
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
