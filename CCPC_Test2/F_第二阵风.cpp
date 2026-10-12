// 比赛/平台：CCPC2026 网络热身赛第二场（CCPCOJ）
// 题目：F - 第二阵风
// 链接：https://cpc.csgrandeur.cn/csgoj/problemset/problem?pid=1588
// 状态：待验证
// 算法：单调栈、有序集合、排列贡献统计

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];
int R[N];
int L[N];

int LL[N];
int RR[N];

int pos[N];

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++){
        pos[a[i]] = i;
    }

    stack <int> stk;
    for (int i = 1; i <= n; i ++){
        while (!stk.empty() && a[i] >= a[stk.top()]){
            stk.pop();
        }
        L[i] = stk.empty() ? 0 : stk.top();
        stk.push(i);
    }

    while (stk.size()){
        stk.pop();
    }

    for (int i = n; i >= 1; i --){
        while (!stk.empty() && a[i] >= a[stk.top()]){
            stk.pop();
        }
        R[i] = stk.empty() ? n + 1 : stk.top();
        stk.push(i);
    }

    /* set <int> s;
    for (int i = 1; i <= n; i ++){
        if (L[i] != 0){
            s.erase(a[L[i]]);
        }

        int x = 0;
        auto it = s.end();
        if (!s.empty()){
            it = s.lower_bound(a[i]);
        }
        if (it != s.end()){
            x = pos[*it];
        }
        LL[i] = x;

        if (L[i] != 0){
            s.insert(a[L[i]]);
        }
        s.insert(a[i]);
    }

    set <int> ss;
    for (int i = n; i >= 1; i --){
        if (R[i] != n + 1){
            ss.erase(a[R[i]]);
        }

        int x = n + 1;
        auto it = ss.end();
        if (!ss.empty()){
            it = ss.lower_bound(a[i]);
        }
        if (it != ss.end()){
            x = pos[*it];
        }
        RR[i] = x;

        if (R[i] != n + 1){
            ss.insert(a[R[i]]);
        }
        ss.insert(a[i]);
    } */

    set <int> s;
    s.insert(0);
    s.insert(n + 1);
    for (int i = n; i >= 1; i --){
        // 下标为x
        int x = pos[i];

        LL[x] = 0;
        RR[x] = n + 1;

        auto it = s.lower_bound(x);

        int l = *prev(it);
        int r = *it;

        if (l != 0){
            LL[x] = *prev(prev(it));
        }

        if (r != n + 1){
            RR[x] = *next(it);
        }

        s.insert(x);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        if (L[i] != 0){
            ans += 1ll * (L[i] - LL[i]) * (i - L[i]) * (R[i] - i);
        }
        if(R[i] != n + 1){
            ans += 1ll * (RR[i] - R[i]) * (i - L[i]) * (R[i] - i);
        }
    }

    /* for (int i = 1; i <= n; i ++){
        cout << L[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n; i ++){
        cout << R[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n; i ++){
        cout << LL[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n; i ++){
        cout << RR[i] << ' ';
    } */

    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t= 1;
    while (t --){
        solve();
    }
    return 0;
}
