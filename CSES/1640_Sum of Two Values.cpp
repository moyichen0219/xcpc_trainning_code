// 比赛/平台：CSES Problem Set
// 题目：1640 Sum of Two Values
// 链接：https://cses.fi/problemset/task/1640/
// 状态：待验证
// 算法：排序、双指针、下标恢复

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    int x;
    int id;

    bool operator < (const node& other) const{
        if (x != other.x){
            return x < other.x;
        }

        return id < other.id;
    }
};

const int N = 2e5 + 10;
node a[N];

void solve(){
    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; i ++){
        cin >> a[i].x ;
        a[i].id = i;
    }

    sort(a + 1, a + n + 1);

    int l = 1;
    int r = n;

    while (l < r){
        ll sum = a[l].x + a[r].x;

        if (sum == x){
            cout << a[l].id << ' ' << a[r].id << '\n';
            return ;
        } else if (sum < x){
            l ++;
        } else {
            r --;
        }
    }

    cout << "IMPOSSIBLE" << '\n';
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
