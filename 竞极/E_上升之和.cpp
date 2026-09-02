// 比赛：竞极比赛 2094600238127988737
// 题目：E - 上升之和
// 链接：http://47.120.23.84/contest/2094600238127988737/2094602665216524290
// 状态：待验证
// 算法：动态规划、离散化、树状数组维护前缀最大值

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll a[N];
// 记录前驱
int pre[N];
int id[N];
int stk[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        id[a[i]] = i;
    }
    int top = 0;
    // int ed = 0;
    // 5->4->2->0
    // stk : 1 1 2 2 3
    for (int i = 1; i <= n; i ++){
        int pos = lower_bound(stk + 1, stk + top + 1, a[i]) - stk;
        // cout << a[i] << ' ' << pos << ' ' << stk[pos] << '\n';
        if (pos == 1){
            pre[i] = 0;
        } else {
            pre[i] = id[pos - 1];
        }
        if (pos > top){
            top ++;
        }
        stk[pos] = a[i];
        // ed = stk[pos];
    }

    ll ans = -4e18;
    for (int i = n; i >= 0; i --){
        ll cur = a[i];
        if (pre[i] == 0){
            ans = max(ans, a[i]);
            continue;
        }
        int x = pre[i];
        while (x){
            // cout << i << ' ' << x << ' ';
            cur += a[x];
            x = pre[x];
            // cout << cur << '\n';
        }
        ans = max(ans, cur);
        // cout << '\n';
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
} */

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int a[N];
ll dp[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    ll ans = -4e18;
    for (int i = 1; i <= n; i ++){
        dp[i] = a[i];
        for (int j = 1; j < i; j ++){
            if (a[j] < a[i] && dp[j] + a[i] > dp[i]) {
                dp[i] = dp[j] + a[i];
            }
        }
        ans = max(ans, dp[i]);
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
} */

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int m;
int a[N];
ll tree[N];
ll dp[N];

int lowbit(int x){
    return x & -x;
}

// 查询：向前查询前缀最大dp
ll query(int x){
    ll res = 0;
    for (int i= x; i > 0; i -= lowbit(i)){
        res = max(res, tree[i]);
    }
    return res;
}

// 更新：在离散化位置 x 上加入 dp 值，并维护前缀最大值
void upd(int x, ll val){
    for (int i = x; i <= m; i += lowbit(i)){
        tree[i] = max(val, tree[i]);
    }
}

void solve(){

    int n;
    cin >> n;

    vector <ll> b;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        b.push_back(a[i]);
    }

    // 由于abs(a[i]) <= 1e9, 对数组a进行离散化排序得到每个数的序号
    sort(begin(b), end(b));
    b.erase(unique(begin(b), end(b)),end(b));
    m = b.size();

    // a[i] 可能有负数，那么ans初始化为-INF
    ll ans = -4e18;

    for (int i = 1; i <= n; i ++){
        // 对于每一个a[i]寻找第一个大于等于他的位置下标
        // b 是 0-based，需要 +1 转换为树状数组的 1-based 下标
        int pos = lower_bound(begin(b), end(b), a[i]) - b.begin() + 1;

        // 满足情况的最大dp[j]
        ll bst = query(pos - 1);

        // dp[i] = max(dp[j]) + a[i]
        dp[i] = bst + a[i];

        ans = max(ans, dp[i]);

        // 更新树状数组维护前缀最大值
        upd(pos, dp[i]);
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
