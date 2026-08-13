// 比赛：Codeforces Round 661 (Div. 3)
// 题目：1399C - Boats Competition
// 链接：https://codeforces.com/problemset/problem/1399/C
// 状态：已通过
// 算法：枚举、排序、双指针

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
const int N = 55;
vector <int> w(N);

int check (int mid){
    int i = 1;
    int j = n;
    int cnt = 0;
    while (i < j){
        if (w[i] + w[j] == mid){
            cnt ++;
            i ++;
            j --;
        } else if (w[i] + w[j] < mid){
            i ++;
        } else {
            j --;
        }
    }
    return cnt;
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> w[i];
    }
    sort(w.begin() + 1, w.begin() + n + 1);
    int ans = 0;
    for (int i = 2; i <= 2 * n; i ++){
        ans = max(ans, check(i));
    }
    cout << ans << '\n';
}

int main(){
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
