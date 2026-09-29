// 比赛：CSES Sorting and Searching
// 题目：1090 - Ferris Wheel
// 链接：https://cses.fi/problemset/task/1090/
// 状态：待验证
// 算法：排序、双指针、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];

void solve(){
    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1, greater <int>());

    int cnt = 0;
    int i = 1;
    int j = n;
    while (i <= j){
        if (a[i] < x){
            cnt ++;
            if (a[i] + a[j] <= x){
                i ++;
                j --;
            } else {
                i ++;
            }
        } else if (a[i] <= x){
            cnt ++;
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
