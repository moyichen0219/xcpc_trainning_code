// 比赛：Codeforces Round 725 (Div. 3)
// 题目：1538C - Number of Pairs
// 链接：https://codeforces.com/problemset/problem/1538/C
// 状态：已通过
// 算法：排序、双指针、区间计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
vector <int> a(N);

int n, l, r;

ll f(vector <int> a, int x){
    int i = 1;
    int j = n;

    ll ans = 0;
    while (i < j){
        if (a[i] + a[j] <= x){
            ans += j - i;
            i ++;
        } else {
            j --;
        }
    }

    return ans;
}

void solve(){

    cin >> n >> l >> r;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    sort(a.begin() + 1, a.begin() + 1 + n);

    ll ans = f(a, r) - f(a, l - 1);

    cout << ans << '\n';
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
