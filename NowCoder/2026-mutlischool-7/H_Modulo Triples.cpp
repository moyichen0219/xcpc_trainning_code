// 比赛：2026 牛客暑期多校训练营 7（133882）
// 题目：H - Modulo Triples - https://ac.nowcoder.com/acm/contest/133882/H
// 状态：已通过（团队提交 84415833，2026-08-09 核对）
// 分类：构造、排列、模运算

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    // 发现 n = 1 时需要特判，2 0 1
    // 其余构造方式，让尽可能多的y + z = x成立 (x > z > y)
    // 因此，可以想到，使n - 1个三元组满足该情况，剩余一组构造x 0 1

    // 2 (0-2, 3-5)
    // 5 2 3
    // 4 0 1

    // 3  (0-2, 3-5, 6-8)
    // 8 2 6
    // 7 3 4
    // 5 0 1

    // 4
    // 11 3 8      11 2 9
    // 10 4 6      10 4 6
    // 9  2 7      8  3 5
    // 5  0 1      7  0 1

    // x + y + z = 2x
    // 2 * sum(x_i) + (剩余的x) + 0 + 1 = (3 * n - 1) * 3 * n / 2

    // z = 3 * (n - 1)    -=3
    // y = 2
    if (n == 1){
        cout << "2 0 1\n";
        return ;
    }
    for (int i = 2, j = 3 * (n - 1); ; j -= 3){
        if (j == 0){
            cout << i << ' ' << 0 << ' ' << 1 << '\n';
            return ;
        }
        cout << i + j << ' ' << min(i, j) << ' ' << max(i , j) << '\n';
        if (i % 3 == 1){
            i ++;
        } else {
            i += 2;
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
