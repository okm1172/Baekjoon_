
//�̰� ���� �ִ밪 �ϴ°Ŷ� �Ȱ��� ������ �̰� �ִ뿡 ����Ʈ�� �ɷ��ֱ⿡ 3���� ���ָ� �ȴٴ°̴ϴ�..�Ͼƴ�..
/*int check[100004] = {0};
int pcheck[100004] = { 0 };
int dp[100004] = { 0 };
int main()
{
	int n;
	int i;
	int x;
	check[0] = 0;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> x >> pcheck[i];
		if (i == 1)
		{
			dp[i] = pcheck[i];
			continue;
		}
		//�ƿ� �����°� üũ
		if (check[i - 1] == 2)
		{
			if (x >= dp[i - 2])
			{
				dp[i] = pcheck[i] + dp[i - 2];
				check[i] = 1;
			}
			else
			{
				check[0] = 99;
				break;
			}
			continue;
		}
		//������
		if (x >= dp[i-1])
		{
			dp[i] = dp[i - 1] + pcheck[i];
			check[i] = check[i - 1];
		}
		else if (x < dp[i - 1])
		{
			//�ι� �������
			if (x < dp[i - 1] && x >= dp[i - 2])
			{
				check[i] = 1;
				dp[i] = pcheck[i - 2] + dp[i];
			}
			//�ƿ� �����°� Ȯ��
			else if (x < dp[i - 1] && x < dp[i - 3] + pcheck[i - 1])
			{
				if (check[i - 1] == 1)
				{
					check[0] = 99;
					break;
				}
				check[i] = 2;
			}
			//�ƿ� �����°� �ƴϰ� �ǳʶٱ� �Ҽ� �ִ�ģ��
			if (x < dp[i - 1] && x >= dp[i-3] + pcheck[i - 1])
			{
				pcheck[i] = pcheck[i-1] + dp[i-3];
				if (check[i - 1] == 1)
				{
					check[0] = 99;
					break;
				}
				check[i] = 1;
			}
		}
	}
	if (check[0] == 99)
		cout << "Zzz";
	else
		cout << "Kkeo-eok";
	return 0;
}
//�ڵ� �����ϰ� �Ϸ��� �ߴµ� �ȵǳ׿�..ü���ϰ� �ؼ���� ���� ���ڽ��ϴ�.
#include <iostream>

using namespace std;
int main()
{
	long long int n, x;
	int p[100002];
	int i;
	long long int sum = 0;
	int check = 0;
	long long int max = -999;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> x >> p[i];
		if (sum > x)
		{
			//max���� ���� �ٷ� ����
			if (check == 2)
			{
				sum -= p[i - 1];
				sum += max;
				if (sum > x)
				{
					cout << "Zzz";
					return 0;
				}
				sum += p[i];
				check = 1;
				continue;
			}
			//�ι� ����
			if (check == 1)
			{
				cout << "Zzz";
				return 0;
			}
			if (check == 0)
			{
				sum = sum - max;
				check = 2;
				if (sum > x)
				{
					cout << "Zzz";
					return 0;
				}
				if (sum <= x)
				{
					sum += p[i];
				}
				continue;
			}
		}
		if (check == 2)
			check = 1;
		if (i >= n - 1 && check == 0)
		{
			cout << "Kkeo-eok";
			return 0;
		}
		if (sum <= x)
		{
			sum += p[i];
		}
		if (max < p[i] && check==0)
			max = p[i];
	}
	cout << "Kkeo-eok";
	return 0;
}*/
//�ƴ�,,�ѹ��� ����� �� �ƴ��� �ʳ���
//���� ���� �ڵ� �Ʊ����ѵ� ��¿������..
#include <iostream>

using namespace std;

int n;
int x[100002], p[100002];
int max = -999;
int maxi = 0;
int case1()
{
	long long int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (sum > x[i])
			return i;
		if (sum <= x[i])
			sum += p[i];
		if (::max < p[i])
		{
			maxi = i;
			::max = p[i];
		}
	}
	return true;
}
bool case2(int ii)
{
	long long int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == ii)
			continue;
		if (sum > x[i])
			return false;
		if (sum <= x[i])
			sum += p[i];
	}
	return true;
}
bool case3()
{
	long long int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == maxi)
			continue;
		if (sum > x[i])
			return false;
		if (sum <= x[i])
			sum += p[i];
	}
	return true;
}
int main()
{
	cin >> n;
	int first = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> p[i];
	}
	first = case1();
	if (first == 0)
	{
		cout << "Kkeo-eok";
		return 0;
	}
	if(case2(first))
	{
		cout << "Kkeo-eok";
		return 0;
	}
	if (case3())
	{
		cout << "Kkeo-eok";
		return 0;
	}
	cout << "Zzz";
	return 0;
}