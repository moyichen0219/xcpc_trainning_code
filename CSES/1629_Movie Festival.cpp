// 比赛：CSES Sorting and Searching
// 题目：1629 - Movie Festival
// 链接：https://cses.fi/problemset/task/1629/
// 状态：待验证
// 算法：贪心、区间调度、排序

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    int st;
    int ed;

    bool operator < (const node& other)const{
        if (ed != other.ed){
            return ed < other.ed;
        }
        return st < other.st;
    }
};

const int N = 2e5 + 10;
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
            cnt ++;
            lst = a[i].ed;
        }
    }

    cout << cnt << '\n';
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
