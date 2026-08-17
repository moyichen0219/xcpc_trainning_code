// 比赛：牛客周赛 Round 157
// 题目：F - 小月的纸带
// 链接：https://ac.nowcoder.com/acm/contest/139206/F
// 状态：已通过
// 算法：线段树、懒标记、区间循环移位

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    // 记录偏移量
    vector <int> pre_base(n + 2, 0);
    while (q --){
        int op;
        cin >> op;
        if (op == 1){
            // 区间偏移量 ++
            int l, r;
            cin >> l >> r;
            pre_base[l - 1] ++;
            pre_base[r] --;
        } else {
            // 字符A 0 B 1 C 2
            // （x + base） % 3 对应的字符就是最后的
            bool lst_A = false;
            int ans = 0;
            int base = 0;
            for (int i = 0; i < s.length(); i ++){
                base += pre_base[i];
                ll st;
                if (s[i] == 'A'){
                    st = 0;
                } else if (s[i] == 'B'){
                    st = 1;
                } else if (s[i] == 'C'){
                    st = 2;
                }
                int now = (st + base) % 3;
                if (now == 0){
                    if (!lst_A){
                        ans ++;
                    }
                    lst_A = true;
                } else {
                    lst_A = false;
                }
            }
            cout << ans << '\n';
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
} */


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct tree{
    // cnt[0] : A段数量
    // cnt[1] : B段数量
    // cnt[2] : C段数量
    int cnt[3];
    int lc, rc;
};

const int N = 2e5 + 10;
tree t[4 * N];
int tag[4 * N];

string s;

// 左儿子
int ls(int p){
    return p * 2;
}

// 右儿子
int rs(int p){
    return p * 2 + 1;
}

void push_up(int p){
    for (int c = 0; c < 3; c ++){
        t[p].cnt[c] = t[ls(p)].cnt[c] + t[rs(p)].cnt[c];
        if (t[ls(p)].rc == c && t[rs(p)].lc == c){
            t[p].cnt[c] --;
        }
    }
    t[p].lc = t[ls(p)].lc;
    t[p].rc = t[rs(p)].rc;
}

void add_tag(int p){
    int temp = t[p].cnt[2];
    t[p].cnt[2] = t[p].cnt[1];
    t[p].cnt[1] = t[p].cnt[0];
    t[p].cnt[0] = temp;
    t[p].lc = (t[p].lc + 1) % 3;
    t[p].rc = (t[p].rc + 1) % 3;
    tag[p] = (tag[p] + 1) % 3;
}

void push_down(int p){
    if (tag[p]){
        int x = tag[p];
        while (x --){
            add_tag(ls(p));
            add_tag(rs(p));
        }
        tag[p] = 0;
    }
}

void build(int p, int pl, int pr){
    if (pl == pr){
        int c;
        if (s[pl - 1] == 'A'){
            c = 0;
        } else if (s[pl - 1] == 'B'){
            c = 1;
        } else if (s[pl - 1] == 'C'){
            c = 2;
        }
        t[p].cnt[0] = 0;
        t[p].cnt[1] = 0;
        t[p].cnt[2] = 0;
        t[p].cnt[c] = 1;
        t[p].lc = t[p].rc = c;
        return ;
    }
    int mid = (pl + pr) >> 1;
    build(ls(p), pl, mid);
    build(rs(p), mid + 1, pr);
    push_up(p);
}

void upd(int l, int r, int p, int pl, int pr){
    if (l <= pl && r >= pr){
        add_tag(p);
        return ;
    }
    push_down(p);
    int mid = (pl + pr) >> 1;
    if (l <= mid){
        upd(l, r, ls(p), pl, mid);
    }
    if (r > mid){
        upd(l, r, rs(p), mid + 1, pr);
    }
    push_up(p);
}

void solve(){
    int n, q;
    cin >> n >> q;
    cin >> s;
    build(1, 1, n);
    while (q --){
        int op;
        cin >> op;
        if (op == 1){
            int l, r;
            cin >> l >> r;
            upd(l, r, 1, 1, n);
        } else if (op == 2){
            cout << t[1].cnt[0] << '\n';
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
