#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int rightdp[10003];
	int leftdp[10003];
	int input[10003];
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		rightdp[i] = 0, leftdp[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <=i; j++)
		{
			if (input[i] > input[j] && rightdp[j] + 1 > rightdp[i])
			{
				rightdp[i] = rightdp[j] + 1;
			}
		}
	}
	return 0;
}