#include <iostream>
#include <vector>

#define ll long long
using namespace std;
//����콺 �Լ� ���.. �����п��� �������� ������ ���� �Լ���ϱ� ��~ �̷��� �ֱ��� �����θ� �˰�����.
ll mobius[1000003];
int n;
ll result(ll mid)
{
	ll cnt = 0;
	//����콺 �Լ��� �̿��� �հ� ���� ���ְ�
	for (ll i = 2; i * i <= mid; i++)
	{
		cnt += mobius[i] * (mid / (i * i));
	}
	return cnt;
}
//�̺�Ž������ �ð��� ���� ��µ� ���� ������ �������� �����غ���
//13 �Է�������, 19 20�� �Ѵ� ���� �����ؾ��� �Ʒ� �Լ�����
//�ٵ� ���ʿ� 20 21���� ���� ������ �ڿ� ������ ���� ���̰� ���ϱ� �� ����� �ƴϰ�
//19 20 ���� 20�� �������� ���� �Ȱ��� �� ������ ����°ǵ�. �̰� �ذ��ϴ°� �ᱹ �տ� �ִ� ������ ���� �ȴٴ°ž�.
//mid + aa >= n�� ���� ���ٴ� �ڵ�� �ᱹ mid+aa==n�� ������ start,mid�� ���°��� mid,last�� �ƴ�..
void two(ll start,ll last)
{
	ll mid = (start + last) / 2;
	ll aa = result(mid);
	if (last==start)
	{
		cout << start;
		return;
	}
	if (mid + aa < n)
		two(mid+1, last);
	else if (mid + aa >= n)
		two(start, mid);
}
//����콺 �Լ� ���ϴ� �Լ�
void Mo()
{
	mobius[1] = 1;
	for (int i = 1; i <= 1000000; i++)
	{
		if (mobius[i] == 0) continue;
		for (int j = 2 * i; j <= 1000000; j += i)
		{
			mobius[j] -= mobius[i];
		}
	}
}
int main()
{
	cin >> n;
	Mo();
	two(0,2000000000);
	return 0;
}