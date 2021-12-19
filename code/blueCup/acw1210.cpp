#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)
  
int a[100005];
int mn, mx;
int res = 0;
int main(){
  int n;
  cin>>n;
  for(int i = 0;i <n;i++){
    cin>>a[i];
  }
  for(int i = 0; i < n; i++){
    mn = INT_MAX;
    mx = INT_MIN;
    for(int j = i;j <n; j++){
      mx = max(mx, a[j]);
      mn = min(mn, a[j]);
      if((mx - mn) == (j - i)) res++;
    }
  }
  cout<<res;
}