#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define INF 2147483647
using namespace std;
//정점 분할에선 최대 유량에선 시작점 out -> 도착점 in 당연하게도?
vector<vector<int>> vec;
int capacity[1000][1000], flow[1000][1000];
int label[900];
int work[900];
int n, p;
bool bfs()
{
	memset(label, 0, sizeof label);
	queue<int> que;
	que.push(1);
	label[1] = 401;
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
	return label[402] != 0;
}
int dfs(int start)
{
	if (start == 2)
		return 1;
	for (int i = work[start]; i < vec[start].size(); i++)
	{
		int ii = vec[start][i];
		if (capacity[start][ii] - flow[start][ii] > 0 && label[ii] == label[start] + 1)
		{
			int aa = dfs(ii);
			if (aa > 0)
			{
				flow[start][ii]++;
				flow[ii][start]--;
				work[start] = i;
				return 1;
			}
		}
	}
	work[start] = vec[start].size();
	return 0;
}
int main()
{
	vec = vector<vector<int>>(803);
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
	{
		vec[i].push_back(400 + i);
		vec[400 + i].push_back(i);
		capacity[i][400 + i] = 1;
	}
	for (int i = 1; i <= p; i++)
	{
		int x, y;
		cin >> x >> y;
		vec[x + 400].push_back(y);
		vec[y].push_back(x + 400);
		capacity[x + 400][y] = INF;
		vec[y + 400].push_back(x);
		vec[x].push_back(y + 400);
		capacity[y + 400][x] = INF;
	}
	int result = 0;
	while (bfs())
	{
		memset(work, 0, sizeof work);
		while (1)
		{
			int ans = dfs(401);
			if (ans == 0)
				break;
			result += ans;
		}
	}
	cout << result;
	return 0;
}