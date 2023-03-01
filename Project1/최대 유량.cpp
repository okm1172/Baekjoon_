#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
//중복있을때는 웬만하면 정점 분할 쓰지말자..대가리만 아파진다..
#define INF 2147483647
using namespace std;

vector<vector<int>> vec;
int capacity[200][200], flow[200][200], label[200], work[200];
int min_ = 99999999;
//in-> a 그대로 out -> 52 + a
int n;
bool bfs()
{
	memset(label, 0, sizeof label);
	queue<int> que;
	que.push((int)'A');
	label[(int)'A'] = 1;
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
	return label[(int)'Z'] != 0;
}
int dfs(int start, int minflow)
{
	if (start == (int)'Z')
	{
		return minflow;
	}
	for (int i = work[start]; i < vec[start].size(); i++)
	{
		int ii = vec[start][i];
		if (capacity[start][ii] - flow[start][ii] > 0 && label[ii] == label[start] + 1)
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
	vec = vector<vector<int>>(200);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char q, w;
		int c;
		cin >> q >> w >> c;
		if (q == w)
			if (min_ > c)
				min_ = c;
		int a = (int)q;
		int b = (int)w;
		vec[a].push_back(b);
		vec[b].push_back(a);
		capacity[a][b] += c;
		capacity[b][a] += c;
	}
	int result = 0;
	while (bfs() == true)
	{
		memset(work, 0, sizeof work);
		while (1)
		{
			int ans = dfs((int)'A', INF);
			if (ans == 0)
				break;
			result += ans;
		}
	}
	if (result > min_)
	{
		cout << min_;
		return 0;
	}
	cout << result;
	return 0;
}