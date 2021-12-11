#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

int n, q, x;
int a[100005];
int main(){
	scanf("%d%d",&n,&q);
	for(int i =0 ;i<n;i++){
		scanf("%d",&a[i]);
	}
	while(q--){
		scanf("%d",&x);
		int l = 0, r = n;
		//搜左边界
		while(l < r){
			int mid = l+r>>1;
			if(a[mid] == x) r = mid;
			else if(a[mid] < x) l = mid + 1;
			else if(a[mid] > x) r = mid;
		}
		if(a[l] != x) {printf("-1 -1\n");continue;}
		int left = l;
		r = n;
		//搜右边界
		while(l < r){
			int mid = l+r>>1;
			if(a[mid] == x) l = mid+1;
			else if( a[mid] < x) l = mid + 1;
			else if( a[mid] > x) r = mid;
		}
		printf("%d %d\n",left,l-1);
		//因为l = mid+1; 退出来时l在mid上，而需要返回mid
	}
}

