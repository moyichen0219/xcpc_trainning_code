// 比赛：NOIP 1998 普及组
// 题目：P1009 - 阶乘之和
// 链接：https://www.luogu.com.cn/problem/P1009
// 状态：已通过
// 算法：高精度、乘法、加法

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void mul (vector <int> &a, int x){
    int car = 0;

    for (int i = 0; i < a.size(); i ++){
        int cur = a[i] * x + car;
        a[i] = cur % 10;
        car = cur / 10;
    }

    while (car){
        a.push_back(car % 10);
        car /= 10;
    }
}

void add (vector <int> &a, const vector <int>& b){
    int car = 0;

    for (int i = 0; i < b.size() || car ; i ++){
        if (i == a.size()){
            a.push_back(0);
        }
        int cur = a[i] + car;

        if (i < b.size()){
            cur += b[i];
        }

        a[i] = cur % 10;
        car = cur / 10;
    }

}

void solve(){
    int n;
    cin >> n;

    vector <int> fac(1, 1);
    vector <int> sum(1, 0);

    for (int i = 1; i <= n; i ++){
        mul(fac, i);
        add(sum, fac);
    }

    for (int i = sum.size() -1; i >= 0; i --){
        cout << sum[i] ;
    }

    cout << '\n';
}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t= 1;
    while (t --){
        solve();
    }
    return 0;
}
