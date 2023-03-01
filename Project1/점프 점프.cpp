#include <iostream>

using namespace std;

int n;
int dp[10003];

int main()
{
	cin >> n;
	fill(dp, dp + 1004, 2147483647);
	dp[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dp[i] == 2147483647)
			break;
		int a;
		cin >> a;
		for (int j = i+1; j <= i + a; j++)
		{
			if (j > n) break;
			if (dp[i] + 1 < dp[j])
				dp[j] = dp[i] + 1;
		}
	}
	cout << (dp[n]==2147483647 ? -1 : dp[n]);
	return 0;
}