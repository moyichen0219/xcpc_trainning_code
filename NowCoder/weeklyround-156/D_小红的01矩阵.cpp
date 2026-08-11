// 比赛：牛客周赛 Round 156
// 题目：D - 小红的01矩阵
// 链接：https://ac.nowcoder.com/acm/contest/138917/D
// 状态：未完成、未通过
// 算法：组合计数（草稿）

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll b){
    ll res = 1;
    while (b ){
        if (b & 1){
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

// 我们发现， 在全是 ？且 n = 3 时，对第一行来看，每一个位置都有两个选择（即0， 1）
// 即第一行有power(2, n)种选择，第二行的选择不能与第一行一致
// 那么，他有power(2, n) - 1种选择，第三行有power(2, n) - 2种选择

void solve(){
    int n;
    cin >> n;
    vector <string> ss;
    for (int i = 1; i <= 3; i ++){
        string s;
        cin >> s;
        ss.push_back(s);
    }
    if (n > 8){
        cout << 0 << '\n';
    }
    ll ans  = 1;
    for (int i = 0; i < n; i ++){

    }
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
