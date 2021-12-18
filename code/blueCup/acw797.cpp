#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

const int N = 1e5+10;
int a[N], d[N];
int n, m;
void insert(int l, int r, int c){
  d[l] += c;
  d[r+1] -= c;
}

int main(){
  cin>>n>>m;
  for(int i = 1; i<=n;i++){
    cin>>a[i];
    d[i] = a[i]-a[i-1];//构建差分数组，a[0] = 0
  }
  int  l, r, c;
  while(m--){
    cin>>l>>r>>c;
    insert(l, r, c);
  }
  for(int i = 1;i<=n;i++){
    a[i] = a[i-1] + d[i]; //前缀和运算
    cout<<a[i]<<" ";
  }
}