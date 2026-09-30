// 比赛：The 2026 ICPC Guizhou Provincial Contest
// 题目：D - Bacteria Culture
// 链接：https://qoj.ac/contest/4121/problem/20287
// 状态：待验证
// 算法：倍增次数、区间操作、贪心扫描

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N], b[N];
int o[N];
bool vis[N];

void solve(){
    int n, M;
    cin >> n >> M;

    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        o[i] = 0;
    }

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++){
        cin >> b[i];
    }

    for (int i = 1; i <= n; i ++){
        ll ans = 0;
        if (a[i] == 0){
            if (b[i] != 0){
                cout << -1 << '\n';
                return ;
            }
            o[i] = 0;
            vis[i] = true;
            continue;
        }

        if (a[i] > b[i]){
            cout << -1 << '\n';
            return ;
        }

        if (b[i] == M){
            ll cnt = (M + a[i] - 1) / a[i];
            ll c = 0;
            ll p = 1;

            while (p < cnt){
                p *= 2;
                c ++;
            }

            ans = max(ans, c);
            vis[i] = true;
        } else {
            if (b[i] % a[i] != 0){
                cout << -1 << '\n';
                return ;
            }

            ll base = b[i] / a[i];
            if (base & (base - 1)){
                cout << -1 << '\n';
                return ;
            }

            ll c = __lg(base);
            ans = max(ans, c);
        }

        o[i] = ans;
    }

    int ans = 0;
    int pre = 0;

    for (int i = 1; i <= n; i ++){
        ll cur = 0;

        if (vis[i]){
            cur = max(pre, o[i]);
        } else {
            cur = o[i];
        }

        if (cur > pre){
            ans += cur - pre;
        }

        pre = cur;
    }

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
