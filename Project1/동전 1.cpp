#include <iostream>
#include <algorithm>
//DP��¥ ��ƴ� �ƴ� �̰� ���� �ȿ�..
//�������ΰŶ� ������ ��¥�� �׳� �𸣰���..
//DP���� ��¥ ���� �ؾ��Ұ� ����.
//DP��ŭ ���� �����°� ����. ���α׷��ֿ���.
using namespace std;
int n, k;
int data_[10004];
int A[10004];
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin>>data_[i];
	sort(data_ + 1, data_ + 1 + n);
	A[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j >= data_[i])
			{
				A[j] += A[j - data_[i]];
			}
		}
	}
	cout << A[k];
	return 0;
}