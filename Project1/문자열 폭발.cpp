#include <iostream>
#include <stack>
#include <string>
//���� 1~2�ð������� Ǯ���� ������ �� ��վ�.
//??�ƴ� �̰� �������� ��������? �ƴ� ��..����..
//�� �̷��� ���ư��鼭 Ǭ����...
//�� �ڵ��..���� �� string ������ ������ �տ������� ���ÿ� �־�鼭 ã�ư��°̴ϴ�..
//�׳� ����Դϴ�.
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<int> result;
	string input;
	cin >> input;
	string input2;
	cin >> input2;
	stack<int> aa;
	int cnt2 = 0;
	//���� 1�ΰ� ���� ó��
	if (input2.length() == 1)
	{
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == input2[0])
				continue;
			cnt2++;
			cout << input[i];
		}
		if (cnt2 == 0)
			cout << "FRULA";
		return 0;
	}
	//abcaabcbb
	//abc
	for (int i = 0; i < input.length(); i++)
	{
		if (!aa.empty())
		{
			if (input[i] == input2[0])
			{
				int cnt = 0;
				for (int j = 1; j < input2.length(); j++)
				{
					i++;
					cnt++;
					if (input[i] != input2[j])
					{
						i--;
						cnt--;
						break;
					}
				}
				if (cnt != input2.length() - 1)
					aa.push(cnt);
			}
			//aabbababaaaa

			else if (input[i] == input2[aa.top()+1])
			{
				int cnt = aa.top()+1;
				for (int j = aa.top()+2; j < input2.length(); j++)
				{
					i++;
					cnt++;
					if (input[i] != input2[j])
					{
						i--;
						cnt--;
						break;
					}
				}
				if (cnt != input2.length() - 1)
				{
					aa.pop();
					aa.push(cnt);
				}
				else
					aa.pop();
			}
			else
			{
				//���� �ȸ����� �� ���
				while (!aa.empty())
				{
					result.push(aa.top());
					aa.pop();
				}
				while (!result.empty())
				{
					for (int j = 0; j <=result.top(); j++)
					{
						cnt2++;
						cout << input2[j];
					}
					result.pop();
				}
				cnt2++;
				cout << input[i];
			}
			continue;
		}
		//ù ��� ã�ƹ�����.
		if (input[i] == input2[0])
		{
			int cnt = 0;
			for (int j = 1; j < input2.length(); j++)
			{
				i++;
				cnt++;
				if (input[i] != input2[j])
				{
					i--;
					cnt--;
					break;
				}
			}
			if (cnt != input2.length()-1)
				aa.push(cnt);
		}
		else
		{
			cnt2++;
			cout << input[i];
		}
	}
	if (!aa.empty())
	{
		while (!aa.empty())
		{
			result.push(aa.top());
			aa.pop();
		}
		while (!result.empty())
		{
			for (int j = 0; j <= result.top(); j++)
			{
				cnt2++;
				cout << input2[j];
			}
			result.pop();
		}
	}
	if (cnt2 == 0)
	{
		cout << "FRULA";
	}
	return 0;
}