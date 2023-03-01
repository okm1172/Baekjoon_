#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define INF 2147483647
using namespace std;

int n, m, k;
vector<vector<int>> vec;
int label[2500], flow[2100][2100],capacity[2100][2100], work[2500];
//직원 -> 직원, 일 -> 1000 + 일, 도착 2001 , 중간 지점 2002 , 시작 0
bool bfs()
{
	memset(label, 0, sizeof label);
	queue<int> que;
	que.push(0);
	label[0] = 1;
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
	return label[2001] != 0;
}
int dfs(int start,int minflow)
{
	if (start == 2001)
		return minflow;
	for (int i = work[start]; i < vec[start].size(); i++)
	{
		int ii = vec[start][i];
		if (capacity[start][ii] - flow[start][ii] > 0 && label[start] + 1 == label[ii])
		{
			int ans = dfs(ii, min(minflow, capacity[start][ii] - flow[start][ii]));
			if (ans > 0)
			{
				flow[start][ii] += ans;
				flow[ii][start] -= ans;
				work[start] = i;
				return ans;
			}
		}
	}
	work[start] = vec[start].size();
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	vec = vector<vector<int>>(2005);
	for (int i = 1; i <= n; i++)
	{
		vec[0].push_back(i);
		vec[i].push_back(0);
		capacity[0][i] = 1;
		vec[2002].push_back(i);
		vec[i].push_back(2002);
		capacity[2002][i] = 1;
	}
	vec[0].push_back(2002);
	vec[2002].push_back(0);
	capacity[0][2002] = k;
	for (int i = 1; i <= n; i++)
	{
		int ii;
		cin >> ii;
		for (int j = 1; j <= ii; j++)
		{
			int qq;
			cin >> qq;
			vec[i].push_back(1000 + qq);
			vec[1000 + qq].push_back(i);
			capacity[i][1000 + qq] = 1;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		vec[1000 + i].push_back(2001);
		vec[2001].push_back(1000 + i);
		capacity[1000 + i][2001] = 1;
	}
	int result = 0;
	while (bfs() == true)
	{
		memset(work, 0, sizeof work);
		while (1)
		{
			int ans = dfs(0, INF);
			if (ans == 0)
				break;
			result += ans;
		}
	}
	cout << result;
	return 0;
}