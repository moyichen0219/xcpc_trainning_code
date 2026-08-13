// 比赛：Codeforces Round 733 (Div. 1 + Div. 2)
// 题目：1530C - Pursuit
// 链接：https://codeforces.com/problemset/problem/1530/C
// 状态：未完成
// 算法：排序、贪心、二分答案（草稿）

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> b(n);
    ll t1 = 0;
    ll t2 = 0;
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++){
        cin >> b[i];
    }
    int k = k - (k / 4);
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    ll suma = 0;
    ll sumb = 0;
    for (int i = 0; i < k; i ++){
        suma += a[i];
    }
    for (int i = 0; i < k; i ++){
        sumb += b[i];
    }

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
