// 比赛：牛客周赛 Round 149
// 题目：B - 小红的01串构造
// 链接：https://ac.nowcoder.com/acm/contest/136720/B
// 状态：已通过
// 算法：贪心、构造

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    if (n % 2 == 1){
        cout << -1 << '\n';
    } else {
        for (int i = 1; i <= n / 2; i ++){
            cout << 1 ;
        }
        for (int i = 1; i <= n / 2; i ++){
            cout << 0 ;
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
