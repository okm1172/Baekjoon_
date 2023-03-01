#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;
//아니..흐음..ㅋㅋ scc를 찾고 DAG그래프 상태에서
//모두 연결 가능한 경우는 진입 차수가 0 이 1개 일때.
vector<vector<int>> adj;
bool finish[1000003];
int nodeNum[1000003];
int nodenum = 0;
stack<int> sta;
int resultcnt = 0;
int check_[1000003];
int deg[1000010];
vector<vector<int>> result;

int dfs(int start)
{
	//nodeNum 각 노드를 1부터 저장한거
	nodeNum[start] = ++nodenum;
	sta.push(start);
	int parent = nodeNum[start];
	for (auto qq : adj[start])
	{
		if (nodeNum[qq] == 0) parent = min(parent, dfs(qq));
		else if (finish[qq] != true) parent = min(parent, nodeNum[qq]);
		else deg[check_[qq]]++;
	}
	if (parent == nodeNum[start])
	{
		vector<int> aq;
		while (true)
		{
			int aa = sta.top();
			sta.pop();
			aq.push_back(aa);
			check_[aa] = resultcnt;
			finish[aa] = true;
			if (aa == start)
				break;
		}
		result.push_back(aq);
		if (!sta.empty())
			deg[resultcnt]++;
		resultcnt++;
	}
	return parent;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int asd;
	cin >> asd;
	for (int qq = 1; qq <= asd; qq++)
	{
		memset(check_, -1, sizeof(check_));
		memset(nodeNum, 0, sizeof(nodeNum));
		memset(deg, 0, sizeof(deg));
		memset(finish, false, sizeof(finish));
		adj = vector<vector<int>>(1000003);
		result.clear();
		nodenum = 0;
		resultcnt = 0;
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for (int i = 0; i < n; i++)
		{
			if (check_[i]==-1)
				dfs(i);
		}
		int ans = 0;
		int cnt_ = 0;
		for (int i = 0; i < resultcnt; i++)
		{
			if (deg[i] == 0)
			{
				ans = i;
				cnt_++;
			}
		}
		if (cnt_ == 1)
		{
			sort(result[ans].begin(), result[ans].end());
			for (int i = 0; i < result[ans].size(); i++)
				cout << result[ans][i] << "\n";
		}
		else
			cout << "Confused" << "\n";
		cout << "\n";
	}
	return 0;
}