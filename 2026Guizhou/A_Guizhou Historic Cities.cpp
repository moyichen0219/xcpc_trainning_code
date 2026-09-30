// 比赛：The 2026 ICPC Guizhou Provincial Contest
// 题目：A - Guizhou Historic Cities
// 链接：https://qoj.ac/contest/4121/problem/20284
// 状态：待验证
// 算法：字符串匹配、枚举

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string o[] = {"fu quan", "an shun", "zhi jin", "si nan", "an long", "da fang", "pu ding"
    , "li ping", "shi qian", "zhen feng"};

    string s;
    getline(cin , s);

    for (auto ss : o){
        if (ss == s){
            cout << "Yes" << '\n';
            return ;
        }
    }

    cout << "No" << '\n';
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
