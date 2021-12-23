#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

const int N = 1e5+10;

int n, m, T;
int pr[N],//优先级
    st[N],//st[i]=1 表示i在优先缓存中
    last[N];//last[N] 表示最近一次的订单时间
PII order[N];//订单：<t, di>

int main(){
  cin>>n>>m>>T;
  for(int i = 0; i<m;i++){
    cin>>order[i].first>>order[i].second;
    // cout<<"*"<<order[i].first<<order[i].second<<endl;
  }
  // cout<<endl;
  //按时间排序
  sort(order, order+m);
  for(int i = 0; i<m;i++){
    // cout<<i<<"*"<<order[i].first<<order[i].second<<endl;
  }

// cout<<endl;
  for(int i = 0; i< m; ){//喵的一开始这里打习惯了一个 i++  ，找了半天bug
    int j = i;
    // cout<<j<<":"<<endl;
    while(order[i] == order[j] && j < m) j++;//pair的相等是key和value都要相等：也就是同一时刻一家店多个订单的情况
    int t = order[i].first, id = order[i].second, 
        cnt = j - i;//t时刻，id店有cnt个订单
    i = j;//订单指针跳转
    pr[id] -= t - last[id] - 1;
    // cout<<"-:t-last-1: "<<t<<"-"<<last[id]<<"-1"<<endl;
    if(pr[id] < 0) pr[id] = 0;
    if(pr[id] <= 3) st[id] = 0;
    // cout<<"-pr"<<id<<" "<<pr[id]<<endl;

    //以上是处理t时刻之前，下面是t时刻
    pr[id] += cnt*2;
    // cout<<"+pr"<<id<<" "<<pr[id]<<endl;
    if(pr[id] > 5) st[id] = 1;
    last[id] = t;
    // cout<<"last"<<id<<" "<<last[id]<<endl;
  }
  // 最后再处理一下
  for(int i = 1; i<= n; i++){
    if(last[i] < T){
      pr[i] -= T - last[i];
      if(pr[i] <= 3) st[i] = 0;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){
    // cout<<pr[i]<<" ";
    ans += st[i];
  }
  // cout<<endl;
  cout<<ans;
  
}