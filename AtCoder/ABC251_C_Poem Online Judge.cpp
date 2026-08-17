// 比赛：AtCoder Beginner Contest 251
// 题目：ABC251 C - Poem Online Judge
// 链接：https://atcoder.jp/contests/abc251/tasks/abc251_c
// 状态：已通过
// 算法：集合、枚举

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    set <string> s;
    int mx = 0;
    int pos = -1;
    for (int i = 1; i <= n; i ++){
        string ss;
        int x;
        cin >> ss >> x;
        if (s.find(ss) == s.end()){
            s.insert(ss);
            if (x > mx){
                mx = x;
                pos = i;
            }
        }
    }
    cout << pos << '\n';
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
