// 比赛：竞极比赛 2093329939779661825
// 题目：B 数轴搬运（本地语义命名）
// 链接：http://47.120.23.84/contest/2093329939779661825/2093331392749481985
// 状态：待验证
// 算法：贪心、排序、分组

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;

ll count(vector<ll> x){
    if (x.empty()){
        return 0;
    }
    ll ans = 0;
    sort(x.begin(), x.end(), greater<ll>());
    for (int i = 0; i < x.size(); i += k){
        ans += 2 * x[i];
    }
    return ans;
}

void solve(){
    cin >> n >> k;
    vector <ll> l, r;
    ll ml = 0;
    ll mr = 0;
    for (int i = 1; i <= n; i ++){
        ll x;
        cin >> x;
        if (x > 0){
            r.push_back(x);
            mr = max(mr, x);
        } else {
            l.push_back(-x);
            ml = max(ml, -x);
        }
    }

    if (ml < mr){
        cout << count(l) + count(r) - mr << '\n';
    } else {
        cout << count(l) + count(r) - ml << '\n';
    }
}

int  main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t --){
        solve();
    }
    return 0;
}
