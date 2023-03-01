#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> que;
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int qq;
		cin >> qq;
		if (qq == 0)
		{
			if (que.empty())
			{
				cout << 0 << "\n";
				continue;
			}
			cout << que.top() * -1<<"\n";
			que.pop();
			continue;
		}
		que.push(qq * -1);
	}
	return 0;
}