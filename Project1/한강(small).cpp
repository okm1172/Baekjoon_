#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int check[1000002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=2;i<=1000000;i++)
	{
		for (int j = 1; j <= 1000000 / i; j++)
		{
			check[i * j]++;
		}
	}
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int result = 0;
		int n, m;
		cin >> n >> m;
		if (check[n] == 1)
		{

			cout << "Case #" << i << ": " << 0 << "\n";
			continue;
		}
		for (int j = 2; j <= n-1; j++)
		{
			if (check[j] == check[n])
			{
				if (sqrt(j) < m)
					continue;
				int check = 0;
				for (int k = 2; k <= m-1; k++)
				{
					if (j % k == 0)
					{
						check = 1;
						break;
					}
				}
				if (check == 0)
					result++;
			}
		}
		cout << "Case #"<<i<<": "<<result << "\n";
	}
	return 0;
}