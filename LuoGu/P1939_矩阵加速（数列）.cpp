// 比赛：洛谷
// 题目：P1939 - 矩阵加速（数列）
// 链接：https://www.luogu.com.cn/problem/P1939
// 状态：已通过
// 算法：矩阵快速幂、三阶线性递推

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int K = 3;
const int MOD = 1e9 + 7;

struct Matrix{
    ll a[K][K];

    Matrix(){
        memset(a, 0, sizeof(a));
    }
};

Matrix operator * (const Matrix& A, const Matrix& B){
    Matrix C;

    for (int i = 0; i < K; i ++){
        for (int k = 0; k < K; k ++){
            for (int j = 0; j < K; j ++){
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
            }
        }
    }

    return C;
}

Matrix qpow(Matrix A, ll n){
    Matrix res;

    for (int i = 0; i < K; i ++){
        res.a[i][i] = 1;
    }

    while (n){
        if (n & 1){
            res = res * A;
        }

        A = A * A;
        n >>= 1;
    }

    return res;
}


void solve(){
    int n;
    cin >> n;

    if (n == 1 || n == 2 || n == 3){
        cout << 1 << '\n';
        return ;
    }

    Matrix A;
    A.a[0][0] = A.a[0][2] = A.a[1][0] = A.a[2][1] = 1;

    Matrix res = qpow(A, n - 3);

    ll ans = (res.a[0][0] + res.a[0][1] + res.a[0][2]) % MOD;

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
