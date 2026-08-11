// 比赛：牛客周赛 Round 156
// 题目：A - 小红找数字
// 链接：https://ac.nowcoder.com/acm/contest/138917/A
// 状态：已通过
// 算法：字符串扫描

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i ++){
        if (s[i] >= '0' && s[i] <= '9'){
            cout << s[i] << '\n';
            return ;
        }
    }
    cout << -1 << '\n';
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
