// 比赛：洛谷题库
// 题目：P2758 编辑距离
// 链接：https://www.luogu.com.cn/problem/P2758
// 状态：已通过
// 算法：字符串动态规划、编辑距离

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2010;
int dp[N][N];

void solve(){
    string a, b;
    cin >> a >> b;
    int lena = a.length();
    int lenb = b.length();

    for (int i = 0; i <= max(lena, lenb); i ++){
        dp[i][0] = i;
        dp[0][i] = i;
    }

    for (int i = 1; i <= lena; i ++){
        for(int j = 1; j <= lenb; j ++){
            if (a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
    }

    cout << dp[lena][lenb] << '\n';
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
