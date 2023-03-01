#include <iostream>

using namespace std;

int code1(int a)
{
	if (a == 1)
		return 5000000;
	else if (a > 1 && a <= 3)
		return 3000000;
	else if (a > 3 && a <= 6)
		return 2000000;
	else if (a > 6 && a <= 10)
		return 500000;
	else if (a > 10 && a <= 15)
		return 300000;
	else if (a > 15 && a <= 21)
		return 100000;
	else
		return 0;
}
int code2(int a)
{
	if (a == 1)
		return 5120000;
	else if (a > 1 && a <= 3)
		return 2560000;
	else if (a > 3 && a <= 7)
		return 1280000;
	else if (a > 7 && a <= 15)
		return 640000;
	else if (a > 15 && a <= 31)
		return 320000;
	else
		return 0;
}
int main()
{
	int a, n, m;
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		cin >> n >> m;
		cout << code1(n) + code2(m) << '\n';
	}
	return 0;
}
//1 3 6 10 15 21
//1 3 7 15 31