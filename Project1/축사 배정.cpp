#include <iostream>
#include <vector>
#include <string.h>
//�ִ��������ε� Ǯ���ִµ�...
//��� �ȳ���..����
using namespace std;

vector<int> a[300];//��->���
int visited[300];//��� visit
int adj[300];//���->��
int n, m;
int vvv(int cow)
{
	if (visited[cow]) return 0;
	visited[cow] = 1;
	for (int i = 0; i < a[cow].size(); i++)
	{
		//cout << a[cow][i];
		if (adj[a[cow][i]] == -1 || vvv(adj[a[cow][i]]))
		{
			adj[a[cow][i]] = cow;
			return 1;
		}
	}
	return 0;
}
//2 2 5
//3 2 3 4
//2 1 5
//3 1 2 5
//1 2
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int aa;
		cin >> aa;
		for (int j = 0; j < aa; j++)
		{
			int in;
			cin >> in;
			a[i].push_back(in-1);
		}
	}
	for (int i = 0; i < 299; i++)
	{
		adj[i] = -1;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		memset(visited, 0, 300 * sizeof(int));
		if (vvv(i)) cnt++;
	}
	cout << cnt;
	return 0;
}