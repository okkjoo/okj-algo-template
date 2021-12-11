#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, n, m) for (int i = n; i < m; ++i)

int n;
const int N = 16;
int st[N] = {0};  //状态
// 0 还没考虑
// 1 选择
// 2 不选择
void dfs(int u) {
  if (u > n) {  //到位了
    for (int i = 1; i <= N; i++) {
      if (st[i] == 1) cout << i << " ";
    }
    cout << "\n";
    return;
  }
  st[u] = 1;   //选的情况
  dfs(u + 1);  //进去递归
  st[u] = 0;   //回溯

  st[u] = 2;   //不选的情况
  dfs(u + 1);  //进去递归
  st[u] = 0;   //回溯
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  dfs(1);
  return 0;
}