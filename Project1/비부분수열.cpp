/*#include <iostream>
#include <vector>
//생각 로직 자체가 틀렸습니다.. 그리디를 다시 생각해봅시다. 그리디..그리디...
using namespace std;

vector<vector<int>> vec;
int n, k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	vec = vector<vector<int>>(k + 2);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		vec[x].push_back(i);
	}
	//빈곳 있나 체크
	int sizemin = 2147483646;
	for (int i = 1; i <= k; i++)
	{
		if (sizemin > vec[i].size())
			sizemin = vec[i].size();
		if (vec[i].size() == 0)
		{
			cout << 1;
			return 0;
		}
	}
	int min = 2147483646;
	for (int i = 1; i <= k; i++)
	{
		if (min > vec[i][vec[i].size() - 1])
			min = vec[i][vec[i].size() - 1];
	}
	int min2 = 2147483646;
	for (int i = 1; i <= k; i++)
	{
		for (int j=0;j<vec[i].size()-1;j++)
		{
			if (vec[i][j] > min)
				if (min2 > j)
					min2 = j + 1;
		}
	}
	if (min2 + 1 < sizemin + 1)
		cout << min2 + 1;
	else
		cout << sizemin + 1;
	return 0;
}*/

#include <iostream>

using namespace std;
int n, m;
int check[100003];
int result = 0;
int main()
{
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (check[x] == 0) check[x] = 1, cnt++;
		if (cnt == m) result++, fill(check, check + m + 1, 0),cnt=0;
	}
	cout << result+1;
	return 0;
}