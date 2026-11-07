// 比赛/平台：2026 CCPC 女生专场
// 题目：L - CCPC 新赛制 2
// 链接：https://qoj.ac/contest/4613/problem/23642/statement/zh_cn
// 状态：待验证
// 算法：模拟、映射、动态统计

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    int ac = 0;
    int e = 0;
};

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    vector <node> x(n);
    vector <map <string, int>> vis(n);
    vector <map <string, int>> AC(n);
    vector <map <string, int>> mp(n + 1);

    map <char, int> mm;
    vector <char> ans;
    // 需要记录每一道题目的AC队伍，每一道题目提交过的队伍

    for (int i = 1; i <= q; i ++){
        string name;
        cin >> name;

        char c;
        cin >> c;

        string status;
        cin >> status;

        int time;
        cin >> time;

        bool is = false;
        if (time >= 240){
            is = true;
        }
        if (x[c - 'A'].ac >= 50){
            is = true;
        }
        if (is){
            mm[c] ++;
            continue;
        }

        if (vis[c - 'A'].find(name) == vis[c - 'A'].end()){
            vis[c - 'A'][name] ++;
            x[c - 'A'].e ++;
        }

        if (status == "AC" && AC[c - 'A'].find(name) == AC[c - 'A'].end()){
            x[c - 'A'].ac ++;
            AC[c - 'A'][name] ++;
        }

        if (!(x[c - 'A'].e > 0 && x[c - 'A'].ac >= 0.2 * x[c - 'A'].e)){
            if (mm.find(c) != mm.end()){
                ans.push_back(c);
            }
        } else {
            mm[c] ++;
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (auto c : ans){
        cout << c ;
    }

    if (ans.size() == 0){
        cout << '-' ;
    }

    cout << '\n';
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
