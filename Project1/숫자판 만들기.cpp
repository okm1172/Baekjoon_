#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

#define INF 2147483647
//이런 표에선 처음이니까 이제 알면 되죠! 표에서 모델링 할때는 각 행 각 열을 정점으로 잡고 해당하는 값을 흘려보내주면 돼요.
//https://skyde47.tistory.com/92참고하세요..유량이 생각보다 어렵습니다..모델링이..화이팅..
using namespace std;

int n;
vector<vector<int>> vec;
int capacity[103][103];
int flow[103][103];
int label[103];
int work[103];

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
	return label[101] != 0;
}
int dfs(int start,int minflow)
{
	if (start == 101)
		return minflow;
	for (int i = work[start]; i < vec[start].size(); i++)
	{
		int q = vec[start][i];
		if (label[q] == label[start] + 1 && capacity[start][q] - flow[start][q] > 0)
		{
			int ans = dfs(q, min(minflow, capacity[start][q] - flow[start][q]));
			if (ans > 0)
			{
				flow[start][q] += ans;
				flow[q][start] -= ans;
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
	//시작 0 도착 101
	int checksum = 0;
	cin >> n;
	vec = vector<vector<int>>(103);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			vec[i].push_back(n + j);
			vec[n + j].push_back(i);
		}
		vec[0].push_back(i);
		vec[i].push_back(0);
		vec[n + i].push_back(101);
		vec[101].push_back(n + i);
	}
	for (int j = 1; j <= n; j++)
	{
		int a;
		cin >> a;
		capacity[0][j] = a;
		checksum += a;
	}
	for (int j = 1; j <= n; j++)
	{
		int a;
		cin >> a;
		capacity[n + j][101] = a;
	}
	int search_1 = 0,search_2=10000;
	while (1)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1;j<=n;j++)
				capacity[i][j + n] = (search_1 + search_2) / 2;
		memset(flow, 0, sizeof flow);
		int ans2 = 0;
		while (bfs() == true)
		{
			memset(work, 0, sizeof work);
			while (1)
			{
				int ans = dfs(0, INF);
				if (ans == 0)
					break;
				ans2 += ans;
			}
		}
		if (search_1 == search_2)
		{
			cout << search_1<<"\n";
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					cout << flow[i][j + n] << " ";
				}
				cout << "\n";
			}
			break;
		}
		if (ans2 == checksum)
		{
			search_2 = (search_1 + search_2) / 2;
		}
		else
		{
			search_1 = (search_1 + search_2) / 2 + 1;
		}
	}
	return 0;
}