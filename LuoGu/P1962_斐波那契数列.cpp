// 比赛：洛谷
// 题目：P1962 - 斐波那契数列
// 链接：https://www.luogu.com.cn/problem/P1962
// 状态：已通过
// 算法：矩阵快速幂、斐波那契数列

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int K = 3;

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
    ll n;
    cin >> n;

    if (n == 1 || n == 2){
        cout << 1 << '\n';
        return ;
    }

    Matrix A;

    A.a[0][0] = A.a[0][1] = A.a[1][0] = A.a[2][1] = 1;

    Matrix res = qpow(A, n - 2);

    ll ans = (res.a[0][0] + res.a[0][1] + res.a[0][2]) % MOD;

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
} */


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int K = 2;

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
    ll n;
    cin >> n;

    if (n == 1 || n == 2){
        cout << 1 << '\n';
        return ;
    }

    Matrix A;

    A.a[0][0] = A.a[0][1] = A.a[1][0] = 1;

    Matrix res = qpow(A, n - 2);

    ll ans = (res.a[0][0] + res.a[0][1]) % MOD;

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
