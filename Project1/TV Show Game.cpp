#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
//scc진짜 이거 위상정렬 후 그냥 받아들여야겠음...
//받아들일건 받아들이고 가는게 가장 빠르게 배우는거임..
//
int N, M;
vector<vector<int>> adj;
int cssNum[1000003];
bool finish[1000003];
int nodeNum[1000003];
int numCnt, resultcnt;
vector<vector<int>> result;
stack<int> sta;
int realResult[100003];
int bfs(int start)
{
	nodeNum[start] = ++numCnt;
	sta.push(start);
	int parent = nodeNum[start];
	for (auto aa : adj[start])
	{
		if (nodeNum[aa] == 0) parent = min(parent, bfs(aa));
		else if (finish[aa] != true) parent = min(parent, nodeNum[aa]);
	}
	if (parent == nodeNum[start])
	{
		vector<int> result_;
		while (1)
		{
			int qq = sta.top();
			sta.pop();
			cssNum[qq] = resultcnt;
			finish[qq] = true;
			result_.push_back(qq);
			if (start == qq)
				break;
		}
		result.push_back(result_);
		resultcnt++;
	}
	return parent;
}
int main()
{
	cin >> N >> M;
	adj = vector<vector<int>>(1000003);
	result.clear();
	memset(realResult, -1, sizeof(realResult));
	for (int qq = 1; qq <= M; qq++)
	{
		//R면 짝수번째
		//B면 홀수번째
		int x, y,z;
		char a, b, c;
		cin >> x >> a >> y >> b >> z >> c;
		int x_, y_,z_;
		if (a=='B')
		{
			x_ = x * 2;
			x = x * 2 + 1;
		}
		else
		{
			x_ = x * 2 + 1;
			x = x * 2;
		}
		if (b=='B')
		{
			y_ = y * 2;
			y = y * 2 + 1;
		}
		else
		{
			y_ = y * 2 + 1;
			y = y * 2;
		}
		if (c == 'B')
		{
			z_ = z * 2;
			z = z * 2 + 1;
		}
		else
		{
			z_ = z * 2 + 1;
			z = z * 2;
		}
		adj[x_].push_back(y);
		adj[x_].push_back(z);
		adj[y_].push_back(x);
		adj[y_].push_back(z);
		adj[z_].push_back(x);
		adj[z_].push_back(y);
	}
	for (int i = 2; i <= N * 2 + 1; i++)
	{
		if (nodeNum[i] == 0)
			bfs(i);
	}
	for (int i = 1; i <= N; i++)
	{
		if (cssNum[i * 2] == cssNum[i * 2 + 1])
		{
			cout << -1;
			return 0;
		}
	}
	vector<pair<int, int>> result_(100003);
	for (int i = 2; i <= N * 2 + 1; i++)
	{
		result_[i] = pair<int, int>(cssNum[i], i);
	}
	sort(result_.begin(), result_.end(), greater<pair<int, int>>());
	
	for (int i = 2 * N + 1; i >= 2; i--)
	{
		int var = result_[i].second;
		if (realResult[var/2] == -1)
		{
			if (var % 2 == 0)
			{
				realResult[var / 2] = 1;
			}
			else
			{
				realResult[var / 2] = 0;
			}
		}
	}
	//그래프의 상황에서 모든 경우가 다 true일때 정답이겠죠?
	for (int i = 1; i <= N; i++)
	{
		cout << (realResult[i]==1 ? "R" : "B");
	}
	return 0;
}