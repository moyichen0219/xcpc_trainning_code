// 比赛：CSES Sorting and Searching
// 题目：2183 - Missing Coin Sum
// 链接：https://cses.fi/problemset/task/2183/
// 状态：待验证
// 算法：贪心、排序、可表示区间

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    ll sum = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] > sum + 1){
            cout << sum + 1 << '\n';
            return ;
        } else {
            sum += a[i];
        }
    }

    cout << sum + 1 << '\n';
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
