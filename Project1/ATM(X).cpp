#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>
#include <queue>
//아 모르겠다 지지 07/30 아니 도대체 메모리 초과가 어디서 나는거야..512메가는 넘기도 힘들겠다 진짜로 ㅋㅋ
//안풀려요 대충 로직만 이해했으면 된거죠 너무 효율 떨어집니다. 이렇게 공부하면.. 수고요 ATM행복햇어요..ㅜㅜ
#define ss 500005
using namespace std;

int n, m;
vector<vector<int>> adj(ss);
vector<vector<int>> scc(ss);
vector<vector<int>> sccscc(ss);
stack<int> sta;
queue<int> que;
bool finish[ss];
int nodeNum[ss];
int sccnode[ss];
int scccostsum[ss];
int cost[ss];
int sccCnt = 1;
int nodeId = 0;
int check[ss];
int check_[ss];
int dfs(int start)
{
	sta.push(start);
	nodeNum[start] = ++nodeId;
	int parent = nodeNum[start];
	for (auto q : adj[start])
	{
		if (nodeNum[q] == 0) parent = min(parent, dfs(q));
		else if (finish[q] != true) parent = min(parent, nodeNum[q]);
	}
	if (parent == nodeNum[start])
	{
		vector<int> result; 
		while (1)
		{
			int aa = sta.top();
			sta.pop();
			finish[aa] = true;
			result.push_back(aa);
			sccnode[aa] = sccCnt;
			if (aa == start)
				break;
		}
		scc[sccCnt] = result;
		sccCnt++;
	}
	return parent;
}
void dfs2(int start)
{
	que.pop();
	for (auto i : sccscc[start])
	{
		que.push(i);
		if (cost[i] < cost[start] + scccostsum[i])
			cost[i] = cost[start] + scccostsum[i];
	}
	if (que.empty())
		return;
	dfs2(que.front());
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		cost[i] = x;
	}
	int start, p;
	cin >> start >> p;
	dfs(start);
	sccCnt--;
	//각 scc에 포함되는 cost들을 미리 더한값을 저장해줍시다.
	for (int i = 1; i <= sccCnt; i++)
	{
	//	cout << i << " ";
		for (auto a : scc[i])
		{
		//	cout << a << " ";
			scccostsum[i] += cost[a];
		}
	//	cout << endl;
	}
	//여기서부터 cost가 dp배열 역할
	for (int i = 1; i <= n; i++)
	{
		if (check[sccnode[i]] == 1)
			continue;
		check[sccnode[i]] = 1;
		memset(check_, 0, sizeof(check_));
		for (auto k : scc[sccnode[i]])
		{
			//sccnode[k] = 4 sccnode[i] = 4
			//k는 1 2 4
			for (auto kk : adj[k])
			{
				if (sccnode[kk] == sccnode[i] || check_[sccnode[kk]]==1)
					continue;
				sccscc[sccnode[i]].push_back(sccnode[kk]);
				check_[sccnode[kk]] = 1;
			}
		}
	}
	//1 5
	//2 3
	//3 6
	//4 4 2 1
	que.push(sccnode[start]);
	memset(cost, 0, sizeof(cost));
	cost[sccnode[start]] = scccostsum[sccnode[start]];
	dfs2(sccnode[start]);
	int max = -999;
	for (int i = 1; i <= p; i++)
	{
		int x;
		cin >> x;
		if (max < cost[sccnode[x]])
			max = cost[sccnode[x]];
	}
	cout << max;
	return 0;
}