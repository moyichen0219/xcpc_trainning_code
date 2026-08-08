// 比赛：2026 牛客暑期多校训练营 6（133881）
// 题目：G - Game on a Graph - https://ac.nowcoder.com/acm/contest/133881/G
// 状态：未通过（本地样例通过，但账号评测状态无 AC）
// 分类：图、邻接关系、集合去重
/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;


void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int>> g(n + 1, vector <int>());
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); 
        g[v].push_back(u);
    }
    set <int> s;
    for (int i = 1; i <= k; i ++){
        int x;
        cin >> x;
        s.insert(x);
    }
    vector <int> ans;
    for (auto u : s){
        for (auto v : g[u]){
            ans.push_back(v);
        }
    }
    vector <int> tar;
    sort(begin(ans), end(ans));
    ans.erase(unique(begin(ans), end(ans)), end(ans));
    for (auto u : ans){
        if (g[u].size() == 3){
            bool vis = false;
            int x = 0, y = 0, z = 0;
            for (auto v : g[u]){
                if (s.find(v) != s.end()){
                    if (x != 0){
                        y = v;
                        vis = true;
                        break;
                    } else {
                        x = v;
                    }
                } else {
                    z = v;
                }
            }
            if (vis){
                tar.push_back(z);
            }
        }
    }
    for (auto i : tar){
        ans.push_back(i);
    }
    sort(begin(ans), end(ans));
    ans.erase(unique(begin(ans), end(ans)), end(ans));
    vector <int> ans1;
    for (auto i : ans){
        if (s.find(i) != s.end()){
            continue;
        }
        ans1.emplace_back(i);
        // cout << i << ' ';
    }
    cout << ans1.size() << '\n';
    for (int &i : ans1) cout << i << ' ';
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
} */

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;


void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int>> g(n + 1, vector <int>());
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); 
        g[v].push_back(u);
    }
    set <int> s;
    for (int i = 1; i <= k; i ++){
        int x;
        cin >> x;
        s.insert(x);
    }
    vector <int> ans;
    for (auto u : s){
        for (auto v : g[u]){
            ans.push_back(v);
        }
    }
    vector <int> tar;
    sort(begin(ans), end(ans));
    ans.erase(unique(begin(ans), end(ans)), end(ans));
    for (int i = 1; i <= n; i++){
        int x = 0;
        if (g[i].size() >= 2){
            bool vis1 = false;
            bool vis2 = false;
            for (auto u : g[i]){
                if (s.find(u) != s.end()){
                    if (!vis1){
                        vis1 = true;
                    } else {
                        vis2 = true;
                    }
                } else {
                    x = u;
                }
            }
            if (vis1 && vis2 && x){
                tar.push_back(x);
            }
        }
    }
    for (auto i : tar){
        ans.push_back(i);
    }
    sort(begin(ans), end(ans));
    ans.erase(unique(begin(ans), end(ans)), end(ans));
    vector <int> ans1;
    for (auto i : ans){
        if (s.find(i) != s.end()){
            continue;
        }
        ans1.emplace_back(i);
        // cout << i << ' ';
    }
    cout << ans1.size() << '\n';
    for (int &i : ans1) cout << i << ' ';
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
} */
 # include <iostream>
# include <vector>
# include <algorithm>
# include <unordered_set>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int>> G(n + 1, vector<int>());
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    unordered_set <int> st;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    vector <int> next;
    for (int i : st) {
        for (int &j : G[i]) {
            if (st.find(j) == st.end()) next.emplace_back(j);
        }
    }
    sort(next.begin(), next.end());
    next.erase(unique(next.begin(), next.end()), next.end());
    vector <int> near;
    for (int &i : next) {
        if (G[i].size() == 3) {
            int x = 0, y = 0, z = 0;
            for (int &j : G[i]) {
                if (st.find(j) == st.end()) z = j;
                else {
                    if (x) y = j;
                    else x = j;
                }
            }
            if (x && y && z) near.emplace_back(z);
        }
    }
    for (int &i : near) next.emplace_back(i);
    sort(next.begin(), next.end());
    next.erase(unique(next.begin(), next.end()), next.end());
    vector <int> ans;
    for (int &i : next) if (st.find(i) == st.end()) ans.emplace_back(i);
    cout << ans.size() << '\n';
    for (int &i : ans) cout << i << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
