#include <iostream>
#define ll long long
using namespace std;

ll n, q;
ll data_[200000];
ll seg[400000];

ll seg_(int start, int last, int i)
{
	if (start == last)
		return seg[i] = data_[start];
	if (start + 1 == last)
	{
		seg[i * 2] = data_[start];
		seg[i * 2 + 1] = data_[last];
		return seg[i] = data_[start] + data_[last];
	}
	ll mid = (start + last) / 2;
	return seg[i] = seg_(start, mid, i * 2) + seg_(mid + 1, last, i * 2 + 1);
}
ll seg_2(int start, int last, int i, int s, int l)
{
	if (last<s || start > l)
		return 0;
	if (start == last)
		return seg[i];
	if (start >= s && last <= l)
		return seg[i];
	ll mid = (start + last) / 2;
	return seg_2(start, mid, i * 2, s, l) + seg_2(mid + 1, last, i * 2 + 1, s, l);
}
ll seg_3(int start, int last, int i, int a)
{
	if (start > a || last < a)
		return seg[i];
	if (start == last)
	{
		return seg[i] = data_[start];
	}
	ll mid = (start + last) / 2;
	return seg[i] = seg_3(start, mid, i * 2, a) + seg_3(mid + 1, last, i * 2 + 1, a);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> data_[i];
	}
	seg_(1, n, 1);
	for (int i = 1; i <= q; i++)
	{
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y)
		{
			int temp = x;
			x = y;
			y = temp;
		}
		cout << seg_2(1, n, 1, x, y)<<"\n";
		data_[a] = b;
		seg_3(1, n, 1, a);
	}
	return 0;
}