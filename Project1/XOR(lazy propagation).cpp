#include <iostream>

using namespace std;

int n;
int m;
int data_[600000];
int data_2[10000000];
int result=0;
int lazy[10000000];
void propa(int start,int last,int i)
{
	if (lazy[i] == 0)
		return;
	if ((last - start + 1) % 2 == 1)
		data_2[i] ^= lazy[i];
	if (start != last)
	{
		lazy[i * 2] ^= lazy[i];
		lazy[i * 2 + 1] ^= lazy[i];
	}
	lazy[i] = 0;
	return;
}
int xor_(int start, int last, int i)
{
	int mid = (start + last) / 2;
	if (start == last)
	{
		data_2[i] = data_[start];
		return data_[start];
	}
	if (start + 1 == last)
	{
		data_2[i * 2] = data_[start];
		data_2[i * 2 + 1] = data_[last];
		return data_2[i] = data_2[i * 2] ^ data_2[i * 2 + 1];
	}
	return data_2[i] = xor_(start, mid, i * 2) ^ xor_(mid + 1, last, i * 2 + 1);
}
void xor_1(int start, int last, int i, int x, int y,int k)
{
	propa(start, last, i);
	int mid = (start + last) / 2;
	if (start > y || last < x)
		return;
	if (start >= x && last <= y)
	{
		lazy[i] ^= k;
		propa(start, last, i);
		return;
	}
	xor_1(start, mid, i * 2, x, y, k);
	xor_1(mid + 1, last, i * 2 + 1, x, y, k);
	data_2[i] = data_2[i * 2] ^ data_2[i * 2 + 1];
}
void xor_2(int start,int last,int i ,int x,int y)
{
	//필요한 값을 얻기 위해 lazy값을 싸그리 아래로 내려줌.
	int mid = (start + last) / 2;
	propa(start, last, i);
	if (start > y || last < x)
		return;
	if (start >= x && last <= y)
	{
		result = result ^ data_2[i];
		return;
	}
	xor_2(start, mid, i * 2, x, y);
	xor_2(mid + 1, last, i * 2 + 1, x, y);
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
	cin >> m;
	xor_(1, n, 1);
	for (int qq = 1; qq <= m; qq++)
	{
		int Aj;
		cin >> Aj;
		if (Aj == 1)
		{
			int i, j, k;
			cin >> i >> j >> k;
			xor_1(1, n, 1, i+1, j+1,k);
		}
		else if (Aj == 2)
		{
			int i, j;
			cin >> i >> j;
			xor_2(1, n, 1, i+1, j+1);
			cout << result << "\n";
			result = 0;
		}
	}
	return 0;
}