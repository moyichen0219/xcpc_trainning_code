// 比赛：Educational Codeforces Round 94 (Rated for Div. 2)
// 题目：1400C - Binary String Reconstruction
// 链接：https://codeforces.com/problemset/problem/1400/C
// 状态：已通过
// 算法：贪心、构造、字符串

/*#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    int x;
    cin >> s >> x;
    int n = s.length();
    vector <int> w(s.length() + 1, -1);
    vector <bool> vis(n + 1);
    for (int i = 0; i < s.length(); i ++){
        int pos1 = i - x + 1;
        int pos2 = i + x + 1;
        if (s[i] == '1'){
            if (pos1 >= 1 && pos2 <= n){
                if (w[pos1] == 0 && w[pos2] == 0){
                    cout << -1 << '\n';
                    return ;
                }
                if (w[pos1] == 0 && w[pos2] != 0){
                    w[pos2] = 1;
                } else if (w[pos1] != 0 && w[pos2] == 0){
                    w[pos1] = 1;
                } else {
                    if (w[pos1] != 1 && w[pos2] != 1){
                        w[pos1] = w[pos2] = 2;
                    }
                }
            } else if (pos1 >= 1 && pos2 > n){
                if (w[pos1] == 0){
                    cout << -1 << '\n';
                    return;
                }
                w[pos1] = 1;
            } else if (pos1 < 1 && pos2 <= n){
                if (w[pos2] == 0){
                    cout << -1 << '\n';
                    return;
                }
                w[pos2] = 1;
            } else {
                cout << -1 << '\n ;
                return ;
            }
        } else if (s[i] == '0'){
            if (pos1 >= 1 && pos2 <= n){
                if (w[pos1] == 1 || w[pos2] == 1){
                    cout << -1 << '\n';
                    return;
                }
                w[pos1] = w[pos2] = 0;
            } else if (pos1 >= 1 && pos2 > n){
                if (w[pos1] == 1){
                    cout << -1 << '\n';
                    return ;
                }
                w[pos1] = 0;
            } else if (pos1 < 1 && pos2 <= n){
                if (w[pos2] == 1){
                    cout << -1 << '\n';
                    return ;
                }
                w[pos2] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i ++){
        if (w[i] == 2){
            cout << 1 ;
            continue;
        } else if (w[i] == -1){
            cout << 0 ;
            continue;
        }
        cout << w[i] ;
    }
    cout << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
} */


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s;
    int x;
    cin >> s >> x;
    int n = s.length();
    vector <int> w(n + 1, -1);
    for (int i = 0; i < n; i ++){
        int pos1 = i - x + 1;
        int pos2 = i + x + 1;
        if (s[i] == '0'){
            if (pos1 >= 1){
                w[pos1] = 0;
            }
            if (pos2 <= n){
                w[pos2] = 0;
            }
        }

    }
    for (int i = 1; i <= n; i ++){
        if (s[i - 1] == '0'){
            continue;
        }
        int pos1 = i - x;
        int pos2 = i + x;
        bool ok1 = (pos1 >= 1 && w[pos1] != 0);
        bool ok2 = (pos2 <= n && w[pos2] != 0);
        if (!ok1 && !ok2){
            cout << -1 << '\n';
            return ;
        }
        if (ok1) {
            w[pos1] = 1;
        } else {
            w[pos2] = 1;
        }
    }
    for (int i = 1; i <= n; i ++){
        if (w[i] == -1){
            w[i] = 0;
        }
        cout << w[i];
    }
    cout << '\n';
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
