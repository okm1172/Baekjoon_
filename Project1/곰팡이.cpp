#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int n, m;
int data_[103][103];
int resultcnt = 0;
int check[103][103];
int checkque2 = 0;
int cnt = 0;
queue<pair<int,pair<int, int>>> que;
queue<pair<int,pair<int, int>>> que2;
void pop_()
{
	while (!que.empty())
		que.pop();
}
int main()
{
	cin >> n>>m;
	for (int i = 1; i <= n; i++)
	{
		string input_;
		cin >> input_;
		for (int j = 1; j <= m; j++)
		{
			data_[i][j] = input_[j - 1] - '0';
			if (data_[i][j] != 0)
				que.push({ data_[i][j],{ i,j } });
		}
	}
	//처음 bfs확인
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (check[i][j] == 0 && data_[i][j] != 0)
			{
				//처음이 아니면?
				if (cnt != 0)
				{
					checkque2 = 1;
					break;
				}
				cnt++;
				queue<pair<int, int>> bfs;
				bfs.push({ i,j });
				check[i][j] = 1;
				while (1)
				{
					int a = bfs.front().first, b = bfs.front().second;
					bfs.pop();
					if (check[a + 1][b] == 0 && data_[a + 1][b] != 0)
						bfs.push({ a + 1,b }), check[a + 1][b] = 1;
					if (check[a - 1][b] == 0 && data_[a - 1][b] != 0)
						bfs.push({ a - 1,b }), check[a - 1][b] = 1;
					if (check[a][b + 1] == 0 && data_[a][b + 1] != 0)
						bfs.push({ a,b + 1 }), check[a][b + 1] = 1;
					if (check[a][b - 1] == 0 && data_[a][b - 1] != 0)
						bfs.push({ a,b - 1 }), check[a][b - 1] = 1;
					if (bfs.empty()) break;
				}
			}
		}
		if (checkque2 == 1)
			break;
	}
	if (checkque2 == 0)
	{
		cout << 0;
		return 0;
	}
	que2 = que;
	pop_();
	while (1)
	{
		int starti, startj, endi, endj;
		int start_i = que2.front().second.first, start_j = que2.front().second.second;
		int data = que2.front().first;
		que2.pop();
		starti = start_i - data, startj = start_j - data, endi = start_i + data, endj = start_j + data;
		for (int i = starti; i <= endi; i++)
		{
			if (i <= 0 || i>n) continue;
			for (int j = startj; j <= endj; j++)
			{
				if (j <= 0 || j > m) continue;
				//data_[i][j] 는 범위안에 해당하는 값
				//data는 뿌린 놈의 자라는 속도
				if (data_[i][j] == data)
					continue;
				if (data_[i][j] < data)
				{
					que.push({ data,{ i,j } });
					data_[i][j] = data;
				}
			}
		}
		/*for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cout << data_[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		if (que2.empty())
		{//한번씩 끝날때마다..
			checkque2 = 0;
			memset(check, 0, sizeof check);
			cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					if (check[i][j] == 0 && data_[i][j]!=0)
					{
						//처음이 아니면?
						if (cnt != 0)
						{
							checkque2 = 1;
							break;
						}
						cnt++;
						queue<pair<int,int>> bfs;
						bfs.push({ i,j });
						check[i][j] = 1;
						while (1)
						{
							int a = bfs.front().first, b = bfs.front().second;
							bfs.pop();
							if (check[a + 1][b] == 0 && data_[a + 1][b] != 0)
								bfs.push({ a + 1,b }),check[a+1][b]=1;
							if (check[a - 1][b] == 0 && data_[a - 1][b] != 0)
								bfs.push({ a - 1,b }),check[a-1][b]=1;
							if (check[a][b + 1] == 0 && data_[a][b + 1] != 0)
								bfs.push({ a,b + 1 }),check[a][b+1]=1;
							if (check[a][b - 1] == 0 && data_[a][b - 1] != 0)
								bfs.push({ a,b - 1 }), check[a][b - 1]=1;
							if (bfs.empty()) break;
						}
					}
				}
				if (checkque2 == 1)
					break;
			}
			if (checkque2 == 0)
			{
				cout << resultcnt + 1;
				return 0;
			}
			resultcnt++;
			que2 = que;
			pop_();
		}
	}
	return 0;
}