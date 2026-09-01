# DP 模板总复习

这份手册以可直接迁移的 C++ 代码为主。状态设计、转移原理和易错点详见 [动态规划复习笔记](../Knowledge/DP/动态规划复习笔记.md)。

## 0. 通用习惯

```cpp
using ll = long long;

const ll INF = (1LL << 62);
const ll NINF = -(1LL << 62);
```

常见初始化：

```cpp
dp[...] = INF;    // 最小值 DP 中不可达
dp[...] = NINF;   // 最大值 DP 中不可达
dp[...] = 0;      // 方案数为 0
dp[...] = false;  // 当前不可达
```

每次固定检查：

```text
1. dp 状态表示什么？
2. 当前状态从哪里转移？
3. 使用 max、min、加法还是逻辑或？
4. 初始合法状态和不可达状态分别是什么？
5. 按什么顺序枚举？
6. 最终答案在哪个状态？
```

从 `INF` 或 `NINF` 转移前先判断可达性，避免溢出或产生伪状态。

---

## 1. 线性 DP

### 1.1 相邻元素不能同时选择

```cpp
// dp[i]：前 i 个数中，不选相邻元素能够得到的最大和
vector <ll> dp(n + 1);

dp[0] = 0;
dp[1] = max(0LL, a[1]); // 允许一个都不选

for (int i = 2; i <= n; i ++){
    dp[i] = max(
        dp[i - 1],
        dp[i - 2] + a[i]
    );
}
```

如果题目要求至少选择一个，需要按题意单独处理全负数和初值。

选与不选拆成两个状态：

```cpp
// dp[i][0]：第 i 个不选
// dp[i][1]：第 i 个被选
dp[1][0] = 0;
dp[1][1] = a[1];

for (int i = 2; i <= n; i ++){
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    dp[i][1] = dp[i - 1][0] + a[i];
}

ll ans = max(dp[n][0], dp[n][1]);
```

### 1.2 Frog：跳一格或两格

```cpp
vector <ll> dp(n, INF);
dp[0] = 0;

for (int i = 1; i < n; i ++){
    dp[i] = min(
        dp[i],
        dp[i - 1] + abs(h[i] - h[i - 1])
    );

    if (i >= 2){
        dp[i] = min(
            dp[i],
            dp[i - 2] + abs(h[i] - h[i - 2])
        );
    }
}
```

最多跳 `k` 格：

```cpp
vector <ll> dp(n, INF);
dp[0] = 0;

for (int i = 1; i < n; i ++){
    for (int j = 1; j <= k && i - j >= 0; j ++){
        dp[i] = min(
            dp[i],
            dp[i - j] + abs(h[i] - h[i - j])
        );
    }
}
```

复杂度为 `O(nk)`。

---

## 2. 背包 DP

### 2.1 01 背包：可达性

二维版本：

```cpp
// dp[i][j]：前 i 个数能否凑出 j
dp[0][0] = true;

for (int i = 1; i <= n; i ++){
    for (int j = 0; j <= S; j ++){
        dp[i][j] = dp[i - 1][j];

        if (j >= a[i]){
            dp[i][j] |= dp[i - 1][j - a[i]];
        }
    }
}
```

一维版本：

```cpp
vector <bool> dp(S + 1, false);
dp[0] = true;

for (int i = 1; i <= n; i ++){
    for (int j = S; j >= a[i]; j --){
        dp[j] = dp[j] || dp[j - a[i]];
    }
}
```

### 2.2 01 背包：最大价值

```cpp
// dp[j]：容量不超过 j 时的最大价值
vector <ll> dp(W + 1, 0);

for (int i = 1; i <= n; i ++){
    for (int j = W; j >= w[i]; j --){
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
}
```

复杂度为 `O(nW)`，容量倒序保证每个物品最多使用一次。

### 2.3 01 背包：恰好装到指定容量

```cpp
// dp[j]：恰好装到重量 j 时的最大价值
vector <ll> dp(W + 1, NINF);
dp[0] = 0;

for (int i = 1; i <= n; i ++){
    for (int j = W; j >= w[i]; j --){
        if (dp[j - w[i]] == NINF){
            continue;
        }

        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
}
```

```text
0     = 合法状态，当前价值为 0
NINF  = 该容量根本不可达
```

### 2.4 完全背包

