#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <map>
//���� ���� ���� ��ٷӽ��ϴ�..
//��� ���� in - out �� ������մϴ� ������ -> ����� , ����� -> ������ �Ѵ� out->in ó�� ������մϴ�.
//vector����..
//map���� ó�����ִ°� ���� �Ź��߽��ϴ�. map���ε� ������ �迭������ ���� �Ҽ� �ֽ��ϴ�..�����ϼ���
#define INF 2147483647
#define out 10000
using namespace std;

int n, m;
int data_[104][104];
vector<vector<int>> vec;
map<pair<int, int>, int> capacity,flow;
int label[20004];
int work[20004];
int start_, end_;

bool bfs()
{
	memset(label, 0, sizeof label);
	label[start_+10000] = 1;
	queue<int> que;
	que.push(start_+10000);
	while (!que.empty())
	{
		int start = que.front();
		que.pop();
		for (int i : vec[start])
		{
			if (capacity[{start, i}] - flow[{start,i}] > 0 && label[i] == 0)
			{
				label[i] = label[start] + 1;
				que.push(i);
			}
		}
	}
	return label[end_] != 0;
}
int dfs(int start, int minflow)
{
	if (start == end_)
		return minflow;
	for (int i = work[start]; i < vec[start].size(); i++)
	{
		int ii = vec[start][i];
		if (capacity[{start, ii}] - flow[{start, ii}] > 0 && label[ii] == label[start] + 1)
		{
			int ans = dfs(ii, min(minflow, capacity[{start, ii}] - flow[{start, ii}]));
			if (ans > 0)
			{
				work[start] = i;
				flow[{start, ii}] += ans;
				flow[{ii, start}] -= ans;
				return ans;
			}
		}
	}
	work[start] = vec[start].size();
	return 0;
}
int main()
{
	char in;
	cin >> n >> m;
	vec = vector<vector<int>>(20003);
	//���� -1
	//����� 1
	//������ 2
	int starti=0, startj=0,endi=0,endj=0;
	//1~10000
	//in �� �״�� out�� 10000 + in
	memset(data_, -1, sizeof data_);
	for (int i = 1; i <= n; i++)
	{
		int sum = (i - 1) * m;
		for (int j = 1; j <= m; j++)
		{
			//in - out ����
			vec[sum + j].push_back(10000 + sum + j);
			vec[10000 + sum + j].push_back(sum + j);
			capacity[{sum + j, 10000 + sum + j}] = 1;
			cin >> in;
			if (in == 'K')
			{
				starti = i;
				startj = j;
				data_[i][j] = 1;
			}
			else if (in == '.')
				data_[i][j] = 0;
			else if (in == '#')
				data_[i][j] = -1;
			else if (in == 'H')
			{
				endi = i;
				endj = j;
				data_[i][j] = 2;
			}
		}
	}
	start_ = (starti - 1) * m + startj;
	end_ = (endi - 1) * m + endj;
	//-1�� ��� �αٿ� ����
	if (data_[starti + 1][startj] == 2 || data_[starti - 1][startj] == 2 || data_[starti][startj + 1] == 2 || data_[starti][startj - 1] == 2)
	{
		cout << -1;
		return 0;
	}
	//���� ����
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int sum = (i - 1) * m + j;
			if (data_[i][j] == -1)
				continue;
			if (data_[i + 1][j] != -1)
			{
				vec[sum + out].push_back(sum + m);
				vec[sum + m].push_back(sum + out);
				vec[sum + m + out].push_back(sum);
				vec[sum].push_back(sum + m + 10000);
				capacity[{sum + 10000, sum + m}] = 1;
				capacity[{sum + 10000 + m, sum}] = 1;
			}
			if (data_[i][j + 1] != -1)
			{
				vec[sum + out].push_back(sum + 1);
				vec[sum + 1].push_back(sum + out);
				vec[sum + out + 1].push_back(sum);
				vec[sum].push_back(sum + out + 1);
				capacity[{sum + 10000, sum + 1}] = 1;
				capacity[{sum + 10000 + 1, sum}] = 1;
			}
		}
	}
	int result = 0;
	while (bfs() == true)
	{
		memset(work, 0, sizeof work);
		while (1)
		{
			int ans = dfs(start_+10000, INF);
			if (ans == 0)
				break;
			result += ans;
		}
	}
	cout << result;
	return 0;
}