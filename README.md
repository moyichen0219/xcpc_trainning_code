# XCPC 代码仓库

本仓库按 **平台 → 比赛/题号** 归档，共有 57 个 C++ 源文件：56 个题目文件和 1 个算法模板。题目链接、代码状态与源码入口汇总如下。

## 状态说明

- `已通过`：平台账号显示该题已经通过；若仓库文件并非完整版本，会在备注中单独说明。
- `未通过`：实现形态较完整，但平台账号显示该题尚未通过。
- `待验证`：已有完整实现，但仓库中没有可核对的在线评测记录。
- `未完成`：空框架、部分实现，或实现与题意不符。
- `模板`：通用算法实现，不对应单一在线评测题目。

> 整理时未删除 `.exe`、`.cph`、`.idea` 或 `.vscode` 等已有文件。

## 当前验证结果

- 57/57 个 `.cpp` 文件通过 `g++ -std=c++17 -fsyntax-only` 语法检查。
- 已完成的样例回归记录为：8 个文件、18 组样例，18/18 组输出一致（比较时忽略行尾空白）。本次新增源码已完成语法检查，并结合平台 AC 记录核对状态。
- 样例通过不等于在线评测通过；AtCoder、Codeforces 与 QOJ 题目的账号状态已于 2026-08-13 核对，牛客与洛谷题目的账号状态已于 2026-08-11 核对。

## AtCoder

