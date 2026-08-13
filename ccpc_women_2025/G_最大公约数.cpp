// 比赛：第十一届中国大学生程序设计竞赛女生专场
// 题目：G - 最大公约数
// 链接：https://qoj.ac/contest/2564/problem/14456
// 状态：待验证
// 算法：数论、质数筛、构造

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5 + 10;
bool vis[N];

void solve(){
    int n, k;
    cin >> n >> k;
    set <int> s;
    s.insert(1);
    for (int i = 2; i <= n; i ++){
        if (!vis[i]){
            s.insert(i);
            for (int j = 2 * i; j <= n; j += i){
                vis[j] = true;
            }
        }
    }
    if (s.size() >= k){
        cout << "YES" << '\n';
        int cnt = 0;
        for (int i : s){
            if (cnt < k){
                cout << i << ' ';
                cnt ++;
            }
        }
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
