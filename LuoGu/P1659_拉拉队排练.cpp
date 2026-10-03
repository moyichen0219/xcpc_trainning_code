// 平台：洛谷
// 题目：P1659 [国家集训队] 拉拉队排练
// 链接：https://www.luogu.com.cn/problem/P1659
// 状态：已通过
// 算法：Manacher、奇回文计数、贪心、快速幂

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 19930726;

ll power(ll a, ll b){
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

void solve(){
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string a = "^";
    for (auto c : s){
        a += '#';
        a += c;
    }
    a += "#$";

    int nn = a.size();
    vector <int> p(nn, 0);

    int mid = 0;
    int r = 0;

    for (int i = 1; i < nn - 1; i ++){
        int mirror = 2 * mid - i;

        if (i < r){
            p[i] = min(p[mirror], r - i);
        }

        while (a[i - p[i] - 1] == a[i + p[i] + 1]){
            p[i] ++;
        }

        if (i + p[i] > r){
            r = i + p[i];
            mid = i;
        }
    }

    // 维护长度恰好为len的奇数回文子串数量
    vector <int> cnt(n + 2, 0);

    for (int i = 0; i < n; i ++){
        int odd = p[i * 2 + 2];
        cnt[odd] ++;
    }

    for (int i = n; i >= 3; i --){
        if (i % 2 == 1){
            cnt[i - 2] += cnt[i];
        }
    }

    ll ans = 1;
    ll c = 0;

    int st = n;
    if (n % 2 == 0){
        st --;
    }

    for (; st >= 1 && c < k; st -= 2){
        ll cur = min((ll)cnt[st], k - c);

        ans = ans * power(st, cur) % MOD;

        c += cur;
    }

    if (c == k){
        cout << ans << '\n';
    } else {
        cout << -1 << '\n';
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
