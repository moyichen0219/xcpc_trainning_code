// 平台：洛谷
// 题目：P3390【模板】矩阵快速幂
// 链接：https://www.luogu.com.cn/problem/P3390
// 状态：已通过（账号；本地需修正）
// 算法：矩阵快速幂、二进制快速幂

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 110;
const int MOD = 1e9 + 7;
int n;

struct Matrix{
    ll a[N][N];

    Matrix (){
        memset(a, 0, sizeof(a));
    }
};

Matrix operator * (const Matrix& A, const Matrix& B){
    Matrix C;

    for (int i = 0; i < n; i ++){
        for (int k = 0; k < n; k ++){
            for (int j = 0; j < n; j ++){
                C.a[i][j] = (C.a[i][j] +  A.a[i][k] * B.a[k][j]) % MOD;
            }
        }
    }

    return C;
}

Matrix qpow(Matrix A, ll h){
    Matrix res;

    for (int i = 0; i < n; i ++){
        res.a[i][i] = 1;
    }

    while (h){
        if (h & 1){
            res = res * A;
        }

        A = A * A;
        h >>= 1;
    }

    return res;
}

void solve(){
    ll k;
    cin >> n >> k;

    Matrix A;

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cin >> A.a[i][j];
        }
    }

    if (k == 0){
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j ++){
                if (i == j){
                    cout << 1 << ' ';
                } else {
                    cout << 0 << ' ';
                }
            }
            cout << '\n';
        }
        return ;
    } else if (k == 1){
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < n; j ++){
                cout << A.a[i][j] << ' ';
            }
            cout << '\n';
        }
        return ;
    }

    Matrix res = qpow(A, k);

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cout << res.a[i][j] % MOD << ' ';
        }
        cout << '\n';
    }
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
