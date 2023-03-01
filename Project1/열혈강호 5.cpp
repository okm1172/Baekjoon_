#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define INF 2147483647
using namespace std;

int n, m;
vector<vector<int>> vec;
int label[2500], flow[2100][2100], capacity[2100][2100], work[2500];
int cost[2100][2100];
int parent[2500];
int dist[2500];
bool inQ[2500];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vec = vector<vector<int>>(2005);

	for (int i = 1; i <= n; i++)
	{
		vec[0].push_back(i);
		vec[i].push_back(0);
		capacity[0][i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		int q;
		cin >> q;
		for (int j = 1; j <= q; j++)
		{
			int aa,cost_;
			cin >> aa >> cost_;
			vec[i].push_back(aa + 1000);
			vec[aa + 1000].push_back(i);
			capacity[i][aa + 1000] = 1;
			cost[i][aa + 1000] = cost_;
			cost[aa + 1000][i] = -cost_;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		vec[1000 + i].push_back(2001);
		vec[2001].push_back(1000 + i);
		capacity[1000 + i][2001] = 1;
	}
	int result = 0;
	int resultcnt = 0;
	while (1)
	{
		//parent 찾아가는 서비스 dist 는 최소 비용 비교
		memset(parent, 0, sizeof parent);
		fill(dist, dist + 2500, INF);
		memset(inQ, 0, sizeof inQ);
		queue<int> que;
		dist[0] = 0;
		que.push(0);
		parent[0] = 0;
		inQ[0] = true;
		//직원 -> 직원, 일 -> 1000 + 일, 도착 2001 , 시작 0
		while(!que.empty())
		{
			int start = que.front();
			que.pop();
			inQ[start] = false;
			for (int i:vec[start])
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
		if (parent[2001] == 0)
			break;
		int minflow = INF;
		for (int i = 2001; i != 0; i = parent[i])
		{
			minflow = min(minflow, capacity[parent[i]][i] - flow[parent[i]][i]);
		}
		for (int i = 2001; i != 0; i = parent[i])
		{
			flow[i][parent[i]] -= minflow;
			flow[parent[i]][i] += minflow;
			result += cost[parent[i]][i];
		}
		resultcnt += minflow;
	}
	cout << resultcnt<<"\n"<<result;
	return 0;
}