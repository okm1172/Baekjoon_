#include <iostream>

using namespace std;

int input[1200][1200];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> input[i][j];
			input[i][j] += input[i - 1][j];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int sum = 0;
		for (int j = y1; j <= y2; j++)
		{
			sum += input[x2][j] - input[x1][j] + (input[x1][j] - input[x1-1][j]);
		}
		cout << sum << "\n";
	}
	return 0;
}