// 模板：动态开点线段树
// 状态：模板
// 功能：单点插入、线段树合并、第 k 小查询
// 复杂度：单点插入与查询 O(log V)，合并按实际节点数均摊

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const int M = N * 40;

struct Node{
    int ls;
    int rs;
    int sum;
}tree[M];

int tot;
int root[N];

void pushup(int p){
    tree[p].sum = tree[tree[p].ls].sum + tree[tree[p].rs].sum;
}

// 在值域x这个位置加入一个元素
void upd(int &p, int l, int r, int x){
    if (!p){
        p = ++tot;
    }

    if (l == r){
        tree[p].sum ++;
        return ;
    }

    int mid = (l + r) >> 1;

    if (x <= mid){
        upd(tree[p].ls, l, mid, x);
    } else {
        upd(tree[p].rs, mid + 1, r, x);
    }

    pushup(p);
}

int merge(int x, int y, int l, int r){
    if (!x || !y){
        return x | y;
    }

    if (l == r){
        tree[x].sum += tree[y].sum;
        return x;
    }

    int mid = (l + r) >> 1;

    tree[x].ls = merge(tree[x].ls, tree[y].ls, l, mid);
    tree[x].rs = merge(tree[x].rs, tree[y].rs, mid + 1, r);

    pushup(x);
    return x;
}


// 第k小的数
int kth(int p, int l, int r, int k){
    if (tree[p].sum < k){
        return -1;
    }

    if (l == r){
        return l;
    }

    int mid = (l + r) >> 1;

    int l_cnt = tree[tree[p].ls].sum;

    if (l_cnt >= k){
        return kth(tree[p].ls, l, mid, k);
    } else {
        return kth(tree[p].rs, mid + 1, r, k - l_cnt);
    }
}

void solve(){

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
