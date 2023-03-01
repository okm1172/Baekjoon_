#include <iostream>
#include <vector>

#define ll long long
using namespace std;
//뫼비우스 함수 사용.. 정수론에서 생각보다 쓰임이 많은 함수라니까 아~ 이런게 있구나 정도로만 알고있자.
ll mobius[1000003];
int n;
ll result(ll mid)
{
	ll cnt = 0;
	//뫼비우스 함수를 이용한 합과 배제 해주고
	for (ll i = 2; i * i <= mid; i++)
	{
		cnt += mobius[i] * (mid / (i * i));
	}
	return cnt;
}
//이분탐색에서 시간을 많이 썼는데 내가 이해한 바탕으로 생각해보면
//13 입력했을때, 19 20이 둘다 답이 가능해었어 아래 함수에서
//근데 애초에 20 21같이 제곱 ㄴㄴ가 뒤에 있으면 개수 차이가 나니까 비교 대상이 아니고
//19 20 같이 20이 제곱수라서 값이 똑같을 때 문제가 생기는건데. 이걸 해결하는건 결국 앞에 있는 범위를 쓰면 된다는거야.
//mid + aa >= n은 앞을 쓴다는 코드고 결국 mid+aa==n인 범위가 start,mid로 가는거지 mid,last가 아닌..
void two(ll start,ll last)
{
	ll mid = (start + last) / 2;
	ll aa = result(mid);
	if (last==start)
	{
		cout << start;
		return;
	}
	if (mid + aa < n)
		two(mid+1, last);
	else if (mid + aa >= n)
		two(start, mid);
}
//뫼비우스 함수 구하는 함수
void Mo()
{
	mobius[1] = 1;
	for (int i = 1; i <= 1000000; i++)
	{
		if (mobius[i] == 0) continue;
		for (int j = 2 * i; j <= 1000000; j += i)
		{
			mobius[j] -= mobius[i];
		}
	}
}
int main()
{
	cin >> n;
	Mo();
	two(0,2000000000);
	return 0;
}