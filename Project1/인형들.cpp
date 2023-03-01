#include <iostream>
#include <math.h>
#include <stdio.h>
//문제 잘보자,, 오류도 잘보고 이런문제는 예시를 따로 구해서 못하니까 제발좀,,제발!!
using namespace std;

int main()
{
	long double min = 999999999999;
	int n, m;
	int dat[1000];
	int i,j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		cin >> dat[i];
	}
	for (i = m; i <= n; i++)
	{
		for (j = 1; j <= n - i + 1; j++)
		{
			long double sum = 0.0;
			for (int k = j; k <= j + i - 1; k++)
			{
				sum += (double)dat[k];
			}
			sum = sum / (double)i;
			long double sum2 = 0.0;
			for (int k = j; k <= j + i - 1; k++)
			{
				sum2 += ((double)dat[k] - sum) * ((double)dat[k] - sum);
			}
			sum2 = sum2 / (double)i;
			if (min > sum2)
				min = sum2;
		}
	}
	min=sqrt(min);
	printf("%.11Lf", min);
	return 0;
}