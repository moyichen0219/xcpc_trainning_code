// 比赛：AtCoder Beginner Contest 190
// 题目：C - Bowls and Dishes
// 链接：https://atcoder.jp/contests/abc190/tasks/abc190_c
// 状态：已通过
// 算法：DFS、回溯、状态枚举

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k;
int ans = 0;

vector <pair<int, int>> con;
vector <pair<int, int>> choice;

vector <int> cnt;

void dfs(int p){
    if (p == k + 1){
        int res = 0;
        for (int i = 1; i <= m; i ++){
            auto [a, b] = con[i];
            if (cnt[a] && cnt[b]){
                res ++;
            }
        }
        ans = max(ans, res);
        return ;
    }
    cnt[choice[p].first] ++;
    dfs(p + 1);
    cnt[choice[p].first] --;
    cnt[choice[p].second] ++;
    dfs(p + 1);
    cnt[choice[p].second] --;
}

void solve(){
    cin >> n >> m;
    con.resize(m + 1);
    for (int i = 1; i <= m; i ++){
        cin >> con[i].first >> con[i].second;
    }
    cin >> k;
    choice.resize(k + 1);
    for (int i = 1; i <= k; i ++){
        cin >> choice[i].first >> choice[i].second;
    }
    cnt.assign(n + 1, 0);
    ans = 0;
    dfs(1);
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
