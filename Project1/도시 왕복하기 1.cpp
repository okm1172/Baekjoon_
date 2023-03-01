//에드몬즈 - 카프 시간 초과 나네요..ㅜㅜ
//min(O(V * E^2) , O(|E|f) )
/*#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
int n, p;
vector<vector<int>> vec;
int parent[500];
int capacity[500][500];
int flow[500][500];

int main()
{
	int n, p;
	cin >> n >> p;
	vec = vector<vector<int>>(n + 2);
	for (int i = 1; i <= p; i++)
	{
		int x, y;
		cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);
		capacity[x][y] = 1;
	}
	int resultcnt = 0;
	while (1)
	{
		queue<int> que;
		memset(parent, 0, sizeof(parent));
		que.push(1);
		parent[1] = 1;
		while (!que.empty())
		{
			int start = que.front();
			if (start == 2) break;
			que.pop();
			for (int i : vec[start])
			{
				if (parent[i] == 0 && capacity[start][i] - flow[start][i] > 0)
				{
					parent[i] = start;
					que.push(i);
				}
			}
		}
		//순환 X
		if (parent[n] == 0)
			break;
		for (int i = 2; i != 1; i = parent[i])
		{
			flow[i][parent[i]]--;
			flow[parent[i]][i]++;
		}
		resultcnt++;
	}
	cout << resultcnt;
	return 0;
}*/
//V 정점 E 간선
//그냥 디닉 O(V^2 * E)
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int n, p;
vector<vector<int>> vec;
int label[500];
int capacity[500][500], flow[500][500];
int work[500];

//디닉 bfs
bool bfs()
{
	memset(label, 0, sizeof(label));
	label[1] = 1;
	queue<int> que;
	que.push(1);
	while (!que.empty())
	{
		int start = que.front();
		que.pop();
		for (int i : vec[start])
		{
			if(label[i]==0 && capacity[start][i] - flow[start][i]>0)
			{
				label[i] = label[start] + 1;
				que.push(i);
			}
		}
	}
	return label[2] != 0;
}
//디닉 dfs
int dfs(int start)
{
	if (start == 2)
		return 1;
	for (int i=work[start];i<vec[start].size(); i++)
	{
		int ii = vec[start][i];
		if (label[ii] == label[start] + 1 && (capacity[start][ii] - flow[start][ii]) > 0)
		{
			int ret = dfs(ii);
			if (ret > 0)
			{
				flow[start][ii]++;
				flow[ii][start]--;
				//work는 간선 이미 진행된거 알려주는겁니당!
				work[start] = i;
				return 1;
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
	cin >> n >> p;
	vec = vector<vector<int>>(n + 3);
	for (int i = 1; i <= p; i++)
	{
		int x, y;
		cin >> x >> y;
		vec[x].push_back(y);
		vec[y].push_back(x);
		capacity[x][y] = 1;
	}
	int resultcnt = 0;
	while (bfs() != false)
	{
		memset(work, 0, sizeof(work));
		while (1)
		{
			int check=dfs(1);
			if (check == 0)
				break;
			resultcnt += check;
		}
	}
	cout << resultcnt;
	return 0;
}