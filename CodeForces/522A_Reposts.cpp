// 比赛：VK Cup 2015 - Qualification Round 1
// 题目：522A - Reposts
// 链接：https://codeforces.com/problemset/problem/522/A
// 状态：已通过
// 算法：BFS、最长链、字符串处理

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    string s;
    cin >> n;
    getline(cin, s);
    map<string, vector<string>> mp;
    for(int i = 1; i <= n; i ++){
        getline(cin, s);
        bool vis_re = false;
        bool vis_re_2 = true;
        string a = "";
        string b = "";
        int cnt = 0;
        for (int j = 0; j < s.length(); j ++){
            if (s[j] == ' '){
                cnt ++;
                continue;
            }
            if (cnt == 0){
                a += tolower(s[j]);
            }
            else if (cnt == 2){
                b += tolower(s[j]);
            }
        }
        mp[b].push_back(a);
    }
    /* if (mp.find("polycarp") == mp.end()){
        cout << 0 << '\n';
        return ;
    } */
    set <string> ss;
    queue <pair <string, int>> q;
    q.push({"polycarp", 1});
    ss.insert("polycarp");
    int ans = 1;
    while (q.size()){
        auto [u, w] = q.front();
        q.pop();
        ans = max(ans, w);
        for (auto v : mp[u]){
            if (!ss.count(v)){
                ss.insert(v);
                q.push({v, w + 1});
            }
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
