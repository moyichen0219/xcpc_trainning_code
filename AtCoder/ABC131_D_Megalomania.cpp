// 比赛：AtCoder Beginner Contest 131
// 题目：ABC131 D - Megalomania
// 链接：https://atcoder.jp/contests/abc131/tasks/abc131_d
// 状态：待验证
// 算法：贪心、按截止时间排序

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    ll a, b;
};

const int N = 2e5 + 10;
node task[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> task[i].a >> task[i].b;
    }
    sort(task + 1, task + n + 1, [](const node& x, const node& y){
        if (x.b != y.b){
            return x.b < y.b;
        }
        return x.a < y.a;
    });
    ll t = 0;
    for (int i = 1; i <= n; i ++){
        t += task[i].a;
        if (t > task[i].b){
            cout << "No" << '\n';
            return ;
        }
    }
    cout << "Yes" << '\n';
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
