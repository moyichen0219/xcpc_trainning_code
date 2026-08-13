// 比赛：Codeforces Round 142 (Div. 2)
// 题目：230A - Dragons
// 链接：https://codeforces.com/problemset/problem/230/A
// 状态：已通过
// 算法：排序、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct d{
    int x, y;
};

const int N = 1e3 + 10;
d dar[N];

void solve(){
    ll s, n;
    cin >> s >> n;
    for (int i = 1; i <= n; i ++){
        cin >> dar[i].x >> dar[i].y;
    }
    sort(dar + 1, dar + n + 1, [](const d& A, const d& B){
        if (A.x != B.x){
            return A.x < B.x;
        }
        return A.y > B.y;
    });
    for (int i = 1; i <= n; i ++){
        if (s > dar[i].x){
            s += dar[i].y;
        } else {
            cout << "NO" << '\n';
            return ;
        }
    }
    cout << "YES" << '\n';
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
