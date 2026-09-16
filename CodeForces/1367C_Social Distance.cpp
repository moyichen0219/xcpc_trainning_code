// 比赛：Codeforces Round 650 (Div. 3)
// 题目：1367C - Social Distance
// 链接：https://codeforces.com/problemset/problem/1367/C
// 状态：已通过
// 算法：贪心、字符串、间隔计数

/* // https://codeforces.com/problemset/problem/1367/C

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (s.find('1') == string::npos){
        int cnt = n / (k + 1);
        int rem = n % (k + 1);
        if (rem){
            cnt ++;
        }
        cout << cnt << '\n';
        return ;
    }

    vector <int> vis1;
    for (int i = 0; i < s.length(); i ++){
        if (s[i] == '1'){
            vis1.push_back(i + 1);
        }
    }

    int ans = 0;

    // 和开头隔着几个数？
    int len = (vis1[0] - 1 - k);
    if (len > 0){
        ans += (len + k) / (k + 1);
    }

    for (int i = 1; i < vis1.size(); i ++){
        int len = (vis1[i] - vis1[i - 1] - 1 - 2 * k);
        if (len > 0){
            ans += (len + k) / (k + 1);
        }
    }

    len = (n - vis1.back() - k);
    if (len > 0){
        ans += (len + k) / (k + 1);
    }


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
} */

// https://codeforces.com/problemset/problem/1367/C

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (s.find('1') == string::npos){
        int cnt = n / (k + 1);
        int rem = n % (k + 1);
        if (rem){
            cnt ++;
        }
        cout << cnt << '\n';
        return ;
    }

    vector <int> vis1;
    for (int i = 0; i < s.length(); i ++){
        if (s[i] == '1'){
            vis1.push_back(i + 1);
        }
    }

    int ans = 0;

    // 和开头隔着几个数？
    int len = (vis1[0] - 1);
    if (len > k){
        ans += len / (k + 1);
    }

    for (int i = 1; i < vis1.size(); i ++){
        int len = (vis1[i] - vis1[i - 1] - 1 - k);
        if (len > k){
            ans += len / (k + 1);
        }
    }

    len = (n - vis1.back());
    if (len > k){
        ans += len / (k + 1);
    }


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
