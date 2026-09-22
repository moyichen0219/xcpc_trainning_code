// 比赛：洛谷
// 题目：P1803 - 凌乱的yyy / 线段覆盖
// 链接：https://www.luogu.com.cn/problem/P1803
// 状态：已通过
// 算法：贪心、区间调度、排序

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    int st;
    int ed;

    // 结束时间最早的优先
    bool operator < (const node& other) const {
        if (ed != other.ed){
            return ed < other.ed;
        }
        return st < other.st;
    }
};

const int N = 1e6 + 10;
node a[N];

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++){
        cin >> a[i].st >> a[i].ed;
    }

    sort(a + 1, a + n + 1);

    int lst = -1;
    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        if (a[i].st >= lst){
            lst = a[i].ed;
            cnt ++;
        }
    }

    cout << cnt << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t  = 1;
    while (t --){
        solve();
    }
    return 0;
}
