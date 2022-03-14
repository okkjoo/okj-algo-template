#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, n, m) for (int i = n; i < m; ++i)

const int maxn = 1e5 + 10;
ll x[maxn], y[maxn];
int stk[maxn],  //模拟栈
    top;        //栈顶
set<int> se;

//是否为凹点——即不是凸点:kab <= kac(叉乘)
bool isConcave(int a, int b, int c) {
  return (x[c] - x[a]) * (y[b] - y[a]) <= (x[b] - x[a]) * (y[c] - y[a]);
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    //如果原先栈中已有两点(top>=1)，
    //那么再加上目前遍历读入的这个点就有三个点可以叉乘了
    if (top >= 1) {
      while (top >= 2 && isConcave(i, stk[top - 1], stk[top - 2]))
        top--;                    //舍弃凹点，知道找到凸点
      if (stk[top - 1] != 0)      //总部不算
        se.insert(stk[top - 1]);  //凸点入集合
    }
    stk[top++] = i;  //将这个新点加入栈
  }
  cout << se.size() << endl;
  return 0;
}