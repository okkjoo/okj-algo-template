#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeap(int year){
  if(year % 400 == 0 || (year%100 != 0 && year%4 == 0)) return true;
  return false;
}

int y, m, d;//设为全局，方便主程序里
bool judge(int date){//传入八位数
  y = date/10000;
  m = date%10000/100;
  d = date%100;
  if(d < 1 || d > 31) return false;
  if(m <1 || m > 12) return false;
  //二月之外
  if(m != 2 && d > months[m]) return false;
  //特殊情况：闰年二月
  else if(m == 2 && d > 28+isLeap(y)) return false;//注意这里必须使用大于号>而不是不等于!=  ，这与类型转换有关
  
  return true;
}

int main(){
  int a, b, c;
  scanf("%d/%d/%d", &a,&b,&c);
  for(int i = 19600101; i<= 20591231; i++){
    if(judge(i)){
      //年月日、月日年、日月年;年是后两位数
      if(        
        (y%100 == a && m == b && d == c) ||
        (d == a && m == b && y%100 == c) ||
        (m == a && d == b && y%100 == c)
      ){
        printf("%d-%02d-%02d\n",y,m,d);
      }
    }
  }
}