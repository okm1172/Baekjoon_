#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define INF 2147483646

//���ͽ�Ʈ��� ���� priority_queue�� Ǳ�ô�!
//�ξ� ����� ���� �ڴ� bfs����
//��� ���� ��¥ memset
//priority�� �켱������ �̾����� ����ġ������ ���°� �ƴ϶� ����ġ���� ����
//priority�� �����Ǿ���մϴ�.. �̸��� ����?
//https://devfunny.tistory.com/641�����ϼ���..���ͽ�Ʈ�� �� �׷��׿�..��
//O((V+E)*logV)
using namespace std;

int v, e;
int k;
vector<vector<pair<int,int>>> vec;
int cost[20003];
priority_queue<pair<int,int>> que;
void bfs()
{
	while (!que.empty())
	{
		int start = que.top().second;
		que.pop();
		for (pair<int,int> i : vec[start])
		{
			int cost_ = i.first;
			int vertex_ = i.second;
			if (cost_ + cost[start] < cost[vertex_])
			{
				cost[vertex_] = cost_ + cost[start];
				que.push({ cost[vertex_] * -1,i.second});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> v >> e;
	for (int i = 1; i <= v; i++)
	{
		cost[i] = INF;
	}
	vec = vector<vector<pair<int,int>>>(v+3);
	cin >> k;
	for (int i = 1; i <= e; i++)
	{
		int x, y,cost;
		cin >> x >> y>>cost;
		vec[x].push_back({ cost,y });
	}
	//pair< ����ġ, ���� >
	//k�� ������
	cost[k] = 0;
	que.push({ 0,k });
	bfs();
	for (int i = 1; i <= v; i++)
	{
		if (cost[i] == INF)
		{
			cout << "INF" << "\n";
			continue;
		}
		cout << cost[i] << "\n";
	}
	return 0;
}