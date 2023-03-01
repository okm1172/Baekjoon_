#include <iostream>
#include <string.h>

using namespace std;

long long n, m;
long long dp[53][106][3];
long long dp_(int a, int b, int k)
{
	if (a == n)
	{
		return b || k;
	}
	if (dp[a][b+51][k] != -1)
		return dp[a][b+51][k];
	return dp[a][b+51][k] = dp_(a + 1, b + 1, k) + dp_(a + 1, b - 1, (b<1) || k);
}
void result_(int a,int b,int c,long long k)
{
	if (a == n) return;
	if (dp_(a+1,b+1,c) <= k)
	{
		cout << ")";
		result_(a + 1, b - 1, (b < 1) || c, k - dp_(a + 1, b + 1, c));
	}
	else
	{
		cout << "(";
		result_(a + 1, b + 1, c , k);
	}
}
int main()
{
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	if (dp_(0, 0, 0) <= m)
		cout << -1;
	else
		result_(0, 0, 0, m);
	return 0;
}