#include <iostream>

using namespace std;

long long bb[800000][3];
long long input_[4000000];
long long a, b, c;
int max__ = -999;
int timecheck = 0;
int maxi = 0;
int aoter;
int max(int start, int last, int i)
{
	if (aoter== 1)
	{
		if (start > b || last < b)
			return bb[i][1];
	}
	if (start == last)
	{
		bb[i][1] = input_[start];
		bb[i][2] = start;
		return input_[start];
	}
	else if (start + 1 == last)
	{
		bb[i * 2][1] = input_[start];
		bb[i * 2][2] = start;
		bb[i * 2 + 1][1] = input_[last];
		bb[i * 2 + 1][2] = last;
		if (bb[i * 2][1] > bb[i * 2 + 1][1])
		{
			bb[i][1] = bb[i * 2][1];
			bb[i][2] = start;
		}
		else
		{
			bb[i][1] = bb[i * 2 + 1][1];
			bb[i][2] = last;
		}
		return bb[i][1];
	}
	int mid = (start + last) / 2;
	int a1 = max(start, mid, i * 2);
	int a2 = max(mid + 1, last, i * 2 + 1);
	if (a1 > a2)
	{
		bb[i][1] = bb[i * 2][1];
		bb[i][2] = bb[i * 2][2];
	}
	else
	{
		bb[i][1] = bb[i * 2 + 1][1];
		bb[i][2] = bb[i * 2 + 1][2];
	}
	return bb[i][1];
}
void result(int start, int last, int i, int x, int y)
{
	int mid = (start + last) / 2;
	if (start > y)
		return;
	if (last < x)
		return;
	if (start >= x && last <= y)
	{
		if (max__ < bb[i][1])
		{
			if(timecheck!=1)
				maxi = bb[i][2];
			max__ = bb[i][1];
		}
		return;
	}
	result(start, mid, i * 2, x, y);
	result(mid + 1, last, i * 2 + 1, x, y);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	int cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> input_[i];
	}
	max(1, n, 1);
	aoter = 1;
	cin >> m;
	for(int jj=1;jj<=m;jj++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			input_[b] = c;
			//세그먼트 트리 재구성
			max(1, n, 1);
		}
		else if (a == 2)
		{
			//result(탐색시작,탐색끝,인덱스,입력받은b,c)
			//구간내 최대값 구해줌.
			result(1, n, 1, b, c);
			timecheck = 1;
			int sum = 0;
			sum = max__;
			int max = -99999;
			max__=-999;
			result(1, n, 1, b, maxi-1);
			max = max__;
			max__=-999;
			result(1, n, 1, maxi + 1, c);
			if (max < max__)
				sum += max__;
			else
				sum += max;
			cout << sum << "\n";
			sum = 0;
			max__ = -9999;
			timecheck = 0;
		}
	}
	return 0;
}