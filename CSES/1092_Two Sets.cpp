// 比赛/平台：CSES Problem Set
// 题目：1092 - Two Sets
// 链接：https://cses.fi/problemset/task/1092/
// 状态：待验证
// 算法：贪心构造、等和划分

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n;
    cin >> n;

    if ((n * (n + 1) / 2) % 2 == 1){
        cout << "NO" << '\n';
        return ;
    } else {
        cout << "YES" << '\n';
    }

    ll sum = (n * (n + 1) / 2) / 2;

    vector <int> a;
    vector <int> b;
    for (int i = n; i >= 1; i --){
        if (i <= sum){
            sum -= i;
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }

    cout << a.size() << '\n';
    for (auto i : a){
        cout << i << ' ';
    }

    cout << '\n';

    cout << b.size() << '\n';
    for (auto i : b){
        cout << i << ' ';
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
