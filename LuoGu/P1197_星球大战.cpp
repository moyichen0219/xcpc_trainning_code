// 平台：洛谷
// 题目：P1197 [JSOI2008] 星球大战
// 链接：https://www.luogu.com.cn/problem/P1197
// 状态：已通过
// 算法：离线逆序、并查集、动态连通性

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 10;
vector <int> g[N];
bool attacked[N];
int pre[N];

void init (int n){
    for (int i = 0; i < n; i ++){
        pre[i] = i;
    }
}

int root(int u){
    return pre[u] == u ? u : pre[u] = root(pre[u]);
}

bool isConnect(int u, int v){
    if (root(u) != root(v)){
        return false;
    } else {
        return true;
    }
}

void merge(int u, int v){
    int rtu = root(u);
    int rtv = root(v);
    if (rtu != rtv){
        pre[rtu] = rtv;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    init (n);
    for (int i = 1; i <= m; i ++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int k;
    cin >> k;

    vector <int> del(k + 1);
    for (int i = 1; i <= k; i ++){
        cin >> del[i];
        attacked[del[i]] = 1;
    }

    int cnt = n - k;
    for (int i = 0; i < n; i ++){
        if (!attacked[i]){
            for (auto v : g[i]){
                if (!attacked[v]){
                    if (!isConnect(i, v)){
                        cnt --;
                    }
                    merge(i, v);
                }
            }
        }
    }

    vector <int> ans;
    ans.push_back(cnt);

    for (int i = k; i >= 1; i --){
        attacked[del[i]] = 0;
        cnt ++;
        for (auto v : g[del[i]]){
            if (!attacked[v]){
                if (!isConnect(del[i], v)){
                    cnt --;
                }
                merge(v, del[i]);
            }
        }
        ans.push_back(cnt);
    }

    for (int i = ans.size() - 1; i >= 0; i --){
        cout << ans[i] << '\n';
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
