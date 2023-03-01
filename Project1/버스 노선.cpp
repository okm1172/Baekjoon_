#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 2000005

struct bus
{
	int start;
	int last;
	int cnt;
};

struct bus data[MAX];
bool compare(bus a, bus b)
{
	if (a.start == b.start)
	{
		return a.last > b.last;
	}
	return a.start < b.start;
}
int check2[5000004];
int main()
{
	int n, m;
	cin >> n >> m;
	int cnt = m - 1;
	for (int i = 0; i < m; i++)
	{
		int start, last;
		cin >> start >> last;
		if (start > last)
		{
			::data[i].start = start;
			::data[i].last = last + n;
			::data[i].cnt = i;
		}
		else
		{
			::data[i].start = start;
			::data[i].last = last;
			::data[i].cnt = i;
			cnt++;
			::data[cnt].start = start + n;
			::data[cnt].last = last + n;
			::data[cnt].cnt = i;
		}
	}
	cnt = cnt + 1;
	sort(::data,::data + cnt, compare);
	/*for (int i = 0; i < cnt; i++)
	{
		cout << ::data[i].start << " " << ::data[i].last << " " << ::data[i].cnt<<endl;
	}*/
	int max = -999;
	max = ::data[0].last;
	for (int i = 1; i < cnt; i++)
	{
		if (::data[i].last <= max)
		{
			::check2[::data[i].cnt] = 1;
		}
		if (max < ::data[i].last)
			max = ::data[i].last;
	}
	for (int i = 0; i < m; i++) {
		if (::check2[i] == 1)
			continue;
		cout << i + 1<<'\n';
	}
	return 0;
}