#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

const int N = 1e5+10;
int a[N];
int main(){
  int n;cin>>n;
  int idx = 0;//数组下标
  string line;
  getchar();//把行数后面这个回车吃了
  while(n--){
    getline(cin, line);
    stringstream ssin(line);//输入流
    while(ssin >> a[idx]) idx++;
  }
  sort(a, a+idx);//排序，方便后面查重
  int res1, res2;
  // FOR(i,0,idx)cout<<a[i]<<" ";
  // cout<<endl;
  FOR(i, 1, idx){
    if(a[i] > a[i-1] + 2) res1 = a[i]-1;//断号
    if(a[i] == a[i-1])res2 = a[i];//重号
  }
  cout<<res1<<" "<<res2;
}