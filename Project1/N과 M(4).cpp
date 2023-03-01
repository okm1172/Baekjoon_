#include <iostream>

using namespace std;

int n, m;
int check[10];
void aa(int start,int cnt)
{
	if (cnt == m)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= check[i]; j++)
			{
				cout << i << " ";
			}
		}
		cout << "\n";
		return;
	}
	for (int i = start; i <= n; i++)
	{
		check[i]++;
		aa(i,cnt + 1);
		check[i]--;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	aa(1,0);
	return 0;
}