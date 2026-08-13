// 比赛：AtCoder Beginner Contest 121
// 题目：ABC121 C - Energy Drink Collector
// 链接：https://atcoder.jp/contests/abc121/tasks/abc121_c
// 状态：待验证
// 算法：贪心、排序

#include<bits/stdc++.h>
using namespace std;
using i128 = __int128;
using ll = long long;

struct node{
    // 价格
    ll a;
    // 数量
    ll b;
};

const int N = 1e5 + 10;
node buy[N];

void print(i128 x){
    if (x == 0){
        cout << 0;
        return;
    }
    if (x < 0){
        cout << '-';
        x = -x;
    }
    string s;
    while (x){
        s.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> buy[i].a >> buy[i].b;
    }
    sort(buy + 1, buy + n + 1, [](const node& x, const node& y){
        if (x.a != y.a){
            return x.a < y.a;
        }
        return x.b > y.b;
    });
    i128 ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        if (buy[i].b <= m - cnt){
            ans += (i128)buy[i].a * buy[i].b;
            cnt += buy[i].b;
        } else {
            int k = m- cnt;
            ans += (i128)buy[i].a * k;
            break;
        }
    }
    print(ans);
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
