// 比赛：AtCoder Beginner Contest 221
// 题目：C - Select Mul
// 链接：https://atcoder.jp/contests/abc221/tasks/abc221_c
// 状态：已通过
// 算法：二进制枚举、排序、数位构造

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll power (ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1){
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    vector <int> a(n + 1);
    for (int i = 0; i < n; i ++){
        a[i + 1] = s[i] - '0';
    }
    int x, y;
    if (n % 2 == 0){
        x = y = n / 2;
    } else {
        x = (n + 1) / 2;
        y = (n - 1) / 2;
    }
    ll ans1 = 0;
    ll ans2 = 0;
    int cnt = 0;
    // cout << n << '\n' << '\n';
    sort(a.begin() + 1, a.begin() + n + 1, greater<int>());
    bool same = true;
    for (int i = 1; i <= min(x, y); i ++){
        int a1 = a[cnt + 1];
        int a2 = a[cnt + 2];
        if (same){
            ans1 = ans1 * 10 + a1;
            ans2 = ans2 * 10 + a2;

            if (a1 != a2){
                same = false;
            }
        } else {
            ans1 = ans1 * 10 + a2;
            ans2 = ans2 * 10 + a1;
        }
        cnt += 2;
    }
    if (cnt != n){
        ans2 = ans2 * 10 + a[cnt + 1];
    }
    ll ans = ans1 * ans2;
    cout << ans << '\n';
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
} */


/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    sort(s.begin(), s.end());
    ll ans = 0;
    do {
        for (int i = 1; i < n; i ++){
            ll x = 0;
            ll y = 0;
            for (int j = 0; j < i; j ++){
                x = x * 10 + (s[j] - '0');
            }
            for (int j = i; j < n; j ++){
                y = y * 10 + (s[j] - '0');
            }
            ans = max(ans, x * y);
        }
    }while (next_permutation(s.begin(), s.end()));
    cout << ans << '\n';
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
} */


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    ll ans = 0;
    for (int mask = 1; mask < (1 << n) - 1; mask ++){
        vector <int> a;
        vector <int> b;
        for (int i = 0; i < n; i ++){
            // 第i位是0还是1
            if (mask >> i & 1){
                a.push_back(s[i] - '0');
            } else {
                b.push_back(s[i] - '0');
            }
        }
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        if (a[0] == 0 || b[0] == 0){
            continue;
        }
        ll x = 0;
        ll y = 0;
        for (auto i : a){
            x = x * 10 + i;
        }
        for (auto i : b){
            y = y * 10 + i;
        }
        ans = max(ans, x * y);
    }
    cout << ans << '\n';
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
