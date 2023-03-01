#include <iostream>
#define left 1
#define right 2
using namespace std;

int data_[35][35][4];
int data_2[35][35][4];
//n이 사다리 h가 점선
int n, m, h;
int cnt_ = 999;
int ccnt = 0;
int check = 0;
void result()
{
	for (int i = 1; i <= n; i++)
	{
		int start = i;
		for (int j = 1; j <= h; j++)
		{
			if (data_2[j][start][right] != 0 && data_2[j][start+1][left] != 0 && start<=n-1)
				start++;
			else if (data_2[j][start][left] != 0 && data_2[j][start-1][right] != 0 && start>=2)
				start--;
		}
		if (start != i)
			return;
	}
	int cnt__ = 0;
	check = 1;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (data_2[i][j][right] != 0)
				cnt__++;
		}
	}
	if (cnt_ > cnt__ - m)
		cnt_ = cnt__ - m;
}
void letter(int cnt,int ii)
{
	if (cnt == ccnt)
	{
		result();
		return;
	}
	for (int i = ii; i <= h; i++)
	{
		for (int j = 1; j <= n-1; j++)
		{
			if (data_2[i][j][right] != 0 && data_2[i][j+1][left] != 0)
			{
				j += 2;
			}
			else if (data_2[i][j][left] != 0)
			{
				j += 1;
			}
			else if (data_2[i][j + 1][right] != 0)
			{
				j += 3;
			}
			if (data_2[i][j][right] == 0 && data_2[i][j + 1][left] == 0 && data_2[i][j][left]==0 && data_2[i][j+1][right]==0)
			{
				data_2[i][j][right]++;
				data_2[i][j + 1][left]++;
				letter(cnt + 1,i);
				data_2[i][j][right]--;
				data_2[i][j + 1][left]--;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> h;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		data_[a][b][right] = 1;
		data_[a][b + 1][left] = 1;
		data_2[a][b][right] = 1;
		data_2[a][b + 1][left] = 1;
	}
	//ccnt=0
	result();
	if (check == 1)
	{
		cout << 0;
		return 0;
	}
	ccnt = 1;
	letter(0,1);
	if (check == 1)
	{
		cout << 1;
		return 0;
	}
	ccnt = 2;
	letter(0,1);
	if (check == 1)
	{
		cout << 2;
		return 0;
	}
	ccnt = 3;
	letter(0,1);
	if (check == 1)
	{
		cout << 3;
		return 0;
	}
	cout << -1;
	return 0;
}