// 比赛：Codeforces Round 277.5 (Div. 2)
// 题目：489B - BerSU Ball
// 链接：https://codeforces.com/problemset/problem/489/B
// 状态：已通过
// 算法：排序、双指针、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 110;

vector <int> g[N];

int a[N], b[N];
int match[N];
bool vis[N];

bool dfs(int u){
    for (auto v : g[u]){
        if (vis[v]){
            continue;
        }

        vis[v] = true;

        // 这个点原先没有匹配到人 或者 这个点原先匹配到的人可以找到其他人和他匹配
        if (match[v] == 0 || dfs(match[v])){
            match[v] = u;
            return true;
        }
    }
    return false;
}

void solve(){
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i ++){
        cin >> b[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int i = 1;
    int j = 1;
    int ans = 0;
    while (i <= n && j <= m){
        if (abs(a[i] - b[j]) <= 1){
            ans ++;
            i ++;
            j ++;
        } else if (a[i] > b[j]) {
            j ++;
        } else if (a[i] < b[j]){
            i ++;
        }
    }
    cout << ans << '\n';
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
