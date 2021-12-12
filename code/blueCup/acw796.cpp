#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

const int N = 1e3+10;
int a[N][N], s[N][N];
int main(){
  int  n, m , q;
  cin>>n>>m>>q;
  for(int i =1;i<=n;i++)
    for(int j = 1;j<=m;j++)
      cin>>a[i][j];
  
  for(int i = 1; i<= n; i++)
    for(int j = 1;j <=m; j++)
      s[i][j] = s[i-1][j]+s[i][j-1] - s[i-1][j-1]  + a[i][j];//注意减去重叠导致的多余部分

  int x1, y1, x2, y2;
  while(q--){
    cin>>x1>>y1>>x2>>y2;
    int res = s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];//画个图就知道了
    cout<<res<<endl;
  }
}
