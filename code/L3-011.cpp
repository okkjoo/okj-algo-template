#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, n, m) for (int i = n; i < m; ++i)

struct node {
  int id, dis;

  //方便后面的优先队列
  bool friend operator<(const node &a, const node &b) { return a.dis > b.dis; }
};

int n, k, s, t, cnt, d,
    enemyNum[205],  //各个大本营敌军数量
    enemyAll[205],  //到该点的总共的歼敌数量
    pre[205],       //到该大本营的上一个点
    Dis[205],       //起点到各点的最短距离
    vis[205],
    sum[205],         //到该点路线数量
    liberation[205];  //到该店解放的大本营数

//映射
map<string, int> ntoi;  // name->id
map<int, string> iton;  // id->name

vector<pair<int, int>> E[205];  //存图, <u,d>:E[i]到u点,权为d
vector<int> ans;
string S, T, u, v;

void Dijskra() {
  fill(Dis, Dis + 205, 1e9);
  Dis[s] = 0;
  sum[s] = 1;
  priority_queue<node> Q;
  Q.push(node{s, 0});
  while (!Q.empty()) {
    int now = Q.top().id, nowD = Q.top().dis;
    Q.pop();
    if (vis[now]) continue;
    vis[now] = 1;
    for (auto it : E[now]) {
      int itV = it.first, itD = it.second;
      if (Dis[itV] > nowD + itD) {
        Dis[itV] = nowD + itD;
        enemyAll[itV] = enemyAll[now] + enemyNum[itV];
        sum[itV] = sum[now];
        liberation[itV] = liberation[now] + 1;
        Q.push(node{itV, Dis[itV]});
        pre[itV] = now;
      } else if (Dis[itV] == nowD + itD) {
        sum[itV] += sum[now];
        if (liberation[itV] < liberation[now] + 1) {
          liberation[itV] = liberation[now] + 1;
          enemyAll[itV] = enemyAll[now] + enemyNum[itV];
          Q.push(node{itV, Dis[itV]});
          pre[itV] = now;
        } else if (liberation[itV] == liberation[now] + 1) {
          if (enemyAll[itV] < enemyAll[now] + enemyNum[itV]) {
            enemyAll[itV] = enemyAll[now] + enemyNum[itV];
            Q.push(node{itV, Dis[itV]});
            pre[itV] = now;
          }
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k >> S >> T;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> d;
    ntoi[u] = ++cnt;
    iton[cnt] = u;
    enemyNum[cnt] = d;
  }
  //起点的映射
  ntoi[S] = 0, iton[0] = S;
  //终点
  t = ntoi[T];

  for (int i = 0; i < k; i++) {
    cin >> u >> v >> d;
    //存边
    E[ntoi[u]].push_back({ntoi[v], d});
    E[ntoi[v]].push_back({ntoi[u], d});
  }
  Dijskra();
  d = t;
  while (d) {
    ans.push_back(d);
    d = pre[d];
  }
  cout << iton[0];
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << "->" << iton[ans[i]];
  }
  cout << "\n" << sum[t] << " " << Dis[t] << " " << enemyAll[t] << "\n";
  return 0;
}