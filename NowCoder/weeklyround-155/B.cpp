// 比赛：牛客周赛 Round 155（138240）
// 题目：B - 小月的立方体 - https://ac.nowcoder.com/acm/contest/138240/B
// 状态：已通过（账号评测状态已于 2026-08-08 核对）
// 分类：三维枚举、空间对角线
// 创建：MYC，2026/8/2

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int a;
    cin >> a;
    ll ans = 0;
    for (int x = 0; x <= a; x ++){
        for (int y = 0; y <= a; y ++){
            for (int z = 0; z <= a; z ++){
                ll v; cin >> v;
                if (x == y && y == z){
                    ans += v;
                }
                if (x == y && x + z == a){
                    ans += v;
                }
                if (x == z && x + y == a){
                    ans += v;
                }
                if (y == z && x + y == a){
                    ans += v;
                }
            }
        }
    }
    cout << ans << '\n';

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
