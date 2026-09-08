// 比赛：The 2026 ICPC Asia East Continent Online Contest (I)
// 题目：A - Recall
// 链接：https://qoj.ac/contest/4071/problem/20016
// 状态：待验证
// 算法：离线处理、栈、字符串构造

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    string ans = "";

    vector <pair<char, int>> ops;
    for (int i = 1; i <= n; i ++){
        char op;
        int x;
        cin >> op >> x;
        ops.push_back({op, x});
    }

    vector <int> ne(n, -1);

    map <int, int> m;
    for (int i = n - 1; i >= 0; i --){
        auto [op, x] = ops[i];

        if (op == 'T'){
            if (!m.count(x)){
                m[x] = i;
            }
        } else if (op == 'F'){
            m.erase(x);
        } else if (op == '+') {
            if (m.count(x)){
                ne[i] = m[x];
            } else {
                ne[i] = i;
            }
            m.erase(x);
        }
    }

    stack <pair<int, int>> stk;

    for (int i = 0; i < n; i ++){
        auto [op, x] = ops[i];

        if (op == '+'){
            stk.push({x, ne[i]});
            ans += '+';
        } else {
            ans += '?';
        }

        while (!stk.empty() && stk.top().second <= i){
            stk.pop();
            ans += '-';
        }
    }

    cout << ans << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t --){
        solve();
    }
    return 0;
}
