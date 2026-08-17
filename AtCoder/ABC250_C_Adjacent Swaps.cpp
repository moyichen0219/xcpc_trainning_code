// 比赛：AtCoder Beginner Contest 250
// 题目：ABC250 C - Adjacent Swaps
// 链接：https://atcoder.jp/contests/abc250/tasks/abc250_c
// 状态：已通过
// 算法：模拟、位置数组

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, q;
    cin >> n >> q;
    vector <int> a(n + 1);
    vector <int> pos(n + 1);
    for (int i = 1; i <= n; i ++){
        a[i] = i;
        pos[i] = i;
    }
    while (q --){
        int x;
        cin >> x;
        int p = pos[x];
        int nxt = 0;
        if (p != n){
            nxt = p + 1;
        } else {
            nxt = p - 1;
        }
        swap(a[p], a[nxt]);
        pos[a[p]] = p;
        pos[a[nxt]] = nxt;
    }
    for (int i = 1; i <= n; i ++){
        cout << a[i] << ' ';
    }
    cout << '\n';
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
