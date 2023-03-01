#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stack>

using namespace std;

int N, M;
vector<vector<int>> adj;
int cssNum[1000003];
bool finish[1000003];
int nodeNum[1000003];
int numCnt,resultcnt;
stack<int> sta;

int bfs(int start)
{
	nodeNum[start] = ++numCnt;
	sta.push(start);
	int parent = nodeNum[start];
	for (auto aa : adj[start])
	{
		if (nodeNum[aa] == 0) parent = min(parent, bfs(aa));
		else if (finish[aa] != true) parent = min(parent, nodeNum[aa]);
	}
	if (parent == nodeNum[start])
	{
		while (1)
		{
			int qq = sta.top();
			sta.pop();
			cssNum[qq] = resultcnt;
			finish[qq] = true;
			if (start == qq)
				break;
		}
		resultcnt++;
	}
	return parent;
}
int main()
{
	cin >> N >> M;
	adj = vector<vector<int>>(1000003);
	for (int qq = 1; qq <= M; qq++)
	{
		//À½¼ö¸é È¦¼ö¹øÂ°
		//Â¦¼ö¸é Â¦¼ö¹øÂ°
		int x, y;
		cin >> x >> y;
		int x_, y_;
		if (x < 0)
		{
			x_ = x * -2;
			x = x * -2 + 1;
		}
		else
		{
			x_ = x * 2 + 1;
			x = x * 2;
		}
		if (y < 0)
		{
			y_ = y * -2;
			y = y * -2 + 1;
		}
		else
		{
			y_ = y * 2 + 1;
			y = y * 2;
		}
		adj[x_].push_back(y);
		adj[y_].push_back(x);
	}
	for (int i = 2; i <= N * 2 + 1; i++)
	{
		if (nodeNum[i] == 0)
			bfs(i);
	}
	for (int i = 1; i <= N; i++)
	{
		if (cssNum[i * 2] == cssNum[i * 2 + 1])
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}