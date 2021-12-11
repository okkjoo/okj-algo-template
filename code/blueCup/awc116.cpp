#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> PII;
#define FOR(i, n, m) for (int i = n; i < m; ++i)

/*  DFS
typedef pair<int,int> PII;
PII ans[20],cur[20];
char c[6][6];
int sum;
void turn(int x,int y)
{       for(int i=0;i<4;i++)
        {
            if(c[i][y]=='+') c[i][y]='-';
            else  c[i][y]='+';
        }
        for(int i=0;i<4;i++)
        {
            if(c[x][i]=='+') c[x][i]='-';
            else  c[x][i]='+';
        }
         if(c[x][y]=='+') c[x][y]='-';
            else  c[x][y]='+';


}
bool check(char c[][6])
{   for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
        if(c[i][j]=='+')
           return false; 

     return true; 

}
void dfs(int x,int y,int res){
        if(x==4)
        {
            if(check(c)&&res<sum)
            {   memcpy(ans,cur,sizeof(ans));
                sum=res;
            }
            return;
        }
        int dx=x,dy=y+1;
        if(dy==4){
            dx++,dy=0;
        }
        turn(x,y);
        cur[res+1]={x,y};
        dfs(dx,dy,res+1);
        turn(x,y);
        dfs(dx,dy,res);


}
int main()
{   for(int i=0;i<4;i++)  cin>>c[i];
    sum=0x3f3f3f3f;
    dfs(0,0,0);
    cout<<sum<<endl;
    for(int i=1;i<=sum;i++)
    {
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }


    return 0;
}
 */


int change[4][4];
int get(int x, int y){//获取位数
	return x*4 + y;
}
int main(){
	int state = 0;//棋盘状态
	for(int i =0 ; i<4; i++){
		string line;
		cin>>line;
		for(int j = 0;j<4;j++){
			if(line[j] == '+')
				state += 1 << get(i,j);			
		}
	} 

	//预处理
	for(int i = 0; i < 4; i++)
	for(int j =0; j<4; j++){
		for(int k=0; k < 4; k++){
			change[i][j] += 1<<get(i, k);
			change[i][j] += 1<<get(k, j);
		}
		change[i][j] -= 1<<get(i, j);//行列操作后多操作了一次，要减去
	}
	vector<PII> res;
	for(int k = 0;k< 1<<16; k++){//暴力遍历
		int now = state;//存一下当前局面
		vector<PII> path;
		for(int i =0; i<16; i++){//如果k的某一位是1，就表示需要操作
			if(k >>i & 1){
				//对编号是i的格子进行操作
				int x = i/4, y = i%4;//找到他的行列位置
				now ^= change[x][y];
				path.push_back({x, y});
			}
			if(!now && (res.empty()|| res.size() >path.size())){
			//全0说明合法 && （原先res为空 || 新的方法步骤更少）
				res = path;
			}
		}
	}
	cout<<res.size()<<endl;
	for(auto p:res)cout<< p.first+1<<" "<<p.second+1<<endl;
}