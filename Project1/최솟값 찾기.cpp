//세그먼트 시간초과 어김없이..
/*#include <iostream>
#include <queue>
using namespace std;
int n, l;
int data_[20000000];
int seg[20000000];
int seg_(int start, int last,int i)
{
	if (start == last)
	{
		return seg[i] = data_[start];
	}
	if (start+1 == last)
	{
		seg[i * 2] = data_[start];
		seg[i * 2 + 1] = data_[last];
		return seg[i] = min(seg[i * 2] , seg[i * 2 + 1]);
	}
	int mid = (start + last) / 2;
	return seg[i] = min(seg_(start, mid, i * 2), seg_(mid + 1, last, i * 2 + 1));
}
int seg_2(int start, int last, int i, int s, int l)
{
	if (start > l || last < s)
		return 2147483647;
	if (s <= start && last <= l)
	{
		return seg[i];
	}
	int mid = (start + last) / 2;
	return min(seg_2(start, mid, i * 2, s, l), seg_2(mid + 1, last, i * 2 + 1, s, l));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
	{
		cin>>data_[i];
	}
	seg_(1, n,1);
	int min = 2147483647;
	for (int i = 1; i <= l - 1; i++)
	{
		if (min > data_[i])
		{
			min = data_[i];
		}
		cout << min << " ";
	}
	for (int i = 1; i <= n - l + 1; i++)
	{
		cout << seg_2(1, n, 1, i, i + l - 1)<<" ";
	}
	return 0;
}*/
//덱 -> deque랑 리스트 차이는 덱은 더블 링크드 리스트이고 일반 리스트는 array를 띄기 때문.
#include <iostream>
#include <queue>

using namespace std;

int l, n;
priority_queue<pair<int, int>> que;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
	{
		int qq;
		cin >> qq;
		que.push({ -qq,i });
		while (que.top().second <= i - l)
			que.pop();
		cout << -que.top().first << " ";
	}
}
