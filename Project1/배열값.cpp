#include <iostream>
#define ai 2005
using namespace std;
//아 이거 벽땜에 가져올수 없는 값을 생각 안했네..ㅜㅜ
int data2[ai][ai], data5[ai][ai], mem2[ai][ai], mem5[ai][ai];
int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int x, cnt2 = 0, cnt5 = 0;
			cin >> x;
			if(x==0)
			{
				data2[i][j] = -1, data5[i][j] = -1;
				continue;
			}
			while (1)
			{
				if (x % 2 == 0)
				{
					x /= 2;
					cnt2++; continue;
				}
				break;
			}
			while (1)
			{
				if (x % 5 == 0)
				{
					x /= 5;
					cnt5++; continue;
				}
				break;
			}
			data2[i][j] = cnt2;
			data5[i][j] = cnt5;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == 1 && j == 1)
			{
				mem2[i][j] = data2[i][j];
				mem5[i][j] = data5[i][j];
				continue;
			}
			if (data2[i][j] == -1)
			{
				mem2[i][j] = -1, mem5[i][j] = -1;
				continue;
			}
			int a = (i == 1) ? -1 : mem2[i - 1][j];
			int b = (j == 1) ? -1 : mem2[i][j - 1];
			int c;
			if (a < 0)
				c = b;
			else if (b < 0)
				c = a;
			else
				c = (a < b) ? a : b;
			if (a < 0 && b < 0)
				mem2[i][j] = c;
			else
				mem2[i][j] = c + data2[i][j];
			a = (i == 1) ? -1 : mem5[i - 1][j];
			b = (j == 1) ? -1 : mem5[i][j - 1];
			if (a < 0)
				c = b;
			else if (b < 0)
				c = a;
			else
				c = (a < b) ? a : b;
			if (a < 0 && b < 0)
				mem5[i][j] = c;
			else
				mem5[i][j] = c + data5[i][j];
		}
	}
	cout << min(mem2[n][n], mem5[n][n]);
	return 0;
}