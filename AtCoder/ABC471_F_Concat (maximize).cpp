// 比赛：AtCoder Beginner Contest 471
// 题目：ABC471 F - Concat (maximize)
// 链接：https://atcoder.jp/contests/abc471/tasks/abc471_f
// 状态：未通过
// 算法：字符串排序、贪心（待修正）

#include<bits/stdc++.h>
using namespace std;
using ll = long long;


const int N = 2e5 + 10;
const int MOD = 998244353;
ll fac[N];

void init(){
    fac[0] = fac[1] = 1;
    for (int i = 2; i < N; i ++){
        fac[i] = fac[i - 1] * i % MOD;
    }
}

ll power (ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll x){
    return power(x, MOD - 2);
}

ll C(ll n, ll m){
    if (n < m || m < 0 || n < 0){
        return 0;
    }
    return fac[n] * inv(fac[n - m]) % MOD * inv(fac[m]) % MOD;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector <string> ss;
    for (int i = 1; i <= n; i ++){
        string s;
        cin >> s;
        ss.push_back(s);
    }
    sort(ss.begin(), ss.end(), [](const string& a, const string &b){
        return a + b > b + a;
    });
    string ans = "";
    for (int i = 0; i < k; i ++){
        ans += ss[i];
    }
    ll p = 0;
    while (p < ans.size() && ans[p] == '0'){
        p ++;
    }
    if (p == ans.size()){
        cout << 0 << '\n';
    } else {
        cout << ans.substr(p) << '\n';
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    init();
    while (t --){
        solve();
    }
    return 0;
}
