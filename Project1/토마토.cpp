#include <iostream>
#include <queue>
//����ü ��¥ ���ϴ� �ڷᱸ�� ����
//for�� �ȿ� ���� �ڷᱸ�� ������� �ٲ��.
//����� �����ؼ� ���� ������ 30��ó�� ���� ���س��� �������Ѵ�.
using namespace std;
typedef struct aa {
	int x, y;
};
queue<aa> q;
int n, m;
int dat[1002][1002];
int check[5][2] = { {0,1},{-1,0},{1,0},{0,-1} };
int main()
{
	int i, j;
	int count = 0;
	cin >> n>> m;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> dat[i][j];
			if (dat[i][j] == 1)
				q.push({ i,j });
		}
	}
	while (!q.empty())
	{
		int size = q.size();
		for (i = 0; i < size; i++)
		{
			int a = q.front().x, b = q.front().y;
			q.pop();
			for (j = 0; j < 4; j++)
			{
				int aa = a + check[j][0], bb = b + check[j][1];
				if (aa < 0 || bb < 0 || aa >= m || bb >= n || dat[aa][bb] != 0)
					continue;
				dat[aa][bb] = 1;
				q.push({ aa ,bb });
			}
		}
		if (q.empty())
			break;
		count++;
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (dat[i][j] == 0)
			{
				cout << "-1";
				return 0;
			}
		}
	}
	cout << count;
	return 0;
}