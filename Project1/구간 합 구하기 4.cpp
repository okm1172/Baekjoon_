#include <stdio.h>

//����,, iostream ���� �Է°� ����� stdio.h�� ����ü� ����.
//endl ���� '\n'�� �� ������..

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