#include <iostream>
#include <vector>

//��Ʈ ����ŷ
using namespace std;
int n, visit[500000], resultcnt;
vector<int> now, result;
void w(int cnt_, int what)
{
	//���ᰪ, �̹� ���۵Ǿ�����, ������ ������� ���� �ϰ�, ���� �� �� ã��
	if (cnt_ != 0 && what == 0 && cnt_ > resultcnt)
	{
		resultcnt = cnt_;
		result = now;
		return;
	}
	//m�� �� �������, n�� ����� Ƚ��
	for (int i = 0; i < n; i++)
	{
		//����
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
			//�����°� visit�ǵ� ��� �Ͼ���ְ�.
			else if (cnt_ != 0 && k == 0)
			{
				visit[0] = 1;
				now.push_back(i);
				w(cnt_ + 1, 0);
				now.pop_back();
			}
		}
		//�߰�
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