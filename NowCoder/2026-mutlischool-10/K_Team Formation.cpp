// 比赛：2026 牛客暑期多校训练营 10
// 题目：K - Team Formation
// 链接：https://ac.nowcoder.com/acm/contest/133885/K
// 状态：已通过
// 算法：模拟退火、随机化、分组优化

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
const int N = 25;
int a[N][N];
const double eps = 1e-8;

ll g(vector <int> &p){
    ll res = 0;
    for (int i = 0; i < n; ++i){
        int x = p[3 * i];
        int y = p[3 * i + 1];
        int z = p[3 * i + 2];
        res += (ll)a[x][y] + a[x][z] + a[y][z];
    }
    return res;
}

ll SA(mt19937 &gen){
    int m = 3 * n;

    vector<int> cur(m);
    iota(cur.begin(), cur.end(), 0);
    shuffle(cur.begin(), cur.end(), gen);

    ll lst = g(cur);
    ll ans = lst;

    double T = 5e8;
    double delta = 0.995;

    uniform_real_distribution<double> rd(0.0, 1.0);

    while (T > 1e-8){

        int x = gen() % m;
        int y = gen() % m;

        if (x == y || x / 3 == y / 3){
            T *= delta;
            continue;
        }

        swap(cur[x], cur[y]);

        ll now = g(cur);
        ll dE = now - lst;

        if (dE >= 0 || rd(gen) < exp((double)dE / T)){
            lst = now;
        } else {
            swap(cur[x], cur[y]);
        }

        ans = max(ans, lst);

        T *= delta;
    }

    return ans;
}

void solve(){
    cin >> n;
    for (int i = 0; i < 3 * n; i ++){
        for (int j = 0; j < 3 * n; j ++){
            cin >> a[i][j];
        }
    }
    ll ans = LLONG_MIN;
    /* // 模拟退火
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
    vector<int> cur(3 * n);
    iota(cur.begin(), cur.end(), 0);
    shuffle(cur.begin(), cur.end(), gen);
    ll lst = g(cur);
    double T = 5e8;
    double delta = 0.995;
    while (T > eps){
        ans = max(ans, lst);
        int x = gen() % (3 * n);
        int y = gen() % (3 * n);
        if (x == y || x / 3 == y / 3){
            T *= delta;
            continue;
        }
        swap(cur[x], cur[y]);
        ll now = g(cur);
        ll dE = now - lst;
        // 只要状态更优，那么更新答案
        if(dE >= 0 || exp((double)dE / T) > uniform_real_distribution<double>(0, 1)(gen)){
            lst = now;
        } else {
            swap(cur[x], cur[y]);
        }
        ans = max(ans, lst);
        T *= delta;
    } */
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
    for (int i = 0; i < 30; i++){
        ans = max(ans, SA(gen));
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
