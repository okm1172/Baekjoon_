#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define INF 2147483646

//다익스트라는 거의 priority_queue로 풉시당!
//훨씬 빨라요 갖다 박는 bfs보다
//어우 시팔 진짜 memset
//priority에 우선순위가 이어지는 가중치만으로 보는게 아니라 가중치들의 합이
//priority로 구성되어야합니다.. 이말이 뭐냐?
//https://devfunny.tistory.com/641참고하세요..다익스트라도 쫌 그러네요..ㅜ
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
	//pair< 가중치, 정점 >
	//k가 시작점
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