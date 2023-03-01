#include <iostream>
#include <string.h>

using namespace std;

int n, m;
int x, y;
int data_[22][22];
int k;
//À§¾Æ·¡
int dicehi[10];
//¾ç¿·
int diceri[10];
int k_;
int xx, yy;
void result(int x,int y)
{
	if (k_ == 1)
	{
		for (int i = 3; i >= 1; i--)
		{
			diceri[i] = diceri[i - 1];
		}
		diceri[1] = dicehi[4];
		dicehi[4] = data_[x][y],dicehi[0] = dicehi[4];
		diceri[0] = diceri[3], diceri[4] = diceri[1], dicehi[2] = diceri[2];
	}
	else if (k_ == 2)
	{
		for (int i = 1; i <= 3; i++)
		{
			diceri[i] = diceri[i + 1];
		}
		diceri[3] = dicehi[4];
		dicehi[4] = data_[x][y], dicehi[0] = dicehi[4];
		diceri[0] = diceri[3], diceri[4] = diceri[1], dicehi[2] = diceri[2];
	}
	else if (k_ == 3)
	{
		for (int i = 1; i <= 4; i++)
		{
			dicehi[i] = dicehi[i + 1];
		}
		dicehi[4] = data_[x][y];
		dicehi[0] = dicehi[4], dicehi[5] = dicehi[1], diceri[2] = dicehi[2];
	}
	else if (k_ == 4)
	{
		for (int i = 4; i >= 1; i--)
		{
			dicehi[i] = dicehi[i - 1];
		}
		dicehi[4] = data_[x][y];
		dicehi[0] = dicehi[4], dicehi[5] = dicehi[1], diceri[2] = dicehi[2];
	}
}
void check()
{
	if (k_ == 1)
		y++;
	else if (k_ == 2)
		y--;
	else if (k_ == 3)
		x--;
	else if (k_ == 4)
		x++;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//1 -> µ¿ 2 -> ¼­ 3 -> ºÏ 4 -> ³²
	memset(data_, -1, sizeof(data_));
	cin >> n >> m>>x>>y>>k;
	x++, y++;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> data_[i][j];
		}
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> k_;
		xx = x,yy=y;
		check();
		if (data_[x][y] == -1)
		{
			x = xx, y = yy;
			continue;
		}
		if (data_[x][y] == 0)
		{
			if (k_ == 1)
				data_[x][y] = diceri[3];
			if (k_ == 2)
				data_[x][y] = diceri[1];
			if (k_ == 3)
				data_[x][y] = dicehi[1];
			if (k_ == 4)
				data_[x][y] = dicehi[3];
			result(x, y);
		}
		else
		{
			result(x, y);
			data_[x][y] = 0;
		}
		cout << diceri[2]<<"\n";
	}
	return 0;
}