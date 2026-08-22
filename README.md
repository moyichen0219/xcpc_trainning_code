# XCPC 代码仓库

本仓库按 **平台 → 比赛/题号** 归档，共有 123 个 C++ 源文件：122 个题目文件和 1 个算法模板。题目链接、代码状态与源码入口汇总如下。

## 状态说明

- `已通过`：平台账号显示该题已经通过；若仓库文件并非完整版本，会在备注中单独说明。
- `未通过`：实现形态较完整，但平台账号显示该题尚未通过。
- `待验证`：已有完整实现，但仓库中没有可核对的在线评测记录。
- `未完成`：空框架、部分实现，或实现与题意不符。
- `模板`：通用算法实现，不对应单一在线评测题目。

> 整理时未删除 `.exe`、`.cph`、`.idea` 或 `.vscode` 等已有文件。

## 当前验证结果

- 123/123 个 `.cpp` 文件通过 `g++ -std=c++17 -fsyntax-only` 语法检查。
- 已完成的样例或构造回归记录为：14 个文件、30 组检查，30/30 组通过。本次新增源码已完成语法检查，并结合平台 AC 记录核对状态。
- 样例通过不等于在线评测通过；AtCoder 与 Codeforces 状态最近于 2026-08-22 核对，牛客状态于 2026-08-21 核对，QOJ 状态于 2026-08-13 核对，洛谷状态于 2026-08-11 核对。

## AtCoder

