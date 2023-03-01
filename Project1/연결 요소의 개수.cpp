#include <iostream>

using namespace std;

int dfs[1050][1050];
int memo[1050];
int resultcnt = 0;
int N, M;
void Dfs(int start)
{
	for (int j = 1; j <= N; j++)
	{
		if (dfs[start][j] == 1 && memo[j] == 0)
		{
			memo[j] = 1;
			Dfs(j);
		}
	}
}
int main()
{
	cin >> N>>M;
	for (int i = 1; i <= M; i++)
	{
		int x, y;
		cin >> x >> y;
		dfs[x][y] = 1;
		dfs[y][x] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dfs[i][j] == 1 && memo[i] == 0)
			{
				memo[i] = 1;
				Dfs(i);
				resultcnt++;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (memo[i] == 0)
			resultcnt++;
	}
	cout << resultcnt;
	return 0;
}