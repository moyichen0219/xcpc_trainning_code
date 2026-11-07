// 比赛/平台：洛谷
// 题目：P1007 独木桥
// 链接：https://www.luogu.com.cn/problem/P1007
// 状态：已通过
// 算法：贪心、等价交换、极值

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int l;
    cin >> l;

    int n;
    cin >> n;

    int ans1 = 0;
    int ans2 = 0;

    for (int i = 1; i <= n; i ++){
        int x;
        cin >> x;

        ans1 = max(ans1, min(x, l - x + 1));
        ans2 = max(ans2, max(x, l - x + 1));
    }

    cout << ans1 << ' ' << ans2 << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t --){
        solve();
    }
    return 0;
}
