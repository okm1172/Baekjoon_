#include <iostream>
#include <algorithm>
//아니 이거 초등부 3번 맞아? 진짜 개어려운데 이게 그리디임? dp랑 아예 다르네
//이거 아이디어 또라이 급인데 이거 KOI 이였으면 생각 못했음 나,,

using namespace std;

int main()
{
	int n;
	int data[10003];
	int sum = 0;
	int max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
		max+= data[i];
	}
	sort(data, data + n);
	data[n] = max + 2;
	if (data[0] != 1)
	{
		cout << "1";
		return 0;
	}
	sum = data[0];
	for (int i =1;i<=n;i++)
	{
		if (sum + 1 < data[i])
		{
			cout << sum + 1;
			return 0;
		}
		sum += data[i];
	}
	return 0;
}