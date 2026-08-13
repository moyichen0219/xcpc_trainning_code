// 比赛：2026 牛客暑期多校训练营 8
// 题目：M - KV Cache
// 链接：https://ac.nowcoder.com/acm/contest/133883/M
// 状态：未完成
// 算法：Trie（草稿）

/* #include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct trie {
  int nex[100000][26], cnt;
  bool exist[100000];  // 该结点结尾的字符串是否存在

  void insert(char *s, int l) {  // 插入字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
      p = nex[p][c];
    }
    exist[p] = true;
  }

  bool find(char *s, int l) {  // 查找字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) return 0;
      p = nex[p][c];
    }
    return exist[p];
  }
};

const int N = 1e6 + 10;
int ch[N][26];
int tag[N];
int tot = 1;

void solve(){
    int n, m;
    cin >> n >> m;
    int res = 0;
    for (int i = 1; i <= n; i ++){
        string s;
        cin >> s;
        int u = 1;
        for (int j = 1; s[j]; j ++){
            int c = s[j] - 'a';
            u = ch[u][c];
            // 不存在对应的边
            if (!u){
                res ++;
                ch[u][c] = ++ tot;
            }
            u = ch[u][c];
        }
        if (tag[u] == 1){
            // 这一整个字符串已被访问过
            tag[u] = 2;
        } else if (tag[2] == 2){
            // 这一整个字符串都被访问过
            res -= s.length() + 1;
        } else {
            tag[u] = 1;
        }
    }
    cout << res << '\n';
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

const int N = 1e6 + 10;

void solve(){
    int n, m;
    cin >> n >> m;

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
