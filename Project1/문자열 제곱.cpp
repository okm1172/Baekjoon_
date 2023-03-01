#include <iostream>
#include <string>
//이거 이론 너무 어렵다.
//이해하는데 4시간 걸렸어 이거 진짜 한번더 복습하자.
//접미사 값을 접두사로 내팽개쳐 버리는
//while 문의 의미는 ababa 같은곳에서 aba를 찾을때..
//https://m.blog.naver.com/kks227/220917078260 설명 굳
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
		//실패함수
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
		//datt 은 dat + dat
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
					//i-j는 처음 어디서 찾았냐?
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