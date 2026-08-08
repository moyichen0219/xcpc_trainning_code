// 比赛：2026 牛客暑期多校训练营 6（133881）
// 题目：J - Just Add and Divide - https://ac.nowcoder.com/acm/contest/133881/J
// 状态：未完成（账号未通过；当前区间加、区间和模板不符合题意）
// 分类：点修改、区间最优点对、线段树
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct tree{
    int L, R;
    ll data;
};

const int N = 1e5 + 10;
ll a[N];
ll tag[4 * N];
tree t[4 * N];

// 左儿子
int ls(int p){
    return p * 2;
}

// 右儿子
int rs(int p){
    return p * 2 + 1;
}

void push_up(int p){
    // 区间和
    t[p].data = t[ls(p)].data + t[rs(p)].data;
}

// lazy tag
void add_tag(int p, int pl, int pr, ll d){
    tag[p] += d;
    t[p].data += d * (pr - pl + 1);
}

void push_down(int p, int pl, int pr){
    if (tag[p]){
        ll mid = (pl + pr) >> 1;
        add_tag(ls(p), pl, mid, tag[p]);
        add_tag(rs(p), mid + 1, pr, tag[p]);
        tag[p] = 0;
    }
}

void build(int p, int pl, int pr){
    if (pl == pr){
        t[p].data = a[pl];
        return ;
    }
    int mid = (pl + pr) >> 1;
    build(ls(p), pl, mid);
    build(rs(p), mid + 1, pr);
    push_up(p);
}

void upd(int l, int r, int p, int pl, int pr, ll d){
    if (l <= pl && r >= pr){
        add_tag(p, pl, pr, d);
        return ;
    }
    push_down(p, pl, pr);
    ll mid = (pl + pr) >> 1;
    if (l <= mid){
        upd(l, r, ls(p), pl, mid, d);
    }
    if (r > mid){
        upd(l, r, rs(p), mid + 1, pr, d);
    }
    push_up(p);
}

// 查询
ll query(int l, int r, int p, int pl, int pr){
    ll res = 0;
    if (l <= pl && r >= pr){
        return t[p].data;
    }
    push_down(p, pl, pr);
    int mid = (pl + pr) >> 1;
    if (l <= mid){
        res += query(l, r, ls(p), pl, mid);
    }
    if (r > mid){
        res += query(l, r, rs(p), mid + 1, pr);
    }
    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    build(1, 1, n);
    while (m --){
        int op;
        cin >> op;
        if (op == 1){
            ll x, y, z;
            cin >> x >> y >> z;
            upd(x, y, 1, 1, n, z);
        } else if(op == 2){
            int x, y;
            cin >> x >> y;
            cout << query(x, y, 1, 1, n) << '\n';
        }
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
