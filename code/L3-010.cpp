#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, n, m) for (int i = n; i < m; ++i)

int t[1 << 20];
int n, num;
void BST(int a) {
  //找到可放入的空节点
  if (t[a] == 0)
    t[a] = num;
  else if (t[a] < num)  // num大于该节点，放到左子树中
    BST(a << 1);
  else
    BST(a << 1 | 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  FOR(i, 0, n) {
    cin >> num;
    BST(1);  //从根节点开始找点放入num
  }
  bool flag = 1;
  for (int cnt = 1, k = 1; cnt <= n; k++) {
    if (t[k] == 0)  //有空节点
      flag = 0;
    else {
      cout << t[k];
      if (cnt != n) cout << " ";
      cnt++;
    }
  }
  if (flag == 1)
    cout << "\nYES";
  else
    cout << "\nNO";
  return 0;
}