// 模板：矩阵快速幂
// 状态：模板
// 内容：固定维度矩阵乘法、单位矩阵、二进制快速幂
// 使用：按需设置 K、MOD 和转移矩阵，指数应为非负数；solve() 留作调用入口。

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
// 随着矩阵的维度进行变化
const int K = 2;

struct Matrix{
    ll a[K][K];

    Matrix(){
        memset(a, 0, sizeof(a));
    }
};

Matrix operator * (const Matrix &A, const Matrix &B){
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

    // 单位矩阵
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
