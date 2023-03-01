#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#define INF 2147483647
using namespace std;
//https://justicehui.github.io/ps/2019/10/25/BOJ17506/ 아이디어 진짜 신기하네요 ㅋㅋㅋㅋ 와 mcmf에서 무조건 하나 이상을 이렇게 처리를 하구나..버리는 값 방법도 여기서 알아갑니다.
int capacity[510][510], flow[510][510], cost[510][510];
int inQ[510], parent[510], dist[510];
int n;
vector<vector<int>> vec;
int min_ = INF;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	vec = vector<vector<int>>(510);
	//중간 505
	//출발 그래프 연결
	vec[0].push_back(505);
	vec[505].push_back(0);
	capacity[0][505] = 3;
	cost[0][505] = -10001;
	cost[505][0] = 10001;
	for (int i = 1; i <= 3; i++)
	{
		vec[505].push_back(500 + i);
		vec[500 + i].push_back(505);
		capacity[505][500 + i] = 1;
	}
	for (int i = 1; i <= 3; i++)
	{
		int x;
		cin >> x;
		vec[0].push_back(500 + i);
		vec[500 + i].push_back(0);
		x--;
		capacity[0][500 + i] = x;
	}
	//정점 연결
	for (int i = 1; i <= n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vec[501].push_back(i);
		vec[i].push_back(501);
		cost[501][i] = -a;
		cost[i][501] = a;
		capacity[501][i] = 1;
		vec[502].push_back(i);
		vec[i].push_back(502);
		cost[502][i] = -b;
		cost[i][502] = b;
		capacity[502][i] = 1;
		vec[503].push_back(i);
		vec[i].push_back(503);
		cost[503][i] = -c;
		cost[i][503] = c;
		capacity[503][i] = 1;
	}
	//끝점 연결
	for (int i = 1; i <= n; i++)
	{
		vec[i].push_back(504);
		vec[504].push_back(i);
		capacity[i][504] = 1;
	}
	int result = 0;
	while (1)
	{
		memset(parent, 0, sizeof parent);
		memset(inQ, false, sizeof inQ);
		fill(dist, dist + 510, INF);
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
		if (parent[504] == 0) break;
		int minflow = INF;
		for (int i = 504; i != 0; i = parent[i])
		{
			int start = parent[i];
			minflow = min(minflow, capacity[start][i] - flow[start][i]);
		}
		for (int i = 504; i != 0; i = parent[i])
		{
			flow[parent[i]][i] += minflow;
			flow[i][parent[i]] -= minflow;
			result += cost[parent[i]][i] * minflow;
			//cout << parent[i] << " " << i << "="<<cost[parent[i]][i] * minflow<<endl;
		}
		//cout << endl;
		//cout << result << endl;
		if (result < min_)
			min_ = result;
	}
	cout << -min_-30003;
	return 0;
}