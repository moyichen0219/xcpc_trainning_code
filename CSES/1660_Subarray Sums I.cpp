// 比赛：CSES Sorting and Searching
// 题目：1660 - Subarray Sums I
// 链接：https://cses.fi/problemset/task/1660/
// 状态：待验证
// 算法：滑动窗口、双指针

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];
ll pre[N];

/* void solve(){
    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++){
        pre[i] = pre[i - 1] + a[i];
    }

    int cnt = 0;
    map <ll, int> mp;
    mp[0] = 1;
    for (int i = 1; i <= n; i ++){
        if (mp.find(pre[i] - x) != mp.end()){
            cnt += mp[pre[i] - x];
        }
        mp[pre[i]] ++;
    }

    cout << cnt << '\n';
} */

void solve(){
    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    int cnt = 0;
    int i = 1;
    int j = 1;
    ll sum = 0;
    while (i <= n && j <= n){
        sum += a[j];

        while (sum > x){
            sum -= a[i];
            i ++;
        }

        if (sum == x){
            cnt ++;
        }

        j ++;
    }

    cout << cnt << '\n';
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
