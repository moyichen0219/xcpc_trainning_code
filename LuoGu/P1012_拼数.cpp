// 比赛：NOIP 1998 提高组
// 题目：P1012 - 拼数
// 链接：https://www.luogu.com.cn/problem/P1012
// 状态：已通过
// 算法：贪心排序、字符串拼接

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <string> s(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> s[i] ;
    }
    sort(s.begin() + 1, s.end(), [](const string& a, const string& b){
        return a + b > b + a;
    });

    for (int i = 1;  i <= n; i ++){
        cout << s[i];
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
