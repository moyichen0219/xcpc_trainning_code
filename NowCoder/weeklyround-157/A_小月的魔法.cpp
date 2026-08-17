// 比赛：牛客周赛 Round 157
// 题目：A - 小月的魔法
// 链接：https://ac.nowcoder.com/acm/contest/139206/A
// 状态：已通过
// 算法：基础运算

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int a, b;
    cin >> a >> b;
    if (a + b == 10){
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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
