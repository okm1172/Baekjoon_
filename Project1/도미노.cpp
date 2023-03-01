#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stack>

using namespace std;

vector<vector<int>> adj;
int nodeNum[1000003];
bool finish[1000003];
int NumId;
stack<int> sta;
int deg[1000003];
int sccNum[1000003];
int resultcnt = 0;

int dfs(int start)
{
	sta.push(start);
	nodeNum[start] = ++NumId;
	int parent = nodeNum[start];
	for (auto k : adj[start])
	{
		if (nodeNum[k] == 0) parent = min(parent, dfs(k));
		else if (finish[k] != true) parent = min(parent, nodeNum[k]);
		else deg[sccNum[k]]++;
	}
	if (parent == nodeNum[start])
	{
		while (1)
		{
			int aa = sta.top();
			sta.pop();
			sccNum[aa] = resultcnt;
			finish[aa] = true;
			if (start == aa)
				break;
		}
		if (!sta.empty())
			deg[resultcnt]++;
		resultcnt++;
	}
	return parent;
}
int main()
{
	int tt;
	cin >> tt;
	for (int qq = 1; qq <= tt; qq++)
	{
		int N, M;
		cin >> N>> M;
		memset(sccNum, -1, sizeof(sccNum));
		memset(deg, 0, sizeof(deg));
		memset(finish, false, sizeof(finish));
		memset(nodeNum, 0, sizeof(nodeNum));
		adj = vector<vector<int>>(1000003);
		resultcnt = 0;
		NumId = 0;
		for (int i = 1; i <= M; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for (int i = 1; i <= N; i++)
		{
			if (nodeNum[i] == 0)
				dfs(i);
		}
		int cnt_ = 0;
		for (int i = 0;i<resultcnt; i++)
		{
			if (deg[i] == 0)
			{
				cnt_++;
			}
		}
		cout << cnt_ << "\n";
	}
	return 0;
}