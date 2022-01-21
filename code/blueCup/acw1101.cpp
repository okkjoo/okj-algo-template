#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

const int N = 210;
int dis[N][N];
char a[N][N];
void bfs(PII start) {
  queue<PII> q;
  q.push(start);
  while (!q.empty()) {
    PII u = q.front();
    q.pop();
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    //遍历四个方向
    for (int i = 0; i < 4; i++) {
      int x = u.first + dx[i], y = u.second + dy[i];
      if (a[x][y] == '#') continue;  //是墙直接下一个
      if (a[x][y] == '.') {
        dis[x][y] = dis[u.first][u.second] + 1;
        a[x][y] = '#';  //遍历过的点直接记录为墙防止再次进入多余循环
        q.push({x, y});
      }
      if (a[x][y] == 'E') {  //找到终点
        cout << dis[u.first][u.second] + 1 << "\n";
        return;
      }
    }
  }
  cout << "oop!\n";  //没找到
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(a, '#', sizeof(a));  //地图全初始化为墙
    memset(dis, 0, sizeof(dis));
    int n, m;
    cin >> n >> m;
    PII start;
    //下标从1开始，这样图的边缘也就是墙
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'S') {  //记录起点
          start = {i, j};
          // start.first = i, start.second = j;
          a[i][j] = '#';  //记录为墙防止进去bfs后多余的重复遍历
        }
      }
    }
    bfs(start);
  }
  return 0;
}