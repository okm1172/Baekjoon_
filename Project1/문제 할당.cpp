#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

#define INF 2147483647
using namespace std;

int n;
int flow[250][250], capacity[250][250],cost[250][250];
int dist[250], parent[250], inQ[250];
vector<vector<int>> vec;
//시작 0 도착 201 문제 -> 100 + a
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vec = vector<vector<int>>(250);
	for (int i = 1; i <= n; i++)
	{
		//출발 도착 정점 연결
		vec[0].push_back(i);
		vec[i].push_back(0);
		capacity[0][i] = 1;
		vec[100 + i].push_back(201);
		vec[201].push_back(100 + i);
		capacity[100 + i][201] = 1;
		for (int j = 1; j <= n; j++)
		{
			//정점 끼리 연결
			int x;
			cin >> x;
			vec[i].push_back(100 + j);
			vec[100 + j].push_back(i);
			cost[i][100 + j] = x;
			cost[100 + j][i] = -x;
			capacity[i][100 + j] = 1;
		}
	}
	int result = 0;
	while (1)
	{
		memset(parent, 0, sizeof parent);
		fill(dist, dist + 250, INF);
		memset(inQ, false, sizeof inQ);
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
					if (inQ[i] == false)
					{
						inQ[i] = true;
						que.push(i);
					}
				}
			}
		}
		if (parent[201] == 0) break;
		int minflow = INF;
		for (int i = 201; i != 0; i = parent[i])
		{
			int start = parent[i];
			minflow = min(minflow, capacity[start][i] - flow[start][i]);
		}
		for (int i = 201; i != 0; i = parent[i])
		{
			flow[parent[i]][i] += minflow;
			flow[i][parent[i]] -= minflow;
			result += cost[parent[i]][i];
		}
	}
	cout << result;
	return 0;
}