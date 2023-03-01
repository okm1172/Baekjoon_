#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
//unordered_map사용법은 header추가 해주고 선언할때 unordered_map
//해주면 되는데 사용 조건은 key가 중복 X map보다 훨씬 입력 데이터 많을때.

using namespace std;

unordered_map<string, int> mm;
string mm2[100003];
string mm3[100003];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		mm2[i] = input;
		mm.insert(make_pair(input, i));
	}
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		if (input[0] >= '0' && input[0] <= '9')
		{
			mm3[i] = mm2[stoi(input)-1];
		}
		else
			mm3[i] = to_string(mm[input]+1);
	}
	for (int i = 0; i < m; i++)
	{
		cout << mm3[i] << "\n";
	}
	return 0;
}