// 比赛：洛谷题库
// 题目：P2240 - [深基12.例1] 部分背包问题
// 链接：https://www.luogu.com.cn/problem/P2240
// 状态：已通过
// 算法：贪心、排序
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 110;

struct cion{
    long double m;
    int v;
    long double avg;
    bool operator < (const cion& other){
        return avg > other.avg;
    }
};

cion cions[N];

void solve(){
    int n;
    long double t;
    cin >> n >> t;
    for (int i = 1; i <= n; i ++){
        cin >> cions[i].m >> cions[i].v;
        long double avg = 1.0 * cions[i].v / cions[i].m;
        cions[i].avg = avg;
    }
    long double ans = 0.0;
    sort(cions + 1, cions + n + 1);
    for (int i = 1; i <= n; i ++){
        if (t - cions[i].m > 1e-9){
            t -= cions[i].m;
            ans += cions[i].v;
        } else {
            ans += t * cions[i].avg;
            break;
        }
    }
    cout << fixed << setprecision(2) << ans << '\n';
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
