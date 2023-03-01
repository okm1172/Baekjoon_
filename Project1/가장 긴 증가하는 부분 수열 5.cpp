#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int resultcnt, result[1000004];
int re[1000004];
int index[1000004];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cin >> result[1];
	re[1] = result[1];
	index[1] = 1;
	resultcnt = 1;
	for (int i = 2; i <= n; i++)
	{
		int data_;
		cin >> data_;
		re[i] = data_;
		if (result[resultcnt] < data_)
		{
			resultcnt++;
			result[resultcnt] = data_;
			index[i] = resultcnt;
		}
		else
		{
			int aa = lower_bound(result + 1, result + resultcnt + 1, data_) - result;
			result[aa] = data_;
			index[i] = aa;
		}
	}
	cout << resultcnt << "\n";
	int count = resultcnt;
	vector<int> c;
	for (int i = n; i >= 1; i--)
	{
		if (count == 0) break;
		if (index[i] == count)
		{
			c.push_back(re[i]);
			count--;
		}
	}
	for (int i = c.size() - 1; i >= 0; i--)
		cout << c[i] << " ";
	return 0;
}