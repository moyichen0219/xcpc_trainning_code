// 比赛：The 2026 ICPC Guizhou Provincial Contest
// 题目：B - Aquarium Bubble Lights
// 链接：https://qoj.ac/contest/4121/problem/20285
// 状态：待验证
// 算法：时间偏移、桶计数、动态维护正数数量

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];
int o[N];

void solve(){
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i ++){
        a[i] = o[i] = 0;
    }

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        if (a[i] <= q && a[i] >= 1){
            o[a[i]] ++;
        }
        if (a[i] > 0){
            cnt ++;
        }
    }


    map <int, int> mp;
    for (int i = 1; i <= q; i ++){
        int x, v;
        cin >> x >> v;

        cnt -= o[i];

        if (x != 0){
            int temp = a[x];
            int cur = 0;
            int die = 0;

            if (mp.find(x) != mp.end() && mp[x] > 0){
                cur = a[x] - i + mp[x];
            } else {
                cur = a[x] - i;
            }

            if (mp.find(x) != mp.end() && mp[x] > 0){
                die = a[x] + mp[x];
            } else {
                die = a[x];
            }

            if (die <= q){
                o[die] --;
            }

            cur = max(cur, 0);

                a[x] = max({cur, v, 0});
                mp[x] = i;

            if (cur == 0 && a[x] > 0){
                cnt ++;
            }

            if (a[x] + i <= q){
                o[a[x] + i] ++;
            }
        }

        cout << cnt << '\n';
    }

    for (int i = 1; i <= n; i ++){
        cout << max(a[i] - q + mp[i], 0) << ' ';
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t --){
        solve();
    }
    return 0;
}
