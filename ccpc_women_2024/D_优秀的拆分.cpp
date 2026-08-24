// 比赛：2024 年 CCPC 女生专场
// 题目：D - 优秀的拆分
// 链接：https://qoj.ac/contest/1841/problem/9742
// 状态：未通过
// 算法：模拟退火、随机化搜索

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;

int n;
int a[N];
ll ans = 0;

ll g(vector <int> &b){
    vector <int> x;
    vector <int> y;
    for (int i = 0; i < n; i ++){
        if (b[i] & 1){
            x.push_back(a[i]);
        } else {
            y.push_back(a[i]);
        }
    }
    int mxx = x.empty() ? 0 : 1;
    int mxy = y.empty() ? 0 : 1;
    int curx = mxx;
    int cury = mxy;
    for (int i = 1; i < (int)x.size(); i ++){
        if (x[i] > x[i - 1]) curx ++;
        else curx = 1;
        mxx = max(mxx, curx);
    }
    for (int i = 1; i < (int)y.size(); i ++){
        if (y[i] < y[i - 1]) cury ++;
        else cury = 1;
        mxy = max(mxy, cury);
    }
    return mxx + mxy;
}

ll SA(mt19937 &gen){
    vector<int> cur(n, 0);
    shuffle(cur.begin(), cur.end(), gen);

    ll lst = g(cur);
    ll ans = lst;

    double T = 5e4;
    double delta = 0.995;
    uniform_real_distribution<double> rd(0.0, 1.0);

    while (T > 1e-8){
        int x = gen() % n;

       cur[x] ^= 1;
        ll now = g(cur);
        ll dE = now - lst;

        if (dE >= 0 || rd(gen) < exp((double)dE / T)){
            lst = now;
        } else {
            cur[x] ^= 1;
        }
        ans = max(ans, lst);

        T *= delta;
    }
    return ans;
}

void solve(){
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    ans = 0;
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
    ans = max(ans, SA(gen));
    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t --){
        solve();
    }
    return 0;
}
