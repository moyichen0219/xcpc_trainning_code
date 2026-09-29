// 比赛：Educational Codeforces Round 12
// 题目：665E - Beautiful Subarrays
// 链接：https://codeforces.com/problemset/problem/665/E
// 状态：已通过
// 算法：前缀异或、01 字典树、子数组计数

// 找到有多少个子数组异或和大于等于k

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
int a[N];
int pre[N];
int k;

int son[N * 32][2];
int cnt[N * 32];
int idx = 0;

void insert(int x){
    int p = 0;

    for (int i = 30; i >= 0; i --){
        int bit = (x >> i) & 1;

        if (!son[p][bit]){
            son[p][bit] = ++ idx;
        }

        p = son[p][bit];
        cnt[p] ++;
    }
}

int query(int x){
    int p = 0;
    int c = 0;

    for (int i = 30; i >= 0; i --){
        int bit = (x >> i) & 1;
        int kb  = (k >> i) & 1;

        if (kb == 0){
            if (son[p][bit ^ 1]){
                c += cnt[son[p][bit ^ 1]];
            }
            p = son[p][bit];
        } else {
            p = son[p][bit ^ 1];
        }

        if (!p){
            break;
        }
    }

    // 一直相等到最后，即 XOR == k
    if (p){
        c += cnt[p];
    }

    return c;
}

void solve(){
    int n;
    cin >> n >> k;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++){
        pre[i] = pre[i - 1] ^ a[i];
    }

    insert(0);

    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        ans += query(pre[i]);
        insert(pre[i]);
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
