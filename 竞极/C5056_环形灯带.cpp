// 比赛：竞极题库
// 题目：C5056 环形灯带
// 链接：http://47.120.23.84/problems/2091929267406413826
// 状态：待验证
// 算法：字符串、环形序列、连续段

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = s + s;
    int lst = -1;
    int mx = 0;
    if (s.find('0') == string::npos){
        cout << n << '\n';
        return ;
    }
    for (int i = 0; i < s.length(); i ++){
        if (lst == -1 && s[i] == '1'){
            lst = i;
        }
        if (lst != -1 && s[i] == '0'){
            mx = max (mx, i - lst);
            lst = -1;
        }
    }
    cout << mx << '\n';
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
