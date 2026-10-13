// 比赛/平台：洛谷
// 题目：P10505 Dropping Test
// 链接：https://www.luogu.com.cn/problem/P10505
// 状态：已通过
// 算法：01 分数规划、二分答案、贪心排序

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(double mid,vector <int> a, vector <int> b, int n, int k){
    vector <double> c(n + 1);

    for (int i = 1; i <= n; i ++){
        c[i] = 100.0 * a[i] - mid * b[i];
    }

    sort(c.begin() + 1, c.end());

    double score = 0.0;
    for (int i = n; i >= k + 1; i --){
        score += c[i];
    }

    return score >= 0;
}

void solve(){
    int n, k;
    while (cin >> n >> k){
        if (n == 0 && k == 0){
            break;
        }

        vector <int> a(n + 1);
        vector <int> b(n + 1);

        for (int i = 1; i <= n; i ++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i ++){
            cin >> b[i];
        }

        double l = 0;
        double r = 100;

        for (int i = 1; i <= 100; i ++){
            double mid = (l + r) / 2.0;
            if (check(mid, a, b, n, k)){
                l = mid;
            } else {
                r = mid;
            }
        }

        cout << fixed << setprecision(0) << l << endl;
    }
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
