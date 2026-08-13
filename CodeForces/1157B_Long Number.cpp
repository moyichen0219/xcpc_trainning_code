// 比赛：Codeforces Round 555 (Div. 3)
// 题目：1157B - Long Number
// 链接：https://codeforces.com/problemset/problem/1157/B
// 状态：已通过
// 算法：贪心、字符串

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <int> a(10);
    for (int i = 1; i <= 9; i ++){
        cin >> a[i];
    }
    bool ok = false;
    for (int i = 0; i < n; i ++){
        if (s[i] - '0' < a[s[i] - '0']){
            cout << a[s[i] - '0'];
            ok = true;
        } else {
            if (!ok){
                cout << s[i];
            } else {
                if (s[i] - '0' == a[s[i] - '0']){
                    cout << s[i];
                    continue;
                }
                cout << s.substr(i);
                break;
            }
        }
    }
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
