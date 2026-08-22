// 比赛：百度之星 2024
// 题目：BD202401 - 补给
// 链接：https://www.matiji.net/exam/brushquestion/1/4498/F16DA07A4D99E21DFFEF46BD18FF68AD?from=1
// 状态：已通过
// 算法：排序、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 10;

struct node {
    ll p, s;
};

node a[N];

void solve(){
    int n, b;
    cin >> n >> b;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].p >> a[i].s;
    }
    sort(a + 1, a + n + 1, [](const node& x, const node& y){
        return x.p + x.s < y.p + y.s;
    });
    int cnt = 0;
    int now = 0;
    while (now <= b){
        if (now + a[cnt + 1].p + a[cnt + 1].s <= b){
            now += a[cnt + 1].p + a[cnt + 1].s;
            cnt ++;
        } else if (now + a[cnt + 1].p + a[cnt + 1].s > b){
            now += (a[cnt + 1].p / 2) + a[cnt + 1].s;
            if (now > b){
                break;
            } else if (now == b){
                cnt ++;
                break;
            } else {
                cnt ++;
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
    while(t --){
        solve();
    }
    return 0;
}
