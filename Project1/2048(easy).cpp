#include <iostream>
#include <vector>

using namespace std;

int data_[30][30];
//result에선 data_2만 써요.
int data_2[30][30];
int n;
int case_[6];
vector<int> result_;
int resultmax = -999999;
//1 오른 2 왼 3 위 4 아래
void result(int check)
{
	if (check == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			result_.clear();
			result_.push_back(data_2[i][n]);
			for (int j = n - 1; j >= 1; j--)
			{
				if (data_2[i][j] == result_[result_.size() - 1])
					result_[result_.size() - 1] *= 2;
				else
					result_.push_back(data_2[i][j]);
			}
			int q = result_.size();
			for (int j = q; j <= n; j++)
				result_.push_back(0);
			for (int j = 1; j <= n; j++)
			{
				data_2[i][(n+1)-j] = result_[j - 1];
			}
		}
	}
	else if (check == 2)
	{
		for (int i = 1; i <= n; i++)
		{
			result_.clear();
			result_.push_back(data_2[i][1]);
			for (int j = 2; j <= n; j++)
			{
				if (data_2[i][j] == result_[result_.size() - 1])
					result_[result_.size() - 1] *= 2;
				else
					result_.push_back(data_2[i][j]);
			}
			int q = result_.size();
			for (int j = q; j <= n; j++)
				result_.push_back(0);
			for (int j = 1; j <= n; j++)
			{
				data_2[i][j] = result_[j - 1];
			}
		}
	}
	//위쪽
	else if (check == 3)
	{
		for (int j = 1; j <= n; j++)
		{
			result_.clear();
			result_.push_back(data_2[1][j]);
			for (int i = 2; i <= n; i++)
			{
				if (data_2[i][j] == result_[result_.size() - 1])
					result_[result_.size() - 1] *= 2;
				else
					result_.push_back(data_2[i][j]);
			}
			int q = result_.size();
			for (int i = q; i <= n; i++)
				result_.push_back(0);
			for (int i = 1; i <= n; i++)
			{
				data_2[i][j] = result_[i - 1];
			}
		}
	}
	else if (check == 4)
	{
		for (int j = 1; j <= n; j++)
		{
			result_.clear();
			result_.push_back(data_2[n][j]);
			for (int i = n-1; i>=1; i--)
			{
				if (data_2[i][j] == result_[result_.size() - 1])
					result_[result_.size() - 1] *= 2;
				else
					result_.push_back(data_2[i][j]);
			}
			int q = result_.size();
			for (int i = q; i <= n; i++)
				result_.push_back(0);
			for (int i = 1; i <= n; i++)
			{
				data_[(n + 1) - i][j] = result_[i - 1];
			}
		}
	}
}
void case2(int cnt)
{
	if (cnt == 6)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				data_2[i][j] = data_[i][j];
		for (int i = 1; i <= 5; i++)
		{
			result(case_[i]);
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (resultmax < data_2[i][j])
					resultmax = data_2[i][j];
		return;
	}
	for (int i = 1; i <= 4; i++)
	{
		case_[cnt] = i;
		case2(cnt + 1);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> data_[i][j];
		}
	}
	case2(1);
	cout << resultmax;
	return 0;
}