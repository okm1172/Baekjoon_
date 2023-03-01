#include <iostream>
#include <string>

using namespace std;

int n;

int main()
{
	cin >> n;
	int x1, y1, x2, y2;
	string result;
	cin >> x1 >> y1 >> x2 >> y2;
	int x = x2 - x1, y= y2 - y1;
	if (x < 0 || y < 0)
	{
		cout << -1;
		return 0;
	}
	if ((x + y) <= n)
	{
		for (int i = 1; i <= x; i++) cout << "R";
		for (int i = 1; i <= y; i++) cout << "U";
		for (int i = 1; i <= n-(x+y); i++) cout << "R";
		return 0;
	}
	result = string(n, 'Z');
	int aa = (x + y) % n;
	int bb = (x + y) / n;
	//오차 구하기
	for (int i = n; i >= 0; i--)
	{
		if (x - i < 0)
			continue;
		if ((x - i) % bb == 0)
		{
			int r1 = i;
			int r2 = (x - i) / bb - i;
			int u1 = aa - r1;
			int u2 = n - r1 - r2 - u1;
			if (r1 < 0 || r2 < 0 || u1 < 0 || u2 < 0)
				continue;
			string result_;
			result_ += string(r1, 'R');
			result_ += string(u1, 'U');
			result_ += string(r2, 'R');
			result_ += string(u2, 'U');
			if (result_ < result)
				result = result_;
		}
	}
	if (result[0] == 'Z')
		cout << -1;
	else
		for (int i = 0; i < result.size(); i++) cout << result[i];
	return 0;
}