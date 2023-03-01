#include <iostream>

using namespace std;

int checkgrand[103];
int data_[103][103];
int xgrand, ygrand, xcnt, ycnt;
int n;
int x, y;
int m, xx, yy;
int check = 0;
int end_ = 0;
int x_[30], y_[30];
int noone[300];
void dfsx(int start,int cnt)
{
	if (checkgrand[start] == 0)
	{
		xcnt = cnt;
		xgrand = start;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (data_[start][i] == 1)
		{
			x_[cnt+1] = i;
			dfsx(i,cnt+1);
			if (end_ == 1)
				break;
		}
	}
}
void dfsy(int start, int cnt)
{
	if (checkgrand[start] == 0)
	{
		ycnt = cnt;
		ygrand = start;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (data_[start][i] == 1)
		{
			y_[cnt+1] = i;
			dfsy(i, cnt + 1);
			if (end_ == 1)
				break;
		}
	}
}
int main()
{
	cin >> n >> x >> y;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> xx >> yy;
		data_[yy][xx] = 1;
		checkgrand[yy] = 1;
		noone[xx] = 1, noone[yy] = 1;
	}
	if (noone[x] == 0 || noone[y] == 0)
	{
		cout << -1;
		return 0;
	}
	dfsx(x, 0);
	dfsy(y, 0);
	for (int i = 1; i <= xcnt; i++)
	{
		if (x_[i] == y)
		{
			cout << i;
			return 0;
		}
	}
	for (int i = 1; i <= ycnt; i++)
	{
		if (y_[i] == x)
		{
			cout << i;
			return 0;
		}
	}
	for (int i = 1; i <= xcnt; i++)
	{
		for (int j = 1; j <= ycnt; j++)
		{
			if (x_[i] == y_[j])
			{
				cout << i + j;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}