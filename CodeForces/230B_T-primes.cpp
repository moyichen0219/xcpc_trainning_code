// 比赛/平台：Codeforces
// 题目：230B T-primes
// 链接：https://codeforces.com/problemset/problem/230/B
// 状态：已通过
// 算法：埃氏筛、完全平方数、素数判定

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
bool vis[N];

void init(){
    vis[0] = vis[1] = true;

    for (int i = 2; 1LL * i * i < N; i ++){
        if (!vis[i]){
            for (int j = i * i; j < N; j += i){
                vis[j] = true;
            }
        }
    }
}

bool check(ll x){
    ll p = sqrtl(x);

    if (p * p != x){
        return false;
    }

    if (vis[p]){
        return false;
    }

    return true;
}

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        ll x;
        cin >> x;

        if (check(x)){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
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
