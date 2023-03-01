#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int dat[66][66] = { 0 };
char datt;
int n;

void quad(int leftx,int lefty,int rightx,int righty,int check)
{
	int i, j;
	int sum = 0;
	
	for (i = leftx; i <= rightx; i++)
	{
		for (j = lefty; j <= righty; j++)
		{
			sum += dat[i][j];
		}
	}
	if (sum == 0)
	{
		cout << 0;
		return;
	}
	else if (sum == (rightx - leftx+1) * (rightx - leftx+1))
	{
		cout << 1;
		return;
	}
	cout << "(";
	quad(leftx, lefty, (leftx + rightx) / 2, (lefty + righty) / 2,1);
	quad(leftx, (lefty + righty) / 2 + 1, (rightx+leftx)/2, righty,2);
	quad((leftx + rightx) / 2 + 1, lefty, rightx, (righty + lefty) / 2,3);
	quad((leftx + rightx) / 2 + 1, (righty + lefty) / 2 + 1, rightx, righty,4);
	cout << ")";
}
int main()
{
	cin >> n;
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> datt;
			dat[i][j] = datt - '0';
		}
	}
	quad(1, 1, n, n,1);
	return 0;
}