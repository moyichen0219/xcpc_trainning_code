// 比赛/平台：Codeforces
// 题目：977D Divide by three, multiply by two
// 链接：https://codeforces.com/problemset/problem/977/D
// 状态：已通过
// 算法：排序、质因数指数、构造

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 110;
ll a[N];

ll cnt3(ll a){
    ll cnt = 0;

    while (a % 3== 0){
        cnt ++;
        a /= 3;
    }

    return cnt;
}

bool cmp(ll a, ll b){
    if (cnt3(a) != cnt3(b)){
        return cnt3(a) > cnt3(b);
    }
    return a < b;
}

void solve(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i ++){
        cout << a[i] << ' ';
    }
    cout << '\n';
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
