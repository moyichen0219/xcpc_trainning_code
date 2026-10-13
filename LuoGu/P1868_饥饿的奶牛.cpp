// 比赛/平台：洛谷
// 题目：P1868 饥饿的奶牛
// 链接：https://www.luogu.com.cn/problem/P1868
// 状态：已通过
// 算法：动态规划、树状数组、区间调度

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    int l, r;
};

const int M = 3e6 + 10;
ll t[M];

const int N = 2e5 + 10;
node a[N];

int lowbit(int x){
    return x & -x;
}

void upd(ll k, int x){
    for (int i = x; i < M; i += lowbit(i)){
        t[i] = max(t[i], k);
    }
}

ll query(int x){
    ll res = 0;

    for (int i = x; i > 0; i -= lowbit(i)){
        res = max(res, t[i]);
    }

    return res;
}

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> a[i].l >> a[i].r;
    }

    sort(a + 1, a + n + 1, [](const node& x, const node& y){
        if (x.r != y.r){
            return x.r < y.r;
        }
        return x.l < y.l;
    });

    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        ll cur = query(a[i].l) + (a[i].r - a[i].l + 1);

        ans = max(ans, cur);

        upd(cur, a[i].r + 1);
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
