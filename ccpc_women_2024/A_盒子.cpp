// 比赛：2024 年 CCPC 女生专场
// 题目：A - 盒子
// 链接：https://qoj.ac/contest/1841/problem/9739
// 状态：已通过
// 算法：坐标范围、模拟

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int z0, h, u0, v0, u1, v1;
    cin >> z0 >> h >> u0 >> v0 >> u1 >> v1;
    int q;
    cin >> q;
    while (q --){
        int x, y, z;
        cin >> x >> y >> z;
        if (z >= z0 && z <= z0 + h
         && x >= min(u1, u0) && x <= max(u0, u1)
         && y >= min(v1, v0) && y <= max(v1, v0)){
            cout << "YES" << '\n';
         } else {
            cout << "NO" << '\n';
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
