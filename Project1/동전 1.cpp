#include <iostream>
#include <algorithm>
//DP진짜 어렵다 아니 이거 감이 안옴..
//지엽적인거랑 별개로 진짜로 그냥 모르겠음..
//DP연습 진짜 많이 해야할거 같음.
//DP만큼 자주 나오는게 없어. 프로그래밍에서.
using namespace std;
int n, k;
int data_[10004];
int A[10004];
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin>>data_[i];
	sort(data_ + 1, data_ + 1 + n);
	A[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j >= data_[i])
			{
				A[j] += A[j - data_[i]];
			}
		}
	}
	cout << A[k];
	return 0;
}