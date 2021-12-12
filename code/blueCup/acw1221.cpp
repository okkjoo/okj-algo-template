#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

/* int n;
unordered_map<int, PII> mp;
int main(){
  cin>>n;
  for(int c =0;c*c<=n/2; c++) //c的枚举范围优化
    for(int d = c; d*d+c*c <= n; d++){//d>=c所以直接从c开始
      int t = c*c + d*d;
      if(mp.count(t) == 0) mp[t] = {c, d};//没有就存；有了的话，顺序也排在后面，没必要存
    }

  for(int a = 0; a*a <= n/4; a++){//优化枚举范围
    for(int b = a; a*a+b*b<=n/2; b++){//这里同样可以优化枚举范围
      int t = n - a*a-b*b;
      if(mp.count(t)){
        cout<<a<<" "<<b<<" "<<mp[t].first<<" "<<mp[t].second;
        //输出第一个就可以了
        return 0;
      }
    }
  }
} */

//二分
const int N = 25e5 + 10;

struct Sum
{
    int s, c, d; // s表示c和d的平方
    bool operator<(const Sum& t) const //返回较小的那个
    {
        if(s != t.s) return s < t.s;
        if(c != t.c) return c < t.c;
        return d < t.d;
    }
} sum[N];

int n, m;

int main(void)
{
    scanf("%d", &n);

    for(int c = 0; c * c <= n; c++)
        for(int d = c; c * c + d * d <= n; d++) sum[m++] = {c * c + d * d, c, d};

    sort(sum, sum + m);

    for(int a = 0; a <= n; a++)
        for(int b = 0; b * b + a * a <= n; b++)
        {
            int t = n - a * a - b * b;
            int l = 0, r = m - 1;
            while(l < r)
            {
                int mid = l + r >> 1;
                if(sum[mid].s >= t) //要找一个最小的 所以是>=
                    r = mid;
                else
                    l = mid + 1;
            }
            if(sum[l].s == t)
            {
                printf("%d %d %d %d\n", a, b, sum[l].c, sum[l].d);
                return 0;
            }
        }
    return 0;
}
