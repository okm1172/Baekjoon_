#include <iostream>

using namespace std;

int dp[20];
int n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t, p;
		cin >> t >> p;
		for (int j = i + t; j <= n + 1; j++)
		{
			if (dp[j] < dp[i] + p)
				dp[j] = dp[i] + p;
		}
	}
	cout << dp[n + 1];
	return 0;
}