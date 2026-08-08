// 比赛：牛客周赛 Round 155（138240）
// 题目：C - 小月的密码锁 - https://ac.nowcoder.com/acm/contest/138240/C
// 状态：未完成（账号未通过；仅有前后缀统计框架）
// 分类：字符串、前后缀统计
// 创建：MYC，2026/8/3

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 10;
int pre[N][5];
int suf[N][5];

int f(char c){
    if (c == 'A'){
        return 1;
    } else if (c == 'B'){
        return 2;
    } else if (c == 'C'){
        return 3;
    } else if (c == 'D'){
        return 4;
    } else if (c == 'E'){
        return 5;
    }
}

void solve(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < n; i ++){
        for (int c = 1; c <= 5; c ++){
            for (int k = 1; k <= 5; k ++){
                
            }
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
