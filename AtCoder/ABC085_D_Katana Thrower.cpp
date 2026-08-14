// 比赛：AtCoder Beginner Contest 085
// 题目：ABC085 D - Katana Thrower
// 链接：https://atcoder.jp/contests/abc085/tasks/abc085_d
// 状态：已通过（账号；本地版本需修正）
// 算法：贪心、排序

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    int a, b;
};

const int N = 1e5 + 10;
node d[N];

void solve(){
    int n, H;
    cin >> n >> H;
    int mx = 0;
    for (int i = 1; i <= n; i ++){
        cin >> d[i].a >> d[i].b;
        mx = max(mx, d[i].a);
    }
    sort(d + 1, d + n + 1, [](const node& x, const node& y){
        if (x.b != y.b){
            return x.b > y.b;
        }
        return x.a > y.a;
    });
    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        if (d[i].b <= mx){
            continue;
        }
        H -= d[i].b;
        cnt ++;
        if (H <= 0){
            break;
        }
    }
    if (H > 0){
        int base = H / mx;
        int rem = H % mx;
        if (rem == 0){
            cnt += base;
        } else {
            cnt += base + 1;
            for (int i = n; i >= 1; i --){
                if (d[i].b < rem){
                    cnt --;
                    rem -= d[i].b;
                } else {
                    break;
                }
            }
        }
    }
    cout << cnt << '\n';
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
