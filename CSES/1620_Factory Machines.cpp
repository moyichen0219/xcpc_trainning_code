// 比赛：CSES Sorting and Searching
// 题目：1620 - Factory Machines
// 链接：https://cses.fi/problemset/task/1620/
// 状态：待验证
// 算法：二分答案、产量判定

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int k[N];
int n, t;

bool check(ll x){
    ll cur = 0;
    for (int i = 1; i <= n; i ++){
        cur += x / k[i];
        if (cur >= t){
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> t;

    for (int i = 1; i <= n; i ++){
        cin >> k[i];
    }

    ll l = 1;
    ll r = 4e18;
    while (l != r){
        ll mid = l + (r - l) / 2;;
        if (check(mid)){
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
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
