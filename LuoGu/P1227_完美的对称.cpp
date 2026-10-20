// 比赛/平台：洛谷
// 题目：P1227 [JSOI2008] 完美的对称
// 链接：https://www.luogu.com.cn/problem/P1227
// 状态：已通过
// 算法：几何中心、中心对称、频次映射

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    double x, y;
    bool operator <(const node& other) const {
        if (x != other.x){
            return x < other.x;
        }
        return y < other.y;
    }
};

const int N = 2e5 + 10;
node a[N];

void solve(){
    int n;
    cin >> n;

    double sumx = 0.0;
    double sumy = 0.0;

    map <pair <double, double>, int> mp;

    for (int i = 1; i <= n; i ++){
        cin >> a[i].x >> a[i].y ;

        mp[{a[i].x, a[i].y}] ++;

        sumx += a[i].x;
        sumy += a[i].y;
    }

    double xx = sumx / (1.0 * n);
    double yy = sumy / (1.0 * n);

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i ++){
        double x = 2.0 * xx - a[i].x;
        double y = 2.0 * yy - a[i].y;

        if (mp[{x, y}] != mp[{a[i].x, a[i].y}]){
            cout << "This is a dangerous situation!" << '\n';
            return ;
        }
    }

    cout << fixed << setprecision(1) << "V.I.P. should stay at (" << xx << ',' << yy << ")." << '\n';
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
