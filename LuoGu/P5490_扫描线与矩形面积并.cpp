// 比赛：洛谷模板
// 题目：P5490 - 扫描线与矩形面积并
// 链接：https://www.luogu.com.cn/problem/P5490
// 状态：已通过
// 算法：扫描线、离散化、线段树、矩形面积并

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;

struct Event{
    // 当前扫描到的x坐标
    ll x;
    // 需要修改的y区间
    ll y1, y2;
    // 进入+1/离开-1
    int k;

    // 按x从小到大扫描
    bool operator <(const Event & a)const {
        if(x != a.x){
            return x < a.x;
        }
        return k > a.k;
    }
};

// 线段树维护离散化之后的y小区间
struct Node{
    // 当前节点维护的区间编号
    int l, r;
    // 覆盖次数
    int cnt;
    // 当前节点贡献的真实y长度
    ll len;
};

// 所有扫描线事件
vector <Event> e;
// 离散化的y轴坐标
vector <ll> ys;
Node tree[N * 4];

void pushup(int p){
    // 当前区间被覆盖
    if (tree[p].cnt){
        // 真实长度：ys[r+1]-ys[l]
        tree[p].len = ys[tree[p].r + 1] - ys[tree[p].l];
    }else {
        // 没覆盖，看孩子
        if (tree[p].l == tree[p].r){
            // 叶子节点，没有孩子
            tree[p].len = 0;
        }else {
            // 非叶子，看左右子树
            tree[p].len = tree[p << 1].len + tree[p << 1 | 1].len;
        }
    }
}

// n个y点，形成n-1个小区间
void build(int p, int l, int r){
    tree[p].l = l;
    tree[p].r = r;

    // 初始没有矩形覆盖
    tree[p].cnt = 0;
    tree[p].len = 0;

    if (l == r){
        return ;
    }

    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}

void upd(int p, int l, int r, int L, int R, int k){
    if (L <= l && r <= R){
        tree[p].cnt += k;
        pushup(p);
        return ;
    }

    int mid = (l + r) >> 1;

    // 修改左孩子
    if (L <= mid){
        upd(p << 1, l, mid, L, R, k);
    }

    // 修改右孩子
    if (R > mid){
        upd(p << 1 | 1, mid + 1, r, L, R, k);
    }

    // 子节点变化，更新当前节点
    pushup(p);
}


void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 进入矩形，加入y边界
        e.push_back({x1, y1, y2, 1});
        // 离开矩形，删除y边界
        e.push_back({x2, y1, y2, -1});
        ys.push_back(y1);
        ys.push_back(y2);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    // 按x排序，模拟扫描线从左往右移动
    sort(e.begin(), e.end());

    build(1, 0, ys.size() - 2);

    ll ans = 0;

    for (int i = 0 ; i < e.size(); i ++){
        // tree[1].len：当前x位置覆盖的y长度
        // 先计算上一段的面积
        if (i){
            ll dx = e[i].x - e[i - 1].x;
            ans += dx * tree[1].len;
        }

        // 找到y对应离散后的编号
        int y1 = lower_bound(ys.begin(), ys.end(), e[i].y1) - ys.begin();
        int y2 = lower_bound(ys.begin(), ys.end(), e[i].y2) - ys.begin();

        upd(1, 0, ys.size() - 2, y1, y2 - 1, e[i].k);
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
