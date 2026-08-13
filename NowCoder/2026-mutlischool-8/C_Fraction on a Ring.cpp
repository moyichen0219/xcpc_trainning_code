// 比赛：2026 牛客暑期多校训练营 8
// 题目：C - Fraction on a Ring
// 链接：https://ac.nowcoder.com/acm/contest/133883/C
// 状态：未完成
// 算法：数学、枚举（草稿中含未初始化变量）

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;

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

ll inv(ll x){
       return power(x, MOD - 2);
}

void solve(){
       ll n, p;
       cin >> n >> p;
       int cnt = 0;
       for (int i = 1; i <= n; i ++){
              for (int j = 1; j <= n; j ++){
                     ll a = i * p;
                     ll b = ((i * inv(b) ) % p) * b;
                     cout << a << ' ' << b << '\n';
                     if (a > b){
                            cnt ++;
                     }
              }
       }
       cout << cnt << '\n';
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
