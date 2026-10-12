// 比赛/平台：CCPC2026 网络热身赛第二场（CCPCOJ）
// 题目：E - 双泊对照
// 链接：https://cpc.csgrandeur.cn/csgoj/problemset/problem?pid=1587
// 状态：待验证
// 算法：排序、多重集合、双角色通信
// 备注：程序通过命令行参数选择运行角色。

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(int r){
    if (r == 0){
        int n;
        cin >> n;

        vector <ll> a(n + 1);

        for (int i = 1; i <= n; i ++){
            cin >> a[i];
        }

        cout << n << endl;
        sort(a.begin() + 1, a.end());
        for (int i = 1; i <= n; i ++){
            cout << a[i] << ' ';
        }
        cout << endl;

        int ans;
        cin >> ans;

        cout << ans << endl;
    } else if (r == 1){
        int n;
        cin >> n;

        multiset <ll> s1;
        for (int i = 1; i <= n; i ++){
            ll x;
            cin >> x;
            s1.insert(x);
        }

        cin >> n;
        multiset <ll> s2;
        for (int i = 1; i <= n; i ++){
            ll x;
            cin >> x;
            s2.insert(x);
        }

        if (s1 == s2){
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

int main (int argc, char *argv[]){
    int r = atoi(argv[1]);
    int t = 1;
    while (t --){
        solve(r);
    }
    return 0;
}
