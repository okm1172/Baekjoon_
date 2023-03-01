#include <iostream>
#include <vector>

//비트 마스킹
using namespace std;
int n, visit[500000], resultcnt;
vector<int> now, result;
void w(int cnt_, int what)
{
	//종료값, 이미 시작되었으며, 마지막 사람까지 퇴장 하고, 가장 긴 놈 찾기
	if (cnt_ != 0 && what == 0 && cnt_ > resultcnt)
	{
		resultcnt = cnt_;
		result = now;
		return;
	}
	//m은 뭐 골랐는지, n은 진행된 횟수
	for (int i = 0; i < n; i++)
	{
		//삭제
		if (((1 << i) & what) > 0)
		{
			int k = (~(1 << i)) & what;
			if (visit[k] == 0)
			{
				visit[k] = 1;
				now.push_back(i);
				w(cnt_ + 1, k);
				now.pop_back();
			}
			//나가는건 visit되도 계속 일어날수있게.
			else if (cnt_ != 0 && k == 0)
			{
				visit[0] = 1;
				now.push_back(i);
				w(cnt_ + 1, 0);
				now.pop_back();
			}
		}
		//추가
		if (((1 << i) & what) == 0)
		{
			int k = (1 << i) | what;
			if (visit[k] == 0)
			{
				visit[k] = 1;
				now.push_back(i);
				w(cnt_ + 1, k);
				now.pop_back();
			}
		}
	}
}
int main()
{
	cin >> n;
	w(0, 0);
	cout << resultcnt - 1<<"\n";
	for (int i : result)
		cout << i+1 << "\n";
	return 0;
}