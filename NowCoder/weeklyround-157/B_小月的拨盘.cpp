// 比赛：牛客周赛 Round 157
// 题目：B - 小月的拨盘
// 链接：https://ac.nowcoder.com/acm/contest/139206/B
// 状态：已通过
// 算法：模拟、循环计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    int cur = d;
    int cnt = 0;
    for (int i = 0; i < n; i ++){
        if (s[i] == '+'){
            cur ++;
            if (cur == 10){
                cur = 0;
            }
        } else if (s[i] == '-'){
            cur --;
            if (cur == -1){
                cur = 9;
            }
        }
        if (cur == d){
            cnt ++;
        }
    }
    cout << cur << ' ' << cnt << '\n';
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
