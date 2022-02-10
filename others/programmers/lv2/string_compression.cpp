#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = 1005;

	for (int j = 1; j <= s.size(); j++)
	{
		vector<string> strings;
		int tmplen = 0;
		int flag = 1;
		for (int i = 0; i < s.size(); i += j)
			strings.push_back(s.substr(i, min(j, (int)s.size() - i)));
		for (int i = 0; i < strings.size() - 1; i++)
		{
			if (!strings[i].compare(strings[i + 1]))
				flag++;
			else
			{
				tmplen += j + (flag == 1 ? 0 : to_string(flag).size());
				flag = 1;
			}
		}
		if (flag != 1)
			tmplen += to_string(flag).size();
		tmplen += strings[strings.size() - 1].size();
		if (tmplen != 0)
			answer = min(answer, tmplen);
	}
	return answer;
}