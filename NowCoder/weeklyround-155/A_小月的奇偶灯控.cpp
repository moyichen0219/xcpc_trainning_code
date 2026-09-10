// 比赛：牛客周赛 Round 155（138240）
// 题目：A - 小月的奇偶灯控
// 链接：https://ac.nowcoder.com/acm/contest/138240/A
// 状态：已通过
// 算法：模拟、奇偶性

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int cnt = 0;
    for (int i = 1; i<= 3; i ++){
        int x;
        cin >> x;
        cnt += x;
    }
    if (cnt % 2 == 1){
        cout << "ON";
    } else {
        cout << "OFF";
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while ( t --){
        solve();
    }
    return 0;
}
