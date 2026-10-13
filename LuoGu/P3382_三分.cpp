// 比赛/平台：洛谷
// 题目：P3382 三分
// 链接：https://www.luogu.com.cn/problem/P3382
// 状态：已通过
// 算法：三分搜索、Horner 法求值

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 15;
vector <double> p;
int n;

double f(double x){
    double ans = p[0];

    for (int i = 1; i <= n; i ++){
        ans = ans * x + p[i];
    }

    return ans;
}

void solve(){
    double l, r;
    cin >> n >> l >> r;

    p.resize(n + 1);
    for (int i = 0; i <= n; i ++){
        cin >> p[i];
    }

    for (int i = 1; i <= 100; i ++){
        double k = (r - l) / 3.0;
        double mid1 = l + k;
        double mid2 = r - k;

        if (f(mid1) > f(mid2)){
            r = mid2;
        } else {
            l = mid1;
        }
    }

    cout << fixed << setprecision(12) << l << '\n';
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
