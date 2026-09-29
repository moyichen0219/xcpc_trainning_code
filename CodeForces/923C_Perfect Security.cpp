// 比赛：VK Cup 2018 - Round 1
// 题目：923C - Perfect Security
// 链接：https://codeforces.com/problemset/problem/923/C
// 状态：已通过
// 算法：01 字典树、贪心、可删除多重集合

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5 + 10;
int son[N * 32][2];
int cnt[32 * N];
int idx = 0;
int a[N];

void insert(int x, int val){
    int p = 0;

    for (int i = 30; i >= 0; i --){
        int bit = (x >> i ) & 1;
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
        if (son[p][bit] && cnt[son[p][bit]]){
            p = son[p][bit];
        } else {
            ans |= (1 << i);
            p = son[p][bit ^ 1];
        }
        cnt[p] --;
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++){
        int x; cin >> x;
        insert(x, 1);
    }

    for (int i = 1; i <= n; i ++){
        cout << query(a[i]) << ' ';
    }

    cout << '\n';
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
