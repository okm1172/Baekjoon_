#include <iostream>
#include <vector>
#include <string.h>
//dp는 진짜 어렵네요..dp는 감도 안잡혀요..
using namespace std;

vector<pair<int, int>> map_;
vector<pair<int, int>> police1(1002), police2(1002);
int N, W;
int dp[1002][1002];

int MAX(int a, int b)
{
	return a > b ? a : b;
}
int MIN(int a, int b)
{
	return a < b ? a : b;
}
int calc(int x1, int y1, int x2, int y2)
{
	int xx = (x1 - x2 < 0) ? x2 - x1 : x1 - x2;
	int yy = (y1 - y2 < 0) ? y2 - y1 : y1 - y2;
	return xx + yy;
}
int dp_(int pol1,int pol2)
{
	if (pol1 == W || pol2 == W) return 0;
	if (dp[pol1][pol2] != -1) return dp[pol1][pol2];
	int next = MAX(pol1, pol2) + 1;
	int dis1, dis2;
	if (pol1 == 0)
		dis1 = calc(1, 1, map_[next].first, map_[next].second); else
	dis1 = calc(map_[pol1].first, map_[pol1].second, map_[next].first, map_[next].second);
	if (pol2 == 0)
		dis2 = calc(N, N, map_[next].first, map_[next].second); else
	dis2 = calc(map_[pol2].first, map_[pol2].second, map_[next].first, map_[next].second);
	dp[pol1][pol2] = MIN(dis1 + dp_(next, pol2), dis2 + dp_(pol1, next));
	return dp[pol1][pol2];
}
void dpprint(int pol1, int pol2)
{
	if (pol1 == W || pol2 == W)
		return;
	int next = MAX(pol1, pol2) + 1;
	int dis1, dis2;
	if (pol1 == 0)
		dis1 = calc(1, 1, map_[next].first, map_[next].second); else
		dis1 = calc(map_[pol1].first, map_[pol1].second, map_[next].first, map_[next].second);
	if (pol2 == 0)
		dis2 = calc(N, N, map_[next].first, map_[next].second); else
		dis2 = calc(map_[pol2].first, map_[pol2].second, map_[next].first, map_[next].second);
	if (dis1 + dp[next][pol2] < dis2 + dp[pol1][next])
	{
		cout << 1 << endl;
		dpprint(next, pol2);
	}
	else
	{
		cout << 2 << endl;
		dpprint(pol1, next);
	}
}
int main()
{
	cin >> N >> W;
	map_.push_back({ 0,0 });
	for (int i = 0; i < W; i++)
	{
		int a, b;
		cin >> a >> b;
		map_.push_back({ a,b });
	}
	memset(dp, -1, sizeof(dp));
	cout<<dp_(0, 0)<<endl;
	dpprint(0, 0);
	return 0;
}