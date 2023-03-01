#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
//왜틀린거? 야무지게 짠거 같은데
int prime[2002];
int N;
int cnt = 0;
vector<vector<int>> match(52);
vector<int> ssort;
int input[52], check[52],data1[52];
int resultcheck[2003], check2 = 0;
int zerocheck[53];

void prime_()
{
	prime[1] = 0;
	for (int i = 2; i <= sqrt(2000); i++)
	{
		if (prime[i] == 0)
			continue;
		for (int j = 2; j<= 2000/i; j++)
		{
			prime[j*i] = 0;
		}
	}
}
void ma(int from)
{
	for (int i = 0; i < match[from].size(); i++)
	{
		if (check2 == 1)
		{
			if (from == 0)
				check2 = 0;
			else
				break;	
		}
		if (check[match[from][i]] == 0)
		{
			check[match[from][i]] = 1;
			check[from] = 1;
			data1[match[from][i]] = from;
			data1[from] = match[from][i];
			for (int j = 0; j < N; j++)
			{
				if (zerocheck[j] == 1)
					continue;
				if (check[j] == 0)
				{
					ma(j);
					check[match[from][i]] = 0;
					check[from] = 0;
					data1[match[from][i]] = 0;
					data1[from] = 0;
					break;
				}
				if (j == N - 1)
				{
					if (check[N - 1] == 1)
					{
						cnt = 1;
						check2 = 1;
						if(resultcheck[input[data1[0]]]==0)
							ssort.push_back(input[data1[0]]), resultcheck[input[data1[0]]] = 1;
					}
					check[match[from][i]] = 0;
					check[from] = 0;
					data1[match[from][i]] = 0;
					data1[from] = 0;
					return;
				}
			}
		}
	}
	return;
}
int main()
{
	memset(prime, -1, sizeof(prime));
	cin >> N;
	prime_();
	for (int i = 0; i < N; i++)
		cin >> input[i];
	for (int i = 0; i < N-1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (prime[input[i] + input[j]] == -1)
				match[i].push_back(j);
		}
		if (match[i].size() == 0)
			zerocheck[i] = 1;
	}
	ma(0);
	if (cnt == 0)
		cout << "-1";
	else
	{
		sort(ssort.begin(), ssort.end());
		for (int i : ssort)
		{
			cout << i << " ";
		}
	}
	return 0;
}