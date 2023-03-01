#include <iostream>
#include <string.h>

using namespace std;
long long n, k;
long long dp[54][54];
long long dp_(int a, int b)
{
	if (a == n)
	{
		if (b == 0) return 1;
		else return 0;
	}
	if (b < 0)
		return 0;
	if (dp[a][b] != -1)
		return dp[a][b];
	return dp[a][b] = dp_(a + 1, b + 1) + dp_(a + 1, b - 1);
}
void result(int a, int b,long long k)
{
	if (a==n) return;
	if (dp[a+1][b+1] <= k)
	{
		cout << ")";
		result(a + 1, b - 1, k - dp[a+1][b+1]);
	}
	else
	{
		cout << "(";
		result(a + 1, b + 1, k);
	}
}
int main()
{
	cin >> n >> k;
	memset(dp, -1, sizeof dp);
	if (dp_(0, 0) <= k) cout << -1;
	else result(0, 0,k);
	return 0;
}