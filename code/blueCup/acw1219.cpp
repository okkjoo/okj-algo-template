#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

int main(){
  int w, m, n;cin>>w>>m>>n;
  int x1 = (m-1)/w + 1, x2 = (n-1)/w + 1;//行数
  int y1 = (x1&1)?((m-1)%w + 1): (w-(m-1)%w),//列数+判断行数奇偶情况时的列数
      y2 = (x2&1)?((n-1)%w + 1): (w-(n-1)%w);

  cout<<abs(x1-x2) + abs(y1-y2);
}