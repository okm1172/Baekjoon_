#include <iostream>
//이 코드에서 b==1 일때 말고 왜 b에다가 1를 집어넣으면 오류가 날까?
//아하..check가 아예 안돌아가네..
//이 문제의 아이디어는 "나머지를 양수로만 보지않고 음수로도 볼수있다." 입니당
//엥? 아니 시발 2^31 제곱이 long long 최고보다 작아요.. 아니,,그럼 이 개쥐랄 안했잖아요 나
using namespace std;

int main()
{
	long long a, b, c;
	int check[300];
	cin >> a >> b >> c;
	if (b == 1)
	{
		cout << a % c;
		return 0;
	}
	long long aa = 0,bb=0;
	if (c < a * 2) a = a - c;
	aa = a;
	bb = b;
	int checkcnt = 1;
	//1이 제곱 2가 한번 곱하는거
	while (1)
	{
		if (bb % 2 == 0)
		{
			bb /= 2;
			check[checkcnt] = 1;
		}
		else
		{
			bb--;
			check[checkcnt] = 2;
			checkcnt++;
			bb /= 2;
			check[checkcnt] = 1;
		}
		if (bb == 1)
			break;
		checkcnt++;
	}
	bb = b;
	b = 1;
	while (1)
	{
		if (c < a * 2) a = a - c;
		if (check[checkcnt] == 1)
		{
			a = a * a % c;
			b *= 2;
		}
		else if (check[checkcnt] == 2)
		{
			b++;
			a = a * aa;
			a %= c;
		}
		checkcnt--;
		if (b == bb)
			break;
	}
	if (a<0)
		a = c+a;
	cout << a % c;
	return 0;
}