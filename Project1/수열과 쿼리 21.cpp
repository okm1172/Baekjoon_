#include <iostream>
#define ll long long

using namespace std;
ll n, m, k;
ll data_[10000000], data_sum[10000000], lazy[10000000];
ll result_sum;
ll sum_(int start, int last, int i)
{
	if (start == last)
	{
		return data_sum[i] = data_[start];
	}
	int mid = (start + last) / 2;
	return data_sum[i] = sum_(start, mid, i * 2) + sum_(mid + 1, last, i * 2 + 1);
}
void propa(int start, int last, int i)
{
	if (lazy[i] == 0)
		return;
	data_sum[i] += lazy[i] * (last - start + 1);
	if (start != last)
	{
		lazy[i * 2] += lazy[i];
		lazy[i * 2 + 1] += lazy[i];
	}
	lazy[i] = 0;
	return;
}
void sum__(int start, int last, int i, int x, int y, ll k)
{
	propa(start, last, i);
	if (y<start || x>last)
		return;
	if (start >= x && last <= y)
	{
		lazy[i] += k;
		propa(start, last, i);
		return;
	}
	int mid = (start + last) / 2;
	sum__(start, mid, i * 2, x, y, k);
	sum__(mid + 1, last, i * 2 + 1, x, y, k);
	data_sum[i] = data_sum[i * 2] + data_sum[i * 2 + 1];
}
void result(int start, int last, int i, int x, int y)
{
	propa(start, last, i);
	if (start > y || last < x)
		return;
	if (start >= x && last <= y)
	{
		result_sum += data_sum[i];
		return;
	}
	int mid = (start + last) / 2;
	result(start, mid, i * 2, x, y);
	result(mid + 1, last, i * 2 + 1, x, y);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> data_[i];
	}
	sum_(1, n, 1);
	cin >> m;
	for (int qq = 1; qq <= m; qq++)
	{
		ll a, b, c, d;
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c >> d;
			if (b > c)
			{
				ll temp = b;
				b = c;
				c = temp;
			}
			sum__(1, n, 1, b, c, d);
		}
		else if (a == 2)
		{
			cin >> b;
			result(1, n, 1, b, b);
			cout << result_sum << "\n";
			result_sum = 0;
		}
	}
	return 0;
}