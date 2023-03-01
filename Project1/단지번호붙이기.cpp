#include <iostream>
#include <algorithm>

using namespace std;

int dfs[30][30];
int result[1000];
int resultcnt = 0;
int ccnt = 0;
int N;
void DFS(int x, int y)
{
	if (dfs[x + 1][y] == 1)
	{
		ccnt++;
		dfs[x + 1][y] = 2;
		DFS(x + 1, y);
	}
	if (dfs[x][y+1] == 1)
	{
		ccnt++;
		dfs[x][y+1] = 2;
		DFS(x, y+1);
	}
	if (dfs[x - 1][y] == 1)
	{
		ccnt++;
		dfs[x - 1][y] = 2;
		DFS(x - 1, y);
	}
	if (dfs[x][y-1] == 1)
	{
		ccnt++;
		dfs[x][y-1] = 2;
		DFS(x, y-1);
	}
}
int main()
{
	string qq;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> qq;
		for (int j = 1; j <= N; j++)
		{
			dfs[i][j] = qq[j - 1] - '0';
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dfs[i][j] == 1)
			{
				dfs[i][j] = 2;
				ccnt++;
				DFS(i, j);
				result[resultcnt] = ccnt;
				resultcnt++;
				ccnt = 0;
			}
		}
	}
	sort(result, result + resultcnt);
	cout << resultcnt << endl;
	if (resultcnt == 0)
		return 0;
	for (int i = 0; i < resultcnt; i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}