```cpp
vector <ll> dp(W + 1, 0);

for (int i = 1; i <= n; i ++){
    for (int j = w[i]; j <= W; j ++){
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
}
```

```text
01 背包   → 容量倒序
完全背包 → 容量正序
```

### 2.5 凑和所需的最少元素数

```cpp
// dp[i][j]：使用前 i 个数凑出 j 所需的最少元素数
for (int j = 0; j <= S; j ++){
    dp[0][j] = INF;
}
dp[0][0] = 0;

for (int i = 1; i <= n; i ++){
    for (int j = 0; j <= S; j ++){
        dp[i][j] = dp[i - 1][j];

        if (j >= a[i] && dp[i - 1][j - a[i]] != INF){
            dp[i][j] = min(
                dp[i][j],
                dp[i - 1][j - a[i]] + 1
            );
        }
    }
}
```

### 2.6 分组背包

每组最多选择一个物品：

```cpp
for (auto &group : groups){
    for (int j = W; j >= 0; j --){
        for (auto [w, v] : group){
            if (j >= w){
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
    }
}
```

循环顺序必须是“组 → 容量倒序 → 当前组物品”，防止同一组选择多个物品。

---

## 3. 状态压缩 DP

### 3.1 位运算

```cpp
(mask >> i) & 1       // 判断第 i 位
mask | (1 << i)       // 加入 i
mask & ~(1 << i)      // 删除 i
mask ^ (1 << i)       // 翻转 i
```

### 3.2 通用转移

```cpp
// dp[mask]：已经选择 mask 中元素时的最小代价
for (int mask = 0; mask < (1 << n); mask ++){
    if (dp[mask] == INF){
        continue;
    }

    for (int i = 0; i < n; i ++){
        if ((mask >> i) & 1){
            continue;
        }

        int newMask = mask | (1 << i);
        dp[newMask] = min(dp[newMask], dp[mask] + cost);
    }
}
```

复杂度为 `O(n * 2^n)`。

### 3.3 枚举所有子集

```cpp
for (int sub = mask; sub; sub = (sub - 1) & mask){
    // sub 是 mask 的非空子集
}
```

如果外层枚举所有 `mask`，总复杂度为 `O(3^n)`。

---

## 4. 区间 DP

### 4.1 通用框架

```cpp
// dp[l][r]：区间 [l, r] 的最优答案
for (int len = 2; len <= n; len ++){
    for (int l = 1; l + len - 1 <= n; l ++){
        int r = l + len - 1;

        for (int k = l; k < r; k ++){
            // 从更短区间转移
        }
    }
}
```

遍历顺序是短区间到长区间。

### 4.2 链式石子合并

```cpp
for (int i = 1; i <= n; i ++){
    pre[i] = pre[i - 1] + a[i];
    dp[i][i] = 0;
}

for (int len = 2; len <= n; len ++){
    for (int l = 1; l + len - 1 <= n; l ++){
        int r = l + len - 1;
        dp[l][r] = INF;

        for (int k = l; k < r; k ++){
            dp[l][r] = min(
                dp[l][r],
                dp[l][k]
                + dp[k + 1][r]
                + pre[r] - pre[l - 1]
            );
        }
    }
}
```

### 4.3 P1880 环形石子合并

复制一遍数组，将环断成链：

```cpp
for (int i = 1; i <= n; i ++){
    cin >> a[i];
    a[i + n] = a[i];
}

for (int i = 1; i <= 2 * n; i ++){
    pre[i] = pre[i - 1] + a[i];
    mn[i][i] = 0;
    mx[i][i] = 0;
}
```

```cpp
for (int len = 2; len <= n; len ++){
    for (int l = 1; l + len - 1 <= 2 * n; l ++){
        int r = l + len - 1;
        ll sum = pre[r] - pre[l - 1];

        mn[l][r] = INF;
        mx[l][r] = 0;

        for (int k = l; k < r; k ++){
            mn[l][r] = min(
                mn[l][r],
                mn[l][k] + mn[k + 1][r] + sum
            );

            mx[l][r] = max(
                mx[l][r],
                mx[l][k] + mx[k + 1][r] + sum
            );
        }
    }
}
```

枚举断点：

```cpp
ll ansMin = INF;
ll ansMax = 0;

for (int i = 1; i <= n; i ++){
    ansMin = min(ansMin, mn[i][i + n - 1]);
    ansMax = max(ansMax, mx[i][i + n - 1]);
}
```

