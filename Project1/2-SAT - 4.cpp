#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;

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
		//À½¼ö¸é È¦¼ö¹øÂ°
		//Â¦¼ö¸é Â¦¼ö¹øÂ°
		int x, y;
		cin >> x >> y;
		int x_, y_;
		if (x < 0)
		{
			x_ = x * -2;
			x = x * -2 + 1;
		}
		else
		{
			x_ = x * 2 + 1;
			x = x * 2;
		}
		if (y < 0)
		{
			y_ = y * -2;
			y = y * -2 + 1;
		}
		else
		{
			y_ = y * 2 + 1;
			y = y * 2;
		}
		adj[x_].push_back(y);
		adj[y_].push_back(x);
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
			cout << 0;
			return 0;
		}
	}
	cout << 1 << "\n";
	vector<pair<int, int>> result_(1000003);
	
	for (int i = 2; i <= N * 2 + 1; i++)
	{
		result_[i] = pair<int, int>(cssNum[i], i);
	}
	sort(result_.begin(), result_.end(),greater<pair<int,int>>());
	for (int i = N*2+1;i>=2; i--)
	{
		int var = result_[i].second;
		if (realResult[var / 2] == -1)
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
	for (int i = 1; i <= N; i++)
	{
		if (realResult[i] == -1) cout << 0 << " ";
		else
		cout << realResult[i] << " ";
	}
	return 0;
}