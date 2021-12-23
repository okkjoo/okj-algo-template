#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

//每个月份的天数别搞错了，二月就先默认28，后面再判断闰年
int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

//判断日期是否合法
bool check(int date){  
  int year = date/10000;
  int month = date%10000/100;
  int day = date%10000%100;

  if(!month || month>= 13 || !day || day >31) return false;

  if(month != 2 && day > months[month]) return false;
  if(month == 2) {
    //判断闰年特殊情况
    bool leap = year%4 == 0 && year%100 >0  || year%400 == 0;
    if(day > 28 + leap) return false;
  }
  return true;
}

int main(){
  int d1, d2;cin>>d1>>d2;
  int res = 0;
  for(int i = 1000; i <= 9999; i++){
    //构造一个回文数字串
    int x = i, tmp = i;
    for(int j = 0; j<4;j++) x = x*10 + tmp%10, tmp/=10;
    if(x >= d1 && x<=d2 && check(x)) res++;
  }
  cout<<res;
}