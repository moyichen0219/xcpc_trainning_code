// 比赛/平台：2026 CCPC 女生专场
// 题目：B - 不平衡指数
// 链接：https://qoj.ac/contest/4613/problem/23632/statement/zh_cn
// 状态：待验证
// 算法：排序、前缀和、二分、双指针

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

const int N = 5e5 + 10;
int a[N];
ll pre[N];
ll suf[N];

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    pre[0] = 0;
    for (int i = 1; i <= n; i ++){
        pre[i] = pre[i - 1] + a[i];
    }
    suf[n + 1] = 0;
    for (int i = n; i >= 1; i --){
        suf[i] = suf[i + 1] + a[i];
    }

    // mx
    ll up = 0;
    ll down = 1;

    int mx = 0;

    for (int l = 2; l <= n; l ++){
        int L = l;
        int R = n;
        int ans = l - 1;

        while (L <= R){
            int mid = (L + R) / 2;
            ll cnt = mid - l + 2;

            ll sum = a[1] + pre[mid] - pre[l - 1];

            if ((i128)sum < (i128) cnt * a[l]){
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }

        mx = max(mx, ans - l + 1);
    }

    up = mx;
    down = mx + 1;

    ll g = gcd(up, down);
    cout << up / g << '/' << down / g << ' ';

    // mn
    bool is = false;
    for (int i = 2; i <= n; i ++){
        if (a[i] == a[i - 1]){
            is = true;
            break;
        }
    }

    if (is){
        cout << "0/1" << '\n';
        return ;
    }

    up = 0;
    down = 1;

    int l = 1;
    int mn = 0;

    for (int r = 1; r < n; r++){
        while (l <= r){
            ll sum = a[n] + pre[r] - pre[l - 1];
            ll cnt = r - l + 2;

            if ((i128)sum >= (i128)cnt * a[r]){
                break;
            }

            l++;
        }

        if (l <= r){
            mn = max(mn, r - l + 1);
        }
    }

    up = 1;
    down = mn + 1;

    g = gcd(up, down);
    cout << up / g << '/' << down / g << '\n';
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
