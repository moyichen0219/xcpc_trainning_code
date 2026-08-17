// 比赛：AtCoder Beginner Contest 313
// 题目：ABC313 C - Approximate Equalization 2
// 链接：https://atcoder.jp/contests/abc313/tasks/abc313_c
// 状态：已通过
// 算法：排序、数学

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        sum += a[i];
    }
    if (n == 1){
        cout << 0 << '\n';
        return ;
    }
    ll avg = sum / n;
    ll cnt = sum % n;
    sort(a.begin() + 1, a.begin() + n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        ll tar = 0;
        if (i > n - cnt){
            tar = avg + 1;
        } else {
            tar = avg;
        }
        ans += abs(a[i] - tar);
    }
    cout << ans / 2 << '\n';
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
