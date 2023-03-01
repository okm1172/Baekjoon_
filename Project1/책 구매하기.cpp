#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define INF 2147483647
using namespace std;

vector<vector<int>> vec;
int capacity[203][203], flow[203][203], cost[203][203];
int dist[203], parent[203];
bool inQ[203];
int n, m;
int main()
{
	//start 0 사람은 그대로 서점은 100 + A 도착 201
	cin >> n >> m;
	vec = vector<vector<int>>(203);
	for (int i = 1; i <= n; i++)
	{
		int qq;
		cin >> qq;
		vec[0].push_back(i);
		vec[i].push_back(0);
		capacity[0][i] = qq;
	}
	for (int i = 1; i <= m; i++)
	{
		int qq;
		cin >> qq;
		vec[100 + i].push_back(201);
		vec[201].push_back(100 + i);
		capacity[100 + i][201] = qq;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int cost_;
			cin >> cost_;
			vec[100 + i].push_back(j);
			vec[j].push_back(100+ i);
			capacity[j][100+i] = INF;
			cost[j][100+i] = cost_;
			cost[100+i][j] = -cost_;
		}
	}
	int result = 0;
	while (1)
	{
		memset(inQ, 0, sizeof inQ);
		memset(parent, 0, sizeof parent);
		fill(dist, dist + 203, INF);
		queue<int> que;
		que.push(0);
		dist[0] = 0;
		inQ[0] = true;
		parent[0] = 0;
		while (!que.empty())
		{
			int start = que.front();
			que.pop();
			inQ[start] = false;
			for (int i : vec[start])
			{
				if (capacity[start][i] - flow[start][i] > 0 && dist[i] > dist[start] + cost[start][i])
				{
					dist[i] = dist[start] + cost[start][i];
					parent[i] = start;
					if (!inQ[i])
					{
						que.push(i);
						inQ[i] = true;
					}
				}
			}
		}
		if (parent[201] == 0)
			break;
		int minflow = INF;
		for (int i = 201; i != 0; i = parent[i])
		{
			minflow = min(minflow, capacity[parent[i]][i] - flow[parent[i]][i]);
		}
		for (int i = 201; i != 0; i = parent[i])
		{
			flow[parent[i]][i] += minflow;
			flow[i][parent[i]] -= minflow;
			result += minflow * cost[parent[i]][i];
		}
	}
	cout << result;
	return 0;
}