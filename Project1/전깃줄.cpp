#include <iostream>

using namespace std;

int n;
int data_[503];
int data_re[503];
int dp[503];
int main()
{
	cin >> n;
	//n전기줄 개수
	//전기줄 번호는 500이하
	int max = -999;
	for (int i = 1; i <= n; i++)
	{
		int start, end;
		cin >> start >> end;
		if (max < start)
			max = start;
		if (max < end)
			max = end;
		data_[start] = end;
		data_re[end] = start;
	}
	int dpmax = -999;
	for (int i = 1; i <= max; i++)
	{
		if (data_[i] == 0)
			continue;
		for (int j = 1; j <= data_[i]; j++)
		{
			if (data_re[j] == 0)
				continue;
			if (data_re[j] > i)
				continue;
			if (data_re[j] < i)
			{
				if (dp[i] < dp[data_re[j]] + 1)
				{
					//cout << data_re[j] << " ";
					dp[i] = dp[data_re[j]] + 1;
					if (dpmax < dp[i])
						dpmax = dp[i];
				}
			}
		}/*
		cout << ": " << dp[i];
		cout << endl;*/
	}
	dpmax++;
	cout << n - dpmax;
	return 0;
}