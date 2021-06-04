#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

	sort(lottos.begin(), lottos.end());
	sort(win_nums.begin(), win_nums.end());
	int i;
	int same = 0;
	for (i = 5; i >= 0; i--)
	{
		if (lottos.at(i) == 0)
			break;
		if (binary_search(win_nums.begin(), win_nums.end(), lottos.at(i)))
			same++;
	}
	answer.push_back(max(1, min(6, 7 - (same + i + 1))));
	answer.push_back(min(6, 7 - same));

    return answer;
}
