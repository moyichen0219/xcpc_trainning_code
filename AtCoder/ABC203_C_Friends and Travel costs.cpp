// 比赛：AtCoder Beginner Contest 203
// 题目：ABC203 C - Friends and Travel costs
// 链接：https://atcoder.jp/contests/abc203/tasks/abc203_c
// 状态：待验证
// 算法：排序、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    ll a, b;
};

const int N = 2e5 + 10;
node f[N];

void solve(){
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> f[i].a >> f[i].b;
    }
    sort(f + 1, f + n + 1, [](const node& x, const node& y){
        if (x.a != y.a){
            return x.a < y.a;
        }
        return x.b > y.b;
    });
    ll ans = k;
    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        if (ans >= f[i].a){
            ans += f[i].b;
        } else {
            break;
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
