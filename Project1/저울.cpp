#include <iostream>
#include <algorithm>
//�ƴ� �̰� �ʵ�� 3�� �¾�? ��¥ ������ �̰� �׸�����? dp�� �ƿ� �ٸ���
//�̰� ���̵�� �Ƕ��� ���ε� �̰� KOI �̿����� ���� ������ ��,,

using namespace std;

int main()
{
	int n;
	int data[10003];
	int sum = 0;
	int max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
		max+= data[i];
	}
	sort(data, data + n);
	data[n] = max + 2;
	if (data[0] != 1)
	{
		cout << "1";
		return 0;
	}
	sum = data[0];
	for (int i =1;i<=n;i++)
	{
		if (sum + 1 < data[i])
		{
			cout << sum + 1;
			return 0;
		}
		sum += data[i];
	}
	return 0;
}