### 4.4 最长回文子序列

```cpp
for (int i = 1; i <= n; i ++){
    dp[i][i] = 1;
}

for (int len = 2; len <= n; len ++){
    for (int l = 1; l + len - 1 <= n; l ++){
        int r = l + len - 1;

        if (s[l - 1] == s[r - 1]){
            dp[l][r] = dp[l + 1][r - 1] + 2;
        } else {
            dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
        }
    }
}
```

长度为 `2` 时会访问空区间，需保证相应位置初值为 `0`。

---

## 5. 序列与字符串 DP

### 5.1 LIS：`O(n^2)`

```cpp
// dp[i]：必须以 a[i] 结尾的 LIS 长度
int ans = 0;

for (int i = 1; i <= n; i ++){
    dp[i] = 1;

    for (int j = 1; j < i; j ++){
        if (a[j] < a[i]){
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    ans = max(ans, dp[i]);
}
```

### 5.2 LCS

```cpp
// dp[i][j]：s 前 i 个字符与 t 前 j 个字符的 LCS 长度
for (int i = 1; i <= n; i ++){
    for (int j = 1; j <= m; j ++){
        if (s[i - 1] == t[j - 1]){
            dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}
```

恢复一种 LCS 方案：

```cpp
int i = n;
int j = m;
string ans;

while (i > 0 && j > 0){
    if (s[i - 1] == t[j - 1]){
        ans += s[i - 1];
        i --;
        j --;
    } else if (dp[i - 1][j] > dp[i][j - 1]){
        i --;
    } else {
        j --;
    }
}

reverse(ans.begin(), ans.end());
```

### 5.3 最长公共子串

```cpp
// dp[i][j]：必须以 s[i - 1]、t[j - 1] 结尾的最长公共子串
int ans = 0;

for (int i = 1; i <= n; i ++){
    for (int j = 1; j <= m; j ++){
        if (s[i - 1] == t[j - 1]){
            dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
            dp[i][j] = 0;
        }

        ans = max(ans, dp[i][j]);
    }
}
```

### 5.4 编辑距离

```cpp
for (int i = 0; i <= n; i ++){
    dp[i][0] = i;
}

for (int j = 0; j <= m; j ++){
    dp[0][j] = j;
}

for (int i = 1; i <= n; i ++){
    for (int j = 1; j <= m; j ++){
        if (a[i - 1] == b[j - 1]){
            dp[i][j] = dp[i - 1][j - 1];
        } else {
            dp[i][j] = min({
                dp[i - 1][j - 1],
                dp[i - 1][j],
                dp[i][j - 1]
            }) + 1;
        }
    }
}
```

三个来源依次对应修改、删除和插入。

---

## 6. 网格 DP 与常见优化

### 6.1 网格最大权值路径

```cpp
dp[1][1] = a[1][1];

for (int j = 2; j <= m; j ++){
    dp[1][j] = dp[1][j - 1] + a[1][j];
}

for (int i = 2; i <= n; i ++){
    dp[i][1] = dp[i - 1][1] + a[i][1];
}

for (int i = 2; i <= n; i ++){
    for (int j = 2; j <= m; j ++){
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
    }
}
```

### 6.2 障碍物路径计数与滚动数组

```cpp
vector <ll> dp(m + 1, 0);
dp[1] = 1;

for (int i = 1; i <= n; i ++){
    for (int j = 1; j <= m; j ++){
        if (grid[i][j] == '#'){
            dp[j] = 0;
        } else if (!(i == 1 && j == 1)){
            dp[j] = dp[j] + dp[j - 1];
        }
    }
}
```

`j` 必须正序：更新前的 `dp[j]` 是上方状态，更新后的 `dp[j - 1]` 是左侧状态。

### 6.3 前缀和优化

原转移：

```cpp
dp[i] = dp[i - 1] + dp[i - 2] + ... + dp[i - k];
```

优化：

```cpp
for (int i = 1; i <= n; i ++){
    int l = max(0, i - k);
    int r = i - 1;

    dp[i] = pre[r];
    if (l > 0){
        dp[i] -= pre[l - 1];
    }

    pre[i] = pre[i - 1] + dp[i];
}
```

连续区间求和转移优先考虑前缀和。

### 6.4 单调队列优化

模型：

