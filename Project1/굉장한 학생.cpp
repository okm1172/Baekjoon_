#include <iostream>
#include <vector>
#include <algorithm>
//����..���� ���׸�Ʈ�� �̷��� ���� ����� �����ž� �Ƹ� https://jaemin8852.tistory.com/237 �����ϼ���..��
//��¥ ��ð� �ɸ��ų� ���غ��� �����ؼ� ���ذ� 2�ð� �̻� �ɸ���
//�л� ������ ������� �ֳ�? ���ݸ� �����غ��� �츮�� ������ ����� �ֵ� ����� ���ϸ� ���� ������ �Ű� �Ƚᵵ ���� ���´�.
//������ ����� ����..
#define INF 2147483647
#define ab 500003
using namespace std;

int data1[ab],data2[ab],data3[ab];
int seg[ab * 3];
vector<pair<int, pair<int, int>>> vec;
int n;
int seg_update(int start, int last, int i, int index, int data_)
{
	if (start > index || last < index)
		return seg[i];
	if (start == last)
		return seg[i] = data_;
	int mid = (start + last) / 2;
	return seg[i] = min(seg_update(start, mid, i * 2, index, data_), seg_update(mid + 1, last, i * 2 + 1, index, data_));
}
int seg_min(int start, int last, int i, int index)
{
	if (start > index || last < 1)
		return INF;
	if (start >= 1 && last <= index)
		return seg[i];
	int mid = (start + last) / 2;
	return min(seg_min(start, mid, i * 2, index), seg_min(mid + 1, last, i * 2 + 1, index));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int tt;
		cin >> tt;
		data1[tt] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int tt;
		cin >> tt;
		data2[tt] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int tt;
		cin >> tt;
		data3[tt] = i;
	}
	vec.push_back({ 0,{0,0} });
	fill(seg, seg + 3*ab, INF);
	for (int j = 1; j <= n; j++)
	{
		vec.push_back({ data1[j],{data2[j],data3[j]} });
	}
	int ans = 0;
	sort(vec.begin(), vec.end());
	for (int i = 1; i <= n; i++)
	{
		int qq = seg_min(1, n, 1, vec[i].second.first - 1);
		if (qq > vec[i].second.second) ans++;
		seg_update(1, n, 1, vec[i].second.first, vec[i].second.second);
	//	cout << i<<":"<<qq << endl;
	/*	for (int j = 1; j <= 20; j++)
		{
			cout << seg[j] << " ";
		}
		cout << endl;*/
	}
	cout << ans;
	return 0;
}