#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

usign namespace std;

long long solution(vector<int> x, vector<int> y, vector<int> r, vector<int> v)
{
	long long answer = 0;
	int le, ri, bo, to;
	int cnt = 0;
	vector<int> left;
	vector<int> right;
	vector<int> bottom;
	vector<int> top;
	int ranx, rany;

	for (int i = 0; i < x.size(); i++)
	{
		left.push_back(x[i] - r[i]);
		right.push_back(x[i] + r[i]);
		bottom.push_back(y[i] - r[i]);
		top.push_back(y[i] + r[i]);
	}
	le = *min_element(left.begin(), left.end());
	ri = *max_element(right.begin(), right.end());
	bo = *min_element(bottom.begin(), bottom.end());
	to = *max_element(top.begin(), top.end());

	for (int i = 0; i < v.size() / 2; i++)
	{
		ranx = le + v[2 * i] % (ri = le);
		rany = bo + v[2 * i + 1] % (to - bo);
		for (int j = 0; j < x.size(); j++)
		{
			if (sqrt(pow(ranx - x[j], 2) + pow(rany - y[j], 2)) <= r[j])
			{
				cnt++;
				break;
			}
		}
	}
	answer = (long long)(ri - le) * (to - bo) * cnt / (v.size() / 2);
	return answer;
}
