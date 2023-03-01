#include <iostream>
#define MAX 2147483647
using namespace std;

long long data_[100000] = { 0 };
int main()
{
	data_[1] = 1;
	for (int i = 2;; i++)
	{
		data_[i] = data_[i - 1] + i;
		if (data_[i] * 2 > 2147483647)
			break;
	}
	int n;
	cin >> n;
	while (n)
	{
		long long a, b;
		cin >> a >> b;
		long long c = (a > b ? a - b : b - a);
		if (c == 1)
		{
			cout << 1<<"\n";
			n--;
			continue;
		}
		for (long long i = 1;; i++)
		{
			if (data_[i] * 2 > c)
			{
				long long cc = ((c - data_[i - 1] * 2) % i == 0 ? (c - data_[i - 1] * 2) / i : (c - data_[i - 1] * 2) / i + 1);
				cout << (i - 1) * 2 + cc<< "\n";
				break;
			}
		}
		n--;
	}
	return 0;
}