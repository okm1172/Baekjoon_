#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, k,t,Di;
int cost[10003];
vector<vector<int>> vec;
int whicheck[10003];
int costsum[10003];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t)
	{
		cin >> n >> k;
		memset(cost, 0, sizeof cost);
		memset(whicheck, 0, sizeof whicheck);
		vec = vector<vector<int>>(n+2);
		vector<int> last;
		for (int i = 1; i <= n; i++) cin >> cost[i];
		for (int i = 1; i <= k; i++)
		{
			int x, y;
			cin >> x >> y;
			vec[y].push_back(x);
		}
		cin >> Di;
		queue<int> que;
		que.push(Di);
		whicheck[Di] = 1;
		while (!que.empty())
		{
			int start = que.front();
			que.pop();
			for (int i : vec[start])
			{
				if (whicheck[i] == 0)
					whicheck[i]++, que.push(i);
				else
					whicheck[i]++;
			}
			if (vec[start].size() == 0)
				last.push_back(start);
		}
		que.push(Di);
		fill(costsum, costsum + 1003, -2147483647);
		costsum[Di] = cost[Di];
		while (!que.empty())
		{
			int start = que.front();
			que.pop();
			for (int i : vec[start])
			{
				whicheck[i]--;
				if (costsum[i] < costsum[start] + cost[i])
					costsum[i] = costsum[start] + cost[i];
				if (whicheck[i] == 0)
					que.push(i);
			}
		}
		int max = -1;
		for (int i = 0; i < last.size(); i++)
			if (max < costsum[last[i]])
				max = costsum[last[i]];
		cout << max << "\n";
		t--;
	}
	return 0;
}