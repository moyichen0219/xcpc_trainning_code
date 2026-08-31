# XCPC 代码仓库

本仓库按 **平台 → 比赛/题号** 归档，共有 189 个 C++ 源文件：173 个题目及历史实现文件和 16 个算法模板。题目链接、代码状态与源码入口汇总如下。

## 状态说明

- `已通过`：平台账号显示该题已经通过；若仓库文件并非完整版本，会在备注中单独说明。
- `未通过`：实现形态较完整，但平台账号显示该题尚未通过。
- `待验证`：已有完整实现，但仓库中没有可核对的在线评测记录。
- `未完成`：空框架、部分实现，或实现与题意不符。
- `模板`：通用算法实现，不对应单一在线评测题目。

> 整理时未删除 `.exe`、`.cph`、`.idea` 或 `.vscode` 等已有文件。

## 当前验证结果

- 上一轮归档的 180 个 `.cpp` 文件通过 `g++ -std=c++17 -fsyntax-only` 语法检查；本轮新增的 7 道竞极题和 2 个模板按用户要求仅做轻量静态整理，不重复全仓编译。
- 已完成的样例或构造回归记录为：35 个文件、64 组检查，64/64 组通过。本轮不增加批量运行回归计数；P2662 与 P3868 的本地边界缺陷均已单独标注。
- 样例通过不等于在线评测通过；洛谷、Codeforces 与 AtCoder 状态最近于 2026-08-29 核对，新一批竞极源码于 2026-08-31 按本地语义归档且状态待验证，牛客多校 8 H 于 2026-08-25 复核，QOJ 状态于 2026-08-24 核对，码题集状态由用户于 2026-08-22 确认，其余牛客状态于 2026-08-21 核对。

## AtCoder

