#include <iostream>
#include <string>
#include <queue>
//queue�ڿ� ������ �ڷ����� ��������Ѵ�.
//kmp��µ� �����Լ� �̿��ؼ� Ǫ�°ŷ���? O(N*M)�־��� ���
//���ī���� �ִµ� �̰� �ؽð� ������ Ǫ�°ų׿�..�̰� ���� ���Ǽ� ������ O(n) �ٵ�? 2�������� ��� �������� ������ �̰͵� �� ���� �ذΰ �������� �ʾ� ���δ�.
//������ ����� ���̳׿�..�� �ؾ��ұ�..?
using namespace std;

string dat1, dat2;
queue<int> whe;
int alp[30][1000003];
int main()
{
	cin >> dat1 >> dat2;
	for (int i = 0; i < dat1.length(); i++)
	{
		if (dat1[i] == dat2[0])
		{
			if( i+dat2.length() <= dat1.length())
			whe.push(i);
		}
		alp[dat1[i] - 'a'][i] = 1;
	}
	int check = 0;
	int start = 0;
	while (1)
	{
		start = whe.front();
		for (int i = 0; i < dat2.length(); i++)
		{
			if (alp[dat2[i] - 'a'][start + i] == 0)
			{
				whe.pop();
				if (whe.empty())
				{
					cout << "0";
					return 0;
				}
				break;
			}
			if (i == dat2.length() - 1)
				check = 1;
		}
		if (check == 1)
			break;
	}
	cout << "1";
	return 0;
}