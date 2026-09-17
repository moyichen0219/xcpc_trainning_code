// 比赛：洛谷
// 题目：P1223 - 排队接水
// 链接：https://www.luogu.com.cn/problem/P1223
// 状态：已通过
// 算法：贪心、排序、最短作业优先

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    int t;
    int id;
};

const int N = 1010;
node a[N];

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> a[i].t;
        a[i].id = i;
    }

    sort (a + 1, a + n + 1, [](const node& x, const node& y){
        if (x.t != y.t){
            return x.t < y.t;
        }
        return x.id < y.id;
    });

    ll ans = 0;
    ll pre = 0;
    for (int i = 1; i <= n; i ++){
        ans += pre;
        pre += a[i].t;
    }

    for (int i = 1; i <= n; i ++){
        cout << a[i].id << ' ';
    }
    cout << '\n';

    cout << fixed << setprecision(2) << (double) ans / (1.0 * n) << '\n';
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
