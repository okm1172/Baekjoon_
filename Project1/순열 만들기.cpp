#include <iostream>
//내일 다시 보자 너 진짜 안되겠다 이새기
using namespace std;

int n, m, k;

int n1, m1, k1;
int up;
int main()
{
	int check = 0;
	cin >> n >> m >> k;
	int up1 = 0;
	if (m == 1)
	{
		if (k != n)
			cout << -1;
		else
			for (int j = 1; j <= 2; j++)
			{
				for (int i = n; i >= 1; i--)
					cout << i << " ";
				cout << "\n";
			}
		return 0;
	}
	if (k == 1)
	{
		if (m != n)
			cout << -1;
		else
			for (int j = 1; j <= 2; j++)
			{
				for (int i = 1; i <= n; i++)
					cout << i << " ";
				cout << "\n";
			}
		return 0;
	}
	for (int i = 1;i<=n/k+1; i++)
	{
		n1 = n, m1 = m, k1 = k;
		//m1이 up k1 이 down
		n1 -= k1 * i;
		m1 = m1 - 1 - i;
		up = m1;
		if (n1 - up <= k && n1-up >=1)
		{
			check = 1;
			up1 = i;
			break;
		}
	}
	if (check==0)
	{
		cout << -1; return 0;
	}
	for (int i = 1; i <= up; i++)
		cout << i << " ";
	for (int i = n - k * up1; i >= up + 1; i--)
		cout << i << " ";
	for (int i = up1 - 1; i >= 0; i--)
		for (int j = 0; j <= k-1; j++)
			cout << n - i * k - j << " ";
	cout << "\n";
	for (int i = 1; i <= n / m + 1; i++)
	{
		n1 = n, m1 = m, k1 = k;
		n1 -= m1 * i;
		k1 = k1 - 1 - i;
		up = k1;
		//cout << n1 <<" "<< m1 <<" "<< k1 << endl;
		if (n1 - up <= m && n1 - up >= 1)
		{
			up1 = i;
			break;
		}
	}
	for (int i= 0; i <=up-1; i++)
		cout << n - i << " ";
	for (int i = up1 * m + 1; i <= n - up; i++)
		cout << i << " ";
	for (int i = up1 - 1; i >= 0; i--)
		for (int j = 1; j <= m; j++)
			cout << i * m + j<<" ";
	return 0;
}