#include <iostream>
//�� �ڵ忡�� b==1 �϶� ���� �� b���ٰ� 1�� ��������� ������ ����?
//����..check�� �ƿ� �ȵ��ư���..
//�� ������ ���̵��� "�������� ����θ� �����ʰ� �����ε� �����ִ�." �Դϴ�
//��? �ƴ� �ù� 2^31 ������ long long �ְ��� �۾ƿ�.. �ƴ�,,�׷� �� ����� �����ݾƿ� ��
using namespace std;

int main()
{
	long long a, b, c;
	int check[300];
	cin >> a >> b >> c;
	if (b == 1)
	{
		cout << a % c;
		return 0;
	}
	long long aa = 0,bb=0;
	if (c < a * 2) a = a - c;
	aa = a;
	bb = b;
	int checkcnt = 1;
	//1�� ���� 2�� �ѹ� ���ϴ°�
	while (1)
	{
		if (bb % 2 == 0)
		{
			bb /= 2;
			check[checkcnt] = 1;
		}
		else
		{
			bb--;
			check[checkcnt] = 2;
			checkcnt++;
			bb /= 2;
			check[checkcnt] = 1;
		}
		if (bb == 1)
			break;
		checkcnt++;
	}
	bb = b;
	b = 1;
	while (1)
	{
		if (c < a * 2) a = a - c;
		if (check[checkcnt] == 1)
		{
			a = a * a % c;
			b *= 2;
		}
		else if (check[checkcnt] == 2)
		{
			b++;
			a = a * aa;
			a %= c;
		}
		checkcnt--;
		if (b == bb)
			break;
	}
	if (a<0)
		a = c+a;
	cout << a % c;
	return 0;
}