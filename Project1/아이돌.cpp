#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stack>
//vector생성이 시간 다 잡아먹습니다..진짜로..
using namespace std;

int N, M;
vector<vector<int>> adj;
int cssNum[3003];
bool finish[3003];
int nodeNum[3003];
int numCnt, resultcnt;
stack<int> sta;

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
		while (1)
		{
			int qq = sta.top();
			sta.pop();
			cssNum[qq] = resultcnt;
			finish[qq] = true;
			if (start == qq)
				break;
		}
		resultcnt++;
	}
	return parent;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin>>N>>M)
	{
		adj = vector<vector<int>>(3003);
		//vector생성이 정말 오래걸린다..참고합시당..
		memset(cssNum, -1, sizeof(cssNum));
		memset(nodeNum, 0, sizeof(nodeNum));
		memset(finish, false, sizeof(finish));
		//음수면 홀수번째
		//짝수면 짝수번째
		for (int i = 1; i <= M; i++)
		{
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
		//1->1
		adj[3].push_back(2);
		for (int i = 2; i <= N * 2 + 1; i++)
		{
			if (nodeNum[i] == 0)
				bfs(i);
		}
		for (int i = 1; i <= N; i++)
		{
			if (cssNum[i * 2] == cssNum[i * 2 + 1])
			{
				cout << "no";
				break;
			}
			if (i == N)
				cout << "yes";
		}
		cout << "\n";
	}
	return 0;
}