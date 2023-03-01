#include <iostream>
#include <string>
//LCS는 솔직히 이거 너무 정해져 있는 알고리즘이라서 의미가 잇나 싶을 정도로..ㅎㅎ..
using namespace std;

int aa[1003][1003];

int main()
{
	string a, b;
	cin >> a >> b;
	for (int i = 1; i <= a.length(); i++)
	{
		for (int j = 1; j <= b.length(); j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				aa[i][j] = aa[i - 1][j - 1]+1;
			}
			else if(a[i-1]!=b[j-1])
			{
				aa[i][j] = (aa[i - 1][j] > aa[i][j - 1]) ? aa[i - 1][j] : aa[i][j - 1];
			}
		}
	}
	cout << aa[a.length()][b.length()];
	return 0;
}