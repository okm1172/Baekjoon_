#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
int M, number[11];
int result = 21474836;
int Cnt = 0;
void remote(int n, int cnt)
{
	if (Cnt== cnt)
	{
		int nn = n;
		int ccnt = 0;
		while (1)
		{
			nn /= 10;
			ccnt++;
			if (nn == 0)
				break;
		}
		ccnt = Cnt - ccnt;
		if (n > N)
		{
			if (result > n - N-ccnt)
			{
				result = n - N-ccnt;
			}
		}
		else
		{
			if (result > N - n-ccnt)
			{
				result = N - n-ccnt;
			}
		}
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (number[i] == 1)
			continue;
		remote(n * 10 + i, cnt + 1);
	}
}
int main()
{
	cin >> N;
	int n = N;
	while (1)
	{
		n /= 10;
		Cnt++;
		if (n == 0)
			break;
	}
	cin >> M;
	for (int i = 1; i <= M; i++)
	{
		int a;
		cin >> a;
		number[a] = 1;
	}
	int result2 = 0;
	int Result = 0;
	int ssort[10];
	if (N < 100)
		result2 = 100 - N;
	else
		result2 = N - 100;
	ssort[0] = result2;
	//÷
	remote(0, 0);
	ssort[1] = result + Cnt;
	//÷+1
	Cnt++;
	result = 214748364;
	remote(0, 0);
	ssort[2] = result + Cnt;
	//÷-1
	result = 214748364;
	Cnt -= 2;
	if (Cnt > 0)
	{
		remote(0, 0);
		ssort[3] = result + Cnt;
	}
	else
	{
		ssort[3] = 214748364;
	}
	sort(ssort, ssort + 4);
	cout << ssort[0];
	return 0;
}