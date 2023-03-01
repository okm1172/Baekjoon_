#include <iostream>

using namespace std;

int main()
{
	int resultD = 0,resultW=0;
	int r, c;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> r >> c;
		resultW += r * c;
		while (r * c != 0)
		{
			resultD += (c - 1) * r;
			resultD += (r - 1) * c;
			resultW += (r - 1) * (c - 1) *2;
			r--, c--;
		}
		//화이트 3*2 + 2*1, 2*1 + 1*0
		//다크 3*1 + 2*2, 2*0 + 1*1
		cout << resultW << " " << resultD << endl;
		resultW = 0, resultD = 0;
	}
	return 0;
}