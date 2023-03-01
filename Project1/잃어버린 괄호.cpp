#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	string input;
	queue<int> num;
	queue<char> ope;
	cin >> input;
	int input2=0;
	int result = 0;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '+' || input[i] == '-')
		{
			num.push(input2);
			ope.push(input[i]);
			input2 = 0;
			continue;
		}
		if (input[i] >= '0' && input[i] <= '9')
		{
			input2 *= 10;
			input2 += input[i]-'0';
		}
	}
	num.push(input2);
	result = num.front();
	num.pop();
	while (!num.empty())
	{
		if (ope.front() == '-')
		{
			result -= num.front();
			num.pop();
			ope.pop();
			if (ope.empty())
				break;
			if (ope.front() == '+')
			{
				while (ope.front() == '+')
				{
					result -= num.front();
					num.pop();
					ope.pop();
					if (ope.empty())
						break;
				}
			}
			continue;
		}
		result += num.front();
		num.pop();
		ope.pop();
	}
	cout << result;
	return 0;
}