| 比赛 | 题目 | 代码 | 状态 | 主题 |
| --- | --- | --- | --- | --- |
| 算法与数学 演习问题集 | [060 - Stones Game 1](https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_az) | [060_Stones Game 1.cpp](./AtCoder/060_Stones%20Game%201.cpp) | 已通过 | 博弈论、数学 |
| Educational DP Contest | [A - Frog 1](https://atcoder.jp/contests/dp/tasks/dp_a) | [DP_A_Frog 1.cpp](./AtCoder/DP_A_Frog%201.cpp) | 已通过 | 动态规划、线性 DP |
| Educational DP Contest | [B - Frog 2](https://atcoder.jp/contests/dp/tasks/dp_b) | [DP_B_Frog 2.cpp](./AtCoder/DP_B_Frog%202.cpp) | 已通过 | 动态规划、线性 DP |
| Educational DP Contest | [C - Vacation](https://atcoder.jp/contests/dp/tasks/dp_c) | [DP_C_Vacation.cpp](./AtCoder/DP_C_Vacation.cpp) | 已通过 | 动态规划、状态转移 |
| ABC 085 | [D - Katana Thrower](https://atcoder.jp/contests/abc085/tasks/abc085_d) | [ABC085_D_Katana Thrower.cpp](./AtCoder/ABC085_D_Katana%20Thrower.cpp) | 已通过（账号；本地需修正） | 贪心、排序 |
| ABC 121 | [C - Energy Drink Collector](https://atcoder.jp/contests/abc121/tasks/abc121_c) | [ABC121_C_Energy Drink Collector.cpp](./AtCoder/ABC121_C_Energy%20Drink%20Collector.cpp) | 待验证 | 贪心、排序 |
| ABC 129 | [C - Typical Stairs](https://atcoder.jp/contests/abc129/tasks/abc129_c) | [ABC129_C_Typical Stairs.cpp](./AtCoder/ABC129_C_Typical%20Stairs.cpp) | 已通过 | 动态规划、计数 |
| ABC 131 | [D - Megalomania](https://atcoder.jp/contests/abc131/tasks/abc131_d) | [ABC131_D_Megalomania.cpp](./AtCoder/ABC131_D_Megalomania.cpp) | 待验证 | 贪心、按截止时间排序 |
| ABC 135 | [C - City Savers](https://atcoder.jp/contests/abc135/tasks/abc135_c) | [ABC135_C_City Savers.cpp](./AtCoder/ABC135_C_City%20Savers.cpp) | 已通过 | 贪心、模拟 |
| ABC 136 | [C - Build Stairs](https://atcoder.jp/contests/abc136/tasks/abc136_c) | [ABC136_C_Build Stairs.cpp](./AtCoder/ABC136_C_Build%20Stairs.cpp) | 待验证 | 贪心、差分 |
| ABC 140 | [C - Maximal Value](https://atcoder.jp/contests/abc140/tasks/abc140_c) | [ABC140_C_Maximal Value.cpp](./AtCoder/ABC140_C_Maximal%20Value.cpp) | 已通过 | 贪心、相邻约束 |
| ABC 153 | [C - Fennec vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_c) | [ABC153_C_Fennec vs Monster.cpp](./AtCoder/ABC153_C_Fennec%20vs%20Monster.cpp) | 已通过 | 排序、贪心 |
| ABC 176 | [C - Step](https://atcoder.jp/contests/abc176/tasks/abc176_c) | [ABC176_C_Step.cpp](./AtCoder/ABC176_C_Step.cpp) | 待验证 | 贪心、前缀最大值 |
| ABC 183 | [C - Travel](https://atcoder.jp/contests/abc183/tasks/abc183_c) | [ABC183_C_Travel.cpp](./AtCoder/ABC183_C_Travel.cpp) | 待验证 | 全排列、暴力枚举 |
| ABC 190 | [C - Bowls and Dishes](https://atcoder.jp/contests/abc190/tasks/abc190_c) | [ABC190_C_Bowls and Dishes.cpp](./AtCoder/ABC190_C_Bowls%20and%20Dishes.cpp) | 未完成 | 二进制枚举 |
| ABC 203 | [C - Friends and Travel costs](https://atcoder.jp/contests/abc203/tasks/abc203_c) | [ABC203_C_Friends and Travel costs.cpp](./AtCoder/ABC203_C_Friends%20and%20Travel%20costs.cpp) | 待验证 | 排序、贪心 |
| ABC 208 | [C - Fair Candy Distribution](https://atcoder.jp/contests/abc208/tasks/abc208_c) | [ABC208_C_Fair Candy Distribution.cpp](./AtCoder/ABC208_C_Fair%20Candy%20Distribution.cpp) | 待验证 | 排序、模拟 |
| ABC 211 | [C - chokudai](https://atcoder.jp/contests/abc211/tasks/abc211_c) | [ABC211_C_chokudai.cpp](./AtCoder/ABC211_C_chokudai.cpp) | 已通过 | 动态规划、子序列计数 |
| ABC 212 | [C - Min Difference](https://atcoder.jp/contests/abc212/tasks/abc212_c) | [ABC212_C_Min Difference.cpp](./AtCoder/ABC212_C_Min%20Difference.cpp) | 待验证 | 排序、双指针 |
| ABC 221 | [C - Select Mul](https://atcoder.jp/contests/abc221/tasks/abc221_c) | [ABC221_C_Select Mul.cpp](./AtCoder/ABC221_C_Select%20Mul.cpp) | 已通过 | 贪心、排序、数位构造 |
| ABC 229 | [C - Cheese](https://atcoder.jp/contests/abc229/tasks/abc229_c) | [ABC229_C_Cheese.cpp](./AtCoder/ABC229_C_Cheese.cpp) | 已通过 | 贪心、排序 |
| ABC 240 | [C - Jumping Takahashi](https://atcoder.jp/contests/abc240/tasks/abc240_c) | [ABC240_C_Jumping Takahashi.cpp](./AtCoder/ABC240_C_Jumping%20Takahashi.cpp) | 已通过 | 动态规划、可达性 |
| ABC 245 | [C - Choose Elements](https://atcoder.jp/contests/abc245/tasks/abc245_c) | [ABC245_C_Choose Elements.cpp](./AtCoder/ABC245_C_Choose%20Elements.cpp) | 已通过 | 动态规划、状态压缩 |
| ABC 246 | [C - Coupon](https://atcoder.jp/contests/abc246/tasks/abc246_c) | [ABC246_C_Coupon.cpp](./AtCoder/ABC246_C_Coupon.cpp) | 已通过 | 贪心、排序 |
| ABC 250 | [C - Adjacent Swaps](https://atcoder.jp/contests/abc250/tasks/abc250_c) | [ABC250_C_Adjacent Swaps.cpp](./AtCoder/ABC250_C_Adjacent%20Swaps.cpp) | 已通过 | 模拟、位置数组 |
| ABC 251 | [C - Poem Online Judge](https://atcoder.jp/contests/abc251/tasks/abc251_c) | [ABC251_C_Poem Online Judge.cpp](./AtCoder/ABC251_C_Poem%20Online%20Judge.cpp) | 已通过 | 集合、枚举 |
| ABC 252 | [C - Slot Strategy](https://atcoder.jp/contests/abc252/tasks/abc252_c) | [ABC252_C_Slot Strategy.cpp](./AtCoder/ABC252_C_Slot%20Strategy.cpp) | 已通过 | 枚举、排序 |
| ABC 258 | [C - Rotation](https://atcoder.jp/contests/abc258/tasks/abc258_c) | [ABC258_C_Rotation.cpp](./AtCoder/ABC258_C_Rotation.cpp) | 已通过 | 字符串、循环偏移 |
| ABC 269 | [D - Do use hexagon grid](https://atcoder.jp/contests/abc269/tasks/abc269_d) | [ABC269_D_Do use hexagon grid.cpp](./AtCoder/ABC269_D_Do%20use%20hexagon%20grid.cpp) | 已通过 | BFS、连通块、六边形网格 |
| ABC 271 | [C - Manga](https://atcoder.jp/contests/abc271/tasks/abc271_c) | [ABC271_C_Manga.cpp](./AtCoder/ABC271_C_Manga.cpp) | 已通过 | 贪心、排序、双指针 |
| ABC 277 | [C - Ladder Takahashi](https://atcoder.jp/contests/abc277/tasks/abc277_c) | [ABC277_C_Ladder Takahashi.cpp](./AtCoder/ABC277_C_Ladder%20Takahashi.cpp) | 待验证 | BFS、图遍历、离散顶点 |
| ABC 284 | [C - Count Connected Components](https://atcoder.jp/contests/abc284/tasks/abc284_c) | [ABC284_C_Count Connected Components.cpp](./AtCoder/ABC284_C_Count%20Connected%20Components.cpp) | 已通过 | 并查集、连通块 |
| ABC 286 | [C - Rotate and Palindrome](https://atcoder.jp/contests/abc286/tasks/abc286_c) | [ABC286_C_Rotate and Palindrome.cpp](./AtCoder/ABC286_C_Rotate%20and%20Palindrome.cpp) | 已通过 | 枚举、字符串、回文 |
| ABC 290 | [C - Max MEX](https://atcoder.jp/contests/abc290/tasks/abc290_c) | [ABC290_C_Max MEX.cpp](./AtCoder/ABC290_C_Max%20MEX.cpp) | 已通过 | 排序、MEX |
| ABC 293 | [C - Make Takahashi Happy](https://atcoder.jp/contests/abc293/tasks/abc293_c) | [ABC293_C_Make Takahashi Happy.cpp](./AtCoder/ABC293_C_Make%20Takahashi%20Happy.cpp) | 待验证 | DFS、回溯、路径枚举 |
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

详见 [AtCoder/README.md](./AtCoder/README.md)。

## 洛谷

| 题号 | 题目 | 代码 | 状态 | 主题 |
| --- | --- | --- | --- | --- |
| P1042 | [乒乓球](https://www.luogu.com.cn/problem/P1042) | [P1042_乒乓球.cpp](./LuoGu/P1042_乒乓球.cpp) | 待验证 | 模拟 |
| P1197 | [星球大战](https://www.luogu.com.cn/problem/P1197) | [P1197_星球大战.cpp](./LuoGu/P1197_星球大战.cpp) | 已通过 | 离线逆序、并查集、动态连通性 |
| P1563 | [玩具谜题](https://www.luogu.com.cn/problem/P1563) | [P1563_玩具谜题.cpp](./LuoGu/P1563_玩具谜题.cpp) | 未完成 | 环形模拟 |
| P2240 | [部分背包问题](https://www.luogu.com.cn/problem/P2240) | [P2240_部分背包问题.cpp](./LuoGu/P2240_部分背包问题.cpp) | 待验证 | 贪心、排序 |
| P2670 | [扫雷游戏](https://www.luogu.com.cn/problem/P2670) | [P2670_扫雷游戏.cpp](./LuoGu/P2670_扫雷游戏.cpp) | 待验证 | 网格模拟 |
| P3304 | [直径](https://www.luogu.com.cn/problem/P3304) | [P3304_直径.cpp](./LuoGu/P3304_直径.cpp) | 未完成 | 树的直径；尚缺公共边数量 |
| P3367 | [并查集](https://www.luogu.com.cn/problem/P3367) | [P3367_并查集.cpp](./LuoGu/P3367_并查集.cpp) | 已通过 | 并查集、路径压缩 |
| P3379 | [最近公共祖先（LCA）](https://www.luogu.com.cn/problem/P3379) | [P3379_最近公共祖先.cpp](./LuoGu/P3379_最近公共祖先.cpp) | 待验证 | 倍增、LCA、树上查询 |
| P5318 | [查找文献](https://www.luogu.com.cn/problem/P5318) | [P5318_查找文献.cpp](./LuoGu/P5318_查找文献.cpp) | 已通过 | 图遍历、DFS、BFS |

详见 [LuoGu/README.md](./LuoGu/README.md)。

## Codeforces

| 题号 | 题目 | 代码 | 状态 | 主题 |
| --- | --- | --- | --- | --- |
| 189A | [Cut Ribbon](https://codeforces.com/problemset/problem/189/A) | [189A_Cut Ribbon.cpp](./CodeForces/189A_Cut%20Ribbon.cpp) | 已通过 | 动态规划、完全背包 |
| 217A | [Ice Skating](https://codeforces.com/problemset/problem/217/A) | [217A_Ice Skating.cpp](./CodeForces/217A_Ice%20Skating.cpp) | 已通过 | 并查集、连通块 |
| 230A | [Dragons](https://codeforces.com/problemset/problem/230/A) | [230A_Dragons.cpp](./CodeForces/230A_Dragons.cpp) | 已通过 | 排序、贪心 |
| 467B | [Fedor and New Game](https://codeforces.com/problemset/problem/467/B) | [467B_Fedor and New Game.cpp](./CodeForces/467B_Fedor%20and%20New%20Game.cpp) | 已通过 | 位运算、枚举 |
| 479C | [Exams](https://codeforces.com/problemset/problem/479/C) | [479C_Exams.cpp](./CodeForces/479C_Exams.cpp) | 已通过 | 排序、贪心 |
| 489B | [BerSU Ball](https://codeforces.com/problemset/problem/489/B) | [489B_BerSU Ball.cpp](./CodeForces/489B_BerSU%20Ball.cpp) | 已通过 | 排序、双指针、贪心 |
| 489C | [Given Length and Sum of Digits...](https://codeforces.com/problemset/problem/489/C) | [489C_Given Length and Sum of Digits.cpp](./CodeForces/489C_Given%20Length%20and%20Sum%20of%20Digits.cpp) | 已通过 | 贪心、构造、数位 |
| 500A | [New Year Transportation](https://codeforces.com/problemset/problem/500/A) | [500A_New Year Transportation.cpp](./CodeForces/500A_New%20Year%20Transportation.cpp) | 已通过 | 模拟、图遍历 |
| 522A | [Reposts](https://codeforces.com/problemset/problem/522/A) | [522A_Reposts.cpp](./CodeForces/522A_Reposts.cpp) | 已通过 | BFS、最长链、字符串处理 |
| 1157B | [Long Number](https://codeforces.com/problemset/problem/1157/B) | [1157B_Long Number.cpp](./CodeForces/1157B_Long%20Number.cpp) | 已通过 | 贪心、字符串 |
| 1370B | [GCD Compression](https://codeforces.com/problemset/problem/1370/B) | [1370B_GCD Compression.cpp](./CodeForces/1370B_GCD%20Compression.cpp) | 已通过 | 奇偶分类、构造 |
| 1399C | [Boats Competition](https://codeforces.com/problemset/problem/1399/C) | [1399C_Boats Competition.cpp](./CodeForces/1399C_Boats%20Competition.cpp) | 已通过 | 枚举、排序、双指针 |
| 1400C | [Binary String Reconstruction](https://codeforces.com/problemset/problem/1400/C) | [1400C_Binary String Reconstruction.cpp](./CodeForces/1400C_Binary%20String%20Reconstruction.cpp) | 已通过 | 贪心、构造、字符串 |
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
| 2026 牛客暑期多校训练营 8 | 133883 | [2026-mutlischool-8](./NowCoder/2026-mutlischool-8/) | H 待验证；C、M 未完成 |
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
| 2025 CCPC 女生专场 | [A - 环状线](https://qoj.ac/contest/2564/problem/14450) | [A_环状线.cpp](./ccpc_women_2025/A_环状线.cpp) | 已通过 | 环形距离、分类讨论 |
| 2025 CCPC 女生专场 | [B - 爬山](https://qoj.ac/contest/2564/problem/14451) | [B_爬山.cpp](./ccpc_women_2025/B_爬山.cpp) | 未完成 | 空框架 |
| 2025 CCPC 女生专场 | [C - 短视频](https://qoj.ac/contest/2564/problem/14452) | [C_短视频.cpp](./ccpc_women_2025/C_短视频.cpp) | 已通过 | 模拟、贪心 |
| 2025 CCPC 女生专场 | [G - 最大公约数](https://qoj.ac/contest/2564/problem/14456) | [G_最大公约数.cpp](./ccpc_women_2025/G_最大公约数.cpp) | 已通过 | 数论、质数筛、构造 |
| 2025 CCPC 女生专场 | [J - 后鼻嘤](https://qoj.ac/contest/2564/problem/14459) | [J_后鼻嘤.cpp](./ccpc_women_2025/J_后鼻嘤.cpp) | 已通过 | 字符串模拟 |

比赛与题面入口见 [ccpc_women_2025/README.md](./ccpc_women_2025/README.md)。

Codeforces 账号 `Moyichen0219` 的在线记录已核对；仓库中的 19 道 Codeforces 题目均有 `Accepted` 提交。

## 知识总结

可复用的算法笔记收录在 [Knowledge/README.md](./Knowledge/README.md)；通用源码模板收录在 [Templates](./Templates/) 目录，目前包括匈牙利算法模板。

## 维护约定

1. 在线题目的源码统一使用 `题目编号_题目名字.cpp` 命名；本地测试文件除外。文件头记录比赛、题目链接、状态和算法标签。
2. 只有确认通过评测后，才把状态改为 `已通过`。
3. 新增比赛时，同时更新对应目录的 README 和本文件的总索引。
4. 编译产物、IDE 配置和刷题插件数据不作为题解源码；`.gitignore` 已给出推荐忽略规则。
