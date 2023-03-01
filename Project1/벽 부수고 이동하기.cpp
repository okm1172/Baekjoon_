/*
#include <iostream>
#include <queue>
#include <string>

using namespace std;
priority_queue <pair< int, pair<int, int>>> xy;
//check가 0일때 먼저 봐주고 
//check가 1일때 나중에 봐주면 되지않을까?
//우선순위 큐를 쓰면 풀릴듯? 어차피 더 작아지든 뭐하든 도달까지 가장 작은 값이니까

int data_[1004][1004];
int data_2[1004][1004];
//data_2는 개수 data_는 입력 데이터
int n, m;
void bfs(int x,int y)
{
	int check2 = xy.top().first;
	xy.pop();
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << data_2[i][j] << " ";
		cout << endl;
	}
	cout << x << " " << y << endl;
	cout<<xy.size()<<endl;
	if (x == 0 || x > n || y == 0 || y > m)
		return;
	//1->-1 0은 그대로.
	if (data_[x + 1][y] == 1)
	{
		if (check2 == 0)
		{
			if (data_2[x + 1][y] > data_2[x][y] + 1 || data_2[x+1][y]==0)
			{
				data_2[x + 1][y] = data_2[x][y] + 1;
				xy.push(make_pair(-1, make_pair(x + 1, y)));
			}
		}
	}
	if (data_[x - 1][y] == 1)
	{
		if (check2 == 0)
		{
			if (data_2[x - 1][y] > data_2[x][y] + 1||data_2[x-1][y]==0)
			{
				data_2[x - 1][y] = data_2[x][y] + 1;
				xy.push(make_pair(-1, make_pair(x -1, y)));
			}
		}
	}
	if (data_[x][y + 1] == 1)
	{
		if (check2 == 0)
			if (data_2[x][y+1] > data_2[x][y] + 1 || data_2[x][y+1]==0)
			{
				data_2[x][y + 1] = data_2[x][y] + 1;
				xy.push(make_pair(-1, make_pair(x, y+1)));
			}
	}
	if (data_[x][y - 1] == 1)
	{
		if (check2 == 0)
			if (data_2[x][y-1] > data_2[x][y] + 1 || data_2[x][y-1]==0)
			{
				data_2[x][y - 1] = data_2[x][y] + 1;
				xy.push(make_pair(-1, make_pair(x, y-1)));
			}
	}
	if (data_[x + 1][y] == 0)
	{
		if (check2 == -1)
		{
			if (data_2[x][y] + 1 < data_2[x + 1][y] || data_2[x+1][y]==0)
			{
				data_2[x + 1][y] = data_2[x][y] + 1;
				xy.push(make_pair(-1, make_pair(x + 1, y)));
			}
		}
		else
		{
			if (data_2[x][y] + 1 < data_2[x + 1][y] || data_2[x + 1][y] == 0)
			{
				data_2[x + 1][y] = data_2[x][y] + 1;
				xy.push(make_pair(0, make_pair(x + 1, y)));
			}
		}
	}
	if (data_[x][y + 1] == 0)
	{
		if (check2 == -1)
		{
			if (data_2[x][y] + 1 < data_2[x][y+1] || data_2[x][y+1]==0)
			{
				data_2[x][y + 1] = data_2[x][y] + 1;
				xy.push(make_pair(-1, make_pair(x, y+1)));
			}
		}
		else
		{
			if (data_2[x][y] + 1 < data_2[x][y+1] || data_2[x][y + 1] == 0)
			{
				data_2[x][y + 1] = data_2[x][y] + 1;
				xy.push(make_pair(0, make_pair(x, y+1)));
			}
		}
	}
	if (data_[x - 1][y] == 0)
	{
		if (check2 == -1)
		{
			if (data_2[x][y] + 1 < data_2[x -1 ][y] || data_2[x-1][y]==0)
			{
				data_2[x - 1][y] = data_2[x][y] + 1;
				xy.push(make_pair(-1, make_pair(x - 1, y)));
			}
		}
		else
		{
			if (data_2[x][y] + 1 < data_2[x - 1][y] || data_2[x - 1][y] == 0)
			{
				data_2[x - 1][y] = data_2[x][y] + 1;
				xy.push(make_pair(0, make_pair(x - 1, y)));
			}
		}
	}
	if (data_[x][y - 1] == 0)
	{
		if (check2 == -1)
		{
			if (data_2[x][y] + 1 < data_2[x][y-1] || data_2[x][y-1] == 0)
			{
				data_2[x][y - 1] = data_2[x][y] + 1;
				xy.push(make_pair(-1, make_pair(x, y-1)));
			}
		}
		else
		{
			if (data_2[x][y] + 1 < data_2[x][y - 1] || data_2[x][y-1] == 0)
			{
				data_2[x][y - 1] = data_2[x][y] + 1;
				xy.push(make_pair(0, make_pair(x, y-1)));
			}
		}
	}
	if (xy.empty())
	{
		return;
	}
	int xx = xy.top().second.first, yy = xy.top().second.second;
	bfs(xx, yy);
}
int main()
{
	string input;
	char qq;
	cin >> n >> m;
	for (int i = 0; i <=n + 1; i++)
	{
		for (int j = 0; j <= m + 1; j++)
		{
			data_[i][j] = 2;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		for (int j = 1; j <= m; j++)
		{
			data_[i][j] = input[j-1]=='0' ? 0 : 1;
		}
	}
	data_2[1][1] = 1;
	xy.push(make_pair(0,make_pair(1, 1)));
	bfs(1, 1);
	cout << (data_2[n][m]==0 ? -1 : data_2[n][m]);
	return 0;
}*/
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int data_2[1004][1004][4];
int data_[1004][1004];
string input;
queue<pair<int, int>> xy;
int n, m;
void bfs(int x, int y)
{
	xy.pop();/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << data_2[i][j][0]<< " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << data_2[i][j][1] << " ";
		cout << endl;
	}
	cout << x << " " << y << endl;
	cout << xy.size() << endl;*/
	if (x == 0 || x > n || y == 0 || y > m)
		return;
	//1->-1 0은 그대로.
	if (data_[x + 1][y] == 1)
	{
		if (data_2[x][y][0]!=0)
		{
			if (data_2[x + 1][y][1] > data_2[x][y][0] + 1 || data_2[x + 1][y][1] == 0)
			{
				data_2[x + 1][y][1] = data_2[x][y][0] + 1;
				xy.push(make_pair(x + 1, y));
			}
		}
	}
	if (data_[x - 1][y] == 1)
	{
		if (data_2[x][y][0] != 0)
		{
			if (data_2[x - 1][y][1] > data_2[x][y][0] + 1 || data_2[x - 1][y][1] == 0)
			{
				data_2[x - 1][y][1] = data_2[x][y][0] + 1;
				xy.push(make_pair(x - 1, y));
			}
		}
	}
	if (data_[x][y + 1] == 1)
	{
		if (data_2[x][y][0] != 0)
			if (data_2[x][y + 1][1] > data_2[x][y][0] + 1 || data_2[x][y + 1][1] == 0)
			{
				data_2[x][y + 1][1] = data_2[x][y][0] + 1;
				xy.push(make_pair(x, y + 1));
			}
	}
	if (data_[x][y - 1] == 1)
	{
		if (data_2[x][y][0] != 0)
			if (data_2[x][y - 1][1] > data_2[x][y][0] + 1 || data_2[x][y - 1][1] == 0)
			{
				data_2[x][y - 1][1] = data_2[x][y][0] + 1;
				xy.push(make_pair(x, y - 1));
			}
	}
	if (data_[x + 1][y] == 0)
	{
		if (data_2[x][y][1]!=0)
		{
			if (data_2[x][y][1] + 1 < data_2[x + 1][y][1] || data_2[x + 1][y][1] == 0)
			{
				data_2[x + 1][y][1] = data_2[x][y][1] + 1;
				xy.push(make_pair(x + 1, y));
			}
		}
		if(data_2[x][y][0]!=0)
		{
			if (data_2[x][y][0] + 1 < data_2[x + 1][y][0] || data_2[x + 1][y][0] == 0)
			{
				data_2[x + 1][y][0] = data_2[x][y][0] + 1;
				xy.push(make_pair(x + 1, y));
			}
		}
	}
	if (data_[x][y + 1] == 0)
	{
		if (data_2[x][y][1]!=0)
		{
			if (data_2[x][y][1] + 1 < data_2[x][y + 1][1] || data_2[x][y + 1][1] == 0)
			{
				data_2[x][y + 1][1] = data_2[x][y][1] + 1;
				xy.push( make_pair(x, y + 1));
			}
		}
		if(data_2[x][y][0]!=0)
		{
			if (data_2[x][y][0] + 1 < data_2[x][y + 1][0] || data_2[x][y + 1][0] == 0)
			{
				data_2[x][y + 1][0] = data_2[x][y][0] + 1;
				xy.push(make_pair(x, y + 1));
			}
		}
	}
	if (data_[x - 1][y] == 0)
	{
		if (data_2[x][y][1] != 0)
		{
			if (data_2[x][y][1] + 1 < data_2[x - 1][y][1] || data_2[x - 1][y][1] == 0)
			{
				data_2[x - 1][y][1] = data_2[x][y][1] + 1;
				xy.push(make_pair(x - 1, y));
			}
		}
		if (data_2[x][y][0] != 0)
		{
			if (data_2[x][y][0] + 1 < data_2[x - 1][y][0] || data_2[x - 1][y][0] == 0)
			{
				data_2[x - 1][y][0] = data_2[x][y][0] + 1;
				xy.push( make_pair(x - 1, y));
			}
		}
	}
	if (data_[x][y - 1] == 0)
	{
		if (data_2[x][y][1] != 0)
		{
			if (data_2[x][y][1] + 1 < data_2[x][y - 1][1] || data_2[x][y - 1][1] == 0)
			{
				data_2[x][y - 1][1] = data_2[x][y][1] + 1;
				xy.push(make_pair(x, y - 1));
			}
		}
		if (data_2[x][y][0] != 0)
		{
			if (data_2[x][y][0] + 1 < data_2[x][y - 1][0] || data_2[x][y - 1][0] == 0)
			{
				data_2[x][y - 1][0] = data_2[x][y][0] + 1;
				xy.push(make_pair(x, y - 1));
			}
		}
	}
	if (xy.empty())
	{
		return;
	}
	int xx = xy.front().first, yy = xy.front().second;
	bfs(xx, yy);
}
int main()
{
	string input;
	char qq;
	cin >> n >> m;
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= m + 1; j++)
		{
			data_[i][j] = 2;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		for (int j = 1; j <= m; j++)
		{
			data_[i][j] = input[j - 1] == '0' ? 0 : 1;
		}
	}
	data_2[1][1][0] = 1;
	xy.push(make_pair(1, 1));
	bfs(1, 1);
	if (data_2[n][m][0]==0 && data_2[n][m][1]==0)
	{
		cout << -1;
	}
	else if (data_2[n][m][0] == 0)
		cout << data_2[n][m][1];
	else if (data_2[n][m][1] == 0)
		cout << data_2[n][m][0];
	else
		cout << (data_2[n][m][0] < data_2[n][m][1] ? data_2[n][m][0] : data_2[n][m][1]);
	return 0;
}