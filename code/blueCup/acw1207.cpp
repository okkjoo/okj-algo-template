#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

const int N = 100010;
//用链式前向星存图
int h[N], ne[2 * N], e[2 * N], w[2 * N],
    idx = 0;  //双向图，所以除了起点数组以外都要*2
ll ans = 0;

//加边操作
void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dp[N];
void DP(int u, int p) {
  dp[u] = 0;
  for (int i = h[u]; i != -1; i = ne[i]) {
    int v = e[i];
    if (v == p) {
      continue;
    }
    DP(v, u);
    ans = max(
        ans,
        (ll)(dp[u] + dp[v] +
             w[i]));  //直接用一个全局变量得到最大值，ll强制转换一下数据类型使得max函数不会报错
    dp[u] = max(dp[u], dp[v] + w[i]);
  }
}
int n, a, b, c;
int main() {
  memset(h, -1, sizeof h);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b >> c;
    add(a, b, c), add(b, a, c);
  }
  DP(1, -1);  //任取一点开始搜，这里默认从1号点搜，其没有父结点，父亲为-1
  ans = (21 + ans) * ans / 2;  //计算总花费
  cout << ans;

  return 0;
}