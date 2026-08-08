// 比赛：2026 牛客暑期多校训练营 7（133882）
// 题目：D - Tenkaichi Budōkai - https://ac.nowcoder.com/acm/contest/133882/D
// 状态：已通过（账号评测状态已于 2026-08-08 核对）
// 分类：排列、删除过程、树状数组

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, x;
    cin >> n >> x;
    vector <int> a(n + 1);
    vector <int> b(n + 1);
    bool ok1 = false;
    bool ok2 = false;
    map <int, int> aa;
    map <int, int> bb;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        aa[a[i]] = i;
        if (i == n && a[i] == x){
            ok1 = true;
        }
    }
    for (int i = 1; i <= n; i ++){
        cin >> b[i];
        bb[b[i]] = i;
        if (i == n && b[i] == x){
            ok2 = true;
        }
    }
    if (!ok1 && !ok2){
        cout << "NO" << '\n'; 
        return ;
    }
    cout << "YES" << '\n';
    int cnta = 1;
    int cntb = 1;
    // a[cnta] = m
    // b[cntb] = n
    while (aa.size() >= 1){
        while (aa.find(a[cnta]) == aa.end()){
            cnta ++;
        }
        while (bb.find(b[cntb]) == bb.end()){
            cntb ++;
        }
        if (aa[b[cntb]] < bb[a[cnta]]){
            aa.erase(a[cnta]);
            bb.erase(a[cnta]);

        } else {
            aa.erase(b[cntb]);
            bb.erase(b[cntb]);

        }
    }
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while ( t--){
        solve();
    }
    return 0;
} */

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll t1[N];
ll t2[N];
int n, x;

int lowbit (int x){
    return x & -x;
}

void update (ll k, ll x, int op){
    if (op == 1){
        for (int i = k; i <= n; i += lowbit(i)){
            t1[i] += x;
        }
    } else {
        for (int i = k; i <= n; i += lowbit(i)){
            t2[i] += x;
        }
    }
}

// getsum(pos, op)
ll getsum (int k, int op){
    ll res = 0;
    if (op == 1){
        for (int i = k; i > 0; i -= lowbit(i)){
            res += t1[i];
        }
    } else {
        for (int i = k; i > 0; i -= lowbit(i)){
            res += t2[i];
        }
    }
    return res;
}

void solve() {
    cin >> n >> x;
    vector <int> P(n + 1);
    vector <int> Q(n + 1);

    vector <int> posP(n + 1);
    vector <int> posQ(n + 1);

    // 使用树状数组进行动态更新位置下标
    for (int i = 1; i <= n; i ++){
        cin >> P[i];
        posP[P[i]] = i;
        update(i, 1, 1);
    }
    for (int i = 1; i <= n; i ++){
        cin >> Q[i];
        posQ[Q[i]] = i;
        update(i, 1, 2);
    }

    // u : P
    // v : Q
    // 如果Q序列中u数值的位置大于P序列中v数值的位置，那么保留u，删除v；反之，保留v，删除u
    
    // 下标
    int p = 1;
    int q = 1;
    vector <int> ans;
    for (int i = 1; i <= n - 1; i ++){
        // 如果没有被删除，那么getsum(p, 1) - getsum(p - 1, 1)为1
        while (p <= n && getsum(p, 1) - getsum(p - 1, 1) == 0){
            p ++;
        }
        while (q <= n && getsum(q, 2) - getsum(q - 1, 2) == 0){
            q ++;
        }
        
        // 数值
        int u = P[p];
        int v = Q[q];
        int del;

        // 僵局
        if (u == v){
            cout << "NO" << '\n';
            return;
        }

        // 是否等于x，等于就删除另一个
        if (u == x){
            del = v;
        } else if (v == x){
            del = u;
        } else {
            // 数值当前在P和Q序列中的位置
            int cpos_u = getsum(posQ[u], 2);  // u在Q中的位置
            int cpos_v = getsum(posP[v], 1);  // v在P中的位置
            if (cpos_u > cpos_v){
                del = v;
            } else {
                del = u;
            }
        }

        // 更新删除值
        ans.push_back(del);
        update(posQ[del], -1, 2);
        update(posP[del], -1, 1);
    }

    if (getsum(posQ[x], 2) - getsum(posQ[x] - 1, 2) == 0){
        cout << "NO" << '\n';
        return ;
    }

    cout << "YES" << '\n';
    for (auto i : ans){
        cout << i << ' ';
    }
    cout << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

// ? ?
