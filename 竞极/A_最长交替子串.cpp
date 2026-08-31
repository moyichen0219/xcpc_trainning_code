// 比赛：竞极比赛 2093329939779661825
// 题目：A 最长交替子串（本地语义命名）
// 链接：http://47.120.23.84/contest/2093329939779661825/2093331392745287682
// 状态：待验证
// 算法：滑动窗口、二进制交替串

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n>> k;
    string s;
    cin >> s;

    int ans = 0;

    // 0101……
    int l = 0;
    int cnt = 0;

    for (int r = 0; r < n; r ++){
        char need = ((r % 2 == 0) ? '0' : '1');
        if (s[r] != need){
            cnt ++;
        }

        while (cnt > k){
            char need_l = ((l % 2 == 0) ? '0' : '1');

            if (s[l] != need_l){
                cnt --;
            }

            l ++;
        }

        ans = max(ans, r - l + 1);
    }

    l = 0;
    cnt = 0;

    for (int r = 0; r < n; r ++){
        char need = ((r % 2 == 1) ? '0' : '1');
        if (s[r] != need){
            cnt ++;
        }

        while (cnt > k){
            char need_l = ((l % 2 == 1) ? '0' : '1');

            if (s[l] != need_l){
                cnt --;
            }

            l ++;
        }

        ans = max(ans, r - l + 1);
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
