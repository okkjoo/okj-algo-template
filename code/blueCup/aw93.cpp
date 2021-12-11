#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, n, m) for (int i = n; i < m; ++i)

int n, m;
const int N = 30;
int path[N];

void dfs(int u, int start) {  //准备选第u个数，起点为start
  if (n - start + u < m) return;  //剪枝，已经选不出m个数字了，这条路就丢弃
  if (u == m + 1) {  //到位了
    for (int i = 1; i <= m; i++) {
      cout << path[i] << " ";
    }
    cout << "\n";
    return;
  }
  for (int i = start; i <= n; i++) {
    path[u] = i;
    dfs(u + 1, i + 1);
    path[u] = 0;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  dfs(1, 1);
  return 0;
}