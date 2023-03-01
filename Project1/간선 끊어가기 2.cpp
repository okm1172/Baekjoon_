#include <iostream>
#include <string.h>
#include <queue>
#define INF 2147483647
#define out 500
using namespace std;
//굳이 정점 분할 안해도 되는 문제였네요.. 그냥 capacity를 capacity[x][y] = cost , capacity[y][x] =cost둘다 해주면 되는거였습니다..
int n, m, s, t;
vector<vector<int>> vec;
int capacity[1003][1003];
int flow[1003][1003];
int work[1003];
int label[1003];
bool bfs()
{
	memset(label, 0, sizeof label);
	queue<int> que;
	que.push(s + out);
	label[s + out] = 1;
	while (!que.empty())
	{
		int start = que.front();
		que.pop();
		for (int i : vec[start])
		{
			if (capacity[start][i] - flow[start][i] > 0 && label[i] == 0)
			{
				label[i] = label[start] + 1;
				que.push(i);
			}
		}
	}
	return label[t]!= 0;
}
int dfs(int start, int minflow)
{
	if (start == t)
		return minflow;
	for (int i = work[start]; i < vec[start].size(); i++)
	{
		int ii = vec[start][i];
		if (capacity[start][ii] - flow[start][ii] > 0 && label[ii] == label[start] + 1)
		{
			int ans = dfs(ii, min(minflow, capacity[start][ii] - flow[start][ii]));
			if (ans > 0)
			{
				work[start] = i;
				flow[start][ii] += ans;
				flow[ii][start] -= ans;
				return ans;
			}
		}
	}
	work[start] = vec[start].size();
	return 0;
}
int main()
{
	cin >> n >> m;
	vec = vector<vector<int>>(1003);
	//in-out
	for (int i = 1; i <= n; i++)
	{
		vec[i].push_back(i + out);
		vec[i + out].push_back(i);
		capacity[i][i + out] = INF;
	}
	//간선 연결
	for (int i = 1; i <= m; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		vec[x + out].push_back(y);
		vec[y].push_back(x + out);
		vec[y + out].push_back(x);
		vec[x].push_back(y + out);
		capacity[x + out][y] = cost;
		capacity[y + out][x] = cost;
	}
	cin >> s >> t;
	int result = 0;
	while (bfs() == true)
	{
		memset(work, 0, sizeof work);
		while (1)
		{
			int ans = dfs(s + out, INF);
			if (ans == 0)
				break;
			result += ans;
		}
	}
	cout << result;
	return 0;
}