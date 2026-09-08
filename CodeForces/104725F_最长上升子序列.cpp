// 比赛：2023 年中国大学生程序设计竞赛女生专场
// 题目：104725F - 最长上升子序列
// 链接：https://codeforces.com/gym/104725/problem/F
// 状态：已通过
// 算法：构造、LIS 分层、逆序赋值

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;

vector <int> pos[N];
vector <int> g[N];
vector <int> ind(N);
vector <int> ans(N);

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1, 0);
    bool ok = true;
    int mx = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        if (a[i] > mx + 1){
            ok = false;
        }
        mx = max(mx, a[i]);
        pos[a[i]].push_back(i);
    }

    if (!ok){
        cout << -1 << '\n';
        return ;
    }

    for (int i = 1; i <= mx; i ++){
        for (int j = pos[i].size() - 1; j >= 1; j --){
            g[pos[i][j]].push_back(pos[i][j - 1]);
            ind[pos[i][j - 1]] ++;
        }
    }

    for (int i = 1; i <= mx; i ++){
        if (!pos[i].empty() && !pos[i + 1].empty()){
            g[pos[i][0]].push_back(pos[i + 1].back());
            ind[pos[i + 1].back()] ++;
        }
    }

    priority_queue <int, vector <int>, greater<int>> pq;

    for (int i = 1; i <= n; i ++){
        if (ind[i] == 0){
            pq.push(i);
        }
    }

    int lst = 1;
    while (!pq.empty()){
        int x = pq.top();
        pq.pop();
        ans[x] = lst ++;

        for (auto i : g[x]){
            ind[i] --;
            if (ind[i] == 0){
                pq.push(i);
            }
        }
    }

    for (int i = 1; i <= n; i ++){
        cout << ans[i] << ' ';
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
} */


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
vector <int> pos[N];
vector <int> ans(N);

void solve(){
    int n;
    cin >> n;

    int mx = 0;
    bool ok = true;
    for (int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        if (x > mx + 1){
            ok = false;
        }
        mx = max(mx, x);
        pos[x].push_back(i);
    }

    if (!ok){
        cout << -1 << '\n';
        return ;
    }

    int lst = 1;
    for (int i  = 1; i <= mx; i ++){
        for (int j = pos[i].size() - 1; j >= 0; j --){
            ans[pos[i][j]] = lst;
            lst ++;
        }
    }

    for (int i = 1; i <= n; i ++){
        cout << ans[i] << ' ';
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
