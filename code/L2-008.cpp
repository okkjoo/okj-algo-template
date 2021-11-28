#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, n, m) for (int i = n; i < m; ++i)

string str;
string expendS(string &s)
{
	string _s = "*#";
	for (int i = 0; i < s.size(); i++)
	{
		_s += s[i];
		_s += "#";
	}
	return _s;
}

string Manacher(string &S)
{
	string s = expendS(S);
	int Len[10000], maxx = 0, idx = 0, maxLen = 0, start = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (i < maxx)
		{
			Len[i] = min(Len[2 * idx - i], maxx - i);
		}
		else
		{
			Len[i] = 1;
		}
		while (i + Len[i] < s.size() && i - Len[i] > 0 && s[i + Len[i]] == s[i - Len[i]])
			Len[i]++;
		if (i + Len[i] > maxx)
		{
			maxx = i + Len[i];
			idx = i;
		}
		if (Len[i] - 1 > maxLen)
		{
			maxLen = Len[i] - 1;
			start = (idx - maxLen) / 2;
		}
	}
	return S.substr(start, maxLen);
}
int main()
{
	ios::sync_with_stdio(false);
	getline(cin, str);
	cout << Manacher(str).size();
	return 0;
}