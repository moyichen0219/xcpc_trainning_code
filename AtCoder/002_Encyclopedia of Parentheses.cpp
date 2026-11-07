// 比赛/平台：AtCoder 典型 90 问
// 题目：002 - Encyclopedia of Parentheses
// 链接：https://atcoder.jp/contests/typical90/tasks/typical90_b
// 状态：已通过
// 算法：DFS、回溯、括号序列生成

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

/* void dfs(int l, int r, string s){
    if (l == r && l == n / 2){
        cout << s << '\n';
        return ;
    }

    if (l == 0 && r == 0){
        s += '(';
        l ++;
        dfs(l, r, s);
    } else if (l == r){
        s += '(';
        l ++;
        dfs(l, r, s);
    } else if (l > r){
        string tmp = s;

        if (l + 1 <= n / 2){
            l ++;
            dfs(l, r, tmp + '(');
            l --;
        }

        r ++;
        dfs(l, r, tmp + ')');
    }
} */

void dfs(int l, int r, string s){
    if (l == n / 2 && l == r){
        cout << s << '\n';
        return ;
    }

    if (l < n / 2){
        dfs(l + 1, r, s + '(');
    }

    if (r < l){
        dfs(l, r + 1, s + ')');
    }
}

void solve(){
    cin >> n;

    if (n % 2 == 1){
        return ;
    }

    dfs(0, 0, "");
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
