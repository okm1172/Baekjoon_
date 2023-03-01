#include <iostream>
//후우..이걸..어떻게해야할까..
//최대값을 두개 구해서 최대값이 바꼈는데 바뀐 값이 그 수열에 최대값이면?
//1 3 -> 1 2 이면 갱신은 안되지만 최대값은 2라는거지..
//1 3 -> 2 3 이면 갱신은 안되지만 최소값은 1이라는거지..
//따라서 최대값, 최소값을 따로 두개를 구해서 계속 왔다리 갔다리 해야함.
using namespace std;
int n, k;
int data_[2000000];
int data_max[2000000][4];
int data_min[2000000][4];
int max_ = -999;
int min_ = 9999999;

void maxmin_(int start, int last, int i)
{
	if (start == last)
	{
		data_max[i][1] = data_[start];
		data_min[i][1] = data_[start];
		return;
	}
	int mid = (start + last) / 2;
	maxmin_(start, mid, i * 2);
	maxmin_(mid + 1, last, i * 2 + 1);
	data_max[i][1] = (data_max[i * 2][1] > data_max[i * 2 + 1][1]) ? data_max[i * 2][1] : data_max[i * 2 + 1][1];
	data_min[i][1] = (data_min[i * 2][1] < data_min[i * 2 + 1][1]) ? data_min[i * 2][1] : data_min[i * 2 + 1][1];
}
int _max(int start, int last, int i,int x,int y)
{
	if (start > y || last < x)
		return -99;
	if (start == last)
	{
		return data_max[i][1];
	}
	int mid = (start + last) / 2;
	return (_max(start, mid, i * 2, x, y) > _max(mid + 1, last, i * 2 + 1, x, y)) ? _max(start, mid, i * 2, x, y) : _max(mid + 1, last, i * 2 + 1, x, y);
}/*
void swit(int start, int last, int i, int where_,int k)
{
	if (start > where_ || last < where_)
		return;
	if (data_max[i] < k)
		data_max[i] = k;
	if (data_min[i] > k)
		data_min[i] = k;
	if (start == last)
	{
		data_max[i] = k;
		data_min[i] = k;
		return;
	}
	int mid = (start + last) / 2;
	swit(start, mid, i * 2, where_, k);
	swit(mid + 1, last, i * 2 + 1, where_, k);
}*/
void result(int start, int last, int i, int x,int y)
{
	if (start > y || last < x)
		return;
	if (start >= x && last <= y)
	{
		if (max_ < data_max[i])
			max_ = data_max[i];
		if (min_ > data_min[i])
			min_ = data_min[i];
		return;
	}
	int mid = (start + last) / 2;
	result(start, mid, i * 2, x,y);
	result(mid + 1, last, i * 2 + 1, x,y);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int qq = 1; qq <= T; qq++)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			data_[i] = i;
		}
		maxmin_(1, n, 1);
		int q, a, b;
		for (int i = 1; i <= k; i++)
		{
			cin >> q >> a >> b;
			a++, b++;
			if (q == 1)
			{
				result(1, n, 1, a, b);
				cout << max_ << " " << min_ << " " << a << " " << b << endl;
				cout << ((max_ == b && min_ == a) ? "YES" : "NO") << "\n";
				max_ = -999;
				min_ = 9999999;
			}
			else if (q == 0)
			{
				swit(1, n, 1, a, data_[b]);
				swit(1, n, 1, b, data_[a]);
				int tmp = data_[a];
				data_[a] = b;
				data_[b] = tmp;
				for (int i = 1; i <= 20; i++)
				{
					cout << data_max[i] << " ";
				}
				cout << endl;
				for (int i = 1; i <= 20; i++)
				{
					cout << data_min[i] << " ";
				}
				cout << endl;

			}
		}
	}
	return 0;
}