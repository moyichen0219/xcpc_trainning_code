// 比赛/平台：洛谷
// 题目：P2168 [NOI2015] 荷马史诗
// 链接：https://www.luogu.com.cn/problem/P2168
// 状态：已通过
// 算法：K 叉 Huffman 树、优先队列、树高统计

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    ll w;
    ll h;
    bool operator < (const node& other) const {
        if (w != other.w){
            return w > other.w;
        }
        return h > other.h;
    }
};

const int N = 1e6 + 10;

void solve(){
    ll n, k;
    cin >> n >> k;

    priority_queue <node> pq;
    for (int i = 1; i <= n; i ++){
        ll w;
        cin >> w;
        pq.push({w, 0});
    }

    while ((pq.size() - 1) % (k - 1) != 0){
        pq.push({0, 0});
    }

    ll w = 0;

    while (pq.size() > 1){
        ll cur = 0;
        ll maxh = 0;
        for (int i = 1; i <= k; i ++){
            if (!pq.empty()){
                cur += pq.top().w;
                maxh = max(pq.top().h, maxh);
                pq.pop();
            } else {
                break;
            }
        }

        pq.push({cur, maxh + 1});
        w += cur;
    }

    cout << w << '\n' << pq.top().h << '\n';
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
