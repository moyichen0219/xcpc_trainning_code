// 比赛：2026 牛客暑期多校训练营 5（133880）
// 题目：I - Sequence Operation 2 - https://ac.nowcoder.com/acm/contest/133880/I
// 状态：未通过（已有实现，但账号评测状态无 AC）
// 分类：位运算、异或不变量、构造
// 创建：MYC，2026/7/31
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    int N = power(2, n) - 1;
    string s;
    cin >> s;
    set <int> st;
    map <int, int> mp;
    int xor_ = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == '1') {
            st.insert(i + 1);
            xor_ = xor_ ^ (i + 1);
        }
    }
    st.erase(xor_);
    while (st.size()) {
        if (st.size() == 1) {
            break;
        }
        int x = *st.begin();
        st.erase(x);
        int y = *st.begin();
        st.erase(y);
        mp[x] = y;
    }
    for (int i = 1; i <= N; i++) {
        if (mp.find(i) != mp.end()) {
            cout << mp[i] << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
