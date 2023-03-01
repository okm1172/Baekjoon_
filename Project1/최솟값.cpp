#include <iostream>

using namespace std;

int aa[10000000];
int bb[10000000];
int input_[200000];
int result_ = 0;
int max_1 = -999;
int min_1 = 2147483644;
int cnt = 0;
int min(int start, int last, int i)
{
	cnt++;
	if (start == last)
	{
		aa[i] = input_[start];
		return input_[start];
	}
	if (start + 1 == last)
	{
		aa[i * 2] = input_[start];
		aa[i * 2 + 1] = input_[last];
		return aa[i] = (aa[i * 2] < aa[i * 2 + 1] ? aa[i * 2] : aa[i * 2 + 1]);
	}
	int mid = (start + last) / 2;
	return aa[i] = (min(start, mid, i * 2) > min(mid + 1, last, i * 2 + 1) ? min(mid + 1, last, i * 2 + 1) : min(start, mid, i * 2));
}
int max(int start, int last, int i)
{
	if (start == last)
	{
		bb[i] = input_[start];
		return input_[start];
	}
	if (start + 1 == last)
	{
		bb[i * 2] = input_[start];
		bb[i * 2 + 1] = input_[last];
		return bb[i] = (bb[i * 2] > bb[i * 2 + 1] ? bb[i * 2] : bb[i * 2 + 1]);
	}
	int mid = (start + last) / 2;
	return bb[i] = (max(start, mid, i * 2) > max(mid + 1, last, i * 2 + 1) ? max(start, mid, i * 2) : max(mid + 1, last, i * 2 + 1));
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
		if (max_1 < bb[i])
			max_1 = bb[i];
		if (min_1 > aa[i])
			min_1 = aa[i];
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
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> input_[i];
	}
	min(1, n, 1);
	max(1, n, 1);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		result(1, n, 1, x, y);
		cout << min_1<<"\n";
		min_1 = 2147483644;
	}
	return 0;
}