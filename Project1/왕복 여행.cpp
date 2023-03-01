#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define INF 2147483647

using namespace std;
//정점 분할로 풀었습니다.
//양방향 최소 비용 최대 용량은 거의 정점 분할이라고 생각합시다.
//왜 why? cost[i][j] 반대를 -cost[j][i]를 못하기 때문 -> 양방향 이슈
//in -> in , out -> 1000 + out
vector<vector<int>> vec;
bool inQ[2003];
int capacity[2003][2003], cost[2003][2003], flow[2003][2003],parent[2003];
long long dist[2003];
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vec = vector<vector<int>>(2004);
	for (int i = 1; i <= n; i++)
	{
		vec[i].push_back(1000 + i);
		vec[1000 + i].push_back(i);
		capacity[i][1000 + i]=INF;
		capacity[1000 + i][i] = INF;
	}
	for (int i = 1; i <= m; i++)
	{
		//1 2 5
		int a, b, c;
		cin >> a >> b >> c;
		vec[1000 + a].push_back(b);
		vec[b].push_back(1000 + a);
		vec[b + 1000].push_back(a);
		vec[a].push_back(b + 1000);
		capacity[1000 + a][b] = 1;
		capacity[1000 + b][a] = 1;
		cost[1000 + a][b] = c;
		cost[b][1000 + a] = -c;
		cost[b + 1000][a] = c;
		cost[a][b + 1000] = -c;
	}
	long long result = 0;
	for (int qq = 1; qq <= 2; qq++)
	{
			fill(inQ, inQ + 2003, false);
			fill(dist, dist + 2003, INF);
			fill(parent, parent + 2003, 0);
			queue<int> que;
			que.push(1001);
			dist[1001] = 0;
			inQ[1001] = true;
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
			if (parent[n] == 0)
				break;
			int minflow = INF;
			for (int i = n; i != 1001; i = parent[i])
			{
				minflow = min(minflow, capacity[parent[i]][i] - flow[parent[i]][i]);
			}
			for (int i = n; i != 1001; i = parent[i])
			{
				result += (long long)cost[parent[i]][i];
				flow[parent[i]][i] += minflow;
				flow[i][parent[i]] -= minflow;
			}
	}
	cout << result;
	return 0;
}