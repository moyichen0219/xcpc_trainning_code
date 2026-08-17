// 比赛：AtCoder Beginner Contest 258
// 题目：ABC258 C - Rotation
// 链接：https://atcoder.jp/contests/abc258/tasks/abc258_c
// 状态：已通过
// 算法：字符串、循环偏移

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int base = 0;
    while (q --){
        int op, x;
        cin >> op >> x;
        if (op == 1){
            base = (base - x + n) % n;
        } else if (op == 2){
            cout << s[(base + x - 1) % n] << '\n';
        }
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
