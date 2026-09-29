// 比赛：CSES Sorting and Searching
// 题目：1085 - Array Division
// 链接：https://cses.fi/problemset/task/1085/
// 状态：待验证
// 算法：二分答案、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;

const int N = 2e5 + 10;
int a[N];

bool check (ll x){
    int cnt = 1;
    ll sum = 0;
    int i = 1;
    while (i <= n){
        if (a[i] > x){
            return false;
        }
        if (sum + a[i] <= x){
            sum += a[i];
        } else {
            cnt ++;
            sum = a[i];
        }
        i ++;
    }
    return cnt <= k;
}

void solve(){

    cin >> n >> k;

    for (int i = 1;i <= n; i ++){
        cin >> a[i];
    }

    ll l = 1;
    ll r = 4e18;
    while (l != r){
        ll mid = (l + r) / 2;
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
