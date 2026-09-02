# E - 上升之和题解

对应源码：[E_上升之和.cpp](./E_上升之和.cpp)

## 上升之和

### 1. 题意解析

给定一个长度为 `n` 的整数数组 $a$，要求选择一个非空的严格上升子序列，使所选元素之和最大。

### 2. 解法推导

先考虑朴素的 $O$($n^2$) 做法。

我们定义：`dp[i]` 表示 以 `a[i]` 结尾的严格上升子序列的最大元素和。

由此，可以得到 DP 转移:

对于位置 i，如果存在位置 j 满足：`j < i && a[j] < a[i]`，那么可以将 `a[i]` 接在以 `a[j]` 结尾的严格上升子序列后面，因此有：

        dp[i] = max(dp[i], dp[j] + a[i]);

同时，`a[i]` 本身也可以作为一个长度为 $1$ 的严格上升子序列，因此初始化：

        dp[i] = a[i];

那么，我们可以得到这个 $n^2$ 的做法代码：
```cpp
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
```

但是题目中：$n ≤ 2 × 10^5$，因此 $O$($n^2$) 的做法显然无法通过。

重新观察状态转移：`dp[i] = max(dp[j]) + a[i]`，要求 `j < i && a[j] < a[i]`。

可以将问题转换成：

> 在所有已经处理过的元素中，找到所有满足 `a[j] < a[i]` 的位置 `j`，并求其中最大的 `dp[j]`。

也就是一个**值域上的前缀最大值查询**。

解决这个问题，我们可以使用**树状数组**或者**权值线段树**进行维护。

单次查询和更新的时间复杂度均为：$O$($log n$)

因此，总时间复杂度可以由 $O$($n^2$) 优化到 $O$($log n$)。

### 3.代码

本题解采用树状数组进行前缀最大值维护。

```cpp
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
```

### 4. 复杂度分析

离散化需要排序，时间复杂度为 $O$($n log n$)。

对于每个 $a[i]$：
- 二分查找离散化位置：$O$($log n$)
- 树状数组查询前缀最大值：$O$($log n$)
- 树状数组单点更新：$O$($log n$)

因此总时间复杂度为：$O$($n log n$)

空间复杂度为：$O$($n$)
