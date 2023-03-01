#include <stdio.h>

//교훈,, iostream 에서 입력과 출력은 stdio.h를 따라올수 없다.
//endl 보다 '\n'이 더 빠르다..

int dat[100006];
int datt[100006];

int main()
{
	int n, m,i;
	datt[0] = 0;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &dat[i]);
		datt[i] = dat[i] + datt[i-1];
	}
	int dat1, dat2;
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &dat1, &dat2);
		printf("%d\n", datt[dat2] - datt[dat1 - 1]);
	}
	return 0;
}