| 比赛 | 题目 | 代码 | 状态 | 主题 |
| --- | --- | --- | --- | --- |
| ABC 121 | [C - Energy Drink Collector](https://atcoder.jp/contests/abc121/tasks/abc121_c) | [ABC121_C_Energy Drink Collector.cpp](./AtCoder/ABC121_C_Energy%20Drink%20Collector.cpp) | 待验证 | 贪心、排序 |
| ABC 131 | [D - Megalomania](https://atcoder.jp/contests/abc131/tasks/abc131_d) | [ABC131_D_Megalomania.cpp](./AtCoder/ABC131_D_Megalomania.cpp) | 待验证 | 贪心、按截止时间排序 |
| ABC 135 | [C - City Savers](https://atcoder.jp/contests/abc135/tasks/abc135_c) | [ABC135_C_City Savers.cpp](./AtCoder/ABC135_C_City%20Savers.cpp) | 已通过 | 贪心、模拟 |
| ABC 136 | [C - Build Stairs](https://atcoder.jp/contests/abc136/tasks/abc136_c) | [ABC136_C_Build Stairs.cpp](./AtCoder/ABC136_C_Build%20Stairs.cpp) | 待验证 | 贪心、差分 |
| ABC 140 | [C - Maximal Value](https://atcoder.jp/contests/abc140/tasks/abc140_c) | [ABC140_C_Maximal Value.cpp](./AtCoder/ABC140_C_Maximal%20Value.cpp) | 已通过 | 贪心、相邻约束 |
| ABC 153 | [C - Fennec vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_c) | [ABC153_C_Fennec vs Monster.cpp](./AtCoder/ABC153_C_Fennec%20vs%20Monster.cpp) | 已通过 | 排序、贪心 |
| ABC 176 | [C - Step](https://atcoder.jp/contests/abc176/tasks/abc176_c) | [ABC176_C_Step.cpp](./AtCoder/ABC176_C_Step.cpp) | 待验证 | 贪心、前缀最大值 |
| ABC 203 | [C - Friends and Travel costs](https://atcoder.jp/contests/abc203/tasks/abc203_c) | [ABC203_C_Friends and Travel costs.cpp](./AtCoder/ABC203_C_Friends%20and%20Travel%20costs.cpp) | 待验证 | 排序、贪心 |
| ABC 208 | [C - Fair Candy Distribution](https://atcoder.jp/contests/abc208/tasks/abc208_c) | [ABC208_C_Fair Candy Distribution.cpp](./AtCoder/ABC208_C_Fair%20Candy%20Distribution.cpp) | 待验证 | 排序、模拟 |
| ABC 212 | [C - Min Difference](https://atcoder.jp/contests/abc212/tasks/abc212_c) | [ABC212_C_Min Difference.cpp](./AtCoder/ABC212_C_Min%20Difference.cpp) | 待验证 | 排序、双指针 |
| ABC 468 | [A - Maximal Value](https://atcoder.jp/contests/abc468/tasks/abc468_a) | [ABC468_A_Maximal Value.cpp](./AtCoder/ABC468_A_Maximal%20Value.cpp) | 已通过 | 枚举、局部最大值 |

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
| 1157B | [Long Number](https://codeforces.com/problemset/problem/1157/B) | [1157B_Long Number.cpp](./CodeForces/1157B_Long%20Number.cpp) | 已通过 | 贪心、字符串 |
| 1370B | [GCD Compression](https://codeforces.com/problemset/problem/1370/B) | [1370B_GCD Compression.cpp](./CodeForces/1370B_GCD%20Compression.cpp) | 已通过 | 奇偶分类、构造 |
| 1399C | [Boats Competition](https://codeforces.com/problemset/problem/1399/C) | [1399C_Boats Competition.cpp](./CodeForces/1399C_Boats%20Competition.cpp) | 已通过 | 枚举、排序、双指针 |
| 1530C | [Pursuit](https://codeforces.com/problemset/problem/1530/C) | [1530C_Pursuit.cpp](./CodeForces/1530C_Pursuit.cpp) | 已通过 | 排序、前缀和、二分答案 |
| 1593C | [Save More Mice](https://codeforces.com/problemset/problem/1593/C) | [1593C_Save More Mice.cpp](./CodeForces/1593C_Save%20More%20Mice.cpp) | 已通过 | 排序、贪心 |
| 230A | [Dragons](https://codeforces.com/problemset/problem/230/A) | [230A_Dragons.cpp](./CodeForces/230A_Dragons.cpp) | 已通过 | 排序、贪心 |
| 489B | [BerSU Ball](https://codeforces.com/problemset/problem/489/B) | [489B_BerSU Ball.cpp](./CodeForces/489B_BerSU%20Ball.cpp) | 已通过 | 排序、双指针、贪心 |

详见 [CodeForces/README.md](./CodeForces/README.md)。

## 牛客

| 比赛 | 比赛 ID | 目录 | 代码概况 |
| --- | ---: | --- | --- |
| 2026 牛客暑期多校训练营 4 | 133879 | [2026-mutlischool-4](./NowCoder/2026-mutlischool-4/) | B 已通过；F 未完成且未通过 |
| 2026 牛客暑期多校训练营 5 | 133880 | [2026-mutlischool-5](./NowCoder/2026-mutlischool-5/) | 账号已通过 E、K；本地 E 仍为未完成版本 |
| 2026 牛客暑期多校训练营 6 | 133881 | [2026-multischool-6](./NowCoder/2026-multischool-6/) | G 未通过；I、J 未完成且未通过 |
| 2026 牛客暑期多校训练营 7 | 133882 | [2026-mutlischool-7](./NowCoder/2026-mutlischool-7/) | D、H 已通过；A 未完成且未通过 |
| 2026 牛客暑期多校训练营 8 | 133883 | [2026-mutlischool-8](./NowCoder/2026-mutlischool-8/) | H 待验证；C、M 未完成 |
| 牛客周赛 Round 155 | 138240 | [weeklyround-155](./NowCoder/weeklyround-155/) | A、B 已通过；C 未完成且未通过 |
| 牛客周赛 Round 156 | 138917 | [weeklyround-156](./NowCoder/weeklyround-156/) | A、B、C 已通过；D 未完成且未通过 |

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

Codeforces 账号 `Moyichen0219` 的在线记录已核对；仓库中的 7 道 Codeforces 题目均有 `OK` 提交。

## 知识总结

可复用的算法笔记收录在 [Knowledge/README.md](./Knowledge/README.md)；通用源码模板收录在 [Templates](./Templates/) 目录，目前包括匈牙利算法模板。

## 维护约定

1. 在线题目的源码统一使用 `题目编号_题目名字.cpp` 命名；本地测试文件除外。文件头记录比赛、题目链接、状态和算法标签。
2. 只有确认通过评测后，才把状态改为 `已通过`。
3. 新增比赛时，同时更新对应目录的 README 和本文件的总索引。
4. 编译产物、IDE 配置和刷题插件数据不作为题解源码；`.gitignore` 已给出推荐忽略规则。
