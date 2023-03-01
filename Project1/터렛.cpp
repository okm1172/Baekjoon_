#include <iostream>
#include <math.h>
//쫄았지만 천천히 읽어보니 정말 쉬운 문제였다.
using namespace std;

int solve(int a, int b)
{
	if (a > b)
		return a - b;
	else
		return b - a;
}

int main()
{
	int n;
	int x1, y1, r1, x2, y2, r2;
	double length = 0.0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x1>> y1>> r1>> x2>> y2>> r2;
		int a = x2 - x1, b = y2 - y1;
		int r3 = r1+r2;
		int r4 = solve(r1,r2);
		length = sqrt(a * a + b * b);
		if (r4 < length) {
			if ((double)r3 > length)
				cout << "2" << '\n';
			else if ((double)r3 == length)
				cout << "1" << '\n';
			else if ((double)r3 < length)
				cout << "0" << '\n';
		}
		else if (r4 == length)
		{
			if (length == 0)
				cout << "-1" << '\n';
			else
				cout << "1" << '\n';
		}
		else if (r4 > length)
		{
			cout << "0" << '\n';
		}
	}
	return 0;
}