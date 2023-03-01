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
//1 위 2 아래 3 오른 4 왼
{
	//r ㅁ c ㅁ s 속력 d 방향 z 크기 // check == 1 역방향 0 순방향 //맞나 모르겠다
	int check;
	if (vec2[i].first == 1)
	{
		int speed = vec[i].second;
		if (vec[i].first.first - 1 < speed)
		{
			speed -= vec[i].first.first - 1;
			//역방향
			if ((speed / dihigh) % 2 == 1)
			{
				vec[i].first.first = 1 + (speed % dihigh);
				vec2[i].first = 2;
			}
			//정방향
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
			//역방향
			if ((speed / dihigh) % 2 == 1)
			{
				vec[i].first.first = R - (speed % dihigh);
				vec2[i].first = 1;
			}
			//정방향
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
			//역방향
			if ((speed / diright) % 2 == 1)
			{
				vec[i].first.second = C - (speed % dihigh);
				vec2[i].first = 4;
			}
			//정방향
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
			//역방향
			if ((speed / dihigh) % 2 == 1)
			{
				vec[i].first.second = 1 + (speed % dihigh);
				vec2[i].first = 3;
			}
			//정방향
			else
				vec[i].first.second = C - (speed % dihigh);
		}
		else
		{
			vec[i].first.second = vec[i].first.second - speed;
		}
	}
	//이동 후 중복 체크
	if (shark_[vec[i].first.first][vec[i].first.second] != -1)
	{
		int ii = shark_[vec[i].first.first][vec[i].first.second];
		//원래 있던 놈이 더 큰거
		if (vec2[ii].second > vec2[i].second)
		{
			vec.erase(vec.begin() + i);
			vec2.erase(vec2.begin() + i);
		}
		//나중에 들어온놈이 더 큰거
		else
		{
			vec.erase(vec.begin() + ii);
			vec2.erase(vec2.begin() + ii);
			shark_[vec[i].first.first][vec[i].first.second] = i;
		}
	}
	//완전 처음 들어옴
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
//규격 생각 안함..
//벡터랑 배열 시작점 다름..
//다 갈아 엎어야함
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