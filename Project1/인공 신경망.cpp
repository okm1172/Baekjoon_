#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n, m, q;
int input_[10000];
long long aa[3000][5000];
long long inputa[10000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++)
	{
		int Ci;
		cin >> Ci;
		vector<long long> vec(Ci);
		for (int j = 0; j < Ci; j++)
		{
			cin >> vec[j];
		}
		vec.push_back(n + 1);
		for (int j :vec)
		{
			cin >> aa[i][j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		for (int j = 1; j <= n+1; j++)
		{
			inputa[j] += aa[i][j] * x;
		}
	}
	int x;
	cin >> x;
	inputa[n+1] += x;
	for (int i = 1; i <= q; i++)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> input_[i];
		}
		input_[n + 1] = 1;
		long long result = 0;
		for (int i = 1; i <= n + 1; i++)
		{
			result += input_[i] * inputa[i];
		}
		cout << result << "\n";
	}
	return 0;
}