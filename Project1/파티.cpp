#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
#define INF 2147483647
//디닉 알고리즘
using namespace std;

int n, k, d;
vector<vector<int>> vec;
int capacity[400][400];
int flow[400][400];
int label[400];
int work[400];
//음식은 200 + d로 표현합니다.인원수가 200명이기 때문에
//마지막 목적지는 350으로 설정
bool bfs()
{
	memset(label, 0, sizeof(label));
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
				que.push(i);
				label[i] = label[start] + 1;
			}
		}
	}
	return label[350] != 0;
}
int dfs(int start,int minflow)
{
	if (start == 350)
		return minflow;
	for (int i = work[start]; i < vec[start].size(); i++)
	{
		int ii = vec[start][i];
		if (capacity[start][ii] - flow[start][ii] > 0 && label[ii] == label[start] + 1)
		{
			int aaa = dfs(ii, min(minflow, capacity[start][ii] - flow[start][ii]));
			if (aaa > 0)
			{
				flow[start][ii] += aaa;
				flow[ii][start] -= aaa;
				work[start] = i;
				return aaa;
			}
		}
	}
	//만족하는게 없으면 이 간선을 통해 볼수있는 간선은 없다. 따라서 vec[start].size()를 넣어주자.
	work[start] = vec[start].size();
	return 0;
}
int main()
{
	cin >> n >> k >> d;
	vec = vector<vector<int>>(352);
	for (int i = 1; i <= n; i++)
	{
		vec[0].push_back(i);
		vec[i].push_back(0);
		capacity[0][i] = k;
	}
	for (int i = 1; i <= d; i++)
	{
		int dd;
		cin >> dd;
		vec[200 + i].push_back(350);
		vec[350].push_back(200 + i);
		capacity[200 + i][350] = dd;
	}
	for (int i = 1; i <= n; i++)
	{
		int dd;
		cin >> dd;
		for (int j = 1; j <= dd; j++)
		{
			int food;
			cin >> food;
			vec[i].push_back(food + 200);
			vec[food + 200].push_back(i);
			capacity[i][food + 200] = 1;
		}
	}
	int resultcnt = 0;
	while (bfs())
	{
		memset(work, 0, sizeof(work));
		while (1)
		{
			int ans = dfs(0,INF);
			if (ans == 0)
				break;
			resultcnt += ans;
		}
	}
	cout << resultcnt;
	return 0;
}