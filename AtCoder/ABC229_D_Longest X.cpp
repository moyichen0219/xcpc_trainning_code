// 比赛/平台：AtCoder Beginner Contest 229
// 题目：D - Longest X
// 链接：https://atcoder.jp/contests/abc229/tasks/abc229_d
// 状态：已通过
// 算法：滑动窗口、双指针、前缀和

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll pre[N];

void solve(){
    string s;
    cin >> s;

    int k;
    cin >> k;

    if (s.find('.') == string::npos){
        cout << s.size() << '\n';
        return ;
    }

    int n = s.size();
    for (int i = 0; i < n; i ++){
        if (s[i] == '.'){
            pre[i + 1] = pre[i] + 1;
        } else {
            pre[i + 1] = pre[i];
        }
    }

    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; i ++){
        while (pre[i + 1] - pre[j] > k){
            j ++;
        }

        ans = max(ans, i - j + 1);
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
