// 比赛/平台：洛谷
// 题目：P10729 [NOISG 2023 Qualification] Dolls
// 链接：https://www.luogu.com.cn/problem/P10729
// 状态：已通过
// 算法：并查集、动态连续段、贡献维护

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 10;
const int M = 1e5 + 10;
int a[M];
int sz[N];
int pre[N];

int ans = 0;

void init(){
    for (int i = 1; i < N; i ++){
        pre[i] = i;
        sz[i] = 1;
    }
}

int root(int x){
    return pre[x] == x ? x : pre[x] = root(pre[x]);
}

void merge(int x, int y){
    int rtx = root(x);
    int rty = root(y);

    if (rtx == rty){
        return ;
    }

    if (sz[rtx] > sz[rty]){
        swap(rtx, rty);
    }

    ans -= (sz[rtx] + 1) / 2;
    ans -= (sz[rty] + 1) / 2;

    pre[rtx] = rty;
    sz[rty] += sz[rtx];

    ans += (sz[rty] + 1) / 2;
}

void solve(){
    int n;
    cin >> n;

    /* map <int, int> mp;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];

        if (mp.find(a[i]) == mp.end()){
            mp[a[i]] ++;

            if (mp.find(a[i] - 2) != mp.end()){
                merge(a[i] - 2, a[i]);
            }

            if (mp.find(a[i] + 2) != mp.end()){
                merge(a[i] + 2, a[i]);
            }
        }

        cout << *max_element(sz + 1, sz + N) << ' ';
    } */

    map <int, int> mp;
    for (int i = 1; i <= n; i ++){
        int x;
        cin >> x;

        if (mp.find(x) == mp.end()){
            ans ++;

            if (x - 1 > 0 && mp.find(x - 1) != mp.end()){
                merge(x - 1, x);
            }
            if (x + 1 < N && mp.find(x + 1) != mp.end()){
                merge(x + 1, x);
            }
        }

        mp[x] ++;

        cout << ans << ' ';
    }

}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    init();
    while (t --){
        solve();
    }
    return 0;
}
