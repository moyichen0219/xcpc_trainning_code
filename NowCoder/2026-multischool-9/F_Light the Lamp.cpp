// 比赛：2026 牛客暑期多校训练营 9
// 题目：F - Light the Lamp
// 链接：https://ac.nowcoder.com/acm/contest/133884/F
// 状态：未完成
// 算法：序列、构造（草稿）

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int i = 1; i < n; i ++){
        if (a[i] + 1 != a[i + 1] && a[i] - 1 != a[i + 1]){
            cout << -1 << '\n';
            return ;
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
