#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

const int N = 1010;
int n, ans;
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  //方向数组
char a[N][N];                                      //地图
int vis[N][N] = {0};                               //标记是否访问过
int flag;                                          //标记单个岛是否淹没

//对(x,y)进行深搜，找出其相连的小岛，判断该连通块是否会完全淹没
void dfs(int x, int y) {
  vis[x][y] = 1;  //标记为访问过

  //四周都是陆地不会被淹没
  if (a[x][y + 1] == '#' && a[x][y - 1] == '#' && a[x - 1][y] == '#' &&
      a[x + 1][y] == '#') {
    //只要有一个不会被淹没，跳出该轮dfs的时候flag都为1——即该连通块不会完全淹没
    flag = 1;
  }
  //继续深搜其周围的陆地
  for (int i = 0; i < 4; i++) {
    int nx = x + d[i][0], ny = y + d[i][1];
    if (vis[nx][ny] == 0 && a[nx][ny] == '#') {  //没被访问过 && 是陆地
      //继续DFS
      dfs(nx, ny);
    }
  }
}
int main() {
  cin >> n;
  //注意下标从1开始，这样四周就不是'#'-->就等于题目中说的四周为海
  FOR(i, 1, n + 1) {
    FOR(j, 1, n + 1) { cin >> a[i][j]; }
  }
  FOR(i, 1, n + 1) {
    FOR(j, 1, n + 1) {
      if (a[i][j] == '#' && vis[i][j] == 0) {  //是陆地并且没访问过
        flag = 0;
        dfs(i, j);  //遍历这个点及其连通块
        if (flag == 0) {  //出来时，flag还是0就说明该点相连的全部都淹没了
          ans++;
        }
      }
    }
  }
  cout << ans;
  return 0;
}