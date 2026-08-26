// 模板：扩展欧几里得算法
// 状态：模板
// 复杂度：O(log min(a, b))

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll exgcd(ll a, ll b, ll&x, ll &y){
    if (b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = exgcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - a/ b * y1;

    return d;
}

void solve(){

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
