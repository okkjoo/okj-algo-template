#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
typedef pair<int, int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

const int N = 1e5 + 10;
int cnt[N];  //记录当前时间窗口内点赞次数
bool st[N];  //有成为过热帖就为1
PII win[N];  //窗口
int main() {
  int n, d, k;
  scanf("%d%d%d", &n, &d, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &win[i].x, &win[i].y);
  }

  sort(win, win + n);  //对第一个关键字也就是时间进行排序方便窗口操作

  for (int i = 0, j = 0; i < n; i++) {
    // i为当前指针,也就是窗口右侧
    // j为窗口左侧
    int id = win[i].y;
    cnt[id]++;
    while (win[i].x - win[j].x >= d) {  //因为是左开右闭区间
      //要把最左边的除掉了
      int id = win[j].y;
      cnt[id]--;
      j++;  //窗口右移
    }
    if (cnt[id] >= k) st[id] = 1;
  }
  for (int i = 0; i < N; i++) {
    if (st[i]) printf("%d\n", i);
  }
}