#include <iostream>
#include <stack>

using namespace std;

int n;
stack<pair<int,pair<int,int>>> sta;
int wh[5000002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int qq;
	cin >> qq;
	wh[qq] = 1;
	sta.push({ qq,{qq,qq} });
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		int nowstart = x, nowlast = x;
		wh[x] = i;
		while (1)
		{
			if (sta.empty())
			{
				sta.push({ x,{nowstart,nowlast} });
				break;
			}
			if (sta.top().second.second + 1 == nowstart)
			{
				nowstart = sta.top().second.first;
				cout << wh[sta.top().first] << "\n";
				sta.pop();
				continue;
			}
			else if (sta.top().second.first - 1 == nowlast)
			{
				nowlast = sta.top().second.second;
				cout << wh[sta.top().first] << "\n";
				sta.pop();
				continue;
			}
			sta.push({ x,{nowstart,nowlast} });
			break;
		}
	}
	return 0;
}