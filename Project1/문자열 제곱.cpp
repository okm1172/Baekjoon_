#include <iostream>
#include <string>
//�̰� �̷� �ʹ� ��ƴ�.
//�����ϴµ� 4�ð� �ɷȾ� �̰� ��¥ �ѹ��� ��������.
//���̻� ���� ���λ�� ���ذ��� ������
//while ���� �ǹ̴� ababa ���������� aba�� ã����..
//https://m.blog.naver.com/kks227/220917078260 ���� ��
using namespace std;
string dat;
string datt;
int fail[1000003];
int main()
{
	while (1)
	{
		fail[0] = 0;
		cin >> dat;
		datt = dat + dat;
		int max = -999;
		if (dat == ".")
			break;
		//�����Լ�
		int j = 0;
		for (int i = 1; i < dat.length(); i++)
		{
			while (dat[i] != dat[j] && j > 0)
			{
				fail[i] = 0;
				j = fail[j - 1];
			}
			if (dat[i] == dat[j])
			{
				j++;
				fail[i] = j;
			}
		}

		/*for (int i = 0; i < dat.length(); i++)
		{
			cout << fail[i];
		}
		cout << endl;*/
		j = 0;
		int check = 0;
		//datt �� dat + dat
		for (int i = 1; i < datt.length(); i++)
		{	
			while (j > 0 && dat[j] != datt[i])
				j = fail[j - 1];
			if (dat[j] == datt[i])
				if (j == dat.length() - 1)
				{
					check = i - j;
					if (check >= dat.length())
					{
						cout << "1";
					}
					//i-j�� ó�� ��� ã�ҳ�?
					else
					cout << dat.length() / (i - j);
					break;
				}
				else
					j++;
		}
		cout << endl;
	}
	return 0;
}