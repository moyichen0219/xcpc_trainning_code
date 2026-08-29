// 模板：__int128 输入输出
// 状态：模板
// 复杂度：O(十进制位数)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

i128 read(){
    string s;
    cin >> s;
    i128 x = 0;
    int st = 0;
    bool neg = false;
    if (s[0] == '-'){
        neg = true;
        st = 1;
    }
    for (int i = st; i < (int)s.size(); i++){
        x = x * 10 + (s[i] - '0');
    }
    return neg ? -x : x;
}

void print(i128 x){
    if (x == 0){
        cout << 0;
        return;
    }
    if (x < 0){
        cout << '-';
        x = -x;
    }
    string s;
    while (x){
        s.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

void solve(){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--){
        solve();
    }
    return 0;
}
