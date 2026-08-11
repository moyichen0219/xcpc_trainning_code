// 比赛：牛客周赛 Round 156
// 题目：B - 小红的回文串
// 链接：https://ac.nowcoder.com/acm/contest/138917/B
// 状态：已通过
// 算法：字符串、枚举、双指针

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
string s;
bool check (char c){
    int l = 0;
    int r = n - 1;
    while (l <= r){
        while (l <= r && s[l] == c){
            l ++;
        }
        while (l <= r && s[r] == c){
            r --;
        }
        if (l > r){
            return true;
        }
        if (s[l] != s[r]){
            return false;
        }
        l ++;
        r --;
    }
    return true;
}

void solve(){
    cin >> n >> s;
    int cnt = 0;
    for (char c = 'a'; c <= 'z'; c ++){
        if (s.find(c) == string:: npos){
            continue;
        }
        if (check (c)){
            cnt ++;
        }
    }
    cout << cnt << '\n';
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
