// 模板：Manacher（马拉车算法）
// 用途：线性求最长回文子串长度
// 复杂度：O(n)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string a;
    cin >> a;

    string s = "^";

    for (auto c : a){
        s += '#';
        s += c;
    }

    s += "#$";

    int n = s.size();
    vector <int> p(n, 0);

    int mid = 0;
    int r = 0;

    int ans = 0;
    for (int i = 1; i < n - 1; i ++){
        int mirror = 2 * mid - i;

        if (i < r){
            p[i] = min(p[mirror], r - i);
        }

        while (s[i - p[i] - 1] == s[i + p[i] + 1]){
            p[i] ++;
        }

        if (i + p[i] > r){
            mid = i;
            r = i + p[i];
        }

        ans = max(ans, p[i]);
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
