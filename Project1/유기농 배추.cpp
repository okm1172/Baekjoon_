#include <iostream>

using namespace std;

int AA[60][60] = { 0 };

void dfs(int x,int y,int cnt)
{
	if (AA[x + 1][y] == -1)
	{
		AA[x + 1][y] = cnt;
		dfs(x + 1, y, cnt);
	}
	if (AA[x - 1][y] == -1)
	{
		AA[x - 1][y] = cnt;
		dfs(x - 1, y, cnt);
	}
	if (AA[x][y+1] == -1)
	{
		AA[x][y+1] = cnt;
		dfs(x, y+1, cnt);
	}
	if (AA[x][y-1] == -1)
	{
		AA[x][y-1] = cnt;
		dfs(x, y-1, cnt);
	}
	return;
}
int main()
{
	int T, M, N,K;
	int xx, yy;
	cin >> T;
	for (int q = 1; q <= T; q++)
	{
		for (int i = 0; i <= 52; i++)
		{
			for (int j = 0; j <= 52; j++)
			{
				AA[i][j] = 0;
			}
		}
		//M 가로 N 세로 K위치의 개수
		cin >> M >> N>>K;
		//입력
		//입력 받을때 0 처리 쉽게 처리하려고 +1씩했습니다.
		for (int i = 1; i <= K; i++)
		{
			cin >> xx >> yy;
			AA[xx+1][yy+1] = -1;
		}
		int cnt = 0;
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (AA[i][j] == -1)
				{
					cnt++;
					AA[i][j] = cnt;
					dfs(i, j, cnt);
				}
			}
		}
		cout << cnt<<"\n";
	}
	return 0;
}