// 模板：线性筛
// 状态：模板
// 内容：质数、欧拉函数、最小质因子

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e7 + 10;

// 存质数
int prime[N];
// 质数个数
int cnt;

// vis[i] = true;那么i不为质数
bool vis[N];
// 欧拉函数: 在 1 ~ i 之间，有多少个数和 i 互质。
int phi[N];
// i的最小质因子
int minp[N];

void init(int n){
    phi[1] = 1;
    minp[1] = 1;
    for (int i = 2; i <= n; i ++){
        // i 是质数
        if (!vis[i]){
            prime[++cnt] = i;
            // 质数p的欧拉函数
            phi[i] = i - 1;
            // 质数的最小质因子是自己
            minp[i] = i;
        }
        for (int j = 1; j <= cnt && 1LL * i * prime[j] <= n; j ++){
            int p = prime[j];
            int x = i * p;
            vis[x] = true;

            minp[x] = p;
            if (i % p == 0){
                // p是i的质因子
                // phi(i * p) = phi(i) * p;
                phi[x] = phi[i] * p;
                // 保证每个合数只被最小质因子筛一次
                break;
            } else {
                // gcd(i, p) = 1;
                // phi(i * p) = phi(i) * phi(p) = phi(i) * (p - 1)
                phi[x] = phi[i] * phi[p];
            }
        }
    }
}

void solve(){

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
