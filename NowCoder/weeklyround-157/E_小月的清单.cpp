// 比赛：牛客周赛 Round 157
// 题目：E - 小月的清单
// 链接：https://ac.nowcoder.com/acm/contest/139206/E
// 状态：已通过
// 算法：前缀和、前后缀最小值

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, q;
    cin >> n >> q;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector <ll> pre(n + 1);
    vector <ll> mn_pre(n + 1);
    vector <ll> mn_suf(n + 2);
    // ll cur = 0;
    pre[0] = mn_pre[0] = 0;
    for (int i = 1; i <= n; i ++){
        if (s[i - 1] == '+'){
            // cur += a[i];
            pre[i] = pre[i - 1] + a[i];
        } else if (s[i - 1] == '-'){
            // cur -= a[i];
            pre[i] = pre[i - 1] - a[i];
        }
        mn_pre[i] = min(mn_pre[i - 1], pre[i]);
    }
    mn_suf[n] = pre[n];
    for (int i = n - 1; i >= 1; i --){
        mn_suf[i] = min(mn_suf[i + 1], pre[i]);
    }
    while (q --){
        int p;
        char c;
        // 位置p， s[p - 1], 只会对后面的造成影响
        cin >> p >> c;
        ll change = 0;
        if (s[p - 1] != c){
            if (s[p - 1] == '+'){
                change = -1 * 2LL * a[p];
            } else {
                change = 2LL * a[p];
            }
        }
        bool ok1 = false;
        bool ok2 = false;
        if (mn_pre[p - 1] >= 0){
            ok1= true;
        }
        if (mn_suf[p] + change >= 0){
            ok2 = true;
        }
        if (ok1 && ok2){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
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
