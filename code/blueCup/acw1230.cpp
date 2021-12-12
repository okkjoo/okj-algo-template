#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

const int N = 1e5+10;
ll s[N];//前缀和数组
int cnt[N];//cnt[x]： 前缀和%k 为x 的个数
ll res = 0;//最后的答案

int main(){
  int  n, k;
  cin>>n>>k;
  for(int i = 1; i<=n; i++){
    cin>>s[i];
    s[i] += s[i-1];
  }
  cnt[0]++;//s[0]放进去
  //这一步的目的是当[1,i]区间累加成的数，也就是s[i]是k的倍数。那么区间[1，i]也是一个k倍区间，但是需要前面有一个点作为这个区间的左端点。而此时s[i]%k进行取余等于0，所以将cnt[0]++;
  for(int i = 1; i<=n; i++){
    res += cnt[s[i] % k];
    cnt[s[i]%k] ++;
  }
  cout<<res;
}