```text
dp[i] = max(dp[j]) + a[i]
i - k <= j <= i - 1
```

```cpp
deque <int> q;
dp[0] = 0;
q.push_back(0);

for (int i = 1; i <= n; i ++){
    while (q.size() && q.front() < i - k){
        q.pop_front();
    }

    dp[i] = dp[q.front()] + a[i];

    while (q.size() && dp[q.back()] <= dp[i]){
        q.pop_back();
    }

    q.push_back(i);
}
```

滑动区间最值转移优先考虑单调队列。

---

## 7. 树形 DP

### 7.1 父子不能同时选择

```cpp
// dp[u][0]：不选择 u 时，u 子树的最大价值
// dp[u][1]：选择 u 时，u 子树的最大价值
void dfs(int u, int fa){
    dp[u][0] = 0;
    dp[u][1] = a[u];

    for (auto v : g[u]){
        if (v == fa){
            continue;
        }

        dfs(v, u);

        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}
```

### 7.2 树上直径

```cpp
// dp[u]：从 u 向子树方向延伸的一条最长链
ll ans = 0;

void dfs(int u, int fa){
    ll mx1 = 0;
    ll mx2 = 0;

    for (auto [v, w] : g[u]){
        if (v == fa){
            continue;
        }

        dfs(v, u);
        ll len = dp[v] + w;

        if (len > mx1){
            mx2 = mx1;
            mx1 = len;
        } else if (len > mx2){
            mx2 = len;
        }
    }

    dp[u] = mx1;
    ans = max(ans, mx1 + mx2);
}
```

传给父亲的是一条最长链，更新直径时使用两条最长链之和。

### 7.3 普通树上背包

```cpp
// dp[u][j]：u 子树中恰好选择 j 个节点的最大价值
void dfs(int u, int fa){
    sz[u] = 1;

    for (int j = 0; j <= n; j ++){
        dp[u][j] = NINF;
    }

    dp[u][0] = 0;
    dp[u][1] = w[u];

    for (auto v : g[u]){
        if (v == fa){
            continue;
        }

        dfs(v, u);

        for (int j = sz[u]; j >= 0; j --){
            for (int k = 0; k <= sz[v]; k ++){
                if (dp[u][j] == NINF || dp[v][k] == NINF){
                    continue;
                }

                dp[u][j + k] = max(
                    dp[u][j + k],
                    dp[u][j] + dp[v][k]
                );
            }
        }

        sz[u] += sz[v];
    }
}
```

### 7.4 P2014 依赖型树上背包

增加虚拟根 `0`，把所有没有先修课的课程接到虚拟根。

```cpp
// dp[u][j]：必须选择 u，并在 u 子树中恰好选择 j 个节点
void dfs(int u){
    sz[u] = 1;

    for (int j = 0; j < N; j ++){
        dp[u][j] = NINF;
    }

    dp[u][1] = w[u];

    for (auto v : g[u]){
        dfs(v);

        for (int j = sz[u]; j >= 1; j --){
            for (int k = 1; k <= sz[v]; k ++){
                if (dp[u][j] == NINF || dp[v][k] == NINF){
                    continue;
                }

                dp[u][j + k] = max(
                    dp[u][j + k],
                    dp[u][j] + dp[v][k]
                );
            }
        }

        sz[u] += sz[v];
    }
}
```

```cpp
for (int i = 1; i <= n; i ++){
    int fa;
    cin >> fa >> w[i];
    g[fa].push_back(i);
}

w[0] = 0;
dfs(0);

cout << dp[0][m + 1] << '\n'; // m 门课程加虚拟根
```

### 7.5 换根：所有点的距离和

```cpp
void dfs1(int u, int fa){
    sz[u] = 1;

    for (auto v : g[u]){
        if (v == fa){
            continue;
        }

        dep[v] = dep[u] + 1;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}
```

```cpp
ans[1] = 0;
for (int i = 1; i <= n; i ++){
    ans[1] += dep[i];
}

void dfs2(int u, int fa){
    for (auto v : g[u]){
        if (v == fa){
            continue;
        }

        ans[v] = ans[u] + n - 2 * sz[v];
        dfs2(v, u);
    }
}
```

### 7.6 换根：`down / up` 最远距离

