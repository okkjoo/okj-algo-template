#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, n, m) for (int i = n; i < m; ++i)
const int inf = INT_MAX, N = 505;
int dis[N],      //起点到各点的距离
    Time[N],     //起点到各点的时间
    e[N][N],     // a->b距离
    w[N][N],     // a->b两地时间
    Timepre[N],  //时间最短路径中的每个点的前驱节点
    weight[N];   //算时间最短路径时，起点到点的长度
bool vis[N];
vector<int> timePath, disPath, tempPath, disPre[N];
int st,             //起点
    fin,            //终点
    minnode = inf;  //最短路径中最少的节点数

//查找时间最短路径
void dfstimePath(int v) {  //传入终点
  timePath.push_back(v);
  if (v == st) return;
  dfstimePath(Timepre[v]);
}
//查找路径最短路径
void dfsdisPath(int v) {
  tempPath.push_back(v);
  if (v == st) {
    if (tempPath.size() < minnode) {
      minnode = tempPath.size();
      disPath = tempPath;
    }
    tempPath.pop_back();
    return;
  }
  for (int i = 0; i < disPre[v].size(); i++) {
    dfsdisPath(disPre[v][i]);
  }
  tempPath.pop_back();
}
int main() {
  ios::sync_with_stdio(false);
  //初始化
  fill(dis, dis + N, inf);
  fill(Time, Time + N, inf);
  fill(weight, weight + N, inf);
  fill(e[0], e[0] + N * N, inf);
  fill(w[0], w[0] + N * N, inf);

  int n, m;
  scanf("%d %d", &n, &m);
  int a, b, flag, len, t;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
    e[a][b] = len;
    w[a][b] = t;
    if (flag != 1) {
      e[b][a] = len;
      w[b][a] = t;
    }
  }
  scanf("%d %d", &st, &fin);  //起点终点

  Time[st] = 0;
  for (int i = 0; i < n; i++) {
    Timepre[i] = i;
  }
  //时间最短Dij
  for (int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for (int j = 0; j < n; j++) {
      if (vis[j] == false && Time[j] < minn) {
        u = j;
        minn = Time[j];
      }
    }
    if (u == -1) break;
    vis[u] = true;
    for (int v = 0; v < n; v++) {
      if (vis[v] == false && w[u][v] != inf) {
        if (w[u][v] + Time[u] < Time[v]) {
          Time[v] = w[u][v] + Time[u];
          Timepre[v] = u;
          weight[v] = weight[u] + e[u][v];
        } else if (w[u][v] + Time[u] == Time[v] &&
                   weight[v] > weight[u] + e[u][v])
        //时间相等的话就要看距离
        {
          weight[v] = weight[u] + e[u][v];
          Timepre[v] = u;
        }
      }
    }
  }

  //存储时间最短路径
  dfstimePath(fin);

  //开始查找
  fill(vis, vis + N, false);
  dis[st] = 0;
  for (int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for (int j = 0; j < n; j++) {
      if (vis[j] == false && minn > dis[j]) {
        u = j;
        minn = dis[j];
      }
    }
    if (u == -1) break;
    vis[u] = true;
    for (int v = 0; v < n; v++) {
      if (vis[v] == false && e[u][v] != inf) {
        if (e[u][v] + dis[u] < dis[v])
        //有更短的路径
        {
          dis[v] = e[u][v] + dis[u];
          disPre[v].clear();  //那之前保存的路径都不用了
          disPre[v].push_back(u);
        } else if (e[u][v] + dis[u] == dis[v]) {
          disPre[v].push_back(u);  //如果长度相似，就都存下来，后面dfs比较节点数
        }
      }
    }
  }

  //存储最短路径
  dfsdisPath(fin);

  printf("Time = %d", Time[fin]);
  if (disPath == timePath) {
    printf("; Distance = %d: ", dis[fin]);
  } else {
    printf(": ");
    for (int i = timePath.size() - 1; i >= 0; i--) {
      printf("%d", timePath[i]);
      if (i != 0) printf(" => ");
    }
    printf("\n");
    printf("Distance = %d: ", dis[fin]);
  }
  for (int i = disPath.size() - 1; i >= 0; i--) {
    printf("%d", disPath[i]);
    if (i != 0) printf(" => ");
  }
  return 0;
}