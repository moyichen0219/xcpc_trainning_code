// 比赛：AtCoder Beginner Contest 271
// 题目：C - Manga
// 链接：https://atcoder.jp/contests/abc271/tasks/abc271_c
// 状态：已通过
// 算法：贪心、排序、双指针

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1);
    map<int, int> mp;
    set <int> ok;
    int cnt = 0;
    int lst = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++){
        if (a[i] == lst + 1){
            ok.insert(a[i]);
            lst = a[i];
        } else {
            mp[a[i]] ++;
            cnt ++;
        }
    }
    if (ok.size()){
        lst = *ok.rbegin();
    } else {
        lst = 0;
    }
    while (true){
        int need = 2;
        bool p = false;
        for (auto [x, k] : mp){
            if (x == lst + 1){
                ok.insert(x);
                lst = x;
                cnt --;
                p = true;
            } else if (k >= 2){
                mp[x] -= 2;
                ok.insert(lst + 1);
                cnt --;
                p = true;
                lst ++;
            } else if (need == 0){
                mp[x] = 0;
                ok.insert(lst + 1);
            } else {
                need -= mp[x];
                mp[x] = 0;
            }
        }
        if (need > 0 || cnt == 0){
            break;
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
} */

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    vector <int> b(n + 1);
    for (int i = 1; i <= n; i ++){
        // 每个数只存一个，多余的用来删去换来新的一卷
        if (i == 1 || a[i] != a[i - 1]){
            b[i] = a[i];
        } else{
            b[i] = INT_MAX;
        }
    }
    // 将已有的从小到大排序放在前面
    sort(b.begin() + 1, b.begin() + n + 1);
    int cnt = 1;
    int l = 1;
    int r = n;
    while (l <= r){
        if (b[l] == cnt){
            l ++;
            cnt ++;
        } else {
            if (r - l + 1 >= 2){
                r -= 2;
                cnt ++;
            } else {
                break;
            }
        }
    }
    cout << cnt - 1 << '\n';
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
