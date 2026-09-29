// 比赛：CSES Sorting and Searching
// 题目：1084 - Apartments
// 链接：https://cses.fi/problemset/task/1084/
// 状态：待验证
// 算法：排序、双指针、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];
int b[N];

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for (int i = 1; i <= m; i ++){
        cin >> b[i];
    }

    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);

    int cnt = 0;
    int j = 1;
    int i = 1;
    while (i <= n && j <= m){
        if ((b[j] >= a[i] - k) && (b[j] <= a[i] + k)){
            cnt ++;
            i ++;
            j ++;
        } else if (b[j] < a[i] - k){
            j ++;
        } else if (b[j] > a[i] + k){
            i ++;
        }
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
