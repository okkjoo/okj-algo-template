#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

const int N =1e5+10;
/* 
//优化枚举+预处理排序+二分
int a[N], b[N], c[N];
int main(){
  int n;scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&a[i]);
  FOR(i,0,n) scanf("%d",&b[i]);
  FOR(i,0,n) scanf("%d",&c[i]);
  
  //排序预处理
  sort(a,a+n);
  sort(b,b+n);
  sort(c,c+n);

  ll ans = 0;

  //枚举B
  for(int i = 0 ; i < n; i++){
    int bkey = b[i];
    //找A中第一个不小于key的数的下标
    int pa = lower_bound(a, a + n, bkey) -  a;
    //找C中第一个大于key的数的下标
    int pc= upper_bound(c, c + n, bkey) - c;
    if(pa >= 0 && pc < n){
      ans += (ll)(pa)*(n-pc);
    } 
  }
  printf("%lld",ans);
} */

int A[N], B[N], C[N];
int cnta[N], cntc[N], sa[N], sc[N];
int main(){
  int n;scanf("%d", &n);
  //每一项都要+1，相对大小不变。防止*处后面越界
  //数i在A中有cnta[i]个
  FOR(i,1,n+1){
    scanf("%d", &A[i]);
    cnta[++A[i]]++;
  }
  FOR(i,1,n+1){
    scanf("%d", &B[i]);
    ++B[i];
  }
  FOR(i,1,n+1){
    scanf("%d", &C[i]);
    cntc[++C[i]]++;
  }
  //对cnta、cntc求前缀和
  sa[0] = cnta[0], 
  sc[0] = cntc[0];
  FOR(i, 1, N+1){ sa[i] = sa[i-1] + cnta[i];}
  FOR(i, 1, N+1){ sc[i] = sc[i-1] + cntc[i];}
  //遍历B
  ll ans = 0;
  FOR(i, 1, n+1){
    int b = B[i];
    //sa[b-1]： A中小于等于b-1的个数即小于b的个数；   sc[N-1] - sc[b]：C中大于b的个数
    ans += (ll)sa[b-1]*(sc[N-1] - sc[b]); //*    sa[b-1]如果B中有个数是0，前面不预处理 加一 就会报错了
    //还有要注意的是，要先转换第一个数为longlong，相乘完再转换有一个样例过不去
  }
  printf("%lld",ans);
}