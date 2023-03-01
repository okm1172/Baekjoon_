#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> vec;
vector<int> vec2;
vector<pair<int, int>> vec3;
queue<int> checknot;
int checksize[300000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vec = vector<vector<int>>(300000);
	vec3.push_back({ 0,0 });
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		vec3.push_back({ a,b });
		vec[a].push_back(i), vec[b].push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		checksize[i] = vec[i].size();
		if (vec[i].size() <= 1)
			checknot.push(i);
	}
	int cnt = 0;
	while (!checknot.empty())
	{
		int a1 = checknot.front();
		checknot.pop();
		checksize[vec3[a1].first]--, checksize[vec3[a1].second]--;
		if (checksize[vec3[a1].first] == 1)
		{
			checknot.push(vec3[a1].first);
		}
		if (checksize[vec3[a1].second] == 1)
		{
			checknot.push(vec3[a1].second);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (checksize[i] <= 1)
			continue;
		cnt++;
		vec2.push_back(i);
	}
	cout << cnt << "\n";
	for (int i : vec2)
		cout << i << " ";
	return 0;
}