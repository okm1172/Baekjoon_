#include <iostream>
#include <stack>
#include <string>
//역시 1~2시간정도에 풀리는 문제가 젤 재밌어.
//??아니 이거 개간단한 문제였네? 아니 난..하하..
//왜 이렇게 돌아가면서 푼거지...
//이 코드는..맞은 비교 string 변수의 개수를 앞에서부터 스택에 넣어가면서 찾아가는겁니다..
//그냥 흑우입니다.
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
	//길이 1인거 따로 처리
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
				//만약 안맞으면 다 출력
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
		//첫 경우 찾아버리기.
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