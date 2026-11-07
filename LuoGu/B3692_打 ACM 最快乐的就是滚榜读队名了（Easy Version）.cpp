// 比赛/平台：洛谷
// 题目：B3692 [语言月赛202212] 打 ACM 最快乐的就是滚榜读队名了（Easy Version）
// 链接：https://www.luogu.com.cn/problem/B3692
// 状态：未完成
// 算法：ICPC 榜单、封榜滚榜、模拟（待实现）

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;

struct node{
    int times;
    int ac;
    string name;

    vector <bool> AC;
    vector <int> WA;

    bool operator < (const node& other) const {
        if (ac != other.ac){
            return ac > other.ac;
        }
        return times < other.times;
    }
};

int count_time(string s){
    int xx = 0;
    int yy = 0;
    int zz = 0;

    char c1, c2;

    istringstream iss(s);
    iss >> xx >> c1 >> yy >> c2 >> zz;

    int time = xx * 60 + yy;

    return time;
}

struct NODE{
    char c;
    int time;
    string status;

    bool operator < (const NODE& other) const {
        if (c != other.c){
            return c < other.c;
        }
        return time < other.time;
    }
};

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    unordered_map<string, node> mp;
    unordered_map<string, priority_queue<NODE, vector<NODE>, greater<NODE>>> waiting_q;

    for (int i = 1; i <= k; i ++){
        string time;
        cin >> time;

        int t = count_time(time);

        char c;
        cin >> c;

        string name;
        cin >> name;

        if (mp.find(name) == mp.end()){
            mp[name].name = name;
            mp[name].WA.assign(n, 0);
            mp[name].AC.assign(n, false);
        }
        cin.get();

        string status;
        getline(cin, status);

        if (t <= 240){
            if (status == "Accepted" && mp[name].AC[c - 'A'] == false){
                mp[name].AC[c - 'A'] = true;
                mp[name].times += t + mp[name].WA[c - 'A'] * 20;
                mp[name].ac ++;
            } else {
                mp[name].WA[c - 'A'] ++;
            }
        } else {
            waiting_q[name].push({c, t, status});
        }
    }

    vector <node> ans;
    for (auto &[name, nn] : mp){
        ans.push_back(nn);
    }

    sort(ans.begin(), ans.end());


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

int id = 0;

struct Problem{
    int flag = 0;
    int time = 0;
};

struct Node{
    string name;
    int times;
    int ac;
    int first_ac = 0;
    Problem AC[26];
    Problem WA[26];
};

bool cmp (Node a, Node b){
    if (a.ac != b.ac){
        return a.ac > b.ac;
    }
    if (a.times != b.times){
        return a.times < b.times;
    }
    return a.first_ac < b.first_ac;
}

int count_time(string s){
    int xx = 0;
    int yy = 0;
    int zz = 0;

    char c1, c2;

    istringstream iss(s);
    iss >> xx >> c1 >> yy >> c2 >> zz;

    int time = xx * 60 + yy;

    return time;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector <Node> team;
    map <string, int> mp;

    for (int i = 1; i <= k; i ++){
        string t;
        cin >> t;

        char c;
        cin >> c;

        string name;
        cin >> name;

        cin.get();

        string status;
        cin >> status;

        int time = count_time(t);

        // 如果是第一次遇见这只队伍
        if (mp.find(name) == mp.end()){

        } else {

        }
    }
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
