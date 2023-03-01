#include <iostream>
#include <string>
#include <queue>
//queue뒤엔 무조건 자료형을 붙혀줘야한다.
//kmp라는데 실패함수 이용해서 푸는거래요? O(N*M)최악의 경우
//라빈카프도 있는데 이건 해시값 가지고 푸는거네요..이게 가장 현실성 있을듯 O(n) 근데? 2제곱으로 계속 곱해지기 때문에 이것도 이 문제 해결엔 적합하지 않아 보인다.
//굉장히 어려워 보이네요..뭘 해야할까..?
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