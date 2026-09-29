// 比赛：CSES Sorting and Searching
// 题目：1630 - Tasks and Deadlines
// 链接：https://cses.fi/problemset/task/1630/
// 状态：待验证
// 算法：贪心、排序、最短作业优先

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    int a;
    int d;
    bool operator < (const node& other) const {
        if (a != other.a){
            return a < other.a;
        }
        return d > other.d;
    }
};

const int N = 2e5 + 10;
node x[N];

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> x[i].a >> x[i].d;
    }

    sort(x + 1, x + n + 1);

    ll cur = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i ++){

        cur += x[i].a;
        ans += x[i].d - cur;
    }

    cout << ans << '\n';
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
