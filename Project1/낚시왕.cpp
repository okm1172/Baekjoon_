#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int R, C, M;
int shark_[103][103];
vector < pair<pair<int, int>,int>> vec;
vector<pair<int, int>> vec2;
int dihigh, diright;
int mindata_ = 0,min_ = 9999999;
int human = 0;
int result = 0;
void move(int i)
//1 �� 2 �Ʒ� 3 ���� 4 ��
{
	//r �� c �� s �ӷ� d ���� z ũ�� // check == 1 ������ 0 ������ //�³� �𸣰ڴ�
	int check;
	if (vec2[i].first == 1)
	{
		int speed = vec[i].second;
		if (vec[i].first.first - 1 < speed)
		{
			speed -= vec[i].first.first - 1;
			//������
			if ((speed / dihigh) % 2 == 1)
			{
				vec[i].first.first = 1 + (speed % dihigh);
				vec2[i].first = 2;
			}
			//������
			else
				vec[i].first.first = R - (speed % dihigh);
		}
		else
		{
			vec[i].first.first = vec[i].first.first - speed;
		}
	}
	else if (vec2[i].first == 2)
	{
		int speed = vec[i].second;
		if (R-vec[i].first.first< speed)
		{
			speed -= R - vec[i].first.first;
			//������
			if ((speed / dihigh) % 2 == 1)
			{
				vec[i].first.first = R - (speed % dihigh);
				vec2[i].first = 1;
			}
			//������
			else
				vec[i].first.first = 1 + (speed % dihigh);
		}
		else
		{
			vec[i].first.first = vec[i].first.first + speed;
		}
	}
	else if (vec2[i].first == 3)
	{
		int speed = vec[i].second;
		if (C-vec[i].first.second < speed)
		{
			speed -= C-vec[i].first.second;
			//������
			if ((speed / diright) % 2 == 1)
			{
				vec[i].first.second = C - (speed % dihigh);
				vec2[i].first = 4;
			}
			//������
			else
				vec[i].first.second = 1 + (speed % dihigh);
		}
		else
		{
			vec[i].first.second = vec[i].first.second + speed;
		}
	}
	else if (vec2[i].first == 4)
	{
		int speed = vec[i].second;
		if (vec[i].first.second - 1 < speed)
		{
			speed -= vec[i].first.second - 1;
			//������
			if ((speed / dihigh) % 2 == 1)
			{
				vec[i].first.second = 1 + (speed % dihigh);
				vec2[i].first = 3;
			}
			//������
			else
				vec[i].first.second = C - (speed % dihigh);
		}
		else
		{
			vec[i].first.second = vec[i].first.second - speed;
		}
	}
	//�̵� �� �ߺ� üũ
	if (shark_[vec[i].first.first][vec[i].first.second] != -1)
	{
		int ii = shark_[vec[i].first.first][vec[i].first.second];
		//���� �ִ� ���� �� ū��
		if (vec2[ii].second > vec2[i].second)
		{
			vec.erase(vec.begin() + i);
			vec2.erase(vec2.begin() + i);
		}
		//���߿� ���³��� �� ū��
		else
		{
			vec.erase(vec.begin() + ii);
			vec2.erase(vec2.begin() + ii);
			shark_[vec[i].first.first][vec[i].first.second] = i;
		}
	}
	//���� ó�� ����
	else
	{
		shark_[vec[i].first.first][vec[i].first.second] = i;
		if (vec[i].first.second == human)
		{
			if (min_ > vec[i].first.first)
			{
				min_ = vec[i].first.first;
				mindata_ = i;
			}
		}
	}
}
//�԰� ���� ����..
//���Ͷ� �迭 ������ �ٸ�..
//�� ���� �������
int main()
{
	cin >> R >> C >> M;
	dihigh = R - 1, diright = C - 1;
	min_ = 999999;
	mindata_ = -3;
	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		r--;
		c--;
		vec.push_back({ {r,c}, s});
		if (vec[i].first.second == human)
		{
			if (min_ > vec[i].first.first)
			{
				min_ = vec[i].first.first;
				mindata_ = i;
			}
		}
		vec2.push_back({ d,z });
	}
	if (mindata_ >= 0)
	{
		result += vec2[mindata_].second;
		vec.erase(vec.begin() + mindata_);
		vec2.erase(vec2.begin() + mindata_);
	}
	cout << mindata_;
	for (int jj = 0; jj < C; jj++)
	{
		memset(shark_, -1, sizeof(shark_));
		min_ = 999999;
		mindata_ = -3;
		for (int i = 0; i < vec.size(); i++)
		{
			move(i);
		}
		if (mindata_ >= 0)
		{
			result+=vec2[mindata_].second;
			vec.erase(vec.begin() + mindata_);
			vec2.erase(vec2.begin() + mindata_);
		}
	}
	cout << result;
	return 0;
}