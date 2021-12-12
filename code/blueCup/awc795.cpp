#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)\

const int N = 1e5+10;
int a[N], sum[N];
int main(){
  int n, m;
  cin>>n>>m;
  for(int i =1;i<=n;i++){
    cin>>a[i];
    sum[i] = a[i] + sum[i-1];    
  }
  while(m--){
    int l, r;
    cin>>l>>r;
    cout<<sum[r] - sum[l-1]<<endl;
  }
}