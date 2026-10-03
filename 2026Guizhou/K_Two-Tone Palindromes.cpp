// 比赛：The 2026 ICPC Guizhou Provincial Contest
// 题目：K - Two-Tone Palindromes
// 链接：https://qoj.ac/contest/4121/problem/20294
// 状态：待验证
// 算法：双指针、Manacher、回文子串计数

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector <int> len(n, 0);
    vector <int> cnt(26, 0);

    int kinds = 0;
    int r = 0;
    for (int i = 0; i < n; i ++){
        while (r < n){
            int c = s[r] - 'a';

            if (cnt[c] == 0 && kinds == 2){
                break;
            }

            if (cnt[c] == 0){
                kinds ++;
            }

            cnt[c] ++;
            r ++;
        }

        len[i] = r - i;

        int c = s[i] - 'a';
        cnt[c] --;

        if (cnt[c] == 0){
            kinds --;
        }
    }

    string a = "^";

    for (auto c : s){
        a += '#';
        a += c;
    }

    a += "#$";

    n = a.size();
    vector <int> p(n, 0);

    int mid = 0;
    r = 0;

    ll ans = 0;
    for (int i = 1; i < n - 1; i ++){
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

    // 以 s[i] 这个字符为中心的奇回文子串个数
    // 以 s[i] 前面的缝为中心的偶回文子串个数
    for (int i = 0; i < s.size(); i ++){
        int odd = (p[2 * i + 2] + 1) / 2;
        int even = p[2 * i + 1] / 2;

        ans += min(odd, len[i]);
        ans += min(even, len[i]);
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