```cpp
int down[N];
int mx1[N], mx2[N], id1[N];

void dfs1(int u, int fa){
    for (auto v : g[u]){
        if (v == fa){
            continue;
        }

        dfs1(v, u);
        int len = down[v] + 1;

        if (len > mx1[u]){
            mx2[u] = mx1[u];
            mx1[u] = len;
            id1[u] = v;
        } else if (len > mx2[u]){
            mx2[u] = len;
        }
    }

    down[u] = mx1[u];
}
```

```cpp
int up[N];

void dfs2(int u, int fa){
    for (auto v : g[u]){
        if (v == fa){
            continue;
        }

        int best;
        if (id1[u] == v){
            best = mx2[u];
        } else {
            best = mx1[u];
        }

        up[v] = 1 + max(up[u], best);
        dfs2(v, u);
    }
}
```

最终答案为：

```cpp
ans[u] = max(down[u], up[u]);
```

---

## 8. DAG DP

### 8.1 记忆化 DFS 求最长路

```cpp
// dp[u]：从 u 出发最多能经过多少条边
int dfs(int u){
    if (vis[u]){
        return dp[u];
    }

    vis[u] = true;

    for (auto v : g[u]){
        dp[u] = max(dp[u], dfs(v) + 1);
    }

    return dp[u];
}
```

不能因为 `v` 已经计算过就跳过它；已经求出的 `dp[v]` 仍然需要参与转移。本写法要求图是 DAG。

### 8.2 拓扑序最长路

```cpp
queue <int> q;

for (int i = 1; i <= n; i ++){
    if (indeg[i] == 0){
        q.push(i);
    }
}

while (q.size()){
    int u = q.front();
    q.pop();

    for (auto [v, w] : g[u]){
        dp[v] = max(dp[v], dp[u] + w);

        indeg[v] --;
        if (indeg[v] == 0){
            q.push(v);
        }
    }
}
```

如果只允许从指定起点出发，除起点外应初始化为 `NINF`，并跳过不可达状态。

### 8.3 DAG 路径计数

```cpp
dp[start] = 1;

for (int u : topo){
    for (auto v : g[u]){
        dp[v] += dp[u];
    }
}
```

---

## 9. 概率与期望 DP

### 9.1 抛硬币概率

```cpp
// dp[i][j]：前 i 次实验恰好成功 j 次的概率
dp[0][0] = 1.0;

for (int i = 1; i <= n; i ++){
    for (int j = 0; j <= i; j ++){
        dp[i][j] += dp[i - 1][j] * (1.0 - p[i]);

        if (j >= 1){
            dp[i][j] += dp[i - 1][j - 1] * p[i];
        }
    }
}
```

### 9.2 期望 DP

```text
E[state] = 当前代价 + Σ(转移概率 × 后续期望)
```

```cpp
dp[n] = 0;

for (int i = n - 1; i >= 0; i --){
    dp[i] = 1 + 0.5 * dp[i + 1] + 0.5 * dp[i + 2];
}
```

如果有 `p0` 的概率停留在当前状态：

```text
E = cost + p0 * E + p1 * E1 + ...
```

移项后：

```text
E = (cost + p1 * E1 + ...) / (1 - p0)
```

---

## 10. 数位 DP

### 10.1 基础框架

```cpp
vector <int> digit;
ll memo[20][2];

ll dfs(int pos, bool limit, bool started){
    if (pos == digit.size()){
        return 1;
    }

    if (!limit && memo[pos][started] != -1){
        return memo[pos][started];
    }

    int up = limit ? digit[pos] : 9;
    ll ans = 0;

    for (int d = 0; d <= up; d ++){
        bool nxtLimit = limit && (d == digit[pos]);
        bool nxtStarted = started || (d != 0);

        ans += dfs(pos + 1, nxtLimit, nxtStarted);
    }

    if (!limit){
        memo[pos][started] = ans;
    }

    return ans;
}
```

该框架会把全前导零计为数字 `0`；题目不统计 `0` 时，需要在终止条件结合 `started` 判断。

### 10.2 数位和等于 `S`

```cpp
ll dfs(int pos, int sum, bool limit){
    if (sum > S){
        return 0;
    }

    if (pos == len){
        return sum == S;
    }

    if (!limit && memo[pos][sum] != -1){
        return memo[pos][sum];
    }

    int up = limit ? digit[pos] : 9;
    ll ans = 0;

    for (int d = 0; d <= up; d ++){
        ans += dfs(
            pos + 1,
            sum + d,
            limit && (d == digit[pos])
        );
    }

    if (!limit){
        memo[pos][sum] = ans;
    }

    return ans;
}
```

