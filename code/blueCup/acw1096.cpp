#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

const int N = 110;
int l, r, c;      //层数、每层的行数、列数
char g[N][N][N];  //存图
int res[N][N][N];  //记录到该点的步数，并且初始化为-1(-1代表没访问过)

//点结构体
struct Point {
  int z, x, y;
} st, ed;  //起点、终点

//判断条件较多，就直接抽取出来当一个函数
bool check(int z, int x, int y) {
  //出界
  if (z < 1 || z > l || x < 1 || x > r || y < 1 || y > c) return false;
  //访问过
  if (res[z][x][y] != -1) return false;
  //是阻碍
  if (g[z][x][y] == '#') return false;
  return true;
}

void bfs() {
  queue<Point> Q;
  Q.push(st);
  res[st.z][st.x][st.y] = 0;  //初始化
  //偏移量:东南西北上下
  int dx[6] = {1, 0, -1, 0, 0, 0};
  int dy[6] = {0, 1, 0, -1, 0, 0};
  int dz[6] = {0, 0, 0, 0, -1, 1};

  while (Q.size()) {
    auto u = Q.front();
    Q.pop();

    //遍历各个方向
    for (int i = 0; i < 6; i++) {
      int z = u.z + dz[i], x = u.x + dx[i], y = u.y + dy[i];
      if (check(z, x, y)) {
        Q.push({z, x, y});
        res[z][x][y] = res[u.z][u.x][u.y] + 1;
      }
    }
  }
}

int main() {
  // while (scanf("%d%d%d", &l, &r, &c) && l) {  // l==0时退出
  while (cin >> l >> r >> c, l) {  // l==0时退出
    //多组输入，所以每次都要初始化数组
    memset(res, -1, sizeof(res));
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < r; j++) {
        string s;
        cin >> s;
        for (int k = 0; k < c; k++) {
          //图的问题，坐标最好都从1 开始，这样默认效果就是四周有墙
          g[i + 1][j + 1][k + 1] = s[k];
          //记录起点和终点
          if (s[k] == 'S')
            st = {i + 1, j + 1, k + 1};
          else if (s[k] == 'E')
            ed = {i + 1, j + 1, k + 1};
        }
      }
    }
    bfs();
    int ans = res[ed.z][ed.x][ed.y];
    if (ans != -1)
      printf("Escaped in %d minute(s).\n", ans);
    else
      printf("Trapped!\n");
  }
  return 0;
}