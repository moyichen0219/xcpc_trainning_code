// 比赛/平台：CCPC2026 网络热身赛第二场（CCPCOJ）
// 题目：B - 暗水位
// 链接：https://cpc.csgrandeur.cn/csgoj/problemset/problem?pid=1584
// 状态：待验证
// 算法：交互、二分答案

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int l = 0;
    int r = 1e9;

    while (l < r){
        int mid = (l + r) / 2;
        cout << '?' << " " << mid << endl;

        int op;
        cin >> op;

        if (op == 1){
            r = mid;
        } else if (op == 0){
            l = mid + 1;
        }
    }

    cout << "! " << l << endl;
}

int main (){
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
