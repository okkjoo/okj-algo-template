#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, n, m) for (int i = n; i < m; ++i)

vector<vector<int>> v(10010); //二维数组存图，直接开好大小
int book[10010];							//记录节点是否访问过
int main()
{
	ios::sync_with_stdio(false);
	int n, m, k, a, b;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		//记下两联的两山头
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < k; i++)
	{
		cin >> a; //查询点
		queue<int> q;
		fill(book, book + 10010, 0); //重置标记
		q.push(a);
		int level[10010]; //记录当前节点的层数,当前层=上一层+1
		int ans = 10010, maxLevel = 0;
		book[a] = 1;
		while (!q.empty())
		{
			int top = q.front();
			q.pop();
			if (level[top] > maxLevel)
			{
				maxLevel = level[top];
				ans = 10010; //设为最大值是为了下面的比较——如果直接在这里 ans = top; 会有一个测试点不过:相同山头时要那个较小编号的
			}
			if (top != a)														//第一次进来的情况，就不用比较ans和top了
				ans = min(ans, top);									//取编号较小的
			for (int j = 0; j < v[top].size(); j++) //遍历top能到的所有点
			{
				if (book[v[top][j]] == 0)
				//没给标记的才可以进入队列，不然可能会进入死循环
				{
					q.push(v[top][j]);
					book[v[top][j]] = 1;
					level[v[top][j]] = level[top] + 1; //当前层=上一层+1
				}
			}
		}
		if (ans != 10010)
			cout << ans << "\n";
		else
			cout << "0\n";
	}
	return 0;
}