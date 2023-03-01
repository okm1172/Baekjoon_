#include <iostream>

using namespace std;

int check[200];
int wh[200];

int main()
{
	int n, k;
	int data[10004];
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		int qqq;
		cin >> qqq;
		check[qqq]++;
		data[i] = qqq;
	}
	int cnt = 0;
	if (k <= n)
	{
		cout << 0;
		return 0;
	}
	//2 3
	for (int i = 1; i <= n; i++)
	{
		check[data[i]]--;
		for (int j = 1; j <= n; j++)
		{
			if (data[i] == wh[j])
			{
				break;
			}
			if (j == n)
				wh[i] = data[i];
		}
	}
	//check는 개수
	//wh는 위치
	//n은 플러그 k 는 총 개수
	//3 14
	//1 4 3 2 5 4 3 2 5 3 4 2 3 4
	int checkcnt2 = 0;
	for (int i = n+1; i <= k; i++)
	{
		int min = 8999;
		int minj = 0;
		int whcnt = 0;
		//중복된거 확인
		for (int j = 1; j <= n; j++)
		{
			if (data[i] == wh[j])
			{
				whcnt++;
			}
			if (check[wh[j]] >= 1)
				checkcnt2++;
		}
		// 1 2 3 4 5
		// 0 1 1 1 1
		// 5 4 3
		int checkmax = -9999;
		int checki = 0;
		if (checkcnt2 == n)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = i; k <= n; k++)
				{
					if (wh[j] == data[k])
					{
						if (checkmax < k)
						{
							checkmax = k;
							checki = j;
						}
						break;
					}
				}
			}
			wh[checki] = data[i];
			check[wh[checki]]--;
			continue;
		}
		if(whcnt==0)
		{
			int ccnt = 0;
			//처음부터 비어져있던 플러그 체크
			for (int j = 1; j <= n; j++)
			{
				if (wh[j] == 0)
				{
					check[data[i]]--;
					wh[j] = data[i];
					ccnt++;
					break;
				}
			}
			if (ccnt == 1)
				continue;
			//빼야할 플러그 체크
			for (int k = 1; k <= n; k++)
			{
				if (check[wh[k]] < min)
				{
					min = check[wh[k]];
					minj = k;
				}
			}
			cout << wh[minj] << " ";
			wh[minj] = data[i];
			check[data[i]]--;
			cnt++;
		}
		//중복된걸 써야할때.
		else
		{
			check[data[i]]--;
		}
	}
	cout << cnt;
	return 0;
}