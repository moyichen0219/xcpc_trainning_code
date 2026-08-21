// 比赛：Codeforces Round 702 (Div. 3)
// 题目：1490E - Accidental Victory
// 链接：https://codeforces.com/problemset/problem/1490/E
// 状态：已通过
// 算法：排序、前缀和、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    // value, idx
    vector<pair<ll, int>> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i].first;
        a[i].second = i;
    }
    int cnt = 1;
    vector <ll> pre(n + 1, 0);
    sort(a.begin() + 1, a.begin() + n + 1);
    for (int i = 1; i <= n; i ++){
        pre[i] = pre[i - 1] + a[i].first;
    }
    int pos = n;
    for (int i = n - 1; i >= 1; i --){
        if (pre[i] >= a[i + 1].first){
            pos = i;
        } else {
            break;
        }
    }
    vector <int> ans;
    for (int i = pos; i <= n; i++){
        ans.push_back(a[i].second);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans){
        cout << i << ' ';
    }
    cout << '\n';
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
