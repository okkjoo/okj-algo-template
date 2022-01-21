#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> PII;

const int N = 50;
int h, w;      //宽高,w 行 h 列
char g[N][N];  //地图
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cnt = 0;

void dfs(int x, int y) {
  cnt++;          //能到就说明是黑格子，记录++
  g[x][y] = '#';  //转为红格子，也就是标记为访问过
  for (int i = 0; i < 4; i++) {
    int a = x + dx[i], b = y + dy[i];
    if (a < 0 || a >= h || b < 0 || b >= w || g[a][b] == '#') continue;
    dfs(a, b);
  }
}

int main() {
  // cpp中逗号表达式的值是最后一个表达式的值，即n||m都为0时退出
  while (cin >> w >> h, h || w) {
    cnt = 0;
    for (int i = 0; i < h; i++)
      scanf("%s", g[i]);  //一次读入一行，因为输入时也没有隔空格

    int x = 0, y = 0, flag = 0;  // flag用来跳出二重循环
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (g[i][j] == '@') {  //找到起点
          x = i, y = j;
          flag = 1;
        }
      }
      // cout << "XY" << x << " " << y << endl;
      if (flag) break;
    }
    dfs(x, y);
    cout << cnt << "\n";
  }
  return 0;
}