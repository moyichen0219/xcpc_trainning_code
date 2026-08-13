// 比赛：Codeforces Round 733 (Div. 1 + Div. 2)
// 题目：1530C - Pursuit
// 链接：https://codeforces.com/problemset/problem/1530/C
// 状态：已通过
// 算法：排序、前缀和、二分答案

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int a[N], b[N];
int prea[N], preb[N];
int n;

bool check (int mid){
    int m = n + mid;
    int k = m - m / 4;

    ll a = 100 * mid;
    ll b = 0;

    int cnta = k - mid;
    int cntb = min(n, k);

    if (cnta > 0){
        a += prea[n] - prea[n - cnta];
    }

    b = preb[n] - preb[n - cntb];

    return a >= b;
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++){
        cin >> b[i];
    }

    int k = n - (n / 4);

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i ++){
        prea[i] = prea[i - 1] + a[i];
        preb[i] = preb[i - 1] + b[i];
    }

    ll suma = 0;
    ll sumb = 0;
    suma = prea[n] - prea[n - k];
    sumb = preb[n] - preb[n - k];
    if (suma >= sumb){
        cout << 0 << '\n';
        return ;
    }

    int l = 0;
    int r = n;
    int ans = 0;
    while (l < r){
        int mid = (l + r) / 2;
        if (check(mid)){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << '\n';
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