| 比赛 | 题目 | 代码 | 状态 | 主题 |
| --- | --- | --- | --- | --- |
| 算法与数学 演习问题集 | [060 - Stones Game 1](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_az) | [060_Stones Game 1.cpp](./AtCoder/060_Stones%20Game%201.cpp) | 已通过 | 博弈论、数学 |
| Educational DP Contest | [A - Frog 1](https://atcoder.jp/contests/dp/tasks/dp_a) | [DP_A_Frog 1.cpp](./AtCoder/DP_A_Frog%201.cpp) | 已通过 | 动态规划、线性 DP |
| Educational DP Contest | [B - Frog 2](https://atcoder.jp/contests/dp/tasks/dp_b) | [DP_B_Frog 2.cpp](./AtCoder/DP_B_Frog%202.cpp) | 已通过 | 动态规划、线性 DP |
| Educational DP Contest | [C - Vacation](https://atcoder.jp/contests/dp/tasks/dp_c) | [DP_C_Vacation.cpp](./AtCoder/DP_C_Vacation.cpp) | 已通过 | 动态规划、状态转移 |
| ABC 085 | [D - Katana Thrower](https://atcoder.jp/contests/abc085/tasks/abc085_d) | [ABC085_D_Katana Thrower.cpp](./AtCoder/ABC085_D_Katana%20Thrower.cpp) | 已通过（账号；本地需修正） | 贪心、排序 |
| ABC 121 | [C - Energy Drink Collector](https://atcoder.jp/contests/abc121/tasks/abc121_c) | [ABC121_C_Energy Drink Collector.cpp](./AtCoder/ABC121_C_Energy%20Drink%20Collector.cpp) | 已通过 | 贪心、排序 |
| ABC 129 | [C - Typical Stairs](https://atcoder.jp/contests/abc129/tasks/abc129_c) | [ABC129_C_Typical Stairs.cpp](./AtCoder/ABC129_C_Typical%20Stairs.cpp) | 已通过 | 动态规划、计数 |
| ABC 131 | [D - Megalomania](https://atcoder.jp/contests/abc131/tasks/abc131_d) | [ABC131_D_Megalomania.cpp](./AtCoder/ABC131_D_Megalomania.cpp) | 已通过 | 贪心、按截止时间排序 |
| ABC 135 | [C - City Savers](https://atcoder.jp/contests/abc135/tasks/abc135_c) | [ABC135_C_City Savers.cpp](./AtCoder/ABC135_C_City%20Savers.cpp) | 已通过 | 贪心、模拟 |
| ABC 136 | [C - Build Stairs](https://atcoder.jp/contests/abc136/tasks/abc136_c) | [ABC136_C_Build Stairs.cpp](./AtCoder/ABC136_C_Build%20Stairs.cpp) | 已通过 | 贪心、差分 |
| ABC 140 | [C - Maximal Value](https://atcoder.jp/contests/abc140/tasks/abc140_c) | [ABC140_C_Maximal Value.cpp](./AtCoder/ABC140_C_Maximal%20Value.cpp) | 已通过 | 贪心、相邻约束 |
| ABC 147 | [C - HonestOrUnkind2](https://atcoder.jp/contests/abc147/tasks/abc147_c) | [ABC147_C_HonestOrUnkind2.cpp](./AtCoder/ABC147_C_HonestOrUnkind2.cpp) | 已通过 | 二进制枚举、状态验证 |
| ABC 153 | [C - Fennec vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_c) | [ABC153_C_Fennec vs Monster.cpp](./AtCoder/ABC153_C_Fennec%20vs%20Monster.cpp) | 已通过 | 排序、贪心 |
| ABC 168 | [D - .. (Double Dots)](https://atcoder.jp/contests/abc168/tasks/abc168_d) | [ABC168_D_.. (Double Dots).cpp](<./AtCoder/ABC168_D_.. (Double Dots).cpp>) | 已通过 | BFS、最短路树、父节点记录 |
| ABC 176 | [C - Step](https://atcoder.jp/contests/abc176/tasks/abc176_c) | [ABC176_C_Step.cpp](./AtCoder/ABC176_C_Step.cpp) | 已通过 | 贪心、前缀最大值 |
| ABC 183 | [C - Travel](https://atcoder.jp/contests/abc183/tasks/abc183_c) | [ABC183_C_Travel.cpp](./AtCoder/ABC183_C_Travel.cpp) | 已通过 | 全排列、暴力枚举 |
| ABC 190 | [C - Bowls and Dishes](https://atcoder.jp/contests/abc190/tasks/abc190_c) | [ABC190_C_Bowls and Dishes.cpp](./AtCoder/ABC190_C_Bowls%20and%20Dishes.cpp) | 已通过 | DFS、回溯、状态枚举 |
| ABC 203 | [C - Friends and Travel costs](https://atcoder.jp/contests/abc203/tasks/abc203_c) | [ABC203_C_Friends and Travel costs.cpp](./AtCoder/ABC203_C_Friends%20and%20Travel%20costs.cpp) | 已通过 | 排序、贪心 |
| ABC 208 | [C - Fair Candy Distribution](https://atcoder.jp/contests/abc208/tasks/abc208_c) | [ABC208_C_Fair Candy Distribution.cpp](./AtCoder/ABC208_C_Fair%20Candy%20Distribution.cpp) | 已通过 | 排序、模拟 |
| ABC 211 | [C - chokudai](https://atcoder.jp/contests/abc211/tasks/abc211_c) | [ABC211_C_chokudai.cpp](./AtCoder/ABC211_C_chokudai.cpp) | 已通过 | 动态规划、子序列计数 |
| ABC 212 | [C - Min Difference](https://atcoder.jp/contests/abc212/tasks/abc212_c) | [ABC212_C_Min Difference.cpp](./AtCoder/ABC212_C_Min%20Difference.cpp) | 已通过 | 排序、双指针 |
| ABC 221 | [C - Select Mul](https://atcoder.jp/contests/abc221/tasks/abc221_c) | [ABC221_C_Select Mul.cpp](./AtCoder/ABC221_C_Select%20Mul.cpp) | 已通过 | 二进制枚举、排序、数位构造 |
| ABC 229 | [C - Cheese](https://atcoder.jp/contests/abc229/tasks/abc229_c) | [ABC229_C_Cheese.cpp](./AtCoder/ABC229_C_Cheese.cpp) | 已通过 | 贪心、排序 |
| ABC 239 | [E - Subtree K-th Max](https://atcoder.jp/contests/abc239/tasks/abc239_e) | [ABC239_E_Subtree K-th Max.cpp](./AtCoder/ABC239_E_Subtree%20K-th%20Max.cpp) | 已通过 | 树上 DFS、Top-K 合并 |
| ABC 240 | [C - Jumping Takahashi](https://atcoder.jp/contests/abc240/tasks/abc240_c) | [ABC240_C_Jumping Takahashi.cpp](./AtCoder/ABC240_C_Jumping%20Takahashi.cpp) | 已通过 | 动态规划、可达性 |
| ABC 245 | [C - Choose Elements](https://atcoder.jp/contests/abc245/tasks/abc245_c) | [ABC245_C_Choose Elements.cpp](./AtCoder/ABC245_C_Choose%20Elements.cpp) | 已通过 | 动态规划、状态压缩 |
| ABC 246 | [C - Coupon](https://atcoder.jp/contests/abc246/tasks/abc246_c) | [ABC246_C_Coupon.cpp](./AtCoder/ABC246_C_Coupon.cpp) | 已通过 | 贪心、排序 |
| ABC 250 | [C - Adjacent Swaps](https://atcoder.jp/contests/abc250/tasks/abc250_c) | [ABC250_C_Adjacent Swaps.cpp](./AtCoder/ABC250_C_Adjacent%20Swaps.cpp) | 已通过 | 模拟、位置数组 |
| ABC 251 | [C - Poem Online Judge](https://atcoder.jp/contests/abc251/tasks/abc251_c) | [ABC251_C_Poem Online Judge.cpp](./AtCoder/ABC251_C_Poem%20Online%20Judge.cpp) | 已通过 | 集合、枚举 |
| ABC 252 | [C - Slot Strategy](https://atcoder.jp/contests/abc252/tasks/abc252_c) | [ABC252_C_Slot Strategy.cpp](./AtCoder/ABC252_C_Slot%20Strategy.cpp) | 已通过 | 枚举、排序 |
| ABC 258 | [C - Rotation](https://atcoder.jp/contests/abc258/tasks/abc258_c) | [ABC258_C_Rotation.cpp](./AtCoder/ABC258_C_Rotation.cpp) | 已通过 | 字符串、循环偏移 |
| ABC 269 | [D - Do use hexagon grid](https://atcoder.jp/contests/abc269/tasks/abc269_d) | [ABC269_D_Do use hexagon grid.cpp](./AtCoder/ABC269_D_Do%20use%20hexagon%20grid.cpp) | 已通过 | BFS、连通块、六边形网格 |
| ABC 271 | [C - Manga](https://atcoder.jp/contests/abc271/tasks/abc271_c) | [ABC271_C_Manga.cpp](./AtCoder/ABC271_C_Manga.cpp) | 已通过 | 贪心、排序、双指针 |
| ABC 274 | [D - Robot Arms 2](https://atcoder.jp/contests/abc274/tasks/abc274_d) | [ABC274_D_Robot Arms 2.cpp](./AtCoder/ABC274_D_Robot%20Arms%202.cpp) | 已通过 | 动态规划、二维可达性拆分 |
| ABC 277 | [C - Ladder Takahashi](https://atcoder.jp/contests/abc277/tasks/abc277_c) | [ABC277_C_Ladder Takahashi.cpp](./AtCoder/ABC277_C_Ladder%20Takahashi.cpp) | 已通过 | BFS、图遍历、离散顶点 |
| ABC 284 | [C - Count Connected Components](https://atcoder.jp/contests/abc284/tasks/abc284_c) | [ABC284_C_Count Connected Components.cpp](./AtCoder/ABC284_C_Count%20Connected%20Components.cpp) | 已通过 | 并查集、连通块 |
| ABC 286 | [C - Rotate and Palindrome](https://atcoder.jp/contests/abc286/tasks/abc286_c) | [ABC286_C_Rotate and Palindrome.cpp](./AtCoder/ABC286_C_Rotate%20and%20Palindrome.cpp) | 已通过 | 枚举、字符串、回文 |
| ABC 290 | [C - Max MEX](https://atcoder.jp/contests/abc290/tasks/abc290_c) | [ABC290_C_Max MEX.cpp](./AtCoder/ABC290_C_Max%20MEX.cpp) | 已通过 | 排序、MEX |
| ABC 293 | [C - Make Takahashi Happy](https://atcoder.jp/contests/abc293/tasks/abc293_c) | [ABC293_C_Make Takahashi Happy.cpp](./AtCoder/ABC293_C_Make%20Takahashi%20Happy.cpp) | 已通过 | DFS、回溯、路径枚举 |
| ABC 313 | [C - Approximate Equalization 2](https://atcoder.jp/contests/abc313/tasks/abc313_c) | [ABC313_C_Approximate Equalization 2.cpp](./AtCoder/ABC313_C_Approximate%20Equalization%202.cpp) | 已通过 | 排序、数学 |
| ABC 318 | [C - Blue Spring](https://atcoder.jp/contests/abc318/tasks/abc318_c) | [ABC318_C_Blue Spring.cpp](./AtCoder/ABC318_C_Blue%20Spring.cpp) | 已通过 | 贪心、排序 |
| ABC 325 | [C - Sensors](https://atcoder.jp/contests/abc325/tasks/abc325_c) | [ABC325_C_Sensors.cpp](./AtCoder/ABC325_C_Sensors.cpp) | 已通过 | BFS、网格连通块 |
| ABC 332 | [C - T-shirts](https://atcoder.jp/contests/abc332/tasks/abc332_c) | [ABC332_C_T-shirts.cpp](./AtCoder/ABC332_C_T-shirts.cpp) | 已通过 | 贪心、字符串模拟 |
| ABC 350 | [C - Sort](https://atcoder.jp/contests/abc350/tasks/abc350_c) | [ABC350_C_Sort.cpp](./AtCoder/ABC350_C_Sort.cpp) | 已通过 | 置换、位置数组、构造 |
| ABC 368 | [C - Triple Attack](https://atcoder.jp/contests/abc368/tasks/abc368_c) | [ABC368_C_Triple Attack.cpp](./AtCoder/ABC368_C_Triple%20Attack.cpp) | 已通过 | 周期模拟、数学 |
| ABC 378 | [D - Count Simple Paths](https://atcoder.jp/contests/abc378/tasks/abc378_d) | [ABC378_D_Count Simple Paths.cpp](./AtCoder/ABC378_D_Count%20Simple%20Paths.cpp) | 已通过 | DFS、回溯、路径计数 |
| ABC 468 | [A - Maximal Value](https://atcoder.jp/contests/abc468/tasks/abc468_a) | [ABC468_A_Maximal Value.cpp](./AtCoder/ABC468_A_Maximal%20Value.cpp) | 已通过 | 枚举、局部最大值 |
| ABC 471 | [A - Nine or Nein](https://atcoder.jp/contests/abc471/tasks/abc471_a) | [ABC471_A_Nine or Nein.cpp](./AtCoder/ABC471_A_Nine%20or%20Nein.cpp) | 已通过 | 枚举、基础运算 |
| ABC 471 | [B - Survey Tabulation](https://atcoder.jp/contests/abc471/tasks/abc471_b) | [ABC471_B_Survey Tabulation.cpp](./AtCoder/ABC471_B_Survey%20Tabulation.cpp) | 已通过 | 字符串、映射、计数 |
| ABC 471 | [C - Cookies and Greedy Takahashi](https://atcoder.jp/contests/abc471/tasks/abc471_c) | [ABC471_C_Cookies and Greedy Takahashi.cpp](./AtCoder/ABC471_C_Cookies%20and%20Greedy%20Takahashi.cpp) | 已通过 | 贪心、有序集合 |
| ABC 471 | [D - Chargers](https://atcoder.jp/contests/abc471/tasks/abc471_d) | [ABC471_D_Chargers.cpp](./AtCoder/ABC471_D_Chargers.cpp) | 已通过 | 优先队列、时间偏移 |
| ABC 471 | [E - Sum of Square of Sum](https://atcoder.jp/contests/abc471/tasks/abc471_e) | [ABC471_E_Sum of Square of Sum.cpp](./AtCoder/ABC471_E_Sum%20of%20Square%20of%20Sum.cpp) | 已通过 | 组合数学、快速幂 |
| ABC 471 | [F - Concat (maximize)](https://atcoder.jp/contests/abc471/tasks/abc471_f) | [ABC471_F_Concat (maximize).cpp](./AtCoder/ABC471_F_Concat%20%28maximize%29.cpp) | 未通过 | 字符串排序、贪心（待修正） |
| ABC 472 | [A - A](https://atcoder.jp/contests/abc472/tasks/abc472_a) | [ABC472_A_A.cpp](./AtCoder/ABC472_A_A.cpp) | 已通过 | 字符串、模拟 |
| ABC 472 | [B - Break a Stick](https://atcoder.jp/contests/abc472/tasks/abc472_b) | [ABC472_B_Break a Stick.cpp](./AtCoder/ABC472_B_Break%20a%20Stick.cpp) | 已通过 | 前缀和、枚举 |
| ABC 472 | [C - On a Diet](https://atcoder.jp/contests/abc472/tasks/abc472_c) | [ABC472_C_On a Diet.cpp](./AtCoder/ABC472_C_On%20a%20Diet.cpp) | 已通过 | 滑动窗口、模拟 |
| ABC 472 | [D - Bomber Mad](https://atcoder.jp/contests/abc472/tasks/abc472_d) | [ABC472_D_Bomber Mad.cpp](./AtCoder/ABC472_D_Bomber%20Mad.cpp) | 已通过 | 多源 BFS、网格最短路 |

详见 [AtCoder/README.md](./AtCoder/README.md)。

## 洛谷

| 题号 | 题目 | 代码 | 状态 | 主题 |
| --- | --- | --- | --- | --- |
| P1042 | [乒乓球](https://www.luogu.com.cn/problem/P1042) | [P1042_乒乓球.cpp](./LuoGu/P1042_乒乓球.cpp) | 已通过 | 模拟 |
| P1082 | [同余方程](https://www.luogu.com.cn/problem/P1082) | [P1082_同余方程.cpp](./LuoGu/P1082_同余方程.cpp) | 已通过 | 扩展欧几里得、乘法逆元 |
| P1197 | [星球大战](https://www.luogu.com.cn/problem/P1197) | [P1197_星球大战.cpp](./LuoGu/P1197_星球大战.cpp) | 已通过 | 离线逆序、并查集、动态连通性 |
| P1495 | [中国剩余定理（CRT）/ 曹冲养猪](https://www.luogu.com.cn/problem/P1495) | [P1495_中国剩余定理（CRT）-曹冲养猪.cpp](./LuoGu/P1495_中国剩余定理（CRT）-曹冲养猪.cpp) | 已通过 | 中国剩余定理、扩展欧几里得 |
| P1516 | [青蛙的约会](https://www.luogu.com.cn/problem/P1516) | [P1516_青蛙的约会.cpp](./LuoGu/P1516_青蛙的约会.cpp) | 已通过 | 扩展欧几里得、线性同余方程 |
| P1551 | [亲戚](https://www.luogu.com.cn/problem/P1551) | [P1551_亲戚.cpp](./LuoGu/P1551_亲戚.cpp) | 已通过 | 并查集、连通性查询 |
| P1563 | [玩具谜题](https://www.luogu.com.cn/problem/P1563) | [P1563_玩具谜题.cpp](./LuoGu/P1563_玩具谜题.cpp) | 未完成 | 环形模拟 |
| P2240 | [部分背包问题](https://www.luogu.com.cn/problem/P2240) | [P2240_部分背包问题.cpp](./LuoGu/P2240_部分背包问题.cpp) | 已通过 | 贪心、排序 |
| P2371 | [墨墨的等式](https://www.luogu.com.cn/problem/P2371) | [P2371_墨墨的等式.cpp](./LuoGu/P2371_墨墨的等式.cpp) | 已通过 | 同余最短路、Dijkstra、区间计数 |
| P2662 | [牛场围栏](https://www.luogu.com.cn/problem/P2662) | [P2662_牛场围栏.cpp](./LuoGu/P2662_牛场围栏.cpp) | 已通过（账号；本地需修正） | 同余最短路、最大不可表示数；缺少 gcd 无解判断 |
| P2670 | [扫雷游戏](https://www.luogu.com.cn/problem/P2670) | [P2670_扫雷游戏.cpp](./LuoGu/P2670_扫雷游戏.cpp) | 已通过 | 网格模拟 |
| P3304 | [直径](https://www.luogu.com.cn/problem/P3304) | [P3304_直径.cpp](./LuoGu/P3304_直径.cpp) | 未完成 | 树的直径；尚缺公共边数量 |
| P3367 | [并查集](https://www.luogu.com.cn/problem/P3367) | [P3367_并查集.cpp](./LuoGu/P3367_并查集.cpp) | 已通过 | 并查集、路径压缩 |
| P3376 | [网络最大流](https://www.luogu.com.cn/problem/P3376) | [P3376_网络最大流.cpp](./LuoGu/P3376_网络最大流.cpp) | 已通过 | Dinic、分层图、当前弧优化 |
| P3379 | [最近公共祖先（LCA）](https://www.luogu.com.cn/problem/P3379) | [P3379_最近公共祖先.cpp](./LuoGu/P3379_最近公共祖先.cpp) | 已通过 | 倍增、LCA、树上查询 |
| P3403 | [跳楼机](https://www.luogu.com.cn/problem/P3403) | [P3403_跳楼机.cpp](./LuoGu/P3403_跳楼机.cpp) | 已通过 | 同余最短路、Dijkstra、可达状态计数 |
| P3868 | [猜数字](https://www.luogu.com.cn/problem/P3868) | [P3868_猜数字.cpp](./LuoGu/P3868_猜数字.cpp) | 已通过（账号；本地需修正） | 中国剩余定理；`k=1` 分支固定输出 0 |
| P3951 | [小凯的疑惑](https://www.luogu.com.cn/problem/P3951) | [P3951_小凯的疑惑.cpp](./LuoGu/P3951_小凯的疑惑.cpp) | 已通过 | 数论、裴蜀定理、Frobenius 数 |
| P4549 | [裴蜀定理](https://www.luogu.com.cn/problem/P4549) | [P4549_裴蜀定理.cpp](./LuoGu/P4549_裴蜀定理.cpp) | 已通过 | 裴蜀定理、最大公约数 |
| P4777 | [扩展中国剩余定理（EXCRT）](https://www.luogu.com.cn/problem/P4777) | [P4777_扩展中国剩余定理（EXCRT）.cpp](./LuoGu/P4777_扩展中国剩余定理（EXCRT）.cpp) | 已通过 | 扩展中国剩余定理、扩展欧几里得 |
| P5318 | [查找文献](https://www.luogu.com.cn/problem/P5318) | [P5318_查找文献.cpp](./LuoGu/P5318_查找文献.cpp) | 已通过 | 图遍历、DFS、BFS |
| P5536 | [核心城市](https://www.luogu.com.cn/problem/P5536) | [P5536_核心城市.cpp](./LuoGu/P5536_核心城市.cpp) | 未完成 | 树的直径、树形 DP（未完成） |
| P5656 | [二元一次不定方程](https://www.luogu.com.cn/problem/P5656) | [P5656_二元一次不定方程.cpp](./LuoGu/P5656_二元一次不定方程.cpp) | 已通过 | 扩展欧几里得、线性丢番图方程、解集计数 |

详见 [LuoGu/README.md](./LuoGu/README.md)。

## 码题集

| 比赛 | 题号 | 题目 | 代码 | 状态 | 主题 |
| --- | --- | --- | --- | --- | --- |
| 百度之星 2024 | BD202401 | [补给](https://www.matiji.net/exam/brushquestion/1/4498/F16DA07A4D99E21DFFEF46BD18FF68AD?from=1) | [BD202401_补给.cpp](./matiji/BD202401_补给.cpp) | 已通过（用户确认） | 排序、贪心 |

详见 [matiji/README.md](./matiji/README.md)。

## 竞极

| 题号 | 题目 | 代码 | 状态 | 主题 |
| --- | --- | --- | --- | --- |
| C5053 | [逐步通车](http://47.120.23.84/problems/2091929270199820290) | [C5053_逐步通车.cpp](./竞极/C5053_逐步通车.cpp) | 待验证 | 离线查询、并查集、连通点对计数 |
| C5054 | [舒适区间](http://47.120.23.84/problems/2091929269054775298) | [C5054_舒适区间.cpp](./竞极/C5054_舒适区间.cpp) | 待验证 | 滑动窗口、多重集合、区间极值 |
| C5055 | [单调台阶](http://47.120.23.84/problems/2091929268077502465) | [C5055_单调台阶.cpp](./竞极/C5055_单调台阶.cpp) | 待验证 | 贪心、前缀最大值 |
| C5056 | [环形灯带](http://47.120.23.84/problems/2091929267406413826) | [C5056_环形灯带.cpp](./竞极/C5056_环形灯带.cpp) | 待验证 | 字符串、环形序列、连续段 |
| C5057 | [环形调度](http://47.120.23.84/problems/2092101704070782977) | [C5057_环形调度.cpp](./竞极/C5057_环形调度.cpp) | 待验证 | 前缀和、中位数、环形均分 |
| A | [最长交替子串（本地语义命名）](http://47.120.23.84/contest/2093329939779661825/2093331392745287682) | [A_最长交替子串.cpp](./竞极/A_最长交替子串.cpp) | 待验证 | 滑动窗口、二进制交替串 |
| B | [数轴搬运（本地语义命名）](http://47.120.23.84/contest/2093329939779661825/2093331392749481985) | [B_数轴搬运.cpp](./竞极/B_数轴搬运.cpp) | 待验证 | 贪心、排序、分组 |
| C | [三段不相交子数组（本地语义命名）](http://47.120.23.84/contest/2093329939779661825/2093331392749481986) | [C_三段不相交子数组.cpp](./竞极/C_三段不相交子数组.cpp) | 待验证 | 动态规划、前缀和、全排列 |
| D | [反转一条边最短路（本地语义命名）](http://47.120.23.84/contest/2093329939779661825/2093331392753676290) | [D_反转一条边最短路.cpp](./竞极/D_反转一条边最短路.cpp) | 待验证 | Dijkstra、正反图、枚举反向边 |
| E | [双周期同步计数（本地语义命名）](http://47.120.23.84/contest/2093329939779661825/2093331392753676291) | [E_双周期同步计数.cpp](./竞极/E_双周期同步计数.cpp) | 待验证 | 线性同余方程、EXCRT、区间计数 |
| F | [子树 H 指数（本地语义命名）](http://47.120.23.84/contest/2093329939779661825/2093331392757870593) | [F_子树H指数.cpp](./竞极/F_子树H指数.cpp) | 待验证 | 动态开点线段树合并、树上 DFS、二分答案 |
| G | [幂塔同余（本地语义命名）](http://47.120.23.84/contest/2093329939779661825/2093331392757870594) | [G_幂塔同余.cpp](./竞极/G_幂塔同余.cpp) | 待验证 | 欧拉降幂、线性筛、模运算 |
| E | [子数组异或计数（本地语义命名）](http://47.120.23.84/contest/2090742212411854849/2092110649929818117) | [E_子数组异或计数.cpp](./竞极/E_子数组异或计数.cpp) | 待验证 | 前缀异或、二进制字典树、子数组计数 |
| F | [跳石取分（本地语义命名）](http://47.120.23.84/contest/2090742212411854849/2092110649929818118) | [F_跳石取分.cpp](./竞极/F_跳石取分.cpp) | 待验证 | 动态规划、单调队列、滑动窗口最值 |

详见 [竞极/README.md](./竞极/README.md)。

## Codeforces

| 题号 | 题目 | 代码 | 状态 | 主题 |
| --- | --- | --- | --- | --- |
| 7C | [Line](https://codeforces.com/problemset/problem/7/C) | [7C_Line.cpp](./CodeForces/7C_Line.cpp) | 已通过 | 扩展欧几里得、线性丢番图方程 |
| 189A | [Cut Ribbon](https://codeforces.com/problemset/problem/189/A) | [189A_Cut Ribbon.cpp](./CodeForces/189A_Cut%20Ribbon.cpp) | 已通过 | 动态规划、完全背包 |
| 217A | [Ice Skating](https://codeforces.com/problemset/problem/217/A) | [217A_Ice Skating.cpp](./CodeForces/217A_Ice%20Skating.cpp) | 已通过 | 并查集、连通块 |
| 230A | [Dragons](https://codeforces.com/problemset/problem/230/A) | [230A_Dragons.cpp](./CodeForces/230A_Dragons.cpp) | 已通过 | 排序、贪心 |
| 455A | [Boredom](https://codeforces.com/problemset/problem/455/A) | [455A_Boredom.cpp](./CodeForces/455A_Boredom.cpp) | 已通过 | 动态规划、值域计数 |
| 467B | [Fedor and New Game](https://codeforces.com/problemset/problem/467/B) | [467B_Fedor and New Game.cpp](./CodeForces/467B_Fedor%20and%20New%20Game.cpp) | 已通过 | 位运算、枚举 |
| 479C | [Exams](https://codeforces.com/problemset/problem/479/C) | [479C_Exams.cpp](./CodeForces/479C_Exams.cpp) | 已通过 | 排序、贪心 |
| 489B | [BerSU Ball](https://codeforces.com/problemset/problem/489/B) | [489B_BerSU Ball.cpp](./CodeForces/489B_BerSU%20Ball.cpp) | 已通过 | 排序、双指针、贪心 |
| 489C | [Given Length and Sum of Digits...](https://codeforces.com/problemset/problem/489/C) | [489C_Given Length and Sum of Digits.cpp](./CodeForces/489C_Given%20Length%20and%20Sum%20of%20Digits.cpp) | 已通过 | 贪心、构造、数位 |
| 500A | [New Year Transportation](https://codeforces.com/problemset/problem/500/A) | [500A_New Year Transportation.cpp](./CodeForces/500A_New%20Year%20Transportation.cpp) | 已通过 | 模拟、图遍历 |
| 510D | [Fox And Jumping](https://codeforces.com/problemset/problem/510/D) | [510D_Fox And Jumping.cpp](./CodeForces/510D_Fox%20And%20Jumping.cpp) | 已通过 | 动态规划、最大公约数、状态压缩 |
| 522A | [Reposts](https://codeforces.com/problemset/problem/522/A) | [522A_Reposts.cpp](./CodeForces/522A_Reposts.cpp) | 已通过 | BFS、最长链、字符串处理 |
| 580C | [Kefa and Park](https://codeforces.com/problemset/problem/580/C) | [580C_Kefa and Park.cpp](<./CodeForces/580C_Kefa and Park.cpp>) | 已通过 | 树上 DFS、连续段约束、叶子计数 |
| 580D | [Kefa and Dishes](https://codeforces.com/problemset/problem/580/D) | [580D_Kefa and Dishes.cpp](./CodeForces/580D_Kefa%20and%20Dishes.cpp) | 已通过 | 状压动态规划 |
| 1157B | [Long Number](https://codeforces.com/problemset/problem/1157/B) | [1157B_Long Number.cpp](./CodeForces/1157B_Long%20Number.cpp) | 已通过 | 贪心、字符串 |
| 1370B | [GCD Compression](https://codeforces.com/problemset/problem/1370/B) | [1370B_GCD Compression.cpp](./CodeForces/1370B_GCD%20Compression.cpp) | 已通过 | 奇偶分类、构造 |
| 1399C | [Boats Competition](https://codeforces.com/problemset/problem/1399/C) | [1399C_Boats Competition.cpp](./CodeForces/1399C_Boats%20Competition.cpp) | 已通过 | 枚举、排序、双指针 |
| 1400C | [Binary String Reconstruction](https://codeforces.com/problemset/problem/1400/C) | [1400C_Binary String Reconstruction.cpp](./CodeForces/1400C_Binary%20String%20Reconstruction.cpp) | 已通过 | 贪心、构造、字符串 |
| 1472C | [Long Jumps](https://codeforces.com/problemset/problem/1472/C) | [1472C_Long Jumps.cpp](./CodeForces/1472C_Long%20Jumps.cpp) | 已通过 | 动态规划、递推 |
| 1490E | [Accidental Victory](https://codeforces.com/problemset/problem/1490/E) | [1490E_Accidental Victory.cpp](./CodeForces/1490E_Accidental%20Victory.cpp) | 已通过 | 排序、前缀和、贪心 |
| 1530C | [Pursuit](https://codeforces.com/problemset/problem/1530/C) | [1530C_Pursuit.cpp](./CodeForces/1530C_Pursuit.cpp) | 已通过 | 排序、前缀和、二分答案 |
| 1530D | [Secret Santa](https://codeforces.com/problemset/problem/1530/D) | [1530D_Secret Santa.cpp](./CodeForces/1530D_Secret%20Santa.cpp) | 已通过 | 贪心、构造、置换 |
| 1593C | [Save More Mice](https://codeforces.com/problemset/problem/1593/C) | [1593C_Save More Mice.cpp](./CodeForces/1593C_Save%20More%20Mice.cpp) | 已通过 | 排序、贪心 |
| 1661B | [Getting Zero](https://codeforces.com/problemset/problem/1661/B) | [1661B_Getting Zero.cpp](./CodeForces/1661B_Getting%20Zero.cpp) | 已通过 | 暴力枚举、模运算 |
| 1829E | [The Lakes](https://codeforces.com/problemset/problem/1829/E) | [1829E_The Lakes.cpp](./CodeForces/1829E_The%20Lakes.cpp) | 已通过 | 网格 DFS、连通块 |

详见 [CodeForces/README.md](./CodeForces/README.md)。

## 牛客

| 比赛 | 比赛 ID | 归档入口 | 代码概况 |
| --- | ---: | --- | --- |
| 2026 牛客暑期多校训练营 4 | 133879 | [2026-mutlischool-4](./NowCoder/2026-mutlischool-4/) | B 已通过；F 未完成且未通过 |
| 2026 牛客暑期多校训练营 5 | 133880 | [2026-mutlischool-5](./NowCoder/2026-mutlischool-5/) | 账号已通过 E、K；本地 E 仍为未完成版本 |
| 2026 牛客暑期多校训练营 6 | 133881 | [2026-multischool-6](./NowCoder/2026-multischool-6/) | G 未通过；I、J 未完成且未通过 |
| 2026 牛客暑期多校训练营 7 | 133882 | [2026-mutlischool-7](./NowCoder/2026-mutlischool-7/) | D、H 已通过；A 未完成且未通过 |
| 2026 牛客暑期多校训练营 8 | 133883 | [2026-mutlischool-8](./NowCoder/2026-mutlischool-8/) | H 待验证（团队 AC 源码与本地版本不同）；C、M 未完成 |
| 2026 牛客暑期多校训练营 9 | 133884 | [2026-multischool-9](./NowCoder/2026-multischool-9/) | I 已通过；A、D、F 未完成 |
| 2026 牛客暑期多校训练营 10 | 133885 | [2026-mutlischool-10](./NowCoder/2026-mutlischool-10/) | K、L 已通过；B、E 未完成且未通过 |
| 牛客周赛 Round 149 | 136720 | [weeklyround-149](./NowCoder/weeklyround-149/) | B 已通过 |
| 牛客周赛 Round 155 | 138240 | [weeklyround-155](./NowCoder/weeklyround-155/) | A、B 已通过；C 未完成且未通过 |
| 牛客周赛 Round 156 | 138917 | [weeklyround-156](./NowCoder/weeklyround-156/) | A、B、C 已通过；D 未完成且未通过 |
| 牛客周赛 Round 157 | 139206 | [weeklyround-157](./NowCoder/weeklyround-157/) | A、B、C、D、E、F 已通过 |
| 牛客小白月赛 119 | 112543 | [NC296377_睡前床边看LIVE.cpp](./NowCoder/NC296377_睡前床边看LIVE.cpp) | C 待验证 |

详见 [NowCoder/README.md](./NowCoder/README.md)。目录名中的 `mutlischool` 是原有拼写，暂不改动，以免破坏本地工具中的路径记录。

## QOJ

| 比赛 | 题目 | 代码 | 状态 | 主题 |
| --- | --- | --- | --- | --- |
| 2024 CCPC 女生专场 | [A - 盒子](https://qoj.ac/contest/1841/problem/9739) | [A_盒子.cpp](./ccpc_women_2024/A_盒子.cpp) | 已通过 | 坐标范围、模拟 |
| 2024 CCPC 女生专场 | [C - CCPC](https://qoj.ac/contest/1841/problem/9741) | [C_CCPC.cpp](./ccpc_women_2024/C_CCPC.cpp) | 已通过 | 字符串计数、贪心 |
| 2024 CCPC 女生专场 | [D - 优秀的拆分](https://qoj.ac/contest/1841/problem/9742) | [D_优秀的拆分.cpp](./ccpc_women_2024/D_优秀的拆分.cpp) | 未通过 | 模拟退火、随机化搜索 |
| 2024 CCPC 女生专场 | [G - 递增序列](https://qoj.ac/contest/1841/problem/9745) | [G_递增序列.cpp](./ccpc_women_2024/G_递增序列.cpp) | 未通过 | 暴力枚举、位运算 |
| 2024 CCPC 女生专场 | [H - 平方根](https://qoj.ac/contest/1841/problem/9746) | [H_平方根.cpp](./ccpc_women_2024/H_平方根.cpp) | 已通过 | 连续段、数学、分类讨论 |
| 2024 CCPC 女生专场 | [L - 拼图](https://qoj.ac/contest/1841/problem/9750) | [L_拼图.cpp](./ccpc_women_2024/L_拼图.cpp) | 已通过 | 枚举、数学、面积最大化 |
| 2024 CCPC 女生专场 | [M - 覆盖一棵树](https://qoj.ac/contest/1841/problem/9751) | [M_覆盖一棵树.cpp](./ccpc_women_2024/M_覆盖一棵树.cpp) | 已通过 | 树形 DP、贪心 |
| 2025 CCPC 女生专场 | [A - 环状线](https://qoj.ac/contest/2564/problem/14450) | [A_环状线.cpp](./ccpc_women_2025/A_环状线.cpp) | 已通过 | 环形距离、分类讨论 |
| 2025 CCPC 女生专场 | [B - 爬山](https://qoj.ac/contest/2564/problem/14451) | [B_爬山.cpp](./ccpc_women_2025/B_爬山.cpp) | 已通过 | 状态扩展、Dijkstra |
| 2025 CCPC 女生专场 | [C - 短视频](https://qoj.ac/contest/2564/problem/14452) | [C_短视频.cpp](./ccpc_women_2025/C_短视频.cpp) | 已通过 | 模拟、贪心 |
| 2025 CCPC 女生专场 | [G - 最大公约数](https://qoj.ac/contest/2564/problem/14456) | [G_最大公约数.cpp](./ccpc_women_2025/G_最大公约数.cpp) | 已通过 | 数论、质数筛、构造 |
| 2025 CCPC 女生专场 | [J - 后鼻嘤](https://qoj.ac/contest/2564/problem/14459) | [J_后鼻嘤.cpp](./ccpc_women_2025/J_后鼻嘤.cpp) | 已通过 | 字符串模拟 |

比赛与题面入口见 [ccpc_women_2024/README.md](./ccpc_women_2024/README.md) 和 [ccpc_women_2025/README.md](./ccpc_women_2025/README.md)。

Codeforces 账号 `Moyichen0219` 的在线记录已核对；仓库中的 25 道 Codeforces 题目均有 `Accepted` 提交。

## 知识总结

可复用的算法笔记收录在 [Knowledge/README.md](./Knowledge/README.md)；通用源码模板见 [Templates/README.md](./Templates/README.md)，目前包括同余最短路、最大不可表示数、Dinic 最大流、扩展欧几里得、CRT、EXCRT、`__int128` 输入输出、动态开点线段树和四类静态线段树、匈牙利算法、线性筛、组合数与模逆元、二项分布。

## 维护约定

1. 在线题目的源码统一使用 `题目编号_题目名字.cpp` 命名；本地测试文件除外。文件头记录比赛、题目链接、状态和算法标签。
2. 只有确认通过评测后，才把状态改为 `已通过`。
3. 新增比赛时，同时更新对应目录的 README 和本文件的总索引。
4. 编译产物、IDE 配置和刷题插件数据不作为题解源码；`.gitignore` 已给出推荐忽略规则。
