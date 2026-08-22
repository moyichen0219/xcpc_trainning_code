// 比赛：Codeforces Round 733 (Div. 1 + Div. 2)
// 题目：1530D - Secret Santa
// 链接：https://codeforces.com/problemset/problem/1530/D
// 状态：已通过
// 算法：贪心、构造、置换

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    // 每个点均有一个出度，有0~n-1个入度
    // 那么我反向存图
    vector <int> g[n + 1];
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        // g[i].push_back(a[i]);
        g[a[i]].push_back(i);
    }
    vector <int> b(n + 1, 0);
    vector <int> bb(n + 1, 0);
    int cnt = 0;
    vector <bool> vis_re(n + 1, false);
    vector <bool> vis_se(n + 1, false);
    for (int i = 1; i <= n; i ++){
        if (g[i].size()){
            for (auto v : g[i]){
                if (!vis_se[v]){
                    cnt ++;
                    b[v] = i;
                    bb[i] = v;
                    vis_se[v] = true;
                    vis_re[i] = true;
                    break;
                }
            }
        }
    }
    vector <int> se;
    set<int> re;
    for (int i = 1; i <= n; i ++){
        if (!vis_se[i]){
            se.push_back(i);
        }
    }
    for (int i = 1; i <= n; i ++){
        if (!vis_re[i]){
            re.insert(i);
        }
    }
    vector <int> ok;
    for (auto i : se){
        if (re.size() == 1 && *re.begin() == i){
            if (ok.size()){
                int ii = ok.back();
                int rei = b[ii];
                b[ii] = *re.begin();
                b[i] = rei;
            } else {
                int tar =  a[i];
                int ii = bb[tar];
                b[i] = tar;
                b[ii] = i;
            }
            break;
        } else {
            auto it = re.begin();
            if (i == *it){
                it ++;
            }
            b[i] = *it;
            re.erase(it);
            ok.push_back(i);
        }
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; i ++){

        cout << b[i] << ' ';
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
