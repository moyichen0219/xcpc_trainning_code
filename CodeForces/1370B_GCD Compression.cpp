// 比赛：Codeforces Round 651 (Div. 2)
// 题目：1370B - GCD Compression
// 链接：https://codeforces.com/problemset/problem/1370/B
// 状态：已通过
// 算法：奇偶分类、构造

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> a(2 * n + 1);
    vector <int> odd;
    vector <int> even;
    for (int i = 1; i <= 2 * n; i ++){
        cin >> a[i];
        if (a[i] % 2 == 1){
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }
    if (odd.size() % 2 == 1){
        odd.pop_back();
        even.pop_back();
    } else {
        if (odd.size() >= 2){
            odd.pop_back();
            odd.pop_back();
        } else {
            even.pop_back();
            even.pop_back();
        }
    }
    for (int i = 0; i < odd.size(); i += 2){
        cout << odd[i] << ' ' << odd[i + 1] << '\n';
    }
    for (int i = 0; i < even.size(); i += 2){
        cout << even[i] << ' ' << even[i + 1] << '\n';
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
