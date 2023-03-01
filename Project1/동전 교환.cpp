#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define INF 2147483647
using namespace std;
int n, m;
int capacity[1004][1004], flow[1004][1004];
int dist[1004];
int parent[1004];
int inQ[1004];
int cost[1004][1004];
vector<vector<int>> vec;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	//Ãâ¹ß 0 µµÂø 1001
	while (t)
	{
		cin >> n >> m;
		vec = vector<vector<int>>(1005);
		memset(capacity, 0, sizeof capacity);
		memset(cost, 0, sizeof cost);
		memset(flow, 0, sizeof flow);
		for (int i = 1; i <= n; i++)
		{
			vec[i].push_back(500 + i);
			vec[500 + i].push_back(i);
			capacity[i][500 + i] = INF;
		}
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			cin >> x >> y;
			vec[x].push_back(500 + y);
			vec[500 + y].push_back(x);
			vec[y].push_back(500 + x);
			vec[500+x].push_back(y);
			capacity[500 + x][y] = INF;
			capacity[500 + y][x] = INF;
			cost[500 + x][y] = 1, cost[500 + y][x] = 1;
			cost[y][500 + x] = -1, cost[x][500 + y] = -1;
		}
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			if (x == 0)
			{
				vec[0].push_back(i);
				vec[i].push_back(0);
				capacity[0][i] = 1;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			if (x == 0)
			{
				vec[500 + i].push_back(1001);
				vec[1001].push_back(500 + i);
				capacity[500 + i][1001] = 1;
			}
		}
		int result = 0;
		while (1)
		{
			memset(parent, 0, sizeof parent);
			memset(inQ, 0, sizeof inQ);
			fill(dist, dist + 1004, INF);
			queue<int> que;
			que.push(0);
			parent[0] = 0;
			inQ[que.front()] = true;
			dist[0] = 0;
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
			if (parent[1001] == 0)
				break;
			int minflow = INF;
			for (int i = 1001; i != 0; i = parent[i])
			{
				minflow = min(minflow, capacity[parent[i]][i] - flow[parent[i]][i]);
			}
			for (int i = 1001; i != 0; i = parent[i])
			{
				result += cost[parent[i]][i] * minflow;
				flow[parent[i]][i] += minflow;
				flow[i][parent[i]] -= minflow;
			}
		}
		cout << result << "\n";
		t--;
	}
	return 0;
}