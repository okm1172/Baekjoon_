#include <iostream>

using namespace std;

//((, () ��ȣ���ڿ� �迭 ���� �����ϰ�
//Ȧ���� �׳� ���
//((���� ���� )) ���־���ϱ⿡ ��ȣ���ڿ� [i-4]
//()���� �ڿ� ��ȣ���ڿ� [i-2]
//÷�� ������ ����� �ƴϳ׿�..�̰� ���߿� õõ�� �����غ����Ұ� ���׿�..
long long ss(int n)
{
	int cnt = n;
	int a = 1;
	while (cnt != 0)
	{
		a *= 2;
		cnt--;
	}
	return a;
}
int main()
{
	int n;
	long long m;
	cin >> n >> m;
	long long n_2[56];
	int char1[56], char2[56], char3[56];
	int output[56] = { 0 };
	n_2[0] = 1;
	n_2[1] = 2;
	for (int i = 2; i <= 48; i++)
	{
		n_2[i] = n_2[i - 1] * 2;
	}
	long long aa = 0;
	if (n % 2 == 1)
	{
		aa = ss(n - 1);
		if (aa*2 <= m)
		{
			cout << "-1";
			return 0;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			aa = ss(i);
			if (m >= aa)
			{
				output[i] = 2;
				m -= aa;
				continue;
			}
			output[i] = 1;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (output[i] == 1)
				cout << "(";
			else
				cout << ")";
		}
		return 0;
	}
	char2[0] = 0;
	char1[0] = 0;
	char2[2] = 1;
	char1[2] = 0;
	char1[4] = 1;
	char2[4] = 1;
	char3[0] = 0;
	char3[2] = 1;
	char3[4] = 2;
	if (n == 2)
	{
		if (m == 0)
			cout << "((";
		else if (m == 1)
			cout << ")(";
		else if (m == 2)
			cout << "))";
		else
			cout << "-1";
		return 0;
	}
	for (int i = 6; i <= n; i = i + 2)
	{
		char1[i] = char3[i - 4];
		char2[i] = char3[i - 2];
		char3[i] = char1[i] + char2[i];
	}
	/*for (int i = 0; i <= n; i = i + 2)
	{
		cout << char1[i] << " " << char2[i] << " " << char3[i] << endl;
	}*/
	//1�� ���� ��ȣ (
	//2�� �ݴ� ��ȣ )
	//char 3 �� n�� ��� ��ȣ ���ڿ� ����
	//char 1 �� (( ���� �ϴ� n ������ ��ȣ ���ڿ�
	//char 2 �� () ���� �ϴ� n ������ ��ȣ ���ڿ�
	m++;
	int acheck = 0, bcheck = 0, ccheck = 0, dcheck = 0;
	int last = n;
	//n=8 m=0 0 1 2 3 4  5  6  7   8
	//n_2   = 1 2 4 8 16 32 64 128 256
	//char1 = 0   0   1     1      2
	//char2 = 0   1   1     2      3
	//char3 = 0   1   2     3      5
	n += 2;
	//1 (( 2 () 3 )( 4 ))
	for (int i = 0; i < last/2; i++)
	{
		n -= 2;
		if (n == 2)
		{
			//(())
			if (acheck == dcheck&&ccheck==0)
			{
				if (m == 1)
				{
					output[i * 2] = 1;
					output[i * 2 + 1] = 1;
				}
				else if (m == 2)
				{
					output[i * 2] = 2;
					output[i * 2 + 1] = 1;
				}
				else if (m == 3)
				{
					output[i * 2] = 2;
					output[i * 2 + 1] = 2;
				}
				break;
			}
			else if (acheck == dcheck && ccheck != 0)
			{
				if (m == 1)
				{
					output[i * 2] = 1;
					output[i * 2 + 1] = 1;
				}
				else if (m == 2)
				{
					output[i * 2] = 1;
					output[i * 2 + 1] = 2;
				}
				else if (m == 3)
				{
					output[i * 2] = 2;
					output[i * 2 + 1] = 1;
				}
				else if (m == 4)
				{
					output[i * 2] = 2;
					output[i * 2 + 1] = 2;
				}
				break;
			}
			//()()
			else if (acheck == ccheck&&ccheck == dcheck && acheck==dcheck && acheck == 0)
			{
				if (m == 1)
				{
					output[i * 2] = 1;
					output[i * 2 + 1] = 1;
				}
				else if (m == 2)
				{
					output[i * 2] = 2;
					output[i * 2 + 1] = 1;
				}
				else if (m == 3)
				{
					output[i * 2] = 2;
					output[i * 2 + 1] = 2;
				}
				break;
			}
			else
			{
				if (m == 1)
				{
					output[i * 2] = 1;
					output[i * 2 + 1] = 1;
				}
				else if (m == 2)
				{
					output[i * 2] = 1;
					output[i * 2 + 1] = 2;
				}
				else if (m == 3)
				{
					output[i * 2] = 2;
					output[i * 2 + 1] = 1;
				}
				else if (m == 4)
				{
					output[i * 2] = 2;
					output[i * 2 + 1] = 2;
				}
				break;
			}
			cout << "-1";
			return 0;
		}
		if (n_2[n-2] - char1[n] < m)
		{
			m -= n_2[n - 2] - char1[n];
		}
		else
		{
			acheck++;
			output[i * 2] = 1;
			output[i * 2 +1 ] = 1;
			continue;
		}
		//
		if (n_2[n - 2] - char2[n] < m)
		{
			m -= n_2[n - 2] - char2[n];
		}
		else
		{
			bcheck++;
			output[i * 2] = 1;
			output[i * 2+1] = 2;
			continue;
		}
		//
		if (n_2[n - 2] < m)
		{
			m -= n_2[n - 2];
		}
		else
		{
			output[i * 2] = 2;
			output[i * 2+1] = 1;
			continue;
		}
		//
		if (n_2[n - 2] < m)
		{
			cout << "-1";
			return 0;
		}
		else
		{
			dcheck++;
			output[i * 2] = 2;
			output[i * 2+1] = 2;
			continue;
		}
	}
	for (int i = 0; i < last; i++)
	{
		if (output[i] == 1)
			cout << "(";
		else
			cout << ")";
	}
	return 0;
}