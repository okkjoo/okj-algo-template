#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

double x;

int main(){
  cin>>x;
  double l = -10000, r = 10000;
  while(r-l > 1e-8){//精度还不够的话
    double mid = (l+r)/2;
    if(mid*mid*mid >= x) r = mid;
    else l = mid;
  }
  printf("%.6lf",l);
}