#include <iostream>
#include <map>
#include <utility>

using namespace std;
#define cc 1000000007


map<pair<int, int>, int> map2;
//??아니 이거 페르마의 소정리는 무슨 소리야 이거..아니 시팔.. 몰라..
int n, m;
int aa(int x, int y)
{
	if (y == 0 || x==y)
		return 1;
	map<pair<int, int>, int>::iterator Iter = map2.find(make_pair(x, y));
	if (Iter!=map2.end())
	{
		return Iter->second;
	}
	int qq = aa(x - 1, y)%cc + aa(x - 1, y - 1)%cc;
	map2.insert(map<pair<int, int>, int>::value_type(make_pair(x, y), qq));
	return qq;
}
int main()
{
	cin >> n >> m;
	aa(n, m);
	map<pair<int, int>, int>::iterator Iter = map2.find(make_pair(n, m));
	cout << Iter->second % cc;
	return 0;
}