# XCPC 代码仓库

本仓库按 **平台 → 比赛/题号** 归档，共有 25 个 C++ 源文件：24 个题目文件和 1 个本地测试文件。题目链接、代码状态与源码入口汇总如下。

## 状态说明

- `已通过`：平台账号显示该题已经通过；若仓库文件并非完整版本，会在备注中单独说明。
- `未通过`：实现形态较完整，但平台账号显示该题尚未通过。
- `待验证`：已有完整实现，但仓库中没有可核对的在线评测记录。
- `未完成`：空框架、部分实现，或实现与题意不符。
- `本地测试`：不对应在线评测题目。

> 整理时未删除 `.exe`、`.cph`、`.idea` 或 `.vscode` 等已有文件。

## 当前验证结果

- 25/25 个 `.cpp` 文件通过 `g++ -std=c++17 -fsyntax-only` 语法检查。
- 8 个带有本地期望输出、且实现不是已知草稿的文件共运行 18 组样例，18/18 组输出一致（比较时忽略行尾空白）。
- 样例通过不等于在线评测通过；牛客与 QOJ 题目的账号状态已于 2026-08-08 通过已登录页面核对。

## AtCoder

| 比赛 | 题目 | 代码 | 状态 | 主题 |
| --- | --- | --- | --- | --- |
| ABC 468 | [A - Maximal Value](https://atcoder.jp/contests/abc468/tasks/abc468_a) | [A_Maximal Value.cpp](./AtCoder/ABC468/A_Maximal%20Value.cpp) | 待验证 | 枚举、局部最大值 |
| ABC 468 | 本地 Hello World 测试 | [test.cpp](./AtCoder/ABC468/test.cpp) | 本地测试 | 环境测试 |

详见 [AtCoder/README.md](./AtCoder/README.md)。

## 洛谷

| 题号 | 题目 | 代码 | 状态 | 主题 |
| --- | --- | --- | --- | --- |
| P1042 | [乒乓球](https://www.luogu.com.cn/problem/P1042) | [P1042_乒乓球.cpp](./LuoGu/P1042_乒乓球.cpp) | 待验证 | 模拟 |
| P1563 | [玩具谜题](https://www.luogu.com.cn/problem/P1563) | [P1563_玩具谜题.cpp](./LuoGu/P1563_玩具谜题.cpp) | 未完成 | 环形模拟 |
| P2240 | [部分背包问题](https://www.luogu.com.cn/problem/P2240) | [P2240_部分背包问题.cpp](./LuoGu/P2240_部分背包问题.cpp) | 待验证 | 贪心、排序 |
| P2670 | [扫雷游戏](https://www.luogu.com.cn/problem/P2670) | [P2670_扫雷游戏.cpp](./LuoGu/P2670_扫雷游戏.cpp) | 待验证 | 网格模拟 |

详见 [LuoGu/README.md](./LuoGu/README.md)。

## 牛客

| 比赛 | 比赛 ID | 目录 | 代码概况 |
| --- | ---: | --- | --- |
| 2026 牛客暑期多校训练营 4 | 133879 | [2026-mutlischool-4](./NowCoder/2026-mutlischool-4/) | B 已通过；F 未完成且未通过 |
| 2026 牛客暑期多校训练营 5 | 133880 | [2026-mutlischool-5](./NowCoder/2026-mutlischool-5/) | 账号已通过 E、K；本地 E 仍为未完成版本 |
| 2026 牛客暑期多校训练营 6 | 133881 | [2026-multischool-6](./NowCoder/2026-multischool-6/) | G 未通过；I、J 未完成且未通过 |
| 2026 牛客暑期多校训练营 7 | 133882 | [2026-mutlischool-7](./NowCoder/2026-mutlischool-7/) | D 已通过；A 未完成且未通过 |
| 牛客周赛 Round 155 | 138240 | [weeklyround-155](./NowCoder/weeklyround-155/) | A、B 已通过；C 未完成且未通过 |

详见 [NowCoder/README.md](./NowCoder/README.md)。目录名中的 `mutlischool` 是原有拼写，暂不改动，以免破坏本地工具中的路径记录。

## QOJ

| 比赛 | 题目 | 代码 | 状态 | 主题 |
| --- | --- | --- | --- | --- |
| 2025 CCPC 女生专场 | [A - 环状线](https://qoj.ac/contest/2564/problem/14450) | [A_环状线.cpp](./ccpc_women_2025/A_环状线.cpp) | 已通过 | 环形距离、分类讨论 |
| 2025 CCPC 女生专场 | [B - 爬山](https://qoj.ac/contest/2564/problem/14451) | [B_爬山.cpp](./ccpc_women_2025/B_爬山.cpp) | 未完成 | 空框架 |
| 2025 CCPC 女生专场 | [J - 后鼻嘤](https://qoj.ac/contest/2564/problem/14459) | [J_后鼻嘤.cpp](./ccpc_women_2025/J_后鼻嘤.cpp) | 已通过 | 字符串模拟 |

比赛与题面入口见 [ccpc_women_2025/README.md](./ccpc_women_2025/README.md)。

Codeforces 账号 `Moyichen0219` 的在线记录已核对；当前仓库没有对应源码，因此未创建 Codeforces 已实现条目。

## 维护约定

1. 在线题目的源码统一使用 `题目编号_题目名字.cpp` 命名；本地测试文件除外。文件头记录比赛、题目链接、状态和算法标签。
2. 只有确认通过评测后，才把状态改为 `已通过`。
3. 新增比赛时，同时更新对应目录的 README 和本文件的总索引。
4. 编译产物、IDE 配置和刷题插件数据不作为题解源码；`.gitignore` 已给出推荐忽略规则。
