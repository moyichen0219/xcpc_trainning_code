// 比赛：信息与未来 2015
// 题目：B3879 - 连续数的和（加强版）
// 链接：https://www.luogu.com.cn/problem/B3879
// 状态：待验证
// 算法：数学、平方因子消除、奇偶分类、枚举

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if (k % 2 == 0){
        // k / 2 = (A ^ 2) * C;
        ll tmp = k / 2;
        for (ll i = 2; i <= k / i; i ++){
            while (tmp % (i * i) == 0){
                tmp /= i * i;
            }
        }

        if (tmp % 2 == 0){
            cout << 0 << '\n';
            return ;
        }

        // 找 (x + x + k - 1) / 2 = (B ^ 2) * C
        for (ll i = 1; i * i * tmp <= 2 * n - k + 1; i += 2){
            if (i * i * tmp >= k + 1){
                ans ++;
            }
        }
    } else if (k % 2 == 1){
        ll tmp = k;
        for (ll i = 2; i <= k / i; i ++){
            while (tmp % (i * i) == 0){
                tmp /= i * i;
            }
        }

        for (ll i = 1; i * i * tmp <= n - (k - 1) / 2; i ++){
            if (i * i * tmp >= (k + 1) / 2){
                ans ++;
            }
        }
    }

    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t= 1;
    while (t --){
        solve();
    }
    return 0;
}
