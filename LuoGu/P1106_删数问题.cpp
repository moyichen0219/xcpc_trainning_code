// 比赛/平台：洛谷
// 题目：P1106 删数问题
// 链接：https://www.luogu.com.cn/problem/P1106
// 状态：已通过
// 算法：单调栈、贪心、前导零

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;

    int n;
    cin >> n;

    stack <char> stk;
    int cnt = n;

    for (int i = 0; i < s.length(); i ++){
        while (!stk.empty() && stk.top() > s[i] && cnt > 0){
            stk.pop();
            cnt --;
        }

        stk.push(s[i]);
    }

    while (cnt > 0){
        stk.pop();
        cnt --;
    }

    string ans = "";
    while (stk.size()){
        ans += stk.top();
        stk.pop();
    }

    reverse(ans.begin(), ans.end());

    int pos = 0;
    while (pos < ans.size() && ans[pos] == '0'){
        pos ++;
    }

    if (pos == ans.size()){
        cout << 0 << '\n';
        return ;
    }

    cout << ans.substr(pos) << '\n';
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
