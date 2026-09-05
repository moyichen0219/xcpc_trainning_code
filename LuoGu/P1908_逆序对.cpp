// 比赛：洛谷
// 题目：P1908 - 逆序对
// 链接：https://www.luogu.com.cn/problem/P1908
// 状态：已通过
// 算法：离散化、树状数组、逆序对

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 10;
ll tree[N];

int lowbit(int x){
    return x & -x;
}

void add(int x, int v, int n){
    for (int i = x; i <= n; i += lowbit(i)){
        tree[i] += v;
    }
}

ll query(int x){
    int res = 0;
    for (int i = x; i ; i -= lowbit(i)){
        res += tree[i];
    }
    return res;
}

void solve(){
    int n;
    cin >> n;

    vector <int> a(n + 1);

    vector <int> b;\

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        b.push_back(a[i]);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    ll ans = 0;

    for (int i = 1; i <= n; i ++){
        int rk = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        int cnt = (i - 1) - query(rk);

        ans += cnt;

        add(rk, 1, b.size());
    }

    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t --){
        solve();
    }
    return 0;
}
