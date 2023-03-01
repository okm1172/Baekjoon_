#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#define _CRT_SECURE_NO_WARNINGS 이거 개꿀입니다.
int dat[3002][3002];
int datt2[3002][3002]; // 가로

int main()
{
	int n, m;
	int q, w;
	scanf("%d %d", &n, &m);
	for (q = 1; q <= n; q++)
	{
		for (w = 1; w <= m; w++)
		{
			scanf("%d", &dat[q][w]);
			datt2[q][w] = dat[q][w] + datt2[q][w - 1];
		}
	}
	int k;
	int i, j, x, y;
	scanf("%d", &k);
	for (q = 1; q <= k; q++)
	{
		scanf("%d %d %d %d", &i, &j, &x, &y);
		int sum = 0;
		for (w = i; w <= x; w++)
		{
			sum += datt2[w][y] - datt2[w][j - 1];
		}
		printf("%d\n", sum);
	}
	return 0;
}