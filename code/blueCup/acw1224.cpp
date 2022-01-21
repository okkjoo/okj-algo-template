#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

const int N = 1e5 + 10;
int a[N];    //存初始数组
bool st[N];  //记录是否已经放进环中

int main() {
  int n, k = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (!st[i]) {  //位置 i 的元素还没有放入到某个环中
      k++;
      // 遍历查找 i 位置元素所在的环中的其他元素
      for (int j = i; !st[j]; j = a[j]) {  //位置 j 指向 a[j] 的元素
        st[j] = 1;                         //记录已经进到某个环中了
      }
    }
  }
  cout << n - k << endl;
  return 0;
}