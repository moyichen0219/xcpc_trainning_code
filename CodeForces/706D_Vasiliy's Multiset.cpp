// 比赛：Codeforces Round 367 (Div. 2)
// 题目：706D - Vasiliy's Multiset
// 链接：https://codeforces.com/problemset/problem/706/D
// 状态：已通过
// 算法：01 字典树、动态多重集合、最大异或

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int son[N * 32][2];
int idx = 0;
int cnt[N * 32];


void insert(int x, int val){
    int p = 0;

    for (int i = 30; i >= 0; i --){
        int bit = (x >> i) & 1;
        if (!son[p][bit]){
            son[p][bit] = ++ idx;
        }
        p = son[p][bit];
        cnt[p] += val;
    }
}

int query(int x){
    int p = 0;
    int ans = 0;

    for (int i = 30; i >= 0; i --){
        int bit = (x >> i) & 1;
        if (son[p][bit ^ 1] && cnt[son[p][bit ^ 1]] > 0){
            ans |= (1 << i);
            p = son[p][bit ^ 1];
        } else {
            p = son[p][bit];
        }
    }

    return ans;
}

void solve(){
    int q;
    cin >> q;

    insert(0, 1);

    while (q --){
        char op;
        int x;
        cin >> op >> x;
        if (op == '+'){
            insert(x, 1);
        } else if (op == '-'){
            insert(x, -1);
        } else if (op == '?'){
            cout << query(x) << '\n';
        }
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
