#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

int map[1001][1001];

int solution(vector<vector<int> > circles)
{
	int answer = 0;
	int n = circles.size();
	double dis, rdiff;
	int x1, x2, y1, y2, r1, r2;

	for (int i = 0; i < n - 1; i++)
	{
		x1 = circles[i][0];
		y1 = circles[i][1];
		r1 = circles[i][2];
		for (int j = i + 1; j < n; j++)
		{
			x2 = circles[j][0];
			y2 = circles[j][1];
			r2 = circles[j][2];
			dis = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
			rdiff = (double)abs(r1 - r2);
			if (dis <= rdiff)
			{
				map[i][j] = 1;
				map[j][i] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		vector<int> tmp; int cnt = 1;
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1)
				tmp.push_back(j);
		}
		cout << "after make tmp\n";
		cout << "tmp.size: " << tmp.size() << '\n';
		if (tmp.size() == 0)
			continue;
		for (int j = 1; j < tmp.size() - 1; j++)
		{
			int k;
			for (k = j + 1; k < tmp.size(); k++)
			{
				if (map[tmp[j]][tmp[k]] == 0)
					break;
			}
			if (k == tmp.size())
				cnt++;
		}
		answer = max(answer, cnt);
		cout << "start i: " << i << " cnt: " << cnt << " answer: " << answer << '\n';
	}
	return answer;
}

int main()
{
	vector<vector<int> > circles;
	vector<int> tmp;

	tmp.push_back(-4);
	tmp.push_back(0);
	tmp.push_back(2);
	circles.push_back(tmp);
	tmp.clear();
	
	tmp.push_back(-4);
	tmp.push_back(0);
	tmp.push_back(4);
	circles.push_back(tmp);
	tmp.clear();

	tmp.push_back(-4);
	tmp.push_back(0);
	tmp.push_back(6);
	circles.push_back(tmp);
	tmp.clear();

	tmp.push_back(2);
	tmp.push_back(0);
	tmp.push_back(8);
	circles.push_back(tmp);
	cout << solution(circles);
	return 0;
}
