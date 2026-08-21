// 比赛：Codeforces Round 274 (Div. 2)
// 题目：479C - Exams
// 链接：https://codeforces.com/problemset/problem/479/C
// 状态：已通过
// 算法：排序、贪心

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e3 + 10;
struct node{
    int a, b;
};
node exams[N];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> exams[i].a >> exams[i].b;
    }
    sort(exams + 1, exams + n + 1, [](const node& x, const node& y){
        if (x.a != y.a){
            return x.a < y.a;
        }
        return x.b < y.b;
    });
    // 上次参加考试的时间
    int lst = 0;
    // 上次出成绩的时间
    int cur = 0;
    for (int i = 1; i <= n; i ++){
        cur = exams[i].a;
        if (exams[i].a >= lst && exams[i].b >= lst){
            lst = min(exams[i].a, exams[i].b);
        } else if (exams[i].a >= lst && exams[i].b < lst){
            lst = exams[i].a;
        } else if (exams[i].a < lst && exams[i].b >= lst){
            lst = exams[i].b;
        }
    }
    cout << lst << '\n';
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
