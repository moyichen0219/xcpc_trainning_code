// 比赛：AtCoder Beginner Contest 229
// 题目：ABC229 C - Cheese
// 链接：https://atcoder.jp/contests/abc229/tasks/abc229_c
// 状态：已通过
// 算法：贪心、排序

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    int a, b;
};

const int N = 3e5 + 10;
node c[N];

void solve(){
    ll n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i ++){
        cin >> c[i].a >> c[i].b;
    }
    sort(c + 1, c + n + 1, [](const node& x, const node& y){
        if (x.a != y.a){
            return x.a > y.a;
        }
        return x.b > y.b;
    });
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        if (c[i].b >= w){
            ans += 1LL * c[i].a * w;
            break;
        } else {
            w -= c[i].b;
            ans += 1LL * c[i].a * c[i].b;
        }
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