### 10.3 数字模 `m`

```cpp
ll dfs(int pos, int mod, bool limit){
    if (pos == len){
        return mod == 0;
    }

    if (!limit && memo[pos][mod] != -1){
        return memo[pos][mod];
    }

    int up = limit ? digit[pos] : 9;
    ll ans = 0;

    for (int d = 0; d <= up; d ++){
        int nxtMod = (mod * 10 + d) % m;
        ans += dfs(pos + 1, nxtMod, limit && (d == digit[pos]));
    }

    if (!limit){
        memo[pos][mod] = ans;
    }

    return ans;
}
```

### 10.4 不能连续出现两个 `1`

```cpp
ll dfs(int pos, int last, bool limit){
    if (pos == len){
        return 1;
    }

    int up = limit ? digit[pos] : 9;
    ll ans = 0;

    for (int d = 0; d <= up; d ++){
        if (last == 1 && d == 1){
            continue;
        }

        ans += dfs(
            pos + 1,
            d == 1,
            limit && (d == digit[pos])
        );
    }

    return ans;
}
```

实际使用时应为非 `limit` 状态增加记忆化；如果前导零影响题意，还要增加 `started`。

---

## 11. 股票状态机 DP

### 11.1 无限次交易

```cpp
// dp[i][0]：第 i 天结束时不持股
// dp[i][1]：第 i 天结束时持股
dp[1][0] = 0;
dp[1][1] = -a[1];

for (int i = 2; i <= n; i ++){
    dp[i][0] = max(
        dp[i - 1][0],
        dp[i - 1][1] + a[i]
    );

    dp[i][1] = max(
        dp[i - 1][1],
        dp[i - 1][0] - a[i]
    );
}

ll ans = dp[n][0];
```

### 11.2 带冷冻期

```cpp
// 0：普通不持股，1：持股，2：今天刚卖出
dp[1][0] = 0;
dp[1][1] = -a[1];
dp[1][2] = NINF;

for (int i = 2; i <= n; i ++){
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - a[i]);
    dp[i][2] = dp[i - 1][1] + a[i];
}

ll ans = max(dp[n][0], dp[n][2]);
```

### 11.3 最多 `k` 次交易

规定买入时交易次数增加 `1`：

```cpp
// dp[i][j][0]：前 i 天发起 j 次交易，当前不持股
// dp[i][j][1]：前 i 天发起 j 次交易，当前持股
dp[i][j][0] = max(
    dp[i - 1][j][0],
    dp[i - 1][j][1] + a[i]
);

dp[i][j][1] = max(
    dp[i - 1][j][1],
    dp[i - 1][j - 1][0] - a[i]
);
```

所有状态先初始化为 `NINF`，再设置第 `0` 天不持股且交易次数为 `0` 的状态：

```cpp
dp[0][0][0] = 0;
```

“在哪一步让交易次数增加”可以自行定义，但状态定义、初始化和转移必须一致。

---

## 12. 题型速查

| 题型特征 | 优先考虑 |
| --- | --- |
| 按位置依次处理前 `i` 个元素 | 线性 DP |
| 当前局面有若干种未来行为不同的状态 | 状态机 DP |
| 每个物品选或不选 | 01 背包 |
| 每种物品可以无限使用 | 完全背包 |
| 每组最多选一个物品 | 分组背包 |
| `n <= 20` 左右并描述集合状态 | 状压 DP |
| 求区间 `[l, r]` 的答案 | 区间 DP |
| 比较两个字符串前缀 | LCS、编辑距离 |
| 树上儿子信息合并到父亲 | 树形 DP |
| 子树还限制选择数量 | 树上背包 |
| 每个点都要作为根求答案 | 换根 DP |
| DAG 中由前驱更新后继 | DAG DP |
| 统计 `[0, N]` 中满足数位性质的数 | 数位 DP |
| 随机状态转移 | 概率、期望 DP |
| 连续区间求和转移 | 前缀和优化 |
| 滑动区间最大值或最小值 | 单调队列优化 |

最终要能独立说清楚：

```text
dp 表示什么
→ 从哪些状态转移
→ 为什么这样初始化
→ 为什么按这个顺序遍历
```
