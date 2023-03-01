#include <iostream>

using namespace std;

int input[1000005];
int result[1000005];
int realresult[1000005];
int search(int left, int right,int intput)
{
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (result[mid] < intput)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return right;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		cin >> input[i];
	}
	result[1] = input[1];
	realresult[1] = input[1];
	int resultcnt = 1;
	int check = 0;
	for (int i = 2; i <=n; i++)
	{
		if (input[i] > result[resultcnt])
		{
			resultcnt++;
			result[resultcnt] = input[i];
			if (check == 1)
			{
				for (int j = 1; j <= resultcnt-1; j++)
				{
					if (realresult[j] != result[j])
					{
						realresult[resultcnt] = result[resultcnt];
						break;
					}
					if (j == resultcnt - 1)
					{
						for (int k = 1; k <= resultcnt; k++)
						{
							realresult[j] = result[k];
						}
					}
				}
				check = 0;
			}
			else
			{
				realresult[resultcnt] = result[resultcnt];
			}
		}
		else
		{
			int idx = search(1,resultcnt,input[i]);
			result[idx] = input[i];
			if (idx == resultcnt)
				check = 1;
		}
	}
	cout << resultcnt<<"\n";
	for (int i = 1; i <= resultcnt; i++)
	{
		cout << realresult[i] << " ";
	}
	return 0;
}