// 比赛：洛谷
// 题目：P1349 - 广义斐波那契数列
// 链接：https://www.luogu.com.cn/problem/P1349
// 状态：已通过
// 算法：矩阵快速幂、二阶线性递推、模运算

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int K = 2;
int m;

struct Matrix{
    ll a[K][K];

    Matrix(){
        memset(a, 0, sizeof(a));
    }
};

Matrix operator * (const Matrix& A, const Matrix& B){
    Matrix C;

    for (int i = 0; i < K; i ++){
        for (int k = 0; k < K; k++){
            for (int j = 0; j < K; j ++){
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % m;
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
    ll p, q, a1, a2, n;
    cin >> p >> q >> a1 >> a2 >> n >> m;

    if (n == 1){
        cout << a1 % m << '\n';
        return ;
    } else if (n == 2){
        cout << a2 % m << '\n';
        return ;
    }

    Matrix A;

    A.a[0][0] = p;
    A.a[0][1] = q;
    A.a[1][0] = 1;
    A.a[1][1] = 0;

    Matrix res;

    res = qpow(A, n - 2);

    ll ans = (res.a[0][0] * a2 % m + res.a[0][1] * a1 % m) % m;

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
