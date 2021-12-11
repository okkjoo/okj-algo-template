#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, n, m) for (int i = n; i < m; ++i)
const int N = 10;
int st[N];     // 0表示还没放，其余表示放了什么
bool book[N];  //标记是否用过
int n;
void dfs(int u) {
  if (u > n) {
    for (int i = 1; i <= n; i++) {
      cout << st[i] << " ";
    }
    cout << endl;
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!book[i]) {
      st[u] = i;
      book[i] = 1;
      dfs(u + 1);
      st[u] = 0;
      book[i] = 0;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  dfs(1);
  return 0;
}