#include <iostream>
//펜윅 트리로도 풀린다고 하는데
//저는 레이지 세그먼트로 풀었습니다.. 레이지에 양 끝 등차 수열 값을 주정해두고 계속 더해가는 재밌는 문제.

#define ll long long
using namespace std;

ll data_[2000000];
ll data_sum[2000000];
ll lazy[2000000][4];
int n;
int q;
ll result_;

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
	if (lazy[i][1] == 0 && lazy[i][2] == 0)
		return;
	data_sum[i] += (lazy[i][2]+lazy[i][1]) * (last - start + 1) / 2;
	if (start != last)
	{
		int cc = last - start;
		int differ = (lazy[i][2] - lazy[i][1]) / (last - start);
		lazy[i * 2][1]+= lazy[i][1];
		lazy[i * 2][2]+= lazy[i][1] + (cc/2)*differ;
		lazy[i * 2 + 1][1] += lazy[i][1] + (cc / 2 + 1) * differ;
		lazy[i * 2 + 1][2]+= lazy[i][2];
	}
	lazy[i][1] = 0, lazy[i][2] = 0;
	return;
}
void sum_1(int start, int last, int i, int x, int y,int diff)
{
	propa(start, last, i);
	if (start > y || last < x)
		return;
	if (start >= x && last <= y)
	{
		//diff = 차이
		lazy[i][1] = start - diff;
		lazy[i][2] = last - diff;
		propa(start, last, i);
		return;
	}
	int mid = (start + last) / 2;
	sum_1(start, mid, i * 2, x, y,diff);
	sum_1(mid + 1, last, i * 2 + 1, x, y,diff);
	data_sum[i] = data_sum[i * 2] + data_sum[i * 2 + 1];
}
void result(int start, int last, int i, int k)
{
	propa(start, last, i);
	if (start > k || last < k)
		return;
	if(start == last && last==k)
	{
		result_ = data_sum[i];
		return;
	}
	int mid = (start + last) / 2;
	result(start, mid, i * 2, k);
	result(mid + 1, last, i * 2 + 1, k);
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
	cin >> q;
	for (int qq = 1; qq <= q; qq++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			int b, c;
			cin >> b >> c;
			if (b > c)
			{
				int tmp = b;
				b = c;
				c = tmp;
			}
			sum_1(1, n, 1, b, c,b-1);
		}
		else if (a == 2)
		{
			int b;
			cin >> b;
			result(1, n, 1, b);
			cout << result_ << "\n";
		}
	}
	return 0;
}