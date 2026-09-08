// 比赛：The 2026 ICPC Asia East Continent Online Contest (I)
// 题目：C - Permutation Inversions
// 链接：https://qoj.ac/contest/4071/problem/20018
// 状态：待验证
// 算法：拓扑排序、优先队列、排列构造

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ull BASE = 1000003;

void solve(){
    int n, m;
    cin >> n >> m;
     vector<vector<int>> g(n + 1);
    vector<int> ind(n + 1);

    map<pair<int, int>, ull> mp;

    bool ok = true;

    for (int i = 1; i <= m; i++){
        int l, r;
        cin >> l >> r;

        int len = r - l + 1;
        ull h = 0;
        int pre = -1;
        for (int j = 1; j <= len; j++){
            int x;
            cin >> x;
            h = h * BASE + x;
            if (j >= 2 && mp.find({l, r}) == mp.end()){
                // x = b[j]
                // pre = b[j - 1]
                g[x].push_back(pre);
                ind[pre]++;
            }
            pre = x;
        }
        auto key = make_pair(l, r);
        if (mp.count(key)){
            if (mp[key] != h){
                ok = false;
            }
        }
        else{
            mp[key] = h;
        }
    }

    if (!ok){
        cout << -1 << '\n';
        return;
    }

    priority_queue<int> pq;

    for (int i = 1; i <= n; i ++){
        if (ind[i] == 0){
            pq.push(i);
        }
    }

    vector <int> ans(n + 1, -1);

    int lst = n;
    while (!pq.empty()){
        int x = pq.top();
        pq.pop();

        if (ans[x] != -1){
            cout << -1 << '\n';
            return;
        }

        ans[x] = lst;
        lst --;

        for (auto v : g[x]){
            ind[v] --;
            if (ind[v] == 0){
                pq.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i ++){
        if (ind[i] != 0){
            cout << -1 << '\n';
            return;
        }
    }

    for (int i = 1; i <= n; i ++){
        cout << ans[i] << ' ';
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
} */


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> ind(n + 1);

    for (int i = 1; i <= m; i++){
        int l, r;
        cin >> l >> r;

        int len = r - l + 1;
        int lst;
        cin >> lst;
        for (int j = 2; j <= len; j ++){
            int x;
            cin >> x;
            g[x].push_back(lst);
            ind[lst] ++;
            lst = x;
        }
    }

    priority_queue<int> pq;

    for (int i = 1; i <= n; i ++){
        if (ind[i] == 0){
            pq.push(i);
        }
    }

    vector <int> ans(n + 1, -1);

    int lst = n;
    while (!pq.empty()){
        int x = pq.top();
        pq.pop();

        if (ans[x] != -1){
            cout << -1 << '\n';
            return;
        }

        ans[x] = lst;
        lst --;

        for (auto v : g[x]){
            ind[v] --;
            if (ind[v] == 0){
                pq.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i ++){
        if (ind[i] != 0){
            cout << -1 << '\n';
            return;
        }
    }

    for (int i = 1; i <= n; i ++){
        cout << ans[i] << ' ';
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
