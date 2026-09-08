// 比赛：The 2026 ICPC Asia East Continent Online Contest (I)
// 题目：M - Check In
// 链接：https://qoj.ac/contest/4071/problem/20028
// 状态：待验证
// 算法：集合、映射、字符串模拟

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;

    set <string> st;
    for (int i = 1; i <= n; i ++){
        string s;
        cin >> s;
        st.insert(s);
    }

    map <string, int> mp;
    for (int i = 1; i <= m; i ++){
        string s;
        cin >> s;
        if (!st.count(s)){
            cout << "WRONG" << '\n';
            continue;
        }
        if (mp.find(s) != mp.end()){
            cout << "REPEAT" << '\n';
            continue;
        } else {
            cout << "OK" << '\n';
            mp[s] ++;
            continue;
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
