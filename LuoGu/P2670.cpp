// 平台：洛谷
// 题目：P2670 [NOIP 2015 普及组] 扫雷游戏 - https://www.luogu.com.cn/problem/P2670
// 状态：待验证（已有完整实现和本地样例，但未记录是否通过评测）
// 分类：网格模拟、八方向枚举
// 创建：MYC，2026/8/2

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

void solve(){
    int n, m;
    cin >> n >> m;
    vector <vector <char>> g(n, vector<char>(m));
    for (int i = 0; i < n;  i ++){
        for (int j = 0; j < m; j ++){
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n;  i ++){
        for (int j = 0; j < m; j ++){
            if (g[i][j] == '*'){
                cout << g[i][j];
            } else {
                int cnt = 0;
                for (int x = 0; x < 8; x ++){
                    int nx = i + dx[x];
                    int ny = j + dy[x];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m){
                        if (g[nx][ny] == '*'){
                            cnt ++;
                        }
                    }
                }
                cout << cnt;
            }
        }
        cout << '\n';
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
