// 比赛：AtCoder Beginner Contest 350
// 题目：ABC350 C - Sort
// 链接：https://atcoder.jp/contests/abc350/tasks/abc350_c
// 状态：已通过
// 算法：置换、位置数组、构造

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1);
    vector <int> pos(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector <pair<int, int>> ans;
    int res = 0;
    for (int i = 1; i <= n; i ++){
        if (a[i] == i){
            continue;
        } else {
            res ++;
            int p1 = pos[a[i]];
            int p2 = pos[i];
            ans.push_back({p1, p2});
            swap(a[p1], a[p2]);
            pos[a[p1]] = p1;
            pos[a[p2]] = p2;
        }
    }
    cout << res << '\n';
    for (auto [i, j] : ans){
        cout << i << ' ' << j << '\n';
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
