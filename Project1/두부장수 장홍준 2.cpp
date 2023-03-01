#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <vector>
#define INF 2147483647
using namespace std;

int n, m;
int data_[60][60];
int data_cost[6][6];
vector<vector<int>> vec;
int capacity[2600][2600],flow[2600][2600],cost[2600][2600];
int inQ[2600], parent[2600], dist[2600];
int remin = INF;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vec = vector<vector<int>>(2600);
	data_cost[0][0] = 10, data_cost[0][1] = 8, data_cost[0][2] = 7, data_cost[0][3] = 5, data_cost[0][4] = 1;
	data_cost[1][0] = 8, data_cost[1][1] = 6, data_cost[1][2] = 4, data_cost[1][3] = 3, data_cost[1][4] = 1;
	data_cost[2][0] = 7, data_cost[2][1] = 4, data_cost[2][2] = 3, data_cost[2][3] = 2, data_cost[2][4] = 1;
	data_cost[3][0] = 5, data_cost[3][1] = 3, data_cost[3][2] = 2, data_cost[3][3] = 2, data_cost[3][4] = 1;
	data_cost[4][0] = 1, data_cost[4][1] = 1, data_cost[4][2] = 1, data_cost[4][3] = 1, data_cost[4][4] = 0;
	//입력
	for (int i = 1; i <= n; i++)
	{
		string a;
		cin >> a;
		for (int j = 0; j < m; j++)
		{
			data_[i][j + 1] = a[j];
			if (a[j] == 'F')
				data_[i][j + 1] = 'E';
		}
	}
	if (n == 1 && m == 1)
	{
		cout << 0;
		return 0;
	}
	//시작점 연결 0
	for (int i = 1; i <= n; i++)
	{
		int aa = (i % 2 == 0 ? 1 : 0);
		for (int j = 1 + aa; j <= m; j = j + 2)
		{
			int now = m * (i - 1) + j;
			vec[0].push_back(now);
			vec[now].push_back(0);
			capacity[0][now] = 1;
		}
	}
	//끝점 연결 2501
	for (int i = 1; i <= n; i++)
	{
		int aa = (i % 2 == 0 ? 0 : 1);
		for (int j = 1 + aa; j <= m; j = j + 2)
		{
			int now = m * (i - 1) + j;
			vec[now].push_back(2501);
			vec[2501].push_back(now);
			capacity[now][2501] = 1;
		}
	}
	//정점 연결
	for (int i = 1; i <= n; i++)
	{
		int aa = (i % 2 == 0 ? 1 : 0);
		for (int j = 1 + aa; j <= m; j = j+ 2)
		{
			int now = m * (i - 1) + j;
			if (data_[i - 1][j] != 0)
			{
				int later = m * (i - 2) + j;
				vec[now].push_back(later);
				vec[later].push_back(now);
				cost[now][later] = -data_cost[data_[i][j] - 'A'][data_[i - 1][j] - 'A'];
				cost[later][now] = -cost[now][later];
				capacity[now][later] = 1;
			}
			if (data_[i + 1][j] != 0)
			{
				int later = m * i + j;
				vec[now].push_back(later);
				vec[later].push_back(now);
				cost[now][later] = -data_cost[data_[i][j] - 'A'][data_[i + 1][j] - 'A'];
				cost[later][now] = -cost[now][later];
				capacity[now][later] = 1;
			}
			if (data_[i][j - 1] != 0)
			{
				int later = now - 1;
				vec[now].push_back(later);
				vec[later].push_back(now);
				cost[now][later] = -data_cost[data_[i][j] - 'A'][data_[i][j - 1] - 'A'];
				cost[later][now] = -cost[now][later];
				capacity[now][later] = 1;
			}
			if (data_[i][j + 1] != 0)
			{
				int later = now + 1;
				vec[now].push_back(later);
				vec[later].push_back(now);
				cost[now][later] = -data_cost[data_[i][j] - 'A'][data_[i][j + 1] - 'A'];
				cost[later][now] = -cost[now][later];
				capacity[now][later] = 1;
			}
		}
	}
	int result = 0;
	//0시작 2501도착
	while (1)
	{
		fill(dist, dist + 2550, INF);
		memset(parent, 0, sizeof parent);
		memset(inQ, false, sizeof inQ);
		queue<int> que;
		que.push(0);
		inQ[0] = true;
		dist[0] = 0;
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
		if (parent[2501] == 0)
			break;
		int minflow = INF;
		for (int i = 2501; i != 0; i = parent[i])
		{
			minflow = min(minflow, capacity[parent[i]][i] - flow[parent[i]][i]);
		}
		for (int i = 2501; i != 0; i = parent[i])
		{
			flow[parent[i]][i] += minflow;
			flow[i][parent[i]] -= minflow;
			result += cost[parent[i]][i]*minflow;
			//cout << '(' << parent[i]<<','<<i<<')' << '='<<cost[parent[i]][i]<<endl;
		}
		if (remin > result)
			remin = result;
		//cout << endl;
	}
	cout << -remin;
	return